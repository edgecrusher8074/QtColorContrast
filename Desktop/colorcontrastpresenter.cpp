#include "colorcontrastpresenter.h"
#include "colorcontrastmodel.h"
#include "colorcontrastviewbase.h"

#include "colorfactormodel.h"
#include "contrastcalculator.h"
#include "contrastcalculatormodel.h"
#include "wcagdefinitions.h"

#include <exception>
#include <cmath>

#include <QDebug>

ColorContrastPresenter::ColorContrastPresenter(ColorContrastViewBase *view, QObject *parent)
    :QObject(parent)
    ,_view(view)
    ,_model(nullptr)
{
}

ColorContrastPresenter::~ColorContrastPresenter() = default;

void ColorContrastPresenter::initialize()
{
    if(_view == nullptr)
        throw std::invalid_argument("view not initialized");

    if(_model == nullptr)
        throw std::invalid_argument("model not initialized");

    _view->addComplianceOption(WCAG2::getTextForGuideline(GuidelineLevel::AA));
    _view->addComplianceOption(WCAG2::getTextForGuideline(GuidelineLevel::AA_18pt_plus));
    _view->addComplianceOption(WCAG2::getTextForGuideline(GuidelineLevel::AAA));
    _view->addComplianceOption(WCAG2::getTextForGuideline(GuidelineLevel::AAA_18pt_plus));

    connect(_view, &ColorContrastViewBase::complianceOptionChanged, this, &ColorContrastPresenter::updateView);

    _view->setComplianceOptionIndex(0);
    updateView();
}

void ColorContrastPresenter::setModel(std::shared_ptr<ColorContrastModel> model)
{
    _model = model;
}

std::shared_ptr<ColorContrastModel> ColorContrastPresenter::getModel() const
{
    return _model;
}

QString ColorContrastPresenter::getColorString(const QString &colorName, const QColor &color)
{
    QString r = QString::number(color.red());
    QString g = QString::number(color.green());
    QString b = QString::number(color.blue());
    QString rgb = QString("(%1, %2, %3)").arg(r, g, b);
    QString hx = color.name(QColor::NameFormat::HexRgb);
    return QString("%1\n%2\n%3").arg(colorName, rgb, hx.toUpper());
}

void ColorContrastPresenter::updateView()
{
    auto data = _model->getData();

    int columnCounter = 1;

    for(const auto& fg : data)
    {
        int rowCounter = 1;

        for(const auto& bg : data)
        {
            if(columnCounter == 1)
            {
                auto colorString = getColorString(bg.name, bg.color);
                _view->addBackgroundColorNameAndCode(rowCounter, colorString);
            }

            if(rowCounter == 1)
            {
               auto colorString = getColorString(fg.name, fg.color);
                _view->addForegroundColorNameAndCode(columnCounter, colorString);
            }

            if(fg.color != bg.color)
            {
                auto contrastModel = std::make_shared<ContrastCalculatorModel>();
                contrastModel->setForeground(fg.color);
                contrastModel->setBackground(bg.color);
                auto currentLevel = static_cast<GuidelineLevel>(_view->getComplianceOptionIndex());
                contrastModel->setGuidelineLevel(currentLevel);

                ContrastCalculator calc(contrastModel);
                calc.doCalculate();

                auto colorContast = std::make_shared<ColorFactorModel>();
                colorContast->setForeground(fg.color);
                colorContast->setBackground(bg.color);
                colorContast->setFactor(contrastModel->getRatio());
                colorContast->setCompliant(contrastModel->getCompliant());

                _view->addVisualization(rowCounter, columnCounter, colorContast);
            }

            ++rowCounter;
        }
        ++columnCounter;
    }
}
