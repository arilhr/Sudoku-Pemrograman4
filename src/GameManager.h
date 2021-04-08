#pragma once
#include <iostream>
#include <stdlib.h>
#include "Board.h"
#include "Player.h"
#include "Invoker.h"
using namespace std;

class GameManager {
    private:
        Board board;
        Player player;
        Invoker *invoker;
        vector<vector<char>> undoData;
        vector<vector<char>> redoData;
    public:
        GameManager();
        void PlayGame();
        void DisplayBoard();
        void InputPlayer();
        bool CheckWin();
        void GameWin();
        void UndoGame();
        void RedoGame();
        void SaveHistoryData(vector<vector<char>> &v);
};