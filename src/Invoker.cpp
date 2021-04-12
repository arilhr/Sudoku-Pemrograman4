/* 4210191014 AURIEL HARLIH */
#include "Invoker.h"

Command* Invoker::GetCommand() {
    return commands.back();
}

void Invoker::PushCommand(Command &command) {
    // push command
    commands.push_back(&command);
}

void Invoker::PopCommand() {
    // cek bila stack command empty, maka hentikan method
    if (commands.empty())
        return;

    // pop command
    commands.pop_back();
}