/* 4210191014 AURIEL HARLIH */
#include "GameManager.h"

GameManager::GameManager () {
    player = new Player();
    board = new Board();
    undoInvoker = new Invoker();
    redoInvoker = new Invoker();
}

void GameManager::PlayGame () {
    // load data awal board
    board->LoadLevelData();

    // mulai permainan
    while (true) {
        cout << "///// SUDOKU GAME /////" << endl;
        cout << "NAME: " << player->GetName() << endl;
        cout << "SCORE: " << player->GetScore() << endl;
        DisplayBoard();

        int playerInput;
        cout << "1. Input Grid | 2. Undo | 3. Redo" << endl;
        cin >> playerInput;
        switch (playerInput)
        {
            case 1:
                InputPlayer();
                break;
            case 2:
                Undo();
                break;
            case 3:
                Redo();
                break;
            default:
                break;
        }
        
        // cek win
        if (CheckWin()) {
            GameWin();
            break;
        }
    }
}

void GameManager::InputPlayer() {
    // method untuk pemain menginput value pada grid
    char value;
    int row, column;

    cout << "Number: ";
    cin >> value;
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> column;
    
    // Declare dan inisialisasi command -> execute -> push ke undo stack -> clear redo stack 
    FillBoard *command = new FillBoard(*board, value, row, column);
    command->Execute();
    undoInvoker->PushCommand(*command);
    redoInvoker->Clear();
}

void GameManager::Undo() {
    // cek apakah stack command kosong atau tidak
    if (!undoInvoker->IsEmpty()) {
        // get command teratas -> undo -> push command ke redo stack -> pop dari undo stack
        Command *command = undoInvoker->GetCommand();
        command->Undo();
        redoInvoker->PushCommand(*command);
        undoInvoker->PopCommand();
    }
}

void GameManager::Redo() {
    // cek stack commands di redo kosong atau tidak
    if (!redoInvoker->IsEmpty()) {
        // get command redo teratas -> execute -> push command ke undo stack -> pop dari redo stack
        Command *command = redoInvoker->GetCommand();
        command->Execute();
        undoInvoker->PushCommand(*command);
        redoInvoker->PopCommand();
    }
}

void GameManager::GameWin() {
    // tambah score pemain
    cout << "\n\n///// WIN /////" << endl;
    player->AddScore();

    DisplayBoard();

    // player input ingin main lagi atau keluar
    int userInput;
    cout << "1 : start again | 2 : to exit" << endl;
    cin >> userInput;
    if (userInput == 1) {
        PlayGame();
    } else if (userInput == 2) {
        exit(3);
    }
}

bool GameManager::CheckWin() {
    // cek horizontal grid -> vertical grid -> per block
    if (!board->CheckHorizontalGrid()) {
        return false;
    }
    if (!board->CheckVerticalGrid()) {
        return false;
    }
    if (!board->CheckBlockGrid()) {
        return false;
    }

    return true;
}

void GameManager::DisplayBoard() {
    board->DisplayBoard();
}
