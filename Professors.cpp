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

CourseList Professor::getPriorityOrder() {
    // Method implementation
    return priorityOrder;
}

CourseList Professor::getCoursesAssigned() {
    // Method implementation
    return coursesAssigned;
}
void Professor::setProfName(string s) {
    // Method implementation
    profName = s;
}

void Professor::setPriorityOrder(CourseList l) {
    // Method implementation
    priorityOrder = l;
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
