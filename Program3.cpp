#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Pokemon.h"
#include "BinaryTree.h"

int main() {
    // Create a binary tree to hold Pokemon objects
    BinaryTree<Pokemon> pokedex;
    ifstream file("pokedex.txt");

    // Check if the file was opened successfully
    if(!file){
        cout << "Error opening file." << endl;
        return 0;
    }

    string line;
    int insertedCount = 0;

    // Read file based on separator #
    if(getline(file, line)){
        // Ref https://www.geeksforgeeks.org/stringstream-c-applications/
        stringstream ss(line);
        string segment;

        // Read each segment of the line
        while(getline(ss, segment, '#')){
            int index;
            string name;

            // Ref: https://www.geeksforgeeks.org/stdstoi-function-in-cpp/
            index = stoi(segment);

            if(!getline(ss, segment, '#')) break;
            name = segment;

            Pokemon p(index, name); // Create a Pokemon object

            // Insert the Pokemon object into the binary tree
            if(!pokedex.searchNode(p)){
                pokedex.insertNode(p);
                cout << "Inserting Pokemon with index " << index << " into the Pokedex." << std::endl;
                insertedCount++;
            } else {
                cout << "Oops!  The Pokemon with index " << index << " is already in the Pokedex." << std::endl;
            }
        }
    }

    // Count the number of Pokemon inserted into the Pokedex
    cout << "\n" << insertedCount << " Pokemon have been added to the Pokedex." << endl;
    cout << "\n********************POKEDEX:********************\n" << endl;

    pokedex.displayInOrder(); // Display the Pokedex in order

    return 0;
}