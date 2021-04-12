/* 4210191014 AURIEL HARLIH */
#pragma once

class Command {
    public:
        virtual void Execute() = 0;
        virtual void Undo() = 0;
};