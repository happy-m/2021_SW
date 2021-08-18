#include <stdio.h>
#include "Rect.h"

void PrintRect(const RECT* rt)
{
    printf("[ 좌상단점=(%d,%d),우하단점=(%d,%d),폭=%d,높이=%d ]\n",
        rt->left, rt->top, rt->right, rt->bottom, Width(rt), Height(rt));
}

int Width(const RECT* rt)
{
    int width = rt->right - rt->left;
    return width > 0 ? width : -width;
}

int Height(const RECT* rt)
{
    int height = rt->bottom - rt->top;
    return height > 0 ? height : -height;
}