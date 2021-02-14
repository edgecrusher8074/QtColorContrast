#include "contrastcalculatormodel.h"

ContrastCalculatorModel::ContrastCalculatorModel()
{
}

ContrastCalculatorModel::~ContrastCalculatorModel() = default;

void ContrastCalculatorModel::setRatio(double ratio)
{
    _ratio = ratio;
}

bool ContrastCalculatorModel::getCompliant() const
{
    return _compliant;
}

void ContrastCalculatorModel::setCompliant(bool compliant)
{
    _compliant = compliant;
}

double ContrastCalculatorModel::getRatio() const
{
    return _ratio;
}

GuidelineLevel ContrastCalculatorModel::getGuidelineLevel() const
{
    return _guidelineLevel;
}

void ContrastCalculatorModel::setGuidelineLevel(const GuidelineLevel &guidelineLevel)
{
    _guidelineLevel = guidelineLevel;
}

void ContrastCalculatorModel::setForeground(const QColor &foreground)
{
    _foreground = foreground;
}

QColor ContrastCalculatorModel::getForeground() const
{
    return _foreground;
}

void ContrastCalculatorModel::setBackground(const QColor &background)
{
    _background = background;
}

QColor ContrastCalculatorModel::getBackground() const
{
    return _background;
}
