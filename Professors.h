// Importing necessary libraries
#include "bits/stdc++.h"
#include "headers.h"
#include "Course.h"
#ifndef PROFESSORS_H
#define PROFESSORS_H

class Professor {
  string profName;
  string profCat;

public:
  // Constructor declaration
  Professor(string profName);
  Professor(string profName, string profCat); 

  // Method declaration
  string getProfName(); 
  string getProfCat();
  void setProfName(string name);
  void setProfCat(string cat);
    
};

#endif
