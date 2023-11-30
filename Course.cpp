#include "Course.h"

using namespace std;
 
Course::Course(string s) {
    // Constructor implementation
    if((s[s.size()-4]=='f' || s[s.size()-4]=='F') && 48<=s[s.size()-3] && s[s.size()-3]<=57 && 48<=s[s.size()-2] && s[s.size()-2]<=57 && 48<=s[s.size()-1] && s[s.size()-1]<=57){
        courseCode = s;
    }
    else {
        courseTitle = s;
    }
    bestPriority = INT_MAX;
    slotsLeft = 2;
}
Course::Course(string s, string c, unsigned int cr, bool e, bool f) {
    // Constructor implementation
    courseCode = c;
    courseTitle = s;
    credit = cr;
    isElective = e;
    isFirstDegree = f;
    bestPriority = INT_MAX;
    slotsLeft = 2;
}
Course::Course(string s, string t) {
    // Constructor implementation
    courseTitle = s;
    courseCode = t;
    bestPriority = INT_MAX;
    isElective = false;
    isFirstDegree = false;
    credit = 0;
    slotsLeft = 2;

}
int Course::getSlotsLeft(){
    return slotsLeft;
}
void Course::decrementSlotsLeft(){
    slotsLeft--;
}

bool Course::getIsElective() {
    // Method implementation
    return isElective;
}

bool Course::getIsFirstDegree() {
    // Method implementation
    return isFirstDegree;
}

string Course::getCourseTitle() {
    // Method implementation
    return courseTitle;
}


string Course::getCourseCode() {
    // Method implementation
    return courseCode;
}

unsigned int Course::getCredit() {
    // Method implementation
    return credit;
}

int Course::getBestPriority() {
    // Method implementation
    return bestPriority;
}

void Course::setBestPriority(int p) {
    // Method implementation
    bestPriority = p;
}

void Course::setIsElective(bool e) {
    // Method implementation
    isElective = e;
}

void Course::setIsFirstDegree(bool f) {
    // Method implementation
    isFirstDegree = f;
}

void Course::setCourseTitle(string t) {
    // Method implementation
    courseTitle = t;
}

void Course::setCourseCode(string c) {
    // Method implementation
    courseCode = c;
}

void Course::setCredit(unsigned int cr) {
    // Method implementation
    credit = cr;
}

void Course::setCourse(string s) {
    // Method implementation
    if((s[s.size()-4]=='f' || s[s.size()-4]=='F') && 48<=s[s.size()-3] && s[s.size()-3]<=57 && 48<=s[s.size()-2] && s[s.size()-2]<=57 && 48<=s[s.size()-1] && s[s.size()-1]<=57){
        courseCode = s;
    }
    else {
        courseTitle = s;
    }
}

void Course::setCourse(string s, string c, unsigned int cr, bool e, bool f) {
    // Method implementation
    courseCode = c;
    courseTitle = s;
    credit = cr;
    isElective = e;
    isFirstDegree = f;
}

void Course::setCourse(string s, string t) {
    // Method implementation
    courseTitle = s;
    courseCode = t;
}

bool Course::sameCourse(Course c) {
    // Method implementation
    if(courseCode == c.courseCode && courseTitle == c.courseTitle){
        return true;
    }
    else {
        return false;
    }
}

bool Course::sameCourse(string s) {
    // Method implementation
    if(courseCode == s || courseTitle == s){
        return true;
    }
    else {
        return false;
    }
}
bool Course::operator==( Course &other) {
    // Implement comparison logic based on your class members
    // For example, if your Course class has an id member:

    if(isElective != other.isElective) return false;
    else if(isFirstDegree != other.isFirstDegree) return false;
    else{
               if(courseTitle != other.courseTitle) return false;
                else return true;    
        
    }
}

bool Course::operator<( Course &other) {
    // Implement comparison logic based on your class members
    // For example, if your Course class has an id member:

    if(isElective && !other.isElective) return false;
    else if(!isElective  && other.isElective) return true;
    else{
        if(isFirstDegree && !other.isFirstDegree) return true;
        else if(!isFirstDegree && other.isFirstDegree) return false;
        else{
            if(bestPriority < other.bestPriority) return true;
            else if(bestPriority > other.bestPriority) return false;
            else{
                    if(courseTitle < other.courseTitle) return true;
                    else if(courseTitle > other.courseTitle) return false;
                    else return false;
                
            }
        }
    }
}