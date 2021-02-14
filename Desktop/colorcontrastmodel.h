#pragma once

#include <QColor>
#include <QString>

#include <vector>

class ColorContrastModel
{
public:
    struct Entry {
        Entry(const QColor& col, const QString& nm);

        QColor color;
        QString name;
    };

    ColorContrastModel();
    virtual ~ColorContrastModel();

    void addColor(const Entry& entry);
    void removeColor(const Entry& entry);

    void setData(const std::vector<ColorContrastModel::Entry>& data);
    const std::vector<ColorContrastModel::Entry>& getData() const;


private:
    std::vector<ColorContrastModel::Entry> _data;
};
