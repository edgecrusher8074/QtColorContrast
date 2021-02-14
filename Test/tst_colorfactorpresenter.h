#pragma once

#include <QtTest>

#include <memory>
#include <QPointer>

#include <colorfactorpresenter.h>
#include <colorfactormodel.h>
#include <colorfactorviewmock.h>

class ColorFactorPresenterMock : public ColorFactorPresenter
{
    Q_OBJECT
public:
    using ColorFactorPresenter::ColorFactorPresenter;
    ~ColorFactorPresenterMock() = default;

    virtual QString getFactorAsString() const override
    {
        return ColorFactorPresenter::getFactorAsString();
    }
};

class TST_ColorFactorPresenter : public QObject
{
    Q_OBJECT

private slots:
    void init()
    {
        _view = new ColorFactorViewMock(nullptr);
        _presenter = new ColorFactorPresenterMock(_view, nullptr);
        _model = std::make_shared<ColorFactorModel>();
        _model->setFactor(0.815);
        _model->setCompliant(true);
        _model->setForeground(Qt::black);
        _model->setBackground(Qt::white);
    }

    void intializationFail()
    {
         QVERIFY_EXCEPTION_THROWN(_presenter->initialize(nullptr), std::invalid_argument);
    }

    void intialization()
    {
         _presenter->initialize(_model);
         QCOMPARE(_view->getFactorText(), _presenter->getFactorAsString());
         QCOMPARE(_view->getForeground(), _model->getForeground());
         QCOMPARE(_view->getBackground(), _model->getBackground());
         QCOMPARE(_view->getCompliant(), _model->getCompliant());
    }

    void cleanup()
    {
        delete _presenter;
        delete _view;
    }

private:
    QPointer<ColorFactorPresenterMock> _presenter{nullptr};
    QPointer<ColorFactorViewMock> _view{nullptr};
    std::shared_ptr<ColorFactorModel> _model{nullptr};
};
