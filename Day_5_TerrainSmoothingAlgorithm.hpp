#pragma once
void smoothTerrain(float HeightData[], uint16_t width, uint16_t height)
{
    float newHeightData[width * height];

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int adjacentSections = 0;
            float sectionsTotal = 0.0f;

            if ((x - 1) >= 0) // left
            {
                sectionsTotal += HeightData[(x - 1) + y * width];
                adjacentSections++;

                if ((y - 1) >= 0) // upper-left
                {
                    sectionsTotal += HeightData[(x - 1) + (y - 1) * width];
                    adjacentSections++;
                }

                if ((y + 1) < height) // bottom-left
                {
                    sectionsTotal += HeightData[(x - 1) + (y + 1) * width];
                    adjacentSections++;
                }
            }

            if ((x + 1) < width) // right
            {
                sectionsTotal += HeightData[(x + 1) + y * width];
                adjacentSections++;

                if ((y - 1) >= 0) // upper-right
                {
                    sectionsTotal += HeightData[(x + 1) + (y - 1) * width];
                    adjacentSections++;
                }

                if ((y + 1) < height) // down-right
                {
                    sectionsTotal += HeightData[(x + 1) + (y + 1) * width];
                    adjacentSections++;
                }
            }

            if ((y - 1) >= 0) // above
            {
                sectionsTotal += HeightData[x + (y - 1) * width];
                adjacentSections++;
            }

            if ((y + 1) < height) // below
            {
                sectionsTotal += HeightData[x + (y + 1) * width];
                adjacentSections++;
            }
            newHeightData[x + y * width] = (HeightData[x + y * width] + (sectionsTotal / adjacentSections)) * 0.5f;
        }
    }

    for (int i = 0; i < width * height; i++)
    {
        HeightData[i] = newHeightData[i];
    }
}
