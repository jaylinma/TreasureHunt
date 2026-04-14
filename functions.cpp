#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

vector map(21, vector<char>(21, '.'));

//sigs:
void playerFeedback(double distance, int treasureX, int treasureY);
int randLocations(int treasureX, int treasureY, int gatorX , int gatorY);
double calculateDistance(double X1, double Y1, double X2, double Y2);
void mapSave(bool treasureFound, double X, double Y, int attempts);


int randLocations(int treasureX, int treasureY, int gatorX , int gatorY) {
    // Random treasure location
   return(treasureX = rand() % 21, treasureY = rand() % 21, gatorX = rand() % 21, gatorY = rand() % 21);

}

void playerFeedback(double distance, int treasureX, int treasureY, int attempts) {
    //feedback to player
    cout << fixed << setprecision(2);
    cout << "Distance from Treasure: " << setw(6) << distance << endl;
    if (distance == 0) {
        map[treasureY][treasureX] = 'T'; // Mark treasure on map
        cout << "\nYou found the Treasure in " << attempts << " attempts!" << endl;
    }
    else if (distance < 3) {
        cout << "Very close!" << endl;
    }
    else if (distance < 7) {
        cout << "Getting warmer..." << endl;
    }
    else {
        cout << "Cold!" << endl;
    }
    cout << "\nMap (X = guessed locations):\n";
    for (int y = 0; y < 21; y++) {
        for (int x = 0; x < 21; x++) {
            cout << map[y][x] << ' ';
        }
        cout << endl;
    }
}

// Save map and results to file
void mapSave(bool treasureFound, int treasureX, int treasureY, int gatorX, int gatorY, int attempts) {
    if (treasureFound == 0) {
        ofstream file("treasure_map.txt");
        file << "Gator Location: (" << gatorX << ", " << gatorY << ")\n";
        file << "Treasure Location: (" << treasureX << ", " << treasureY << ")\n";
        file << "Attempts: " << attempts << "\n\n";
        file << "Map (X = guesses, O = gator, T = treasure):\n";
        for (int y = 0; y < 21; y++) {
            for (int x = 0; x < 21; x++) {
                file << map[y][x] << ' ';
            }
            file << endl;
        }
        file.close();
    } else {
        ofstream file("treasure_map.txt");
        file << "Treasure Location: (" << treasureX << ", " << treasureY << ")\n";
        file << "Attempts: " << attempts << "\n\n";
        file << "Map (X = guesses, T = treasure):\n";
        for (int y = 0; y < 21; y++) {
            for (int x = 0; x < 21; x++) {
                file << map[y][x] << ' ';
            }
            file << endl;
        }
        file.close();
    }
}

double calculateDistance(double X1, double Y1, double X2, double Y2) {
    return sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
}
