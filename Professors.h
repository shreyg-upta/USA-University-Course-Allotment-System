// Importing necessary libraries
#include "bits/stdc++.h"
// #include "headers.h"
// #include "Course.h"
#include "CourseList.h"
#ifndef PROFESSORS_H
#define PROFESSORS_H

class Professor {
  string profName;
  string profCat;
  CourseList HDCDCPref;
  CourseList FDCDCPref;
  CourseList HDELPref;
  CourseList FDELPref;
  CourseList coursesAssigned;
  public: int slotsLeft;
public:
  // Constructor declaration
  Professor(string profName);
  Professor(string profName, string profCat); 

  // Method declaration
  string getProfName(); 
  string getProfCat();
  CourseList getHDCDCPref();
  CourseList getFDCDCPref();
  CourseList getHDELPref();
  CourseList getFDELPref();
  CourseList getCoursesAssigned();
  void setProfName(string name);
  void setProfCat(string cat);
  void setHDCDCPref(CourseList l);  
  void setFDCDCPref(CourseList l);  
  void setHDELPref(CourseList l);  
  void setFDELPref(CourseList l);  
  void setCoursesAssigned(CourseList l);
  bool compare(Professor p);
};

#endif
