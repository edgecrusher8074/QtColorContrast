#pragma once

#include <QFrame>

#include <QPointer>
#include <memory>

class ColorFactorPresenter;
class ColorFactorModel;

class ColorFactorWidget : public QFrame
{
    Q_OBJECT
public:
    ColorFactorWidget(QWidget* parent = nullptr);
    virtual ~ColorFactorWidget();

    void initialize(std::shared_ptr<ColorFactorModel> model);

private:
    QPointer<ColorFactorPresenter> _presenter;
    std::shared_ptr<ColorFactorModel> _model;
};

