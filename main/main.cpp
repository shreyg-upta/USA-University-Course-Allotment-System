#include <bits/stdc++.h>
#include "Professor.h"
using namespace std;

// bool isPresentInCourseVector(const std::vector<Course>& vec, const Course& element) {
//     return std::find(vec.begin(), vec.end(), element) != vec.end();
// }
vector<Professor> allProfs;
vector<Course> bannedCourses;
vector<Professor> bannedProfs;
map<Course, vector<int> > initialMap;
map<Course, vector<int> > finalMap;
bool allotProfessor(Course &course)
{
    if (course.getSlotsLeft() == 2)
    {
        int i = 0;
        while (i < allProfs.size())
        {
            if (initialMap[course][i] > 0 && allProfs[i].slotsLeft > 0 && find(bannedProfs.begin(), bannedProfs.end(), allProfs[i]) == bannedProfs.end())
            {
                initialMap[course][i]--;
                finalMap[course][i]++;
                allProfs[i].slotsLeft--;
                course.decrementSlotsLeft();
                break;
            }
            i++;
        }
    }
    if (course.getSlotsLeft() == 1)
    {
        int i = 0;
        while (i < allProfs.size())
        {
            if (initialMap[course][i] > 0 && allProfs[i].slotsLeft > 0 &&find(bannedProfs.begin(), bannedProfs.end(), allProfs[i]) == bannedProfs.end())
            {   
                initialMap[course][i]--;
                finalMap[course][i]++;
                allProfs[i].slotsLeft--;
                course.decrementSlotsLeft();
                return true;
            }
            i++;
        }
    }
    if (course.getSlotsLeft() == 2)
    {
        // find the first professor with slots left
        bannedCourses.push_back(course);
        Course newCourse("N/A");
        for (int j = 0; j < allProfs.size(); j++)
        {
            if (initialMap[course][j] > 0 && find(bannedProfs.begin(), bannedProfs.end(), allProfs[j]) == bannedProfs.end())
            {
                for (auto it : finalMap)
                {
                    if (it.second[j] > 0)
                    {
                        newCourse = it.first;
                        bannedProfs.push_back(allProfs[j]);
                        if (allotProfessor(newCourse))
                        {
                            initialMap[course][j]++;
                            finalMap[course][j]--;
                            allProfs[j].slotsLeft++;
                            return true;
                        }
                        bannedProfs.pop_back();
                        // auto it = std::find(bannedProfs.begin(), bannedProfs.end(), allProfs[j]);
                        // if (it != bannedProfs.end())
                        // {
                        //     // Element found. 'it' is an iterator pointing to the element.
                        //     bannedProfs.erase(it);
                        // }
                    }
                }
            }
        }
        bannedCourses.pop_back();
        if(course.getSlotsLeft()==2){
            return false;
        }
    }
    if (course.getSlotsLeft() == 1)
    {
        // find the first professor with slots left
        bannedCourses.push_back(course);
        Course newCourse("N/A");
        for (int j = 0; j < allProfs.size(); j++)
        {
            if (initialMap[course][j] > 0 && find(bannedProfs.begin(), bannedProfs.end(), allProfs[j]) == bannedProfs.end())
            {
                for (auto it : finalMap)
                {
                    if (it.second[j] > 0)
                    {
                        newCourse = it.first;
                        bannedProfs.push_back(allProfs[j]);
                        if (allotProfessor(newCourse))
                        {
                            initialMap[course][j]++;
                            finalMap[course][j]--;
                            allProfs[j].slotsLeft++;
                            return true;
                        }
                        bannedProfs.pop_back();
                        // auto it = std::find(bannedProfs.begin(), bannedProfs.end(), allProfs[j]);
                        // if (it != bannedProfs.end())
                        // {
                        //     // Element found. 'it' is an iterator pointing to the element.
                        //     bannedProfs.erase(it);
                        // }
                    }
                }
            }
        }
        bannedCourses.pop_back();
        if(course.getSlotsLeft()==1){
            return false;
        }
    }
}
/*
void writeDataToCSV(const string &filePath, const vector<vector<string> > &data)
{
    // Open the CSV file
    ofstream csvFile(filePath);

    if (!csvFile.is_open())
    {
        cerr << "Error opening the file: " << filePath << endl;
        return;
    }

    // Iterate through each row of data
    for (const vector<string> &row : data)
    {
        // Iterate through each element in the row
        for (auto it = row.begin(); it != row.end(); ++it)
        {
            // Write the element to the file
            csvFile << *it;

            // Add a comma if it's not the last element in the row
            if (next(it) != row.end())
            {
                csvFile << ",";
            }
        }

        // Move to the next line after each row
        csvFile << "\n";
    }

    // Close the file
    csvFile.close();

    cout << "Data written to CSV file: " << filePath << endl;
}
*/
int main()
{
    // input aditya dekh lega

    ifstream inputFile("input.csv");

    if (!inputFile.is_open())
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    // Read the file line by line
    string line, name;
    while (getline(inputFile, line))
    {
        istringstream ss(line);
        string token;

        // Create a Professor object for each line
        Professor professor;

        // Read the professor's name
        getline(ss, name, ',');
        professor.setProfName(name);

        // Read the FDCDCs
        vector<Course> l1;
        while (getline(ss, token, ','))
        {
            l1.checkandadd(token);
            professor.setFDCDCPref(l1);
        }

        // Read the FDElecs
        CourseList l2;
        while (getline(ss, token, ','))
        {
            l2.checkandadd(token);
            professor.setFDELPref(l2);
        }

        // Read the HDCDCs
        CourseList l3;
        while (getline(ss, token, ','))
        {
            professor.setHDCDCPref(l3);
        }

        // Read the HDElecs
        CourseList l4;
        while (getline(ss, token, ','))
        {
            professor.setHDELPref(l4);
        }

        // Add the Professor object to the vector
        allProfs.push_back(professor);
    }

    // Close the file
    inputFile.close();
    // aditya ne dekha kya

    vector<Course> allFDCDCs; // Adding all the FD CDCs offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDCDCPref().size(); j++)
        {
            auto it = std::find(allFDCDCs.begin(), allFDCDCs.end(), allProfs[i].getFDCDCPref()[j]);
            if (it != allFDCDCs.end())
            {
                if (it->getBestPriority() > j)
                    it->setBestPriority(j);
            }
            else
            {
                allFDCDCs.push_back(allProfs[i].getFDCDCPref()[j]);
            }
        }
    }

    vector<Course> allFDElectives; // Adding all the FD Electives offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDELPref().size(); j++)
        {
            auto it = std::find(allFDElectives.begin(), allFDElectives.end(), allProfs[i].getFDELPref()[j]);
            if (it != allFDElectives.end())
            {
                if (it->getBestPriority() > j)
                    it->setBestPriority(j);
            }
            else
            {
                allFDElectives.push_back(allProfs[i].getFDELPref()[j]);
            }
        }
    }

    vector<Course> allHDCDCs; // Adding all the HD CDCs offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDCDCPref().size(); j++)
        {
            auto it = std::find(allHDCDCs.begin(), allHDCDCs.end(), allProfs[i].getHDCDCPref()[j]);
            if (it != allHDCDCs.end())
            {
                if (it->getBestPriority() > j)
                    it->setBestPriority(j);
            }
            else
            {
                allHDCDCs.push_back(allProfs[i].getHDCDCPref()[j]);
            }
        }
    }

    vector<Course> allHDElectives; // Adding all the HD Electives offered in a master CourseList
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDELPref().size(); j++)
        {
            auto it = std::find(allHDElectives.begin(), allHDElectives.end(), allProfs[i].getHDELPref()[j]);
            if (it != allHDElectives.end())
            {
                if (it->getBestPriority() > j)
                    it->setBestPriority(j);
            }
            else
            {
                allHDElectives.push_back(allProfs[i].getHDELPref()[j]);
            }
        }
    }

    // initialising the map
    for (const auto &course : allFDCDCs)
    {
        initialMap[course] = vector<int>(allProfs.size(), 0);
        finalMap[course] = vector<int>(allProfs.size(), 0);
    }
    for (const auto &course : allHDCDCs)
    {
        initialMap[course] = vector<int>(allProfs.size(), 0);
        finalMap[course] = vector<int>(allProfs.size(), 0);
    }
    for (const auto &course : allFDElectives)
    {
        initialMap[course] = vector<int>(allProfs.size(), 0);
        finalMap[course] = vector<int>(allProfs.size(), 0);
    }
    for (const auto &course : allHDElectives)
    {
        initialMap[course] = vector<int>(allProfs.size(), 0);
        finalMap[course] = vector<int>(allProfs.size(), 0);
    }

    // making all the possible edges
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDCDCPref().size(); j++)
        {
            initialMap[allProfs[i].getFDCDCPref()[j]][i] = 2;
        }
    }

    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDELPref().size(); j++)
        {
            initialMap[allProfs[i].getFDELPref()[j]][i] = 2;
        }
    }

    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDCDCPref().size(); j++)
        {
            initialMap[allProfs[i].getHDCDCPref()[j]][i] = 2;
        }
    }

    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDELPref().size(); j++)
        {
            initialMap[allProfs[i].getHDELPref()[j]][i] = 2;
        }
    }
    // incomplete push. Please skip this commit
    // implementing the hungarian algorithm
    for (auto &course : allFDCDCs)
    {
        allotProfessor(course);
    }
    // for (const auto &course : allFDElectives)
    // {
    //     int i = 0;
    //     while (i < allProfs.size())
    //     {
    //         if (initialMap[course][i] > 0 && allProfs[i].slotsLeft > 0)
    //         {
    //             initialMap[course][i]--;
    //             finalMap[course][i]++;
    //             allProfs[i].slotsLeft--;
    //             break;
    //         }
    //         i++;
    //     }
    //     if (i >= allProfs.size())
    //     {
    //         // find the first professor with slots left
    //         int j = 0;
    //         while (j < allProfs.size())
    //         {
    //             if (initialMap[course][i] > 0)
    //             {
    //                 professorConflict(initialMap, finalMap, allProfs, course);
    //                 initialMap[course][j]++;
    //                 finalMap[course][j]--;
    //                 allProfs[j].slotsLeft++;
    //                 bannedCourses.add(course);
    //                 break;
    //             }
    //             j++;
    //         }

    //         // if i =getList.size loop to find first proffessor
    //     }
    // }
    // incomplete push. Please skip this commit
/*
    vector<vector<string> > data = {
        {"Name", "Course"},
        {"Aditya", "CS 213"},
        {"Aditya", "CS 215"},
        {"Aditya", "CS 251"},
        {"Aditya", "CS 293"},
    };

    // File path to write the CSV file
    string filePath = "output.csv";

    // Write data to CSV file
    writeDataToCSV(filePath, data);
*/

    return 0;
}
