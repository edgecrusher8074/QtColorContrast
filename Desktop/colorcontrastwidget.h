#pragma once

#include <QWidget>

#include <memory>
#include <QPointer>

class ColorContrastPresenter;
class ColorContrastModel;

class ColorContrastWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColorContrastWidget(QWidget *parent = nullptr);
    ~ColorContrastWidget();

    void initialize(std::shared_ptr<ColorContrastModel> model);

private:
    QPointer<ColorContrastPresenter> _presenter;
};

