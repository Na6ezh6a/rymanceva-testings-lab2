#include "_text.h"

int j(text txt)
{

    std::list<std::string>::iterator cursor_line = txt->cursor->line;
    std::list<std::string>::iterator cursor_next = txt->cursor->line;
    cursor_next++;

    /* Проверка на последнюю строку */
    if (cursor_next == txt->lines->end()) {
        printf
            ("Невозможно. Текущая строка последняя\n");
        return -1;
    }

    // /* Присоединяем следующую строку */
    // strcat(cursor_line->contents, cursor_next->contents);

    if (cursor_next != txt->lines->end()) {
        /*Запоминаем указатель на следующую строку для последующего очищения */
        *cursor_line += *cursor_next;

        txt->lines->erase(cursor_next);

    }

    return 0;
}
