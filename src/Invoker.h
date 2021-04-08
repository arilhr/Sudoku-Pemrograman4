#pragma once
#include <vector>
#include "Command.h"
#include "Board.h"

class Invoker {
    private:
        Board *board;
        std::vector<Command> commands;
    public:
        Invoker() = default;
        Invoker(Board &board);
        void PushCommand(int row, int column, char value);
        void PopCommand();
};