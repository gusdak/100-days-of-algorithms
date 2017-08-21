#pragma once

class Maze
{
public:
    Maze(uint16_t width, uint16_t height);
    class Cell
    {
    public:
        Cell() : rightWall(false), bottomWall(false) {}
        Cell(uint8_t id, bool rWall, bool bWall) : id(id), rightWall(rWall), bottomWall(bWall) {}
        bool rightWall;
        bool bottomWall;
        uint8_t id;
    };
    Cell GetCell(uint16_t x, uint16_t y) const;
    void SetCell(const Cell& cell, uint16_t x, uint16_t y);
    void PrintMaze() const;

    uint16_t width;
    uint16_t height;
    std::vector<Cell> maze;
};
using MCell = Maze::Cell;


//  1 2 3 4 5
//  _________
//1|_ _|_____|
//2|_ _ _____|
//3|_ _ _____|
//4|_ _ _____|
//5|_ _ _____|
Maze::Maze(uint16_t width, uint16_t height) : width(width), height(height)
{
    maze.resize(width * height);
}

void Maze::SetCell(const Cell& cell, uint16_t x, uint16_t y)
{
    maze[x + y * width] = cell;
}

void Maze::PrintMaze() const
{

    std::cout << " ";
    for(uint16_t x = 1; x < width * 2; x++)
    {
        std::cout << "_";
    }
    std::cout << std::endl;
    for(uint16_t y = 0; y < height; y++)
    {
        std::cout << "|";

        for(uint16_t x = 0; x < width; x++)
        {
            auto& cell = maze[x + y * width];

            if(!cell.bottomWall && y < height - 1)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << "_";
            }

            if(!cell.rightWall && x < width - 1)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
}

void checkAndFixRow(Maze& maze,  uint16_t rowNum)
{
    uint16_t setLength = 0;
    uint16_t isIsolated = true;
    for(uint16_t i = 0; i < maze.width; i++)
    {
        auto cell = maze.maze[i + maze.width * rowNum];
        if(!cell.bottomWall)
        {
            isIsolated = false;
        }
        else
        {
            setLength++;
        }
        if(cell.rightWall && isIsolated)
        {
            maze.maze[rand() % setLength + i + rowNum * maze.width].bottomWall = false;
            isIsolated = true;
        }
    }
}

Maze GenerateMazeEller(uint16_t width, uint16_t height)
{
    Maze maze(width, height);
    uint8_t id = 0;
    for(uint16_t i = 0; i < width; i++)
    {
        maze.SetCell(MCell(id, rand() % 2, /*rand() % 2*/ true), i, 0);
        id++;
    }
    checkAndFixRow(maze, 0);

    return maze;
}