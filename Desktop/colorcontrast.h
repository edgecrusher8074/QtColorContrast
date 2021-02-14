#pragma once

#include <QMainWindow>
#include <memory>

class ColorContrastModel;

namespace Ui { class ColorContrast; }

class ColorContrast : public QMainWindow
{
    Q_OBJECT

public:
    ColorContrast(QWidget *parent = nullptr);
    ~ColorContrast();

private:
    void initialize();
    void initializeModel();

private:
    std::unique_ptr<Ui::ColorContrast> _ui;
    std::shared_ptr<ColorContrastModel> _colors;
};
