#ifndef MP_TESTS_H
#define MP_TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <list>

#include "../app/text/_text.h"
#include "../app/text/text.h"
#include "../app/common.h"

TEST(mpTest, normal)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    m(txt, 1, 2);

    int res = mp(txt, 4);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(txt->cursor->position, 4);

    free(txt);
}

TEST(mpTest, toBig)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    m(txt, 1, 2);

    std::string line = *(txt->cursor->line);

    int res = mp(txt, 1000);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(txt->cursor->position, line.length());

    free(txt);
}


#endif // MP_TESTS_H
