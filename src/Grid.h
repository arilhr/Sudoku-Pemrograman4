#pragma once
#include <iostream>
using namespace std;

class Grid {
    private:
        char num;
        bool isLocked;
        bool isWrong;
    public:
        Grid();
        void SetNum(char num);
        char GetNum();
        bool GetLockCond();
        void SetLockCond(bool isLocked);
        bool GetWrongCond();
        void SetWrongCond(bool isWrong);
};