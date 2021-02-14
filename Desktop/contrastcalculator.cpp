#include "contrastcalculator.h"

#include "contrastcalculatormodel.h"
#include "wcagdefinitions.h"

#include "luminancecoefficients.h"

#include <QColor>

#include <vector>

ContrastCalculator::ContrastCalculator(std::shared_ptr<ContrastCalculatorModel> model)
    :_model(model)
{
}

ContrastCalculator::~ContrastCalculator() = default;

void ContrastCalculator::doCalculate()
{
    _model->setRatio(calculateRatio());
    _model->setCompliant(isCompliant());
}

double ContrastCalculator::calculateRatio() const
{
    double l1 = calculateLuminance(_model->getForeground());
    double l2 = calculateLuminance(_model->getBackground());

    if (l1 >= l2) {
        return (l1 + 0.05) / (l2 + 0.05);
    } else {
        return (l2 + 0.05) / (l1 + 0.05);
    }
}

double ContrastCalculator::calculateLuminance(const QColor &color) const
{
    // https://www.w3.org/TR/WCAG20/#relativeluminancedef
    // https://www.w3.org/WAI/GL/wiki/Relative_luminance
    std::vector<double> RGB;
    RGB.push_back(color.redF());
    RGB.push_back(color.greenF());
    RGB.push_back(color.blueF());

    std::vector<double> sRGB;
    for(const auto& c : RGB)
    {
        if(c <= 0.03928)
            sRGB.push_back(c/12.92);
        else
        {
            double val = (c + 0.055)/1.055;
            sRGB.push_back(pow(val, 2.4));
        }
    }

    double luminance = 0;
    auto itSRGB = sRGB.cbegin();

    std::vector<double> lf;
    lf.push_back(LuminanceCoefficients::Red());
    lf.push_back(LuminanceCoefficients::Green());
    lf.push_back(LuminanceCoefficients::Blue());

    auto itFact = lf.cbegin();

    while(itSRGB != sRGB.cend())
    {
        luminance += *itFact * *itSRGB;
        ++itFact;
        ++itSRGB;
    }

    return luminance;
}


bool ContrastCalculator::isCompliant() const
{
    return _model->getRatio() > WCAG2::getFactorForGuideline(_model->getGuidelineLevel());
}



