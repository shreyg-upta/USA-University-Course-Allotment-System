// Importing necessary libraries
#include "bits/stdc++.h"
#include "headers.h"
#include "Course.h"
#define COURSE_H

using namespace std;

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
