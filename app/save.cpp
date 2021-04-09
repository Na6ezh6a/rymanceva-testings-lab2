#include <stdio.h>
#include "common.h"
#include "text/text.h"
#include <assert.h>

void save_line(int index, std::string line, int cursor, void *f);

/**
 * Загружает содержимое указанного файла
 */
void save(text txt, char *filename)
{
    FILE *f;

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    process_forward(txt, save_line, (void *) f);

    fclose(f);
}

void save_line(int index, std::string line, int cursor, void *f)
{
    /*Неиспользуемые переменные */
    UNUSED(index);
    UNUSED(cursor);

    /*Вывод строки в файл */
    fprintf((FILE *) f, "%s\n", line.c_str());
}
