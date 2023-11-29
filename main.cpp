#include <bits/stdc++.h>
#include "ProfessorConflict.cpp"
using namespace std;


int main()
{
    vector<Professor> allProfs;
    // input aditya dekh lega

    map<Course, vector<int> > initialMap;
    map<Course, vector<int> > finalMap;
    CourseList allFDCDCs; // Adding all the FD CDCs offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDCDCPref().size(); j++)
        {
            allFDCDCs.checkandadd(allProfs[i].getFDCDCPref().getCourse(j));
        }
    }

    CourseList allFDElectives; // Adding all the FD Electives offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDELPref().size(); j++)
        {
            allFDElectives.checkandadd(allProfs[i].getFDELPref().getCourse(j));
        }
    }

    CourseList allHDCDCs; // Adding all the HD CDCs offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDCDCPref().size(); j++)
        {
            allHDCDCs.checkandadd(allProfs[i].getHDCDCPref().getCourse(j));
        }
    }

    CourseList allHDElectives; // Adding all the HD Electives offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDELPref().size(); j++)
        {
            allHDElectives.checkandadd(allProfs[i].getHDELPref().getCourse(j));
        }
    }

    // initialising the map
    for (const Course &course : allFDCDCs.getList())
    {
        initialMap[course] = vector<int>(allProfs.size(), 0);
        finalMap[course] = vector<int>(allProfs.size(), 0);
    }
    for (const Course &course : allHDCDCs.getList())
    {
        initialMap[course] = vector<int>(allProfs.size(), 0);
        finalMap[course] = vector<int>(allProfs.size(), 0);
    }
    for (const Course &course : allFDElectives.getList())
    {
        initialMap[course] = vector<int>(allProfs.size(), 0);
        finalMap[course] = vector<int>(allProfs.size(), 0);
    }
    for (const Course &course : allHDElectives.getList())
    {
        initialMap[course] = vector<int>(allProfs.size(), 0);
        finalMap[course] = vector<int>(allProfs.size(), 0);
    }

    // making all the possible edges
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDCDCPref().size(); j++)
        {
            initialMap[allProfs[i].getFDCDCPref().getCourse(j)][i] = 2;
        }
    }

    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDELPref().size(); j++)
        {
            initialMap[allProfs[i].getFDELPref().getCourse(j)][i] = 2;
        }
    }

    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDCDCPref().size(); j++)
        {
            initialMap[allProfs[i].getHDCDCPref().getCourse(j)][i] = 2;
        }
    }

    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDELPref().size(); j++)
        {
            initialMap[allProfs[i].getHDELPref().getCourse(j)][i] = 2;
        }
    }
    // implementing our algorithm here
    for (const auto &course : allFDCDCs.getList())
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
                // finding professors who can take this course
                if (initialMap[course][j] > 0)
                {
                    int k = 0;
                    int l = 0;
                    int profAllotted[2][3] = {-1, -1, -1, -1, -1, -1};
                    /*
                    profAllotted[0][i] = 0 if FDCDC is allotted;
                    profAllotted[0][i] = 1 if HDCDC is allotted;
                    profAllotted[0][i] = 2 if FDE is allotted;
                    profAllotted[0][i] = 3 if HDE is allotted;
                    */
                    // find what course is allotted to this professor
                    // for FDCDCs
                    while (k < allFDCDCs.size() and l<2)
                    {
                        if (finalMap[course][k] > 0 && !allProfs[j].compare(allProfs[k]))
                        {
                            profAllotted[0][l] = k;
                            profAllotted[1][l] = 0;
                            l++;
                        }
                        k++;
                    }
                    // for HDCDCs
                    k = 0;
                    while (k < allHDCDCs.size() and l<2)
                    {
                        if (finalMap[course][k] > 0 && !allProfs[j].compare(allProfs[k]))
                        {
                            profAllotted[0][l] = k;
                            profAllotted[1][l] = 1;
                            l++;
                        }
                        k++;
                    }
                    // for FDEs
                    k = 0;
                    while (k < allFDElectives.size() and l<2)
                    {
                        if (finalMap[course][k] > 0 && !allProfs[j].compare(allProfs[k]))
                        {
                            profAllotted[0][l] = k;
                            profAllotted[1][l] = 2;
                            l++;
                        }
                        k++;
                    }
                    // for HDEs
                    k = 0;
                    while (k < allHDElectives.size() and l<2)
                    {
                        if (finalMap[course][k] > 0 && !allProfs[j].compare(allProfs[k]))
                        {
                            profAllotted[0][l] = k;
                            profAllotted[1][l] = 3;
                            l++;
                        }
                        k++;
                    }
                    CourseList banned;
                    // finding if the professor can take this course and allotting it to him
                    if (profAllotted[0][0] != -1)
                    {
                        if (professorConflict(initialMap, finalMap, allProfs, course, profAllotted[0][0], profAllotted[1][0], allFDCDCs, allHDCDCs, allFDElectives, allHDElectives, banned))
                        {
                            // write a command to allot the new professor this course
                            break;
                        }
                    }
                    if (profAllotted[0][1] != -1)
                        {
                            if (professorConflict(initialMap, finalMap, allProfs, course, profAllotted[0][1], profAllotted[1][1], allFDCDCs, allHDCDCs, allFDElectives, allHDElectives, banned))
                            {
                            // write a command to allot the new professor this course
                                break;
                            }
                        }
                    break;
                }
                j++;
            }
        }

        // if i =getList.size loop to find first proffessor
    }

    return 0;
}
