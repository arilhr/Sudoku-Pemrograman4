#include "Grid.h"

Grid::Grid() {
    isWrong = false;
    isLocked = false;
    num = ' ';
}

void Grid::SetNum(char num) {
    if (isLocked) {
        cout << "\nThis grid can't be changed.\n" << endl;
        return;
    }

    this->num = num;
}

char Grid::GetNum() {
    return num;
}

void Grid::SetLockCond(bool isLocked) {
    this->isLocked = isLocked;
}

bool Grid::GetLockCond() {
    return isLocked;
}

void Grid::SetWrongCond(bool isWrong) {
    this->isWrong = isWrong;
}

bool Grid::GetWrongCond() {
    return isWrong;
}