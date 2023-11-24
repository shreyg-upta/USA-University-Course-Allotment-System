// Importing necessary libraries
#include "bits/stdc++.h"
#include "headers.h"
// #include "Course.h"  // Why should we not include this class?
#ifndef COURSE_H
#define COURSE_H

class CourseList {
    vector<Course> list;

public:
    // Constructor declaration
    CourseList(Course c1);

    // Accessor declaration
    vector<Course> getList();
    void setCourse(Course c);
    void removeCourse(Course c);
    bool courseInList(Course c);
};

#endif
