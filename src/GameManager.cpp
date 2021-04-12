/* 4210191014 AURIEL HARLIH */
#include "GameManager.h"

GameManager::GameManager () {
    player = new Player();
    board = new Board();
    invoker = new Invoker();
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
    
    // Declare dan inisialisasi command -> execute -> push
    FillBoard *command = new FillBoard(*board, value, row, column);
    command->Execute();
    invoker->PushCommand(*command);
}

void GameManager::Undo() {
    // cek apakah stack command kosong atau tidak
    if (invoker->GetCommand() != NULL) {
        // get command teratas -> undo -> pop
        Command *topCommand = invoker->GetCommand();
        topCommand->Undo();
        invoker->PopCommand();
    }
}

void GameManager::Redo() {
    // dalam tahap pengembangan hehe, masih belum paham gan

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
