#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "./functions.cpp"
using namespace std;

int main() {
    // 2D vector for map (21x21 grid initialized with '.')
    srand(time(0));

    int attempts = 0;
    int guessX, guessY;
    double distance;
    bool treasureFound = false;

    //Start
    cout << "=== Welcome to The Treasure Hunt Game ===" << endl;
    cout << "Guess the Hidden Treasure location from (0-20)!\n";


    do {
        int gatorX = 0, gatorY = 0, treasureX = 0, treasureY = 0;

        cout << "\nEnter X coordinate: ";
        cin >> guessX;
        cout << "Enter Y coordinate: ";
        cin >> guessY;
        attempts++;

        randLocations(treasureX, treasureY, gatorX, gatorY);
        map[guessY][guessX] = 'X';  // 'X' = guessed location
        map[gatorY][gatorX] = 'O'; // Mark gator on map

        double gatorDist = calculateDistance(guessX, guessY, gatorX, gatorY);
        distance = calculateDistance(guessX, guessY, treasureX, treasureY);

        if (gatorDist == 0 and distance !=0 ) {
            cout << "\nUh oh, you've been eaten by a wild gator! Better luck next time." << endl;
            mapSave(treasureFound, treasureX, treasureY,gatorX, gatorY, attempts);
        } else {
            treasureFound = true;
            playerFeedback(distance, treasureX, treasureY, attempts); //new funct - body in functions.cpp
            mapSave(treasureFound, treasureX, treasureY, gatorX, gatorY, attempts); //new funct - body in functions2.cpp
        }

    } while (distance != 0); // Loop exits after the treasure is found

    cout << "\nGame Over. Thanks for playing! Map saved to 'treasure_map.txt'.\n";

    return 0;
}