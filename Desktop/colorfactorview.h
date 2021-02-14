#pragma once

#include "colorfactorviewbase.h"

#include <memory>
#include <QPointer>

class QFrame;
class QString;
class QColor;

namespace Ui { class ColorFactorView; }

class ColorFactorView : public ColorFactorViewBase
{
    Q_OBJECT
public:
    ColorFactorView(QObject* parent = nullptr);
    virtual ~ColorFactorView();

    virtual void setFactorText(const QString &factorText) override;
    virtual void setTextColors(const QColor &foreground, const QColor &background) override;
    virtual void setCompliant(bool compliant) override;

protected:
    static QString getStyleSheetNoBorder();

private:
    std::unique_ptr<Ui::ColorFactorView> _ui;
    QPointer<QFrame> _thisFrame;
};

