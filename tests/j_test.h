#ifndef J_TEST_H
#define J_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <list>

#include "../app/text/_text.h"
#include "../app/text/text.h"
#include "../app/common.h"

TEST(jTest, normal)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    m(txt, 1, 2);

    int res = j(txt);
    ASSERT_EQ(res, 0);

    testing::internal::CaptureStdout(); // перехват stdout
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), "test line 1\nte|st line 2test line 3\n");

    free(txt);
}

TEST(jTest, lastLine)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    m(txt, 2, 2);

    int res = j(txt);
    ASSERT_EQ(res, -1);

    free(txt);
}

#endif // J_TEST_H
