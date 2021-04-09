#include <string.h>
#include "text.h"
#include "_text.h"

int mp(text txt, int arg)
{
    std::list<std::string>::iterator cursor_line = txt->cursor->line;
    /*Если указанная позиция больше, чем длина строки */
    if ((*cursor_line).length() < (long unsigned int) arg)
        arg = (*cursor_line).length();

    /* Новая позиция курсора в строке */
    txt->cursor->position = arg;

    return 0;
}
