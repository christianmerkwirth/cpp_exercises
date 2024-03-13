#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>


using namespace std;


// This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. 
// The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.

// The class Professor should have two integer members: publications and cur_id. There will be two member functions: 
// getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor.
// The function putdata should print the name, age, publications and the cur_id of the professor.

// The class Student should have two data members: marks, which is an array of size  and cur_id. It has two member 
// functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and 
// the marks of the student in  subjects. The function putdata should print the name, age, sum of the marks and the cur_id
// of the student.
// For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from .
// Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.
// Note: Expand the main function to look at how the input is being handled.
// Input Format
// The first line of input contains the number of objects that are being created. If the first line of input for each object is , it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.
// If the first line of input for each object is , it means that the object is of the Student class, you will have to input the name, age and the marks of the student in  subjects.
// Constraints
// , where  is the length of the name.
// , where marks is the marks of the student in each subject.
// Output Format
// There are two types of output depending on the object.
// If the object is of type Professor, print the space separated name, age, publications and id on a new line.
// If the object is of the Student class, print the space separated name, age, the sum of the marks in  subjects and id on a new line.
// Sample Input

//#define VERBOSE

// The class Person should have data members name and age. The classes Professor and Student
// should inherit from this class Person.
struct Person {
    std::string name;
    uint16_t age;
    uint32_t id;

    Person() {};

    virtual ~Person() {
        #ifdef VERBOSE
        std::cout << "Person destructor" << std::endl;
        #endif
    };

    virtual void getdata() {}
    virtual void putdata() {
        std::cout << name << " " << age << " ";
    }
};


// The class Student should have two data members: marks, which is an
// array of size  and cur_id. It has two member functions: getdata and
// putdata. The function getdata should get the input from the user: the
// name, age, and the marks of the student in  subjects. The function
// putdata should print the name, age, sum of the marks and the cur_id of
// the student.
struct Student : Person {
    static uint32_t cur_id;
    std::vector<uint16_t> marks;

    Student() {
        id = cur_id++;
    }
    virtual ~Student() {
        #ifdef VERBOSE
        std::cout << "Student destructor" << std::endl;
        #endif
    };

    virtual void getdata() override {
        cin >> name;
        cin >> age;
        for (int i=0; i < 6; i++) {
            uint16_t this_mark;
            cin >> this_mark;
            marks.push_back(this_mark);
        }

    }
    virtual void putdata() override {
        Person::putdata();
        std::cout << accumulate(marks.begin(), marks.end(), 0) << " " << id << endl;
    }
};

// The class Professor should have two integer members: publications and
// cur_id. There will be two member functions: getdata and putdata. The
// function getdata should get the input from the user: the name, age and
// publications of the professor. The function putdata should print the
// name, age, publications and the cur_id of the professor.
struct Professor : Person {
    uint32_t publications;
    static uint32_t cur_id;

    Professor() {
        id = cur_id++;
    }
    virtual ~Professor() {
        #ifdef VERBOSE
        std::cout << "Professor destructor" << std::endl;
        #endif
    };

    virtual void getdata() override {
        cin >> name;
        cin >> age;
        cin >> publications;
    }
    virtual void putdata() override {
        Person::putdata();
        std::cout << publications << " " << id << endl;
    }
};

uint32_t Professor::cur_id = 1;
uint32_t Student::cur_id = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    vector<Person*> per(n);

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}