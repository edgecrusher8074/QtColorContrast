#pragma once

#include <QtTest>

#include <memory>
#include <QPointer>
#include <QSignalSpy>

#include <colorcontrastpresenter.h>
#include <colorcontrastmodel.h>
#include <colorcontrastviewmock.h>

class TST_ColorContrastPresenter : public QObject
{
    Q_OBJECT

private slots:
    void init()
    {
        _view = new ColorContrastViewMock(nullptr);
        _presenter = new ColorContrastPresenter(_view, nullptr);
        _model = std::make_shared<ColorContrastModel>();
        _model->addColor(ColorContrastModel::Entry(Qt::black, "black"));
        _model->addColor(ColorContrastModel::Entry(Qt::white, "whtie"));
    }

    void intializationFail()
    {
        QVERIFY_EXCEPTION_THROWN(_presenter->initialize(), std::invalid_argument);
    }

    void intialization()
    {
        _presenter->setModel(_model);
        _presenter->initialize();

        int elementCount = static_cast<int>(_presenter->getModel()->getData().size());

        QCOMPARE(elementCount, _view->getBackgroundRow());
        QCOMPARE(elementCount, _view->getForegroundColumn());
        QCOMPARE(elementCount, _view->getVisualizationRow());
        QCOMPARE(elementCount, _view->getVisualizationColumn());
    }

    void signalSpying()
    {
        QSignalSpy spy(_view, SIGNAL(complianceOptionChanged()));

         QCOMPARE(spy.count(), 0);

        _presenter->setModel(_model);
        _presenter->initialize();

       QCOMPARE(spy.count(), 1);

        _view->setComplianceOptionIndex(1);
        QCOMPARE(spy.count(), 2);

        _view->setComplianceOptionIndex(5);
        QCOMPARE(spy.count(), 2);
    }

    void cleanup()
    {
        delete _presenter;
        delete _view;
    }

private:
    QPointer<ColorContrastPresenter> _presenter{nullptr};
    QPointer<ColorContrastViewMock> _view{nullptr};
    std::shared_ptr<ColorContrastModel> _model{nullptr};
};
