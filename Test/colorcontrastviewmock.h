#pragma once

#include <colorcontrastviewbase.h>
#include <colorfactormodel.h>

#include <list>
#include <algorithm>

class ColorContrastViewMock : public ColorContrastViewBase
{
    Q_OBJECT
public:
    ColorContrastViewMock(QObject* parent = nullptr)
        :ColorContrastViewBase(parent)
    {}

    virtual ~ColorContrastViewMock() = default;

    inline virtual void addComplianceOption(const QString &text) override
    {
        _complianceText << text;
    }

    int getComplianceOptionCount() const
    {
        return _complianceText.size();
    }

    inline virtual void setComplianceOptionIndex(int index) override
    {
        if(index < getComplianceOptionCount())
        {
            _complianceIndex = index;
            emit complianceOptionChanged();
        }
    }
    inline virtual int getComplianceOptionIndex() const override
    {
        return _complianceIndex;
    }
    inline virtual void clearVisualization() override
    {
        _foregroundColumn = 0;
        _foregroundNames.clear();
        _backgroundRow = 0;
        _backgroundNames.clear();

        _visualizationRow = 0;
        _visualizationColumn = 0;
        _listData.clear();
    }
    inline virtual void addForegroundColorNameAndCode(int column, const QString &colorNameAndCode) override
    {
        _foregroundColumn = std::max(_foregroundColumn, column);
        _foregroundNames << colorNameAndCode;
        _foregroundNames.removeDuplicates();
    }
    inline virtual void addBackgroundColorNameAndCode(int row, const QString &colorNameAndCode) override
    {
        _backgroundRow = std::max(_backgroundRow, row);
        _backgroundNames << colorNameAndCode;
        _backgroundNames.removeDuplicates();
    }
    inline virtual void addVisualization(int row, int column, std::shared_ptr<ColorFactorModel> data) override
    {
        _visualizationRow = std::max(_visualizationRow, row);
       _visualizationColumn = std::max(_visualizationColumn, column);
       _listData.push_back(data);
    }

    inline int getForegroundColumn() const { return _foregroundColumn; }
    inline int getBackgroundRow() const  { return _backgroundRow; }
    inline int getVisualizationRow() const { return _visualizationRow; }
    inline int getVisualizationColumn() const { return _visualizationColumn; }
    inline int getDataSize() const { return static_cast<int>(_listData.size()); }

private:
    int _complianceIndex {0};
    QStringList _complianceText;

    int _foregroundColumn {0};
    QStringList _foregroundNames;
    int _backgroundRow {0};
    QStringList _backgroundNames;
    int _visualizationRow {0};
    int _visualizationColumn {0};

    std::list<std::shared_ptr<ColorFactorModel>> _listData;

};

