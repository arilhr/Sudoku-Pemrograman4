/* 4210191014 AURIEL HARLIH */
#pragma once
#include "Command.h"
#include "Board.h"

class FillBoard : public Command {
    private:
        Board *board;
        int row, column;
        char value;
    public:
        FillBoard() = default;
        FillBoard(Board &board, char value, int row, int column);
        void Execute();
        void Undo();
};