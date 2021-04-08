#include "Command.h"

Command::Command(Board &board, int row, int column, char value) {
    this->board = &board;
    this->row = row;
    this->column = column;
    this->value = value;

    cout << "Row: " << row << endl;
    cout << "Column: " << column << endl;
    cout << "value: " << value << endl;
}

void Command::Execute() {
    board->SetGrid(value, row, column);
    cout << "Row: " << row << endl;
    cout << "Column: " << column << endl;
    cout << "value: " << value << endl;
}

void Command::Undo() {
    board->DeleteGrid(row, column);
    cout << "UNDO DONE!" << endl;
}