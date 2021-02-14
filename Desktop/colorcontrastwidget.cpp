#include "colorcontrastwidget.h"

#include "colorcontrastpresenter.h"
#include "colorcontrastmodel.h"
#include "colorcontrastview.h"

ColorContrastWidget::ColorContrastWidget(QWidget *parent)
    : QWidget(parent)
    , _presenter(nullptr)
{
}

ColorContrastWidget::~ColorContrastWidget() = default;

void ColorContrastWidget::initialize(std::shared_ptr<ColorContrastModel> model)
{
    auto view = new ColorContrastView(this);
    _presenter = new ColorContrastPresenter(view, this);
    _presenter->setModel(model);
    _presenter->initialize();
}
