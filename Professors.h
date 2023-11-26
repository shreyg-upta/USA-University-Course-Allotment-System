// Importing necessary libraries
#include "bits/stdc++.h"
#include "headers.h"
#include "Course.h"
#include "CourseList.h"
#ifndef PROFESSORS_H
#define PROFESSORS_H

class Professor {
  string profName;
  string profCat;
  CourseList priorityOrder;
  CourseList coursesAssigned;
  int slotsLeft;
public:
  // Constructor declaration
  Professor(string profName);
  Professor(string profName, string profCat); 

  // Method declaration
  string getProfName(); 
  string getProfCat();
  CourseList getPriorityOrder();
  CourseList getCoursesAssigned();
  void setProfName(string name);
  void setProfCat(string cat);
  void setPriorityOrder(CourseList l);  
  void setCoursesAssigned(CourseList l);
};

#endif
