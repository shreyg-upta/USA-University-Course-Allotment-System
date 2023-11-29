#include "CourseList.h"
#include "bits/stdc++.h"
// #include "headers.h"
#include "Course.h"

using namespace std;

CourseList::CourseList() {
    // Constructor implementation
    CourseList l;
}

CourseList::CourseList(Course c1) {
    // Constructor implemetation
    list.push_back(c1);
}

vector<Course> CourseList::getList() {
    return list;
}

void CourseList::add(Course c) {
    list.push_back(c);
}

void CourseList::remove(Course c) {
    list.erase(find(list.begin(), list.end(), c));
}

bool CourseList::check(Course c) {
    if (find(list.begin(), list.end(), c) == list.end()){
        return false;
    }
    else return true;
}

void CourseList::checkandadd(Course c) {
    if (!check(c)) {
        add(c);
    }
}
int CourseList::size() {
    return list.size();
}

Course CourseList::getCourse(int i) {
    return list[i];
}