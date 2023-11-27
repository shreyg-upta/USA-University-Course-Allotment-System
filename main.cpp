#include <bits/stdc++.h>
#include "CourseList.h"
#include "Professors.h"
#include "Course.h"
#include "headers.h"
using namespace std;

//incomplete push. Please skip this commit
void professorConflict(map<Course, vector<int>>& initialMap, map<Course, vector<int>>& finalMap, vector<Professor>& allProfs, Course course)
{
    int i = 0;
        while(i<allProfs.size()){
            if(initialMap[course][i] >0 &&allProfs[i].slotsLeft>0 && allProfs[i].compare()){
                initialMap[course][i]--;
                finalMap[course][i]++;
                allProfs[i].slotsLeft--;
                break;
            }
            i++;
        }
        if(i>=allProfs.size()){
            // find the first professor with slots left
            int j = 0;
            while(j<allProfs.size()){
                if(initialMap[course][i] >0){
                professorConflict(initialMap, finalMap, allProfs, course);
                break;
                }
                j++;
            }
        }
}
//incomplete push. Please skip this commit

int main()
{
    vector <Professor> allProfs;
    // input aditya dekh lega 

    map<Course, vector<int>> initialMap;
    map<Course, vector<int>> finalMap;
    CourseList allFDCDCs; // Adding all the FD CDCs offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDCDCPref().size(); j++){
        allFDCDCs.checkandadd(allProfs[i].getFDCDCPref().getCourse(j));
        }
    }

    CourseList allFDElectives; // Adding all the FD Electives offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDELPref().size(); j++){
        allFDElectives.checkandadd(allProfs[i].getFDELPref().getCourse(j));
        }
    }

    CourseList allHDCDCs; // Adding all the HD CDCs offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDCDCPref().size(); j++){
        allHDCDCs.checkandadd(allProfs[i].getHDCDCPref().getCourse(j));
        }
    }

    CourseList allHDElectives; // Adding all the HD Electives offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDELPref().size(); j++){
        allHDElectives.checkandadd(allProfs[i].getHDELPref().getCourse(j));
        }
    }
     

// initialising the map
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
   
   // making all the possible edges
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDCDCPref().size(); j++){
        initialMap[allProfs[i].getFDCDCPref().getCourse(j)][i] = 2;
        }
    }

   
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDELPref().size(); j++){
            initialMap[allProfs[i].getFDELPref().getCourse(j)][i] = 2;
        }
    }


    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDCDCPref().size(); j++){
        initialMap[allProfs[i].getHDCDCPref().getCourse(j)][i] = 2;
        }
    }


    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDELPref().size(); j++){
       initialMap[allProfs[i].getHDELPref().getCourse(j)][i] = 2;
        }
    }
    // incomplete push. Please skip this commit
    // implementing the hungarian algorithm
    for(const auto& course : allFDCDCs.getList()) {
        int i = 0;
        while(i<allProfs.size()){
            if(initialMap[course][i] >0 &&allProfs[i].slotsLeft>0){
                initialMap[course][i]--;
                finalMap[course][i]++;
                allProfs[i].slotsLeft--;
                break;
            }
            i++;
        }
        if(i>=allProfs.size()){
            // find the first professor with slots left
            int j = 0;
            while(j<allProfs.size()){
                if(initialMap[course][i] >0){
                professorConflict(initialMap, finalMap, allProfs, course);
                break;
                }
                j++;
            }
        }

        // if i =getList.size loop to find first proffessor
    }
    // incomplete push. Please skip this commit

    

  return 0;
}
