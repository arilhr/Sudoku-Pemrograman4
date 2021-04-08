#include "Player.h"

Player::Player() {
    score = 0;
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