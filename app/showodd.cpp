#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, std::string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов
 */
void showodd(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов
 */
static void show_line(int index, std::string contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);
    UNUSED(data);

    /* Работаем только с чётными строками */
    if (index % 2 == 1) {
        /* Выводим строку на экран */
        printf("%s\n", contents.c_str());
    }
}