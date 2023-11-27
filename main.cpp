#include <bits/stdc++.h>
#include "Professors.h"
using namespace std;

//incomplete push. Please skip this commit
void professorConflict(map<Course, vector<int> > &initialMap, map<Course, vector<int> >&finalMap, vector<Professor> & allProfs, Course course)
{
    int i = 0;
        while(i<allProfs.size()){
            if(initialMap[course][i] >0 &&allProfs[i].slotsLeft>0 /*&& allProfs[i].compare()*/){
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

void writeDataToCSV(const string& filePath, const vector<vector<string>>& data) {
    // Open the CSV file
    ofstream csvFile(filePath);

    if (!csvFile.is_open()) {
        cerr << "Error opening the file: " << filePath << endl;
        return;
    }

    // Iterate through each row of data
    for (const vector<string>& row : data) {
        // Iterate through each element in the row
        for (auto it = row.begin(); it != row.end(); ++it) {
            // Write the element to the file
            csvFile << *it;

            // Add a comma if it's not the last element in the row
            if (next(it) != row.end()) {
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

int main()
{
    vector <Professor> allProfs;
    // input aditya dekh lega 

    ifstream inputFile ("input.csv");

    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    // Read the file line by line
    string line, name;
    while (getline(inputFile, line)) {
        istringstream ss(line);
        string token;

        // Create a Professor object for each line
        Professor professor;

        // Read the professor's name
        getline(ss, name, ',');
        professor.setProfName(name);

        // Read the FDCDCs
        CourseList l1;
        while (getline(ss, token, ',')) {
            l1.checkandadd(token);
            professor.setFDCDCPref(l1);
        }

        // Read the FDElecs
        CourseList l2;
        while (getline(ss, token, ',')) {
            l2.checkandadd(token);
            professor.setFDELPref(l2);
        }

        // Read the HDCDCs
        CourseList l3;
        while (getline(ss, token, ',')) {
            professor.setHDCDCPref(l3);
        }

        // Read the HDElecs
        CourseList l4;
        while (getline(ss, token, ',')) {
            professor.setHDELPref(l4);
        }

        // Add the Professor object to the vector
        allProfs.push_back(professor);
    }

    // Close the file
    inputFile.close();

    map<Course, vector<int> > initialMap;
    map<Course, vector<int> > finalMap;
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

    vector<vector<string>> data = {
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

    return 0;
}
