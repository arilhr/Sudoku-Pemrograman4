/* 4210191014 AURIEL HARLIH */
#pragma once
#include "Grid.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <windows.h>
using namespace std;

class Board {
    private:
        Grid grid[9][9];
        char gridSolved[9][9];
        string dataLevel = "dataLevel.txt";
    public:
        void SetGrid(char number, int row, int column);
        Grid GetGrid(int row, int column);
        void DeleteGrid(int row, int column);
        void LoadLevelData();
        void DisplayBoard();
        bool CheckHorizontalGrid();
        bool CheckVerticalGrid();
        bool CheckBlockGrid();
        void CheckCorrectGrid(int num, int row, int column);
};