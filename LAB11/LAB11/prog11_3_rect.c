#include <stdio.h>
#include "Rect.h";

int main(void)
{
    RECT rect1 = { 10, 20, 30, 40 };
    PrintRect(&rect1);

    return 0;
}
