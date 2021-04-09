#ifndef SAVE_TEST_H
#define SAVE_TEST_H

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

const std::string test_file_name_1 = "test_file1.txt";
const std::string test_file_name_2 = "test_file2.txt";

void removeFiles() {
    QDir dir(".");
    dir.remove(QString::fromStdString(test_file_name_1));
    dir.remove(QString::fromStdString(test_file_name_2));
}

TEST(saveTest, normal)
{
    text txt = create_text();
    append_line(txt, "test line 1");
    append_line(txt, "test line 2");
    append_line(txt, "test line 3");

    save(txt, (char*) test_file_name_1.c_str());

    text txt2 = create_text();
    load(txt2, (char*) test_file_name_1.c_str());

    ASSERT_EQ(txt->length, txt2->length);

    auto it1 = txt->lines->begin();
    auto it2 = txt2->lines->begin();

    while( it1 != txt->lines->end() && it2 != txt2->lines->end() )
    {
        EXPECT_STREQ((*it1).c_str(), (*it2).c_str());
        it1++;
        it2++;
    }

    free(txt);
    removeFiles();
}

TEST(saveTest, empty)
{
    text txt = create_text();

    save(txt, (char*) test_file_name_1.c_str());

    text txt2 = create_text();
    load(txt2, (char*) test_file_name_1.c_str());

    EXPECT_EQ(txt->length, 0);
    EXPECT_EQ(txt2->length, 0);

    free(txt);
    removeFiles();
}


#endif // SAVE_TEST_H
