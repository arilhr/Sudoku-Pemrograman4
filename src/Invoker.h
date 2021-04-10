#pragma once
#include <vector>
#include "Command.h"

class Invoker {
    private:
        std::vector<Command*> commands;
    public:
        Invoker() = default;
        Command* GetCommand();
        void PushCommand(Command &command);
        void PopCommand();
};