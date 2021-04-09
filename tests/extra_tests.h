#ifndef EXTRA_TESTS_H
#define EXTRA_TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <list>
#include <QDir>
#include <QFileInfo>
#include <QString>

#include "../app/text/_text.h"
#include "../app/text/text.h"
#include "../app/common.h"

const std::string invalid_file = "random_name_w32f32gf";

TEST(extraTest, invalidFile)
{
    text txt = create_text();

    load(txt, (char*) invalid_file.c_str());

    EXPECT_EQ(txt->length, 0);

    free(txt);
}

TEST(extraTest, nullTxt)
{
    text txt = NULL;
    remove_all(txt); // проверяем не будет ли ошибки (не упадёт ли приложение)
}

TEST(extraTest, clear) {
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    EXPECT_EQ(txt->lines->size(), 3);

    remove_all(txt);

    EXPECT_EQ(txt->lines->size(), 0);
}

#endif // EXTRA_TESTS_H
