#include "tst_appcommandlineparser.h"
#include "tst_context.h"
#include "tst_model.h"
#include "tst_rpc.h"
#include "tst_statemachine.h"
#include "tst_theme.h"

#include <cstdlib>
#include <ctime>

#include <gtest/gtest.h>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    std::srand(std::time(nullptr));
    ::testing::InitGoogleTest(&argc, argv);
    QGuiApplication app(argc, argv);
    return RUN_ALL_TESTS();
}
