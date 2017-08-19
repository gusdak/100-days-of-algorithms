#pragma once

double MonteCarloPi(int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        double x = (double)rand() / (RAND_MAX);
        double y = (double)rand() / (RAND_MAX);

        if (x * x + y * y <= 1.0)
        {
            c++;
        }
    }
    return 4.0 * c / n;
}
