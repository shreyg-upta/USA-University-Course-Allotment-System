#include <bits/stdc++.h>
#include "Professor.cpp"
using namespace std;

// class professor{
//     public:
//     string name;
//     int category;

//     professor(string name, string s){
//         this->name = name;
//         if(s == "x1")
//             this->category = 1;
//         else if(s == "x2")
//             this->category = 2;
//         else if(s == "x3")
//             this->category = 3;
//     }
//     };
// class course{
//     public:
//     string name;
    

//     course(string name){
//         this->name = name;
//     };
//     bool compare(course c1)

// };

int main()
{
    Course ramesh("ramesh", "CSF111", 3, 1, 1);
    Professor prof("ramesh", "x1");
    cout << ramesh.getCourseTitle() << ramesh.sameCourse(ramesh) <<endl;
    cout << prof.getProfName() << prof.getProfCat() << endl;
  return 0;
}
