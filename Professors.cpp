// Importing necessary libraries
#include "Professors.h"
#include "CourseList.h"

using namespace std;

Professor::Professor(string name) {
    // Constructor implementation
    profName = name;
}

Professor::Professor(string name, string cat) {
    // Constructor implementation
    profName = name;
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

CourseList Professor::getHDCDCPref() {
    // Method implementation
    return HDCDCPref;
}

CourseList Professor::getFDCDCPref() {
    // Method implementation
    return FDCDCPref;
}

CourseList Professor::getHDELPref() {
    // Method implementation
    return HDELPref;
}

CourseList Professor::getFDELPref() {
    // Method implementation
    return FDELPref;
}

CourseList Professor::getCoursesAssigned() {
    // Method implementation
    return coursesAssigned;
}
void Professor::setProfName(string s) {
    // Method implementation
    profName = s;
}

void Professor::setHDCDCPref(CourseList l) {
    // Method implementation
    HDCDCPref = l;
}

void Professor::setFDCDCPref(CourseList l) {
    // Method implementation
    FDCDCPref = l;
}

void Professor::setHDELPref(CourseList l) {
    // Method implementation
    HDELPref = l;
}

void Professor::setFDELPref(CourseList l) {
    // Method implementation
    FDELPref = l;
}

void Professor::setCoursesAssigned(CourseList l) {
    // Method implementation
    coursesAssigned = l;
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
    else cout << "Provide a suitable Category";
}

bool Professor::compare(Professor p) {
    // Method implementation
    if (profName == p.getProfName()) {
        return true;
    }
    else return false;
}
