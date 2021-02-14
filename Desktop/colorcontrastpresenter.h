#pragma once

#include <QObject>

#include <QPointer>
#include <memory>

class ColorContrastViewBase;
class ColorContrastModel;

class ColorContrastPresenter :public QObject
{
    Q_OBJECT
public:
    ColorContrastPresenter(ColorContrastViewBase *view, QObject* parent=nullptr);
    virtual ~ColorContrastPresenter();

    void initialize();

    void setModel(std::shared_ptr<ColorContrastModel> model);
    std::shared_ptr<ColorContrastModel> getModel() const;

    static QString getColorString(const QString& colorName, const QColor& color);

protected slots:
    void updateView();

private:
    QPointer<ColorContrastViewBase> _view;
    std::shared_ptr<ColorContrastModel> _model;
};

