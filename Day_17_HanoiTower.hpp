#pragma once

void hanoiTower(int m,  std::string left = "left",
                        std::string right = "right",
                        std::string middle = "middle")
{
    if(m != 0)
    {
        hanoiTower(m - 1, left, middle, right);
        std::cout << "From " << left << " to " << right << std::endl;
        hanoiTower(m - 1, middle, right, left);
    }
}
