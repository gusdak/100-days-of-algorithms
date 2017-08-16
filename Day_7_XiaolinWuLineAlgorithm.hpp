#pragma once

#define fpart_(X) ((double)(X)-floor(X))
#define rfpart_(X) (1.0-fpart_(X))

inline void putPoint (uint16_t canvas[], uint32_t width, int x, int y, float brightness)
{
    canvas[x + y * width] = brightness * 255;
}

void drawAntialiasedLine(uint16_t canvas[], uint32_t width, int x0, int y0, int x1, int y1)
{
    bool steep = abs(y1 - y0) > abs (x1 - x0);
    
    if(steep)
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    if(x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    double dx = x1 - x0;
    double dy = y1 - y0;

    double gradient = dx != 0.0 ? dy / dx : 1.0;

    double xEnd = ceil(x0);
    double yEnd = y0 + gradient * (xEnd - x0);
    double xGap = rfpart_(x0);
    double xpxl1 = xEnd;
    double ypxl1 = floor(yEnd);

    if(steep)
    {
        putPoint(canvas, width, ypxl1   , xpxl1, rfpart_(yEnd) * xGap);
        putPoint(canvas, width, ypxl1 +1, xpxl1, fpart_(yEnd)  * xGap);
    }
    else
    {
        putPoint(canvas, width, xpxl1, ypxl1,     rfpart_(yEnd) * xGap);
        putPoint(canvas, width, xpxl1, ypxl1 + 1, fpart_(yEnd)  * xGap);
    }
    double intery = yEnd + gradient;

    xEnd = ceil(x1);
    yEnd = y1 + gradient * (xEnd - x1);
    xGap = fpart_(x1 + 0.5);
    double xpxl2 = xEnd;
    double ypxl2 = floor(yEnd);
    if(steep)
    {
        putPoint(canvas, width, ypxl2    , xpxl2, rfpart_(yEnd) * xGap);
        putPoint(canvas, width, ypxl2 + 1, xpxl2, fpart_(yEnd)  * xGap);
    }
    else
    {
        putPoint(canvas, width, ypxl2, xpxl2,     rfpart_(yEnd) * xGap);
        putPoint(canvas, width, ypxl2, xpxl2 + 1, fpart_(yEnd)  * xGap);
    }

    if(steep)
    {
        for(int x = xpxl1 + 1; x <= xpxl2 - 1; x++)
        {
            putPoint(canvas, width, floor(intery), x, rfpart_(intery));
            putPoint(canvas, width, floor(intery) + 1, x, fpart_(intery));
            intery += gradient;
        }
    }
    else
    {
        for(int x = xpxl1 + 1; x < xpxl2 -1; x++)
        {
            putPoint(canvas, width, x, floor(intery), rfpart_(intery));
            putPoint(canvas, width, x, floor(intery) + 1,  fpart_(intery));
            intery += gradient;
        }
    }
}

#undef fpart_
#undef rfpart_