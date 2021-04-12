/*4210191002 Irfan Muhammad*/

#include "Player.h"

Player::Player(){
    score = 0;
    InputName();
}

void Player::InputName() {
    string temp;
    cout << "Enter player name: ";
    cin >> temp;
    name = temp;
}

void Player::SetName(string name) {
    this->name = name;
}

string Player::GetName() {
    return name;
}

void Player::SetScore(int score) {
    this->score = score;
}

int Player::GetScore() {
    return score;
}

void Player::AddScore() {
    score += 1;
}