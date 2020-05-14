#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Specialization{
    string name;
    explicit Specialization(string new_name){
        name = new_name;
    }
};
struct Course{
    string name1;
    explicit Course(string new_name1){
        name1 = new_name1;
    }
};
struct Week{
    string name2;
    explicit Week(string new_name2){
        name2 = new_name2;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization specialization1, Course course1, Week week1){
    specialization=specialization1.name;
    course = course1.name1;
    week = week1.name2;
    }
};

int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );


return 0;
}
