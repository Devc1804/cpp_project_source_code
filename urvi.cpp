#include <iostream>
#include <map>
#include <queue>
#include <ctime>  // Include the <ctime> header for randomization

using namespace std;

class SnakeAndLadderGame {

private:
    map<int, int> snakes;
    map<int, int> ladders;
    queue<string> players;
    map<string, int> playerPositions;


public:
    SnakeAndLadderGame() {
        // Initialize the snakes and ladders (same as before)
        snakes[16] = 6;
        snakes[47] = 26;
        snakes[49] = 11;
        snakes[56] = 53;
        snakes[62] = 19;
        snakes[64] = 60;
        snakes[87] = 24;
        snakes[93] = 73;
        snakes[95] = 75;
        snakes[98] = 78;

        ladders[1] = 38;
        ladders[4] = 14;
        ladders[9] = 31;
        ladders[21] = 42;
        ladders[28] = 84;
        ladders[36] = 44;
        ladders[51] = 67;
        ladders[71] = 91;

        ladders[80] = 100;



        // Initialize the players (same as before)
        players.push("Player 1");
        players.push("Player 2");
        players.push("Player 3");
        players.push("Player 4");

        // Initialize the player positions (same as before)
        playerPositions["Player 1"] = 0;
        playerPositions["Player 2"] = 0;
        playerPositions["Player 3"] = 0;
        playerPositions["Player 4"] = 0;
    }

    void playGame() {
        while (!players.empty()) {
            string currentPlayer = players.front();
            players.pop();

            // Allow the user to roll the dice
            cout << "It's " << currentPlayer << "'s turn. Press Enter to roll the dice.";
            cin.get();

            int diceRoll = rollDice();
            cout << currentPlayer << " rolled a " << diceRoll << endl;

            int newPosition = playerPositions[currentPlayer] + diceRoll;

            if (newPosition > 100) {
                newPosition = playerPositions[currentPlayer];
            } else if (newPosition == 100) {
                cout << currentPlayer << " wins the game!" << endl;
                break;
            }

            if (snakes.find(newPosition) != snakes.end()) {
                newPosition = snakes[newPosition];
            } else if (ladders.find(newPosition) != ladders.end()) {
                newPosition = ladders[newPosition];
            }

            playerPositions[currentPlayer] = newPosition;

            cout << currentPlayer << " moved to position " << newPosition << endl;

            players.push(currentPlayer);
        }
    }

    int rollDice() {
        // Generate a random number between 1 and 6
        return rand() % 6 + 1;
    }
};

int main() {


    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator

    SnakeAndLadderGame game;
    game.playGame();

    return 0;

}
