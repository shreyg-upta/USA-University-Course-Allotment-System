// Importing necessary libraries
#include "bits/stdc++.h"
// #include "headers.h"
#include "Course.cpp"
// #include "CourseList.h"
#ifndef PROFESSORS_H
#define PROFESSORS_H

class Professor {
  string profName;
  string profCat;
  vector<Course> HDCDCPref;
  vector<Course> FDCDCPref;
  vector<Course> HDELPref;
  vector<Course> FDELPref;
  vector<Course> coursesAssigned;
  public: int slotsLeft;
  // public: string profName;
  public:
  // Constructor declaration
  Professor();
  Professor(string profName);
  Professor(string profName, string profCat); 

  // Method declaration
  string getProfName(); 
  string getProfCat();
  vector<Course> getHDCDCPref();
  vector<Course> getFDCDCPref();
  vector<Course> getHDELPref();
  vector<Course> getFDELPref();
  vector<Course> getCoursesAssigned();
  void setProfName(string name);
  void setProfCat(string cat);
  void setHDCDCPref(vector<Course> l);  
  void setFDCDCPref(vector<Course> l);  
  void setHDELPref(vector<Course> l);  
  void setFDELPref(vector<Course> l);  
  void setCoursesAssigned(vector<Course> l);
  void addHDCDCPref(Course c);
  void addFDCDCPref(Course c);
  void addHDELPref(Course c);
  void addFDELPref(Course c);
  void addCoursesAssigned(Course c);
  bool compare(Professor p);
  bool operator==(const Professor &other);
};

#endif
