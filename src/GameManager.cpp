#include "GameManager.h"

GameManager::GameManager () {
    string tempName;
    cout << "Enter player name: ";
    cin >> tempName;
    player.SetName(tempName);
}

void GameManager::PlayGame () {
    board.LoadLevelData();
    while (true) {
        cout << "///// SUDOKU GAME /////" << endl;
        cout << "NAME: " << player.GetName() << endl;
        cout << "SCORE: " << player.GetScore() << endl;

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
                UndoGame();
                break;
            case 3:
                RedoGame();
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
    char number;
    int row, column;

    cout << "Number: ";
    cin >> number;
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> column;

    SaveHistoryData(undoData);
    board.SetGrid(number, row-1, column-1);
}

void GameManager::UndoGame() {
    vector<char> temp;
    temp = undoData.back();
    SaveHistoryData(redoData);

    int n = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!board.GetGrid(i, j).GetLockCond()) {
                board.SetGrid(temp[n], i, j);
            }
            n++;
        }
    }

    undoData.pop_back();
}

void GameManager::RedoGame() {
    vector<char> temp;
    temp = redoData.back();
    SaveHistoryData(undoData);

    int n = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!board.GetGrid(i, j).GetLockCond()) {
                board.SetGrid(temp[n], i, j);
            }
            n++;
        }
    }

    redoData.pop_back();
}

void GameManager::SaveHistoryData(vector<vector<char>> &v) {
    vector<char> tempSave;
    tempSave.clear();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            tempSave.push_back(board.GetGrid(i, j).GetNum());
        }
    }

    v.push_back(tempSave);
}

void GameManager::GameWin() {
    cout << "\n\n///// WIN /////" << endl;
    player.AddScore();
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
    if (!board.CheckHorizontalGrid()) {
        return false;
    }
    if (!board.CheckVerticalGrid()) {
        return false;
    }
    if (!board.CheckBlockGrid()) {
        return false;
    }

    return true;
}

void GameManager::DisplayBoard() {
    board.DisplayBoard();
}
