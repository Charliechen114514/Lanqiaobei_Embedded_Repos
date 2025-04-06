#ifndef UI_H
#define UI_H

typedef enum {
    Auto,
    Manual
}Mode;

typedef enum {
    Data,
    Para
}Page;

void display_as_page(Page page, Mode mode);

#endif
