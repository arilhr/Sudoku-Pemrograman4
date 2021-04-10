#pragma once

class Command {
    public:
        Command() = default;
        virtual void Execute() = 0;
        virtual void Undo() = 0;
};