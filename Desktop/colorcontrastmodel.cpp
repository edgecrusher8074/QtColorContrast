#include "colorcontrastmodel.h"

ColorContrastModel::Entry::Entry(const QColor &col, const QString &nm)
    :color(col)
    ,name(nm)
{
}

ColorContrastModel::ColorContrastModel()
{
    _data.clear();
}

ColorContrastModel::~ColorContrastModel() = default;

void ColorContrastModel::addColor(const ColorContrastModel::Entry &entry)
{
    _data.push_back(entry);
}

void ColorContrastModel::removeColor(const ColorContrastModel::Entry &entry)
{
    auto it = std::find_if(_data.begin(), _data.end(), [&entry](const ColorContrastModel::Entry &elem)
    {
        return elem.color == entry.color;
    });

    if(it != _data.end())
        _data.erase(it);
}

void ColorContrastModel::setData(const std::vector<ColorContrastModel::Entry> &data)
{
    _data = data;
}

const std::vector<ColorContrastModel::Entry> &ColorContrastModel::getData() const
{
    return _data;
}
