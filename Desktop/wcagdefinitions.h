#pragma once

#include <QString>
#include <QCoreApplication>

enum class GuidelineLevel {
    AA = 0,
    AA_18pt_plus,
    AAA,
    AAA_18pt_plus
};

class WCAG2 {

    Q_DECLARE_TR_FUNCTIONS(WCAG2)
public:

    inline static QString getTextForGuideline(const GuidelineLevel &guidelineLevel)
    {
        switch (guidelineLevel) {
            case GuidelineLevel::AA:
                return tr("WCAG 2 AA");
            case GuidelineLevel::AA_18pt_plus:
                return tr("WCAG 2 AA 18pt+");
            case GuidelineLevel::AAA:
                return tr("WCAG 2 AAA");
            case GuidelineLevel::AAA_18pt_plus:
                return tr("WCAG 2 AAA 18pt+");
            default:
                throw std::invalid_argument("guidelinelevel unknown");
        }
    }

    inline static double getFactorForGuideline(const GuidelineLevel &guidelineLevel)
    {
        switch (guidelineLevel) {
            case GuidelineLevel::AA:
                return 4.5;
            case GuidelineLevel::AA_18pt_plus:
                return 3.0;
            case GuidelineLevel::AAA:
                return 7.0;
            case GuidelineLevel::AAA_18pt_plus:
                return 4.5;
            default:
                throw std::invalid_argument("guidelinelevel unknown");
        }
    }
};

