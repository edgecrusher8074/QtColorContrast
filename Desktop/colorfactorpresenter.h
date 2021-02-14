#pragma once

#include <QObject>

#include <QPointer>
#include <memory>

class ColorFactorModel;
class ColorFactorViewBase;

class ColorFactorPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ColorFactorPresenter(ColorFactorViewBase* view, QObject *parent = nullptr);
    ~ColorFactorPresenter();

    void initialize(std::shared_ptr<ColorFactorModel> model);

    void setModel(const std::shared_ptr<ColorFactorModel> &model);
    std::shared_ptr<ColorFactorModel> model() const;

    void setView(ColorFactorViewBase* view);
    ColorFactorViewBase* view() const;    

protected:
    virtual QString getFactorAsString() const;
    void updateView();

private:
    std::shared_ptr<ColorFactorModel> _model;
    QPointer<ColorFactorViewBase> _view;
};
