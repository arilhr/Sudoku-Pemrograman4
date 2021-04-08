#pragma once
#include "Board.h"

class Command {
    private:
        private:
        Board *board;
        int row, column;
        char value;
    public:
        Command() = default;
        Command(Board &board, int row, int column, char value);
        void Execute();
        void Undo();
};