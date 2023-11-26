#include "CourseList.h"
#include "bits/stdc++.h"
#include "headers.h"
#include "Course.h"

using namespace std;

CourseList::CourseList(Course c1) {
    // Constructor implemetation
    list.push_back(c1);
}

vector<Course> CourseList::getList() {
    return list;
}

void setList(Course c) {
    list.push_back(c);
}

void removeCourse(Course c) {
    list.erase(find(list.begin(), list.end(), c));
}

bool courseInList(Course c) {
    return list.find(list.begin(), list.end(), c);
}