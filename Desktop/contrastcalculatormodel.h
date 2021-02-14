#pragma once

#include <QColor>
#include "wcagdefinitions.h"

class ContrastCalculatorModel
{
public:
    ContrastCalculatorModel();
    ~ContrastCalculatorModel();

    double getRatio() const;
    void setRatio(double ratio);

    bool getCompliant() const;
    void setCompliant(bool compliant);

    GuidelineLevel getGuidelineLevel() const;
    void setGuidelineLevel(const GuidelineLevel &guidelineLevel);

    void setForeground(const QColor &foreground);
    QColor getForeground() const;

    void setBackground(const QColor &background);
    QColor getBackground() const;

private:
    QColor _foreground;
    QColor _background;

    GuidelineLevel _guidelineLevel {GuidelineLevel::AA};

    double _ratio {0.0};
    bool _compliant {false};
};

