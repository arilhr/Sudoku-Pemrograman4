#pragma once
#include <iostream>
#include <stdlib.h>
#include "Board.h"
#include "Player.h"
#include "Invoker.h"
#include "FillBoard.h"
using namespace std;

class GameManager {
    private:
        Board *board;
        Player *player;
        Invoker *invoker;
    public:
        GameManager();
        void PlayGame();
        void DisplayBoard();
        void InputPlayer();
        bool CheckWin();
        void GameWin();
        void Undo();
        void Redo();
};