#include <gtest/gtest.h>
#include "save_test.h"
#include "show_test.h"
#include "showodd_test.h"
#include "m_test.h"
#include "extra_tests.h"
#include "j_test.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
