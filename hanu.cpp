#include<bits/stdc++.h>
using namespace std;

class Course {
    public:
    string courseTitle;
    string courseCode;
    string id;
    unsigned int credit;
    bool isElective;
    bool isFirstDegree;
    int bestPriority;
    int slotsLeft;
    public:
    Course(string s) {
    // Constructor implementation
    if((s[s.size()-4]=='f' || s[s.size()-4]=='F') && 48<=s[s.size()-3] && s[s.size()-3]<=57 && 48<=s[s.size()-2] && s[s.size()-2]<=57 && 48<=s[s.size()-1] && s[s.size()-1]<=57){
        courseCode = s;
    }
    else {
        courseTitle = s;
    }
    bestPriority = INT_MAX;
    slotsLeft = 2;
}
Course(string s, string c, unsigned int cr, bool e, bool f) {
    // Constructor implementation
    courseCode = c;
    courseTitle = s;
    credit = cr;
    isElective = e;
    isFirstDegree = f;
    bestPriority = INT_MAX;
    slotsLeft = 2;
    id = to_string(!isFirstDegree) + to_string(isElective) + to_string(bestPriority) + courseTitle;
}
Course(string s, bool e, bool f) {
    // Constructor implementation
    courseCode = "";
    courseTitle = s;
    credit = -1;
    isElective = e;
    isFirstDegree = f;
    bestPriority = INT_MAX;
    slotsLeft = 2;
        id = to_string(!isFirstDegree) + to_string(isElective) + to_string(bestPriority) + courseTitle;

}
Course(string s, string t) {
    // Constructor implementation
    courseTitle = s;
    courseCode = t;
    bestPriority = INT_MAX;
    isElective = false;
    isFirstDegree = false;
    credit = 0;
    slotsLeft = 2;
        id = to_string(!isFirstDegree) + to_string(isElective) + to_string(bestPriority) + courseTitle;


}
int getSlotsLeft(){
    return slotsLeft;
}
void decrementSlotsLeft(){
    slotsLeft--;
}

bool getIsElective() {
    // Method implementation
    return isElective;
}

bool getIsFirstDegree() {
    // Method implementation
    return isFirstDegree;
}

string getCourseTitle() {
    // Method implementation
    return courseTitle;
}


string getCourseCode() {
    // Method implementation
    return courseCode;
}

unsigned int getCredit() {
    // Method implementation
    return credit;
}

int getBestPriority() {
    // Method implementation
    return bestPriority;
}

void setBestPriority(int p) {
    // Method implementation
    bestPriority = p;
}

void setIsElective(bool e) {
    // Method implementation
    isElective = e;
}

void setIsFirstDegree(bool f) {
    // Method implementation
    isFirstDegree = f;
}

void setCourseTitle(string t) {
    // Method implementation
    courseTitle = t;
}

void setCourseCode(string c) {
    // Method implementation
    courseCode = c;
}

void setCredit(unsigned int cr) {
    // Method implementation
    credit = cr;
}

void setCourse(string s) {
    // Method implementation
    if((s[s.size()-4]=='f' || s[s.size()-4]=='F') && 48<=s[s.size()-3] && s[s.size()-3]<=57 && 48<=s[s.size()-2] && s[s.size()-2]<=57 && 48<=s[s.size()-1] && s[s.size()-1]<=57){
        courseCode = s;
    }
    else {
        courseTitle = s;
    }
}

void setCourse(string s, string c, unsigned int cr, bool e, bool f) {
    // Method implementation
    courseCode = c;
    courseTitle = s;
    credit = cr;
    isElective = e;
    isFirstDegree = f;
}

void setCourse(string s, string t) {
    // Method implementation
    courseTitle = s;
    courseCode = t;
}

bool sameCourse(Course c) {
    // Method implementation
    if(courseCode == c.courseCode && courseTitle == c.courseTitle){
        return true;
    }
    else {
        return false;
    }
}

bool sameCourse(string s) {
    // Method implementation
    if(courseCode == s || courseTitle == s){
        return true;
    }
    else {
        return false;
    }
}
bool operator==(const Course &other)const {
    // Implement comparison logic based on your class members
    // For example, if your Course class has an id member:

    if(isElective != other.isElective) return false;
    else if(isFirstDegree != other.isFirstDegree) return false;
    else{
               if(courseTitle != other.courseTitle) return false;
                else return true;    
        
    }
}

bool operator<(const Course &other)const {
    // Implement comparison logic based on your class members
    // For example, if your Course class has an id member:

    if(isElective && !other.isElective) return false;
    else if(!isElective  && other.isElective) return true;
    else{
        if(isFirstDegree && !other.isFirstDegree) return true;
        else if(!isFirstDegree && other.isFirstDegree) return false;
        else{
            if(bestPriority < other.bestPriority) return true;
            else if(bestPriority > other.bestPriority) return false;
            else{
                    if(courseTitle < other.courseTitle) return true;
                    else if(courseTitle > other.courseTitle) return false;
                    else return false;
                
            }
        }
    }
}

};
class Professor {
   public:
  string profName;
  string profCat;
  vector<Course> HDCDCPref;
  vector<Course> FDCDCPref;
  vector<Course> HDELPref;
  vector<Course> FDELPref;
  vector<Course> coursesAssigned;
  int slotsLeft;
  public:
Professor(){
    // Constructor implementation
    profName = "";
    profCat = "";
    HDCDCPref = vector<Course>();
    FDCDCPref = vector<Course>();
    HDELPref = vector<Course>();
    FDELPref = vector<Course>();
    coursesAssigned = vector<Course>();
    slotsLeft = -1;
}

Professor(string name) {
    // Constructor implementation
    profName = name;
    slotsLeft = -1;
}

Professor(string name, string cat) {
    // Constructor implementation
    profName = name;
    slotsLeft = -1;
    setProfCat(cat);
}

string getProfName() {
    // Method implementation
    return profName;
}

string getProfCat() {
    // Method implementation
    return profCat;
}

vector<Course> getHDCDCPref() {
    // Method implementation
    return HDCDCPref;
}

vector<Course> getFDCDCPref() {
    // Method implementation
    return FDCDCPref;
}

vector<Course> getHDELPref() {
    // Method implementation
    return HDELPref;
}

vector<Course> getFDELPref() {
    // Method implementation
    return FDELPref;
}

vector<Course> getCoursesAssigned() {
    // Method implementation
    return coursesAssigned;
}
void setProfName(string s) {
    // Method implementation
    profName = s;
}

void setHDCDCPref(vector<Course> l) {
    // Method implementation
    HDCDCPref = l;
}

void setFDCDCPref(vector<Course> l) {
    // Method implementation
    FDCDCPref = l;
}

void setHDELPref(vector<Course> l) {
    // Method implementation
    HDELPref = l;
}

void setFDELPref(vector<Course> l) {
    // Method implementation
    FDELPref = l;
}

void setCoursesAssigned(vector<Course> l) {
    // Method implementation
    coursesAssigned = l;
}
// adding courses to preference lists
void addHDCDCPref(Course l) {
    // Method implementation
    HDCDCPref.push_back(l);
}

void addFDCDCPref(Course l) {
    // Method implementation
    FDCDCPref.push_back(l);
}

void addHDELPref(Course l) {
    // Method implementation
    HDELPref.push_back(l);
}

void addFDELPref(Course l) {
    // Method implementation
    FDELPref.push_back(l);
}

void addCoursesAssigned(Course l) {
    // Method implementation
    coursesAssigned.push_back(l);
}

void setProfCat(string s) {
    // Method implementation
    if (s == "x1") {
        slotsLeft = 1;
        profCat = s;
    }
    else if (s == "x2") {
        slotsLeft = 2;
        profCat = s;
    }
    else if (s == "x3") {
        slotsLeft = 3;
        profCat = s;
    }
    else cout << "Invalid category";
}

bool compare(Professor p) {
    // Method implementation
    if (profName == p.getProfName()) {
        return true;
    }
    else return false;
}
bool operator==(const Professor &other)const{
    // Implement comparison logic based on your class members
    // For example, if your Course class has an id member:
    if (profName == other.profName) {
        return true;
    }
    else return false;
   
}

};

