// Importing necessary libraries
#include "bits/stdc++.h"
// #include "headers.h" 
#ifndef COURSE_H
#define COURSE_H

using namespace std;

class Course {
    string courseTitle;
    string courseCode;
    unsigned int credit;
    bool isElective;
    bool isFirstDegree;

public:
    // Constructor declaration
    Course(string s);
    Course(string s, string c, unsigned int cr, bool e, bool f);
    Course(string s, string t);

    // Accessor declaration
    bool getIsElective();
    bool getIsFirstDegree();
    string getCourseTitle();
    string getCourseCode();
    unsigned int getCredit();
    void setIsElective(bool e);
    void setIsFirstDegree(bool f);
    void setCourseTitle(string t);
    void setCourseCode(string c);
    void setCredit(unsigned int cr);
    void setCourse(string s);
    void setCourse(string s, string c, unsigned int cr, bool e, bool f);
    void setCourse(string s, string t);
    bool sameCourse(Course c);
    bool sameCourse(string s);
    bool operator<(const Course &other);
    
};

#endif
