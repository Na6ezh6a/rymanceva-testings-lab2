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

#endif // EXTRA_TESTS_H
