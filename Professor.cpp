// Importing necessary libraries
#include "Professor.h"
#include "Course.h"
// #include "CourseList.h"

using namespace std;

Professor::Professor(){
    // Constructor implementation
    profName = "";
    profCat = "";
    HDCDCPref = vector<Course>();
    FDCDCPref = vector<Course>();
    HDELPref = vector<Course>();
    FDELPref = vector<Course>();
    coursesAssigned = vector<Course>();
    slotsLeft = -1;
}

Professor::Professor(string name) {
    // Constructor implementation
    profName = name;
    slotsLeft = -1;
}

Professor::Professor(string name, string cat) {
    // Constructor implementation
    profName = name;
    slotsLeft = -1;
    setProfCat(cat);
}

string Professor::getProfName() {
    // Method implementation
    return profName;
}

string Professor::getProfCat() {
    // Method implementation
    return profCat;
}

vector<Course> Professor::getHDCDCPref() {
    // Method implementation
    return HDCDCPref;
}

vector<Course> Professor::getFDCDCPref() {
    // Method implementation
    return FDCDCPref;
}

vector<Course> Professor::getHDELPref() {
    // Method implementation
    return HDELPref;
}

vector<Course> Professor::getFDELPref() {
    // Method implementation
    return FDELPref;
}

vector<Course> Professor::getCoursesAssigned() {
    // Method implementation
    return coursesAssigned;
}
void Professor::setProfName(string s) {
    // Method implementation
    profName = s;
}

void Professor::setHDCDCPref(vector<Course> l) {
    // Method implementation
    HDCDCPref = l;
}

void Professor::setFDCDCPref(vector<Course> l) {
    // Method implementation
    FDCDCPref = l;
}

void Professor::setHDELPref(vector<Course> l) {
    // Method implementation
    HDELPref = l;
}

void Professor::setFDELPref(vector<Course> l) {
    // Method implementation
    FDELPref = l;
}

void Professor::setCoursesAssigned(vector<Course> l) {
    // Method implementation
    coursesAssigned = l;
}
// adding courses to preference lists
void Professor::addHDCDCPref(Course l) {
    // Method implementation
    HDCDCPref.push_back(l);
}

void Professor::addFDCDCPref(Course l) {
    // Method implementation
    FDCDCPref.push_back(l);
}

void Professor::addHDELPref(Course l) {
    // Method implementation
    HDELPref.push_back(l);
}

void Professor::addFDELPref(Course l) {
    // Method implementation
    FDELPref.push_back(l);
}

void Professor::addCoursesAssigned(Course l) {
    // Method implementation
    coursesAssigned.push_back(l);
}

void Professor::setProfCat(string s) {
    // Method implementation
    if (s == "x1") {
        slotsLeft = 1;
        profCat = s;
    }
    else if (s == "x2") {
        slotsLeft = 2;
        profCat = s;
    }
    else if (s == "x3") {
        slotsLeft = 3;
        profCat = s;
    }
    else cout << "Invalid category";
}

bool Professor::compare(Professor p) {
    // Method implementation
    if (profName == p.getProfName()) {
        return true;
    }
    else return false;
}
bool Professor::operator==(const Professor &other) {
    // Implement comparison logic based on your class members
    // For example, if your Course class has an id member:
    if (profName == other.profName) {
        return true;
    }
    else return false;
   
}
