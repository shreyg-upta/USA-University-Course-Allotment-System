#include <bits/stdc++.h>
#include "CourseList.h"
#include "Professors.h"
#include "Course.h"
#include "headers.h"
using namespace std;


int main()
{
    vector <Professor> allProfs;
    // input aditya dekh lega 


    CourseList allFDCDCs; // Adding all the FD CDCs offered in a master CourseList
    for (size_t i = 0; i < allProfs.size(); i++)
    {
        for (size_t j = 0; j < allProfs[i].FDCDCPreferences.size(); j++){
        allFDCDCs.checkandadd(allProfs[i].FDCDCPreferences[j]);
        }
    }

    CourseList allFDElectives; // Adding all the FD Electives offered in a master CourseList
    for (size_t i = 0; i < allProfs.size(); i++)
    {
        for (size_t j = 0; j < allProfs[i].FDElectivePreferences.size(); j++){
        allFDElectives.checkandadd(allProfs[i].FDElectivePreferences[j]);
        }
    }

    CourseList allHDCDCs; // Adding all the HD CDCs offered in a master CourseList
    for (size_t i = 0; i < allProfs.size(); i++)
    {
        for (size_t j = 0; j < allProfs[i].HDCDCPreferences.size(); j++){
        allHDCDCs.checkandadd(allProfs[i].HDCDCPreferences[j]);
        }
    }

    CourseList allHDElectives; // Adding all the HD Electives offered in a master CourseList
    for (size_t i = 0; i < allProfs.size(); i++)
    {
        for (size_t j = 0; j < allProfs[i].HDElectivePreferences.size(); j++){
        allHDElectives.checkandadd(allProfs[i].HDElectivePreferences[j]);
        }
    }
     
    
  return 0;
}
