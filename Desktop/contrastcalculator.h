#pragma once

#include <memory>

class ContrastCalculatorModel;
class QColor;

class ContrastCalculator
{

public:

    ContrastCalculator(std::shared_ptr<ContrastCalculatorModel> model);
    ~ContrastCalculator();

    void doCalculate();

protected:
    double calculateRatio() const;
    double calculateLuminance(const QColor& color) const;
    bool isCompliant() const;

private:
    std::shared_ptr<ContrastCalculatorModel> _model;
};
