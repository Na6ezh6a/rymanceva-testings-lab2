#ifndef SHOW_TEST_H
#define SHOW_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <list>

#include "../app/text/_text.h"
#include "../app/text/text.h"
#include "../app/common.h"

TEST(showTest, normal)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    testing::internal::CaptureStdout(); // перехват stdout
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), "test line 1\ntest line 2\ntest line 3\n");
    free(txt);
}

TEST(showTest, empty)
{
    text txt = create_text();

    testing::internal::CaptureStdout(); // перехват stdout
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_EQ(text.length(), 0);
    EXPECT_STREQ(text.c_str(), "");
    free(txt);
}

#endif // SHOW_TEST_H
