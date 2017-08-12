

void drawLine(bool canvas[], size_t sizeX, size_t sizeY, int x1, int y1, int x2, int y2)
{
    int lengthX = abs(x2 - x1);
    int lengthY = abs(y2 - y1);

    int length = std::max(lengthX, lengthY);

    if (length == 0)
    {
        canvas[x1 + sizeX * y1] = 1;
    }

    if (lengthY <= lengthX)
    {
        int x = x1;
        float y = y1;

        length++;
        while(length--)
        {
            canvas[x + sizeX * (int)y] = 1;
            x++;
            y += float(lengthY) / lengthX;
        }
    }
    else
    {
        float x = x1;
        int y = y1;

        length++;
        while(length--)
        {
            canvas[(int)x + sizeX * y] = 1;
            x += float(lengthX) / lengthY;
            y++;
        }
    }
}