#include "Board.h"

void Board::SetGrid(char number, int row, int column) {
    grid[row][column].SetNum(number);
}

Grid Board::GetGrid(int row, int column) {
    return grid[row][column];
}

void Board::DisplayBoard() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 9; i++) {
        SetConsoleTextAttribute(h, 7);
        if (i % 3 == 0) {
            cout << "===============================" << endl;
        }

        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                cout << "|";
            }

            if (grid[i][j].GetLockCond()) {
                // change color text to blue
                SetConsoleTextAttribute(h, 3);
            } else if (grid[i][j].GetWrongCond()) {
                // change color text to red
                SetConsoleTextAttribute(h, FOREGROUND_RED);
            }

            cout << " " << grid[i][j].GetNum() << " ";
            SetConsoleTextAttribute(h, 7);
        }
        cout << "|" << endl;
    }

    SetConsoleTextAttribute(h, 7);
    cout << "===============================" << endl;
}

bool Board::CheckHorizontalGrid() {
    vector<char> possibleNum;

    for (int i = 0; i < 9; i++) {
        possibleNum = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int j = 0; j < 9; j++) {
            if (find(possibleNum.begin(), possibleNum.end(), grid[i][j].GetNum()) != possibleNum.end()) {
                possibleNum.erase(remove(possibleNum.begin(), possibleNum.end(), grid[i][j].GetNum()), possibleNum.end());
            } else {
                return false;
            }
        }   
    }

    return true;
}

bool Board::CheckVerticalGrid() {
    vector<char> possibleNum;

    for (int i = 0; i < 9; i++) {
        possibleNum = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int j = 0; j < 9; j++) {
            if (find(possibleNum.begin(), possibleNum.end(), grid[j][i].GetNum()) != possibleNum.end()) {
                possibleNum.erase(remove(possibleNum.begin(), possibleNum.end(), grid[j][i].GetNum()), possibleNum.end());
            } else {
                return false;
            }
        }   
    }

    return true;
}

bool Board::CheckBlockGrid() {
    vector<char> possibleNum;

    for (int x = 0; x < 3; x++) { 
        for (int y = 0; y < 3; y++) {
            possibleNum = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char inCheck = grid[i][j + (3 * y)].GetNum();
                    bool isContain = find(possibleNum.begin(), possibleNum.end(), inCheck) != possibleNum.end();
                    if (isContain) {
                        possibleNum.erase(remove(possibleNum.begin(), possibleNum.end(), inCheck), possibleNum.end());
                    } else {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

void Board::LoadLevelData() {
    fstream dataLevelFile;
    string data;
    dataLevelFile.open(dataLevel);
    if (dataLevelFile.is_open()) {
        getline(dataLevelFile, data);
    } else {
        cout << "file not found!" << endl;
    }

    // start game level file
    string startingData = data.substr(0, 81);
    int n = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j].SetLockCond(false);
            if (startingData[n] == '0') {
                grid[i][j].SetNum(' ');
            } else {
                grid[i][j].SetNum(startingData[n]);
                grid[i][j].SetLockCond(true);
            }
            n++;
        }   
    }
}

