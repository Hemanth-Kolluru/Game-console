#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class RockPaperScissors {
public:
    enum Choice {
        ROCK,
        PAPER,
        SCISSORS
    };
    void playGame() {
        cout << "Welcome to Rock, Paper, Scissors!\n";
        while (true) {
            Choice player1 = getPlayerChoice(1);
            Choice player2 = getPlayerChoice(2);

            cout << "\n\tPlayer 1 chose "<<printChoice(player1)<<"\t\t\tPlayer 2 chose "<<printChoice(player2);
            if(player1 == ROCK && player2 == ROCK)
            {
                cout <<R"(
                   _______                        ______
               ---'   ____)                     _(___   '---
                     (_____)                   (_____)
                     (_____)                   (_____)
                     (____)                     (____)
               ---.__(___)                        (___)__.---
               )";
            }
            else if(player1 == PAPER && player2 == ROCK)
            {
                cout <<R"(
                    _______                                ______
                ---'    ___)_____                        _(___   '---
                            ______)_                    (_____)
                             _______)                   (_____)
                            _______)                     (____)
                ---.____________)                         (___)__.---
                )";
            }
            else if(player1 == SCISSORS && player2 == ROCK)
            {
                cout << R"(
                    ______                                  ______
                ---'   ___)_______                        _(___   '---
                            ______)_                     (_____)
                       _____________)                    (_____)
                      (____)                              (____)
                ---.__(___)                                (___)__.---
                )";
            }
            if(player1 == ROCK && player2 == PAPER)
            {
                cout <<R"(
                   _______                             ______
               ---'   ____)                       ____(___   '---
                     (_____)                    _(_______
                     (_____)                   (_______
                     (____)                     (________
               ---.__(___)                         (__________.---
               )";
            }
            else if(player1 == PAPER && player2 == PAPER)
            {
                cout <<R"(
                    ______                                      ______
                ---'    ___)_____                          ____(___   '---
                            ______)_                     _(_______
                             _______)                   (_______
                            _______)                     (________
                ---.____________)                           (_________.---
                )";
            }
            else if(player1 == SCISSORS && player2 == ROCK)
            {
                cout << R"(
                    ______                                      ______
                ---'   ___)_______                         ____(___   '---
                            ______)_                     _(_______
                       _____________)                   (_______
                      (____)                             (________
                ---.__(___)                                 (_________.---
                )";
            }
            if(player1 == ROCK && player2 == ROCK)
            {
                cout <<R"(
                   _______                               ______
               ---'   ____)                       ______(___   '---
                     (_____)                    _(_____
                     (_____)                   (_________
                     (____)                           (____)
               ---.__(___)                             (___)___.---
               )";
            }
            else if(player1 == PAPER && player2 == ROCK)
            {
                cout <<R"(
                    ______                                        _______
                ---'    ___)_____                          ______(___    '---
                            ______)_                     _(______
                             _______)                   (_________
                            _______)                           (____)
                ---.____________)                               (___)____.---
                )";
            }
            else if(player1 == SCISSORS && player2 == ROCK)
            {
                cout << R"(
                    ______                                        _______
                ---'   ___)_______                         ______(___    '---
                            ______)_                     _(______
                       _____________)                   (_________
                      (____)                                   (____)
                ---.__(___)                                     (___)____.---
                )";
            }
            int result = determineWinner(player1, player2);
            if (result == 0) {
                cout << "\n\t\t\t\t\tIt's a tie!\n";
            } else if (result == 1) {
                cout << "\n\t\t\t\tPlayer 1 wins!\n";
            } else {
                cout << "\n\t\t\t\tPlayer 2 wins!\n";
            }
            cout << "Do you want to play again? (y/n): ";
            char playAgain;
            cin >> playAgain;
            if (playAgain != 'y' && playAgain != 'Y') {
                break;
            }
        }
        cout << "Thanks for playing!\n";
    }
private:
    string printChoice(Choice choice) {
        switch (choice) {
            case ROCK:
                return "Rock";
                break;
            case PAPER:
                return "Paper";
                break;
            case SCISSORS:
                return "Scissors";
                break;
        }
    }
    Choice getPlayerChoice(int playerNumber) {
        cout << "Player " << playerNumber << ", enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
        int choice;
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3.\n";
            return getPlayerChoice(playerNumber);
        }
        return static_cast<Choice>(choice - 1);
    }
    int determineWinner(Choice player1, Choice player2) {
        if (player1 == player2) {
            return 0; // It's a tie
        } else if ((player1 == ROCK && player2 == SCISSORS) ||
                   (player1 == PAPER && player2 == ROCK) ||
                   (player1 == SCISSORS && player2 == PAPER)) {
            return 1; // Player 1 wins
        } else {
            return 2; // Player 2 wins
        }
    }
};
int main() {
    RockPaperScissors game;
    game.playGame();
    return 0;
}