#pragma once

#include <colorfactorviewbase.h>
#include <QColor>
#include <QString>

class ColorFactorViewMock : public ColorFactorViewBase
{
    Q_OBJECT
public:
    ColorFactorViewMock(QObject* parent = nullptr)
        :ColorFactorViewBase(parent)
    {}

    virtual ~ColorFactorViewMock() = default;

    virtual void setFactorText(const QString &factorText) override
    {
        _factorText = factorText;
    }

    const QString& getFactorText() const
    {
        return _factorText;
    }

    virtual void setTextColors(const QColor &foreground, const QColor &background) override
    {
        _foreground = foreground;
        _background = background;
    }

    const QColor& getForeground() const
    {
        return _foreground;
    }

    const QColor& getBackground() const
    {
        return _background;
    }

    virtual void setCompliant(bool compliant) override
    {
        _compliant = compliant;
    }

    bool getCompliant() const
    {
        return _compliant;
    }

private:
    QString _factorText;
    QColor _foreground;
    QColor _background;
    bool _compliant;
};
