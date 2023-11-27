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
    ifstream file ("input.csv");

    if (!file.is_open()) {
        cout << "Failed to open the file." << std::endl;
        return 1;
    }

    vector<vector<string>> rowdata;

    for()

    map<Course, vector<int>> initialMap;
    map<Course, vector<int>> finalMap;
    CourseList allFDCDCs; // Adding all the FD CDCs offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].FDCDCPreferences.size(); j++){
        allFDCDCs.checkandadd(allProfs[i].FDCDCPreferences[j]);
        }
    }

    CourseList allFDElectives; // Adding all the FD Electives offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].FDElectivePreferences.size(); j++){
        allFDElectives.checkandadd(allProfs[i].FDElectivePreferences[j]);
        }
    }

    CourseList allHDCDCs; // Adding all the HD CDCs offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].HDCDCPreferences.size(); j++){
        allHDCDCs.checkandadd(allProfs[i].HDCDCPreferences[j]);
        }
    }

    CourseList allHDElectives; // Adding all the HD Electives offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].HDElectivePreferences.size(); j++){
        allHDElectives.checkandadd(allProfs[i].HDElectivePreferences[j]);
        }
    }
     

for(const auto& course : allFDCDCs.getList()) {
    initialMap[course] = vector<int>(allProfs.size(), 0);
    finalMap[course] = vector<int>(allProfs.size(), 0);
}
for(const auto& course : allHDCDCs.getList()) {
    initialMap[course] = vector<int>(allProfs.size(), 0);
    finalMap[course] = vector<int>(allProfs.size(), 0);
}
for(const auto& course : allFDElectives.getList()) {
    initialMap[course] = vector<int>(allProfs.size(), 0);
    finalMap[course] = vector<int>(allProfs.size(), 0);
}
for(const auto& course : allHDElectives.getList()) {
    initialMap[course] = vector<int>(allProfs.size(), 0);
    finalMap[course] = vector<int>(allProfs.size(), 0);
}
   
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].FDCDCPreferences.size(); j++){
        initialMap[allProfs[i].FDCDCPreferences[j]][i] = 2;
        }
    }

   
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].FDElectivePreferences.size(); j++){
            initialMap[allProfs[i].FDElectivePreferences[j]][i] = 2;
        }
    }


    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].HDCDCPreferences.size(); j++){
        initialMap[allProfs[i].HDCDCPreferences[j]][i] = 2;
        }
    }


    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].HDElectivePreferences.size(); j++){
       initialMap[allProfs[i].HDElectivePreferences[j]][i] = 2;
        }
    }

    

  return 0;
}
