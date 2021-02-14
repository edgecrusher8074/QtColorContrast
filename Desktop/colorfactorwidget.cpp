#include "colorfactorwidget.h"

#include "colorfactorpresenter.h"
#include "colorfactormodel.h"
#include "colorfactorview.h"

ColorFactorWidget::ColorFactorWidget(QWidget* parent)
    :QFrame(parent)
    ,_presenter(nullptr)
{
}

ColorFactorWidget::~ColorFactorWidget() = default;

void ColorFactorWidget::initialize(std::shared_ptr<ColorFactorModel> model)
{
    auto view = new ColorFactorView(this);
    _presenter = new ColorFactorPresenter(view, this);
    _presenter->initialize(model);
}

