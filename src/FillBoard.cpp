/* 4210191014 AURIEL HARLIH */
#include "FillBoard.h"

FillBoard::FillBoard (Board &board, char value, int row, int column) {
    this->board = &board;
    this->value = value;
    this->row = row;
    this->column = column;
}

void FillBoard::Execute() {
    board->SetGrid(value, row, column);
}

void FillBoard::Undo() {
    board->DeleteGrid(row, column);
}