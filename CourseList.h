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
    CourseList();
    CourseList(Course c1);

    // Accessor declaration
    vector<Course> getList();
    void add(Course c);
    void remove(Course c);
    bool check(Course c);
    void checkandadd(Course c);

};
