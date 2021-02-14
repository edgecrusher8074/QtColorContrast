#pragma once

#include <QObject>
#include <QColor>
#include <QString>
#include <memory>

class ColorFactorModel;

class ColorContrastViewBase : public QObject
{
    Q_OBJECT
public:
    explicit ColorContrastViewBase(QObject *parent = nullptr);

    virtual ~ColorContrastViewBase();

    virtual void addComplianceOption(const QString& text) = 0;
    virtual void setComplianceOptionIndex(int index) = 0;
    virtual int getComplianceOptionIndex() const = 0;

    virtual void clearVisualization() = 0;

    virtual void addForegroundColorNameAndCode(int column, const QString& colorNameAndCode) = 0;
    virtual void addBackgroundColorNameAndCode(int row, const QString& colorNameAndCode) = 0;

    virtual void addVisualization(int row, int column, std::shared_ptr<ColorFactorModel> data) = 0;

signals:
    void complianceOptionChanged();
};
