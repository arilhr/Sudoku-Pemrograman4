#include "GameManager.h"

GameManager::GameManager () {
    player = new Player();
    board = new Board();
    invoker = new Invoker();
}

void GameManager::PlayGame () {
    board->LoadLevelData();
    while (true) {
        cout << "///// SUDOKU GAME /////" << endl;
        cout << "NAME: " << player->GetName() << endl;
        cout << "SCORE: " << player->GetScore() << endl;

        int playerInput;
        DisplayBoard();
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
        
        if (CheckWin()) {
            GameWin();
            break;
        }
    }
}

void GameManager::InputPlayer() {
    char value;
    int row, column;

    cout << "Number: ";
    cin >> value;
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> column;
    
    FillBoard *command = new FillBoard(*board, value, row, column);
    command->Execute();
    invoker->PushCommand(*command);
}

void GameManager::Undo() {
    if (invoker->GetCommand() != NULL) {
        Command *topCommand = invoker->GetCommand();
        topCommand->Undo();
        invoker->PopCommand();
    }
}

void GameManager::Redo() {
    
}

void GameManager::GameWin() {
    cout << "\n\n///// WIN /////" << endl;
    player->AddScore();
    DisplayBoard();

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
