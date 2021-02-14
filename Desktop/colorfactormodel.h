#pragma once

#include <QColor>

class ColorFactorModel
{
public:
    ColorFactorModel();
    ~ColorFactorModel();

    const QColor& getForeground() const;
    void setForeground(const QColor &foreground);

    const QColor& getBackground() const;
    void setBackground(const QColor &background);

    double getFactor() const;
    void setFactor(double factor);

    bool getCompliant() const;
    void setCompliant(bool value);

private:
    QColor _foreground;
    QColor _background;
    double _factor{0.0};
    bool compliant{false};
};