vector<Professor> allProfs;
vector<Course> bannedCourses;
vector<Professor> bannedProfs;
map<Course, vector<int> > initialMap;
map<Course, vector<int> > finalMap;
bool allotProfessor(Course &course){
    return true;
}

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

int main() {
    // Course c1("a", true, false);
    // Course c2("b", true, false);
    // Course c3("c", true, false);
    // Course c4("d", false, false);
    // Course c5("e", false, false);
    // Course c6("f", false, false);
    // Course c7("g", false, true);
    // Course c8("h", false, true);
    // Course c9("i", false, true);
    // Course c10("j", false, true);
    // Course c11("k", true, true);
    // Course c12("l", true, true);
    // Course c13("m", true, true);
    // vector<Course> v1 ;
    // v1.push_back(c1);
    // v1.push_back(c2);
    // v1.push_back(c3);
    // vector<Course> v2;
    // v2.push_back(c4);
    // v2.push_back(c5);
    // v2.push_back(c6);
    // vector<Course> v3;
    // v3.push_back(c7);
    // v3.push_back(c8);
    // v3.push_back(c9);
    // vector<Course> v4;
    // v4.push_back(c10);
    // v4.push_back(c11);
    // v4.push_back(c12);       
    // vector<Course> v5;
    // v5.push_back(c13);
    // v5.push_back(c1);
    // v5.push_back(c2);
    // vector<Course> v6;
    // v6.push_back(c3);
    // v6.push_back(c4);
    // v6.push_back(c5);
    // vector<Course> v7;
    // v7.push_back(c6);
    // v7.push_back(c7);
    // v7.push_back(c8);
    // vector<Course> v8;
    // v8.push_back(c9);
    // v8.push_back(c10);
    // v8.push_back(c11);
    // Professor p1("A", "x1");
    // Professor p2("B", "x2");
    // Professor p3("C", "x3");
    // Professor p4("D", "x1");
    // Professor p5("E", "x2");
    // Professor p6("F", "x3");
    // p1.setHDCDCPref(v1);
    // p1.setFDCDCPref(v2);
    // p1.setHDELPref(v3);
    // p1.setFDELPref(v4);
    // p2.setHDCDCPref(v5);
    // p2.setFDCDCPref(v6);
    // p2.setHDELPref(v7);
    // p2.setFDELPref(v8);
    // p3.setHDCDCPref(v2);
    // p3.setFDCDCPref(v3);
    // p3.setHDELPref(v4);
    // p3.setFDELPref(v5);
    // p4.setHDCDCPref(v6);
    // p4.setFDCDCPref(v7);
    // p4.setHDELPref(v8);
    // p4.setFDELPref(v1);
    // p5.setHDCDCPref(v3);
    // p5.setFDCDCPref(v4);
    // p5.setHDELPref(v5);
    // p5.setFDELPref(v6);
    // p6.setHDCDCPref(v7);
    // p6.setFDCDCPref(v8);
    // p6.setHDELPref(v1);
    // p6.setFDELPref(v2);
    // allProfs.push_back(p1);
    // allProfs.push_back(p2);
    // allProfs.push_back(p3);
    // allProfs.push_back(p4);
    // allProfs.push_back(p5);
    // allProfs.push_back(p6);

    // try it out
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
            (initialMap[(allProfs[i].getFDCDCPref())[j]])[i]=2;
        }
    }
    // this is where we messed up
    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getFDELPref().size(); j++)
        {
            (initialMap[allProfs[i].getFDELPref()[j]])[i]=2;
        }
    }

    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDCDCPref().size(); j++)
        {
            (initialMap[allProfs[i].getHDCDCPref()[j]])[i]=2;
        }
    }

    for (int i = 0; i < allProfs.size(); i++)
    {
        for (int j = 0; j < allProfs[i].getHDELPref().size(); j++)
        {
            (initialMap[allProfs[i].getHDELPref()[j]])[i]=2;
        }
    }
    
// Our Algorithm
    for (auto &course : allFDCDCs)
    {
        bool check = allotProfessor(course);
    }
    for(auto pr : finalMap){
        cout<<pr.first.courseTitle <<" : ";
        for(auto i : pr.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
   return 0;
}