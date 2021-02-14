#include "colorcontrast.h"
#include "ui_colorcontrast.h"

#include "colorcontrastmodel.h"

ColorContrast::ColorContrast(QWidget *parent)
    : QMainWindow(parent)
    , _ui(std::make_unique<Ui::ColorContrast>())
    , _colors(nullptr)
{
    _ui->setupUi(this);

    initialize();
}

ColorContrast::~ColorContrast() = default;

void ColorContrast::initialize()
{
    initializeModel();
    _ui->centralwidget->initialize(_colors);
}

void ColorContrast::initializeModel()
{
    _colors = std::make_shared<ColorContrastModel>();
    _colors->addColor(ColorContrastModel::Entry(QColor(0, 0, 0, 255), "black"));
    _colors->addColor(ColorContrastModel::Entry(QColor(255, 0, 0, 255), "red"));
    _colors->addColor(ColorContrastModel::Entry(QColor(0, 255, 0, 255), "green"));
    _colors->addColor(ColorContrastModel::Entry(QColor(0, 0, 255, 255), "blue"));
    _colors->addColor(ColorContrastModel::Entry(QColor(255, 255, 255, 255), "white"));
}




