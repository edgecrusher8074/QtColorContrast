#include "colorcontrastview.h"
#include "ui_colorcontrastview.h"

#include "colorfactorwidget.h"
#include "colorfactormodel.h"

#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>

ColorContrastView::ColorContrastView(QObject *parent)
    : ColorContrastViewBase(parent)
    , _ui(std::make_unique<Ui::ColorContrastView>())
    , _mainLayout(nullptr)
{
    _ui->setupUi(qobject_cast<QWidget*>(parent));
    _mainLayout = new QGridLayout(_ui->_centerContents);
    _ui->_centerContents->setLayout(_mainLayout);

    connect(_ui->_comboBoxCompliantTo, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        Q_UNUSED(index);
        emit complianceOptionChanged();
    });
}

ColorContrastView::~ColorContrastView() = default;

void ColorContrastView::clearWidgets(QLayout *layout)
{
    if (layout == nullptr)
       return;

    while (auto item = layout->takeAt(0))
    {
       delete item->widget();
       clearWidgets(item->layout());
    }
}

void ColorContrastView::clearVisualization()
{
    clearWidgets(_mainLayout);
}

void ColorContrastView::addComplianceOption(const QString &text)
{
    _ui->_comboBoxCompliantTo->addItem(text);
}

void ColorContrastView::setComplianceOptionIndex(int index)
{
    _ui->_comboBoxCompliantTo->setCurrentIndex(index);
}

int ColorContrastView::getComplianceOptionIndex() const
{
    return _ui->_comboBoxCompliantTo->currentIndex();
}

void ColorContrastView::addForegroundColorNameAndCode(int column, const QString& colorNameAndCode)
{
    _mainLayout->addWidget(new QLabel(colorNameAndCode, _ui->_centerContents) , 0, column);
}

void ColorContrastView::addBackgroundColorNameAndCode(int row, const QString& colorNameAndCode)
{
    _mainLayout->addWidget(new QLabel(colorNameAndCode, _ui->_centerContents) , row, 0);
}

void ColorContrastView::addVisualization(int row, int column, std::shared_ptr<ColorFactorModel> data)
{
    auto colorFactor = new ColorFactorWidget(_ui->_centerContents);
    colorFactor->initialize(data);
    _mainLayout->addWidget(colorFactor, row, column);
}
