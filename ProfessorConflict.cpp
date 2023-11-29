#include <bits/stdc++.h>
#include "Professors.h"
using namespace std;

bool professorConflict(map<Course, vector<int> > &initialMap, map<Course, vector<int> > &finalMap, vector<Professor> &allProfs, Course course, int profKey,int deptAlloted, CourseList allFDCDCs, CourseList allHDCDCs, CourseList allFDELs, CourseList allHDELs, CourseList bannedCourses)
{
int i = 0;
        while (i < allProfs.size())
        {
            if (initialMap[course][i] > 0 && allProfs[i].slotsLeft > 0)
            {
                initialMap[course][i]--;
                finalMap[course][i]++;
                allProfs[i].slotsLeft--;
                break;
            }
            i++;
        }
        if (i >= allProfs.size())
        {
            
            int j = 0;
            while (j < allProfs.size())
            {
                if (initialMap[course][j] > 0)
            {
                if(professorConflict(initialMap, finalMap, allProfs, course, j, deptAlloted, allFDCDCs, allHDCDCs, allFDELs, allHDELs, bannedCourses)){
                    initialMap[course][j]++;
                    finalMap[course][j]--;
                    allProfs[j].slotsLeft++;
                    bannedCourses.add(course);
                }
                else return false;
                break;
            }
            j++;
            }
        }
} 