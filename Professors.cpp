// Importing necessary libraries
#include "Professors.h"

Professor::Professor(string name) {
    // Constructor implementation
    profName = name;
}

Professor::Professor(string name, string cat) {
    // Constructor implementation
    profName = name;
    profCat = cat;
}

string Professor::getProfName() {
    // Method implementation
    return profName;
}

string Professor::getProfCat() {
    // Method implementation
    return profCat;
}

void Professor::setProfName(string s) {
    // Method implementation
    profName = s;
}

void Professor::setProfCat(string s) {
    // Method implementation
    profCat = s;
}
