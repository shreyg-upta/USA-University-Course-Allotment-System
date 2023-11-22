#include "bits/stdc++.h"
#include "headers.h"  // Include header file
#ifndef COURSE_H
#define COURSE_H

class Course {
    string courseTitle;
    string courseCode;
    unsigned int credit;
    bool isElective;
    bool isFirstDegree;

public:
    Course(string s);
    Course(string s, string c, unsigned int cr, bool e, bool f);
    Course(string s, string t);
      // Constructor declaration

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
      // Accessor declaration

     // Method declaration
};

#endif // MYCLASS_H
