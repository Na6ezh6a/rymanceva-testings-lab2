#ifndef M_TEST_H
#define M_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <list>

#include "../app/text/_text.h"
#include "../app/text/text.h"
#include "../app/common.h"

TEST(mTest, normal)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    m(txt, 1, 2);
    auto it = txt->lines->begin();
    it++;
    EXPECT_EQ(txt->cursor->position, 2);
    EXPECT_STREQ((*it).c_str(), "test line 2");

    free(txt);
}

TEST(mTest, showCursor)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    m(txt, 1, 2);
    auto it = txt->lines->begin();
    it++;
    EXPECT_EQ(txt->cursor->position, 2);
    EXPECT_STREQ((*it).c_str(), "test line 2");

    testing::internal::CaptureStdout(); // перехват stdout
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), "test line 1\nte|st line 2\ntest line 3\n");

    free(txt);
}

#endif // M_TEST_H
