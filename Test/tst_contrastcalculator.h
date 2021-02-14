#pragma once

#include <QtTest>
#include "contrastcalculator.h"
#include "contrastcalculatormodel.h"

class ContrastCalculatorMock : public ContrastCalculator
{

public:
    using ContrastCalculator::ContrastCalculator;

    double testCalculateLuminace(const QColor& color) const
    {
        return calculateLuminance(color);
    }

    bool testCompliance() const
    {
        return isCompliant();
    }
};

class TST_ContrastCalculator : public QObject
{
    Q_OBJECT

private slots:
    void init()
    {
        _model = std::make_shared<ContrastCalculatorModel>();
    }

    void calculateLuminance()
    {
        ContrastCalculatorMock cc(_model);

        double lumRed = cc.testCalculateLuminace(Qt::red);
        double lumGreen = cc.testCalculateLuminace(Qt::green);
        double lumBlue = cc.testCalculateLuminace(Qt::blue);

        QCOMPARE(lumRed, 0.2126);
        QCOMPARE(lumGreen, 0.7152);
        QCOMPARE(lumBlue, 0.0722);
    }

    void calculateRatio()
    {
        _model->setForeground(Qt::white);
        _model->setBackground(Qt::black);
        calculate();

        QCOMPARE(_model->getRatio(), 21.0);
    }

    void calculateCompliance()
    {
        ContrastCalculatorMock cc(_model);

        _model->setGuidelineLevel(GuidelineLevel::AA);
        _model->setRatio(4.51);
        QVERIFY(cc.testCompliance());
        _model->setRatio(4.49);
        QVERIFY(!cc.testCompliance());

        _model->setGuidelineLevel(GuidelineLevel::AA_18pt_plus);
        _model->setRatio(3.01);
        QVERIFY(cc.testCompliance());
        _model->setRatio(2.99);
        QVERIFY(!cc.testCompliance());

        _model->setGuidelineLevel(GuidelineLevel::AAA);
        _model->setRatio(7.01);
        QVERIFY(cc.testCompliance());
        _model->setRatio(6.99);
        QVERIFY(!cc.testCompliance());

        _model->setGuidelineLevel(GuidelineLevel::AAA_18pt_plus);
        _model->setRatio(4.51);
        QVERIFY(cc.testCompliance());
        _model->setRatio(4.49);
        QVERIFY(!cc.testCompliance());

    }

    void cleanup()
    {
    }

private:
    void calculate()
    {
        ContrastCalculatorMock cc(_model);
        cc.doCalculate();
    }

private:
    std::shared_ptr<ContrastCalculatorModel> _model;
};
