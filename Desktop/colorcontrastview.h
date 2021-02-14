#pragma once

#include "colorcontrastviewbase.h"

#include <QPointer>
#include <memory>

class QGridLayout;
class QLayout;
class ColorFactorModel;

namespace Ui { class ColorContrastView; }

class ColorContrastView : public ColorContrastViewBase
{
    Q_OBJECT
public:
    ColorContrastView(QObject *parent = nullptr);
    virtual ~ColorContrastView();

    virtual void clearVisualization() override;

    virtual void addComplianceOption(const QString &text) override;
    virtual void setComplianceOptionIndex(int index) override;
    virtual int getComplianceOptionIndex() const override;

    virtual void addForegroundColorNameAndCode(int column, const QString& colorNameAndCode) override;
    virtual void addBackgroundColorNameAndCode(int row, const QString& colorNameAndCode) override;
    virtual void addVisualization(int row, int column, std::shared_ptr<ColorFactorModel> data) override;

private:
     void clearWidgets(QLayout * layout);

private:
    std::unique_ptr<Ui::ColorContrastView> _ui;
    QPointer<QGridLayout> _mainLayout;
};

