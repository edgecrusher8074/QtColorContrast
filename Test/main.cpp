#include <QTest>

#include <tst_contrastcalculator.h>
#include "tst_colorfactorpresenter.h"
#include "tst_colorcontrastpresenter.h"


int main(int argc, char *argv[])
{
    int status = 0;

    status += QTest::qExec(new TST_ContrastCalculator, argc, argv);
    status += QTest::qExec(new TST_ColorContrastPresenter, argc, argv);
    status += QTest::qExec(new TST_ColorFactorPresenter, argc, argv);

    return status;
}
