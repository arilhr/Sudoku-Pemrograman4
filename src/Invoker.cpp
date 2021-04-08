#include "Invoker.h"

Invoker::Invoker(Board &board) {
    this->board = &board;
}

void Invoker::PushCommand(int row, int column, char value) {
    Command command(*board, row, column, value);
    command.Execute();
    commands.push_back(command);
    cout << "Count: " << commands.size() << endl;
}

void Invoker::PopCommand() {
    if (commands.empty())
        return;
    
    commands.back().Undo();
    commands.pop_back();
    cout << "UNDO COMPLETED"<< endl;
}