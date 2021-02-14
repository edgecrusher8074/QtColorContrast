#include "colorfactormodel.h"

ColorFactorModel::ColorFactorModel()
{
}

ColorFactorModel::~ColorFactorModel() = default;

void ColorFactorModel::setForeground(const QColor &foreground)
{
    _foreground = foreground;
}

const QColor& ColorFactorModel::getForeground() const
{
    return _foreground;
}

void ColorFactorModel::setBackground(const QColor &background)
{
    _background = background;
}

const QColor& ColorFactorModel::getBackground() const
{
    return _background;
}

void ColorFactorModel::setCompliant(bool value)
{
    compliant = value;
}

bool ColorFactorModel::getCompliant() const
{
    return compliant;
}

void ColorFactorModel::setFactor(double factor)
{
    _factor = factor;
}

double ColorFactorModel::getFactor() const
{
    return _factor;
}
