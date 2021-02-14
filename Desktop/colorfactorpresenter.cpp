#include "colorfactorpresenter.h"

#include "colorfactormodel.h"
#include "colorfactorviewbase.h"

ColorFactorPresenter::ColorFactorPresenter(ColorFactorViewBase* view, QObject *parent)
    :QObject(parent)
    , _model(nullptr)
    , _view(view)
{
}

ColorFactorPresenter::~ColorFactorPresenter() = default;

void ColorFactorPresenter::initialize(std::shared_ptr<ColorFactorModel> model)
{
    if(_view == nullptr)
        throw std::invalid_argument("view not initialized");

    if(model == nullptr)
        throw std::invalid_argument("model not initialized");

    setModel(model);
    updateView();
}

std::shared_ptr<ColorFactorModel> ColorFactorPresenter::model() const
{
    return _model;
}

void ColorFactorPresenter::setModel(const std::shared_ptr<ColorFactorModel> &model)
{
    _model = model;
}

ColorFactorViewBase* ColorFactorPresenter::view() const
{
    return _view;
}

void ColorFactorPresenter::setView(ColorFactorViewBase* view)
{
    _view = view;
}

QString ColorFactorPresenter::getFactorAsString() const
{
    return QString("%1 : 1").arg(QString::number(_model->getFactor(),'g', 3));
}

void ColorFactorPresenter::updateView()
{
    _view->setTextColors(_model->getForeground(), _model->getBackground());
    _view->setFactorText(getFactorAsString());
    _view->setCompliant(_model->getCompliant());
}


