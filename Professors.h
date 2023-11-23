#include "bits/stdc++.h"
#include "headers.h"
#include "Course.h"
#ifndef PROFESSORS_H
#define PROFESSORS_H

class Professor {
    string profName;
    string profCat;
    string profPrefer[];
    string profAssign[];

public:
    Professor(string profName);
    Professor(string profName, string profCat);
    Professor(string profName, string profCat, string profPrefer[], string profAssign[]);
      // Constructor declaration

    string getProfName(); 
    string getProfCat();
    string getProfPrefer();
    string getProfAssign();
    void setProfName(string name);
    void setProfCat(string cat);
    void addProfPrefer(Course c);
    void addProfAssign(Course c);
    void removeProfPrefer(Course c);
    void removeProfAssign(Course c);
     // Method declaration
};

#endif // MYCLASS_H
