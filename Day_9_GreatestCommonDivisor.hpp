#pragma once

int32_t GetGreatestCommonDivisor ( int32_t divisor, int32_t remainder)
{
    if(remainder == 0)
    {
        return divisor;
    }

    int32_t x = abs(divisor / remainder);
    int32_t y = divisor - (remainder * x);
    GetGreatestCommonDivisor(remainder, y);
}
