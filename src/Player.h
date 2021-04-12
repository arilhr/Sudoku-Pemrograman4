#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Player {
    protected:
        string name;
        int score;
    public:
        Player();
        void SetName(string name);
        string GetName();
        void InputName();
        void SetScore(int score);
        int GetScore();
        void AddScore();

};