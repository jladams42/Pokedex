#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

using namespace std;

// Pokemon class to hold Pokemon data
class Pokemon {
private:
    int index;
    string name;

public:
    Pokemon(int idx = 0, const string& nm = "None") : index(idx), name(nm) {}; // Constructor

    void setID(int idx) { index = idx; };
    void setName(const string& nm) { name = nm; };

    int getID() const { return index; };
    string getName() const { return name; };

    bool operator<(const Pokemon& right) const {
        return index < right.index;
    }
    bool operator==(const Pokemon& right) const {
        return index == right.index;
    }

    friend ostream& operator<<(ostream& out, const Pokemon& p) {
        out << "Pokemon Index Number: " << p.index << "     Name: " << p.name;
        return out;
    }
};

#endif