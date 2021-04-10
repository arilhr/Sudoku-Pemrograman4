#include "Invoker.h"

Command* Invoker::GetCommand() {
    return commands.back();
}

void Invoker::PushCommand(Command &command) {
    commands.push_back(&command);
}

void Invoker::PopCommand() {
    if (commands.empty())
        return;

    commands.pop_back();
}