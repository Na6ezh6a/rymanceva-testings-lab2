#ifndef SHOWODD_TEST_H
#define SHOWODD_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <list>

#include "../app/text/_text.h"
#include "../app/text/text.h"
#include "../app/common.h"

TEST(showoddTest, normal)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");
    append_line(txt, "test line 4");
    append_line(txt, "test line 5");

    testing::internal::CaptureStdout(); // перехват stdout
    showodd(txt);
    std::string text = testing::internal::GetCapturedStdout();

    // (индекс строк с нуля)
    EXPECT_STREQ(text.c_str(), "test line 2\ntest line 4\n");
    free(txt);
}

TEST(showoddTest, empty)
{
    text txt = create_text();

    testing::internal::CaptureStdout(); // перехват stdout
    showodd(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_EQ(text.length(), 0);
    EXPECT_STREQ(text.c_str(), "");
    free(txt);
}

#endif // SHOWODD_TEST_H
