#pragma once

#include <QObject>

class QColor;
class QString;

class ColorFactorViewBase : public QObject
{
    Q_OBJECT
public:
    explicit ColorFactorViewBase(QObject *parent = nullptr);

    virtual ~ColorFactorViewBase();

    virtual void setFactorText(const QString& factorText) = 0;

    virtual void setTextColors(const QColor& foreground, const QColor& background) = 0;

    virtual void setCompliant(bool compliant) = 0;

};

