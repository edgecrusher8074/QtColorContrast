#include "colorfactorview.h"
#include "ui_colorfactorview.h"

#include <QFrame>
#include <QColor>
#include <QString>

ColorFactorView::ColorFactorView(QObject *parent)
    : ColorFactorViewBase(parent)
    , _ui(std::make_unique<Ui::ColorFactorView>())
    , _thisFrame(nullptr)
{
    _thisFrame = qobject_cast<QFrame*>(parent);
    _ui->setupUi(_thisFrame);

     _ui->_labelFactor->setStyleSheet(getStyleSheetNoBorder());
     _ui->_labelColor->setStyleSheet(getStyleSheetNoBorder());
}

ColorFactorView::~ColorFactorView() = default;

void ColorFactorView::setFactorText(const QString &factorText)
{
    _ui->_labelFactor->setText(factorText);
}

void ColorFactorView::setTextColors(const QColor &foreground, const QColor &background)
{
    QString labelStyle = QString("color: %1; background-color: %2").arg(foreground.name(), background.name());
    labelStyle.append(QString("; %1").arg(getStyleSheetNoBorder()));
    _ui->_labelColor->setStyleSheet(labelStyle);
    _ui->_labelColor->setIndent(4);
}

void ColorFactorView::setCompliant(bool compliant)
{
    QString frameTextColor = QString("%1").arg(compliant ? "green" : "red");

     QString frameStyle = QString("QFrame { border: 2px solid %1; border-radius: 4px}").arg(frameTextColor);
     _thisFrame->setStyleSheet(frameStyle);

     _ui->_labelFactor->setStyleSheet(QString("color: %1; %2").arg(frameTextColor,getStyleSheetNoBorder()));

}

QString ColorFactorView::getStyleSheetNoBorder()
{
    return QString("border: 0px solid white; border-radius: 0px");
}
