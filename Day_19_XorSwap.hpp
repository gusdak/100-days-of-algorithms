#pragma once

void xorSwap (int* x, int* y)
{
    if (x != y)
    {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}