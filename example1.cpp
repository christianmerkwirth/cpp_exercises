#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using EMB_MAP=std::map<std::string, int64_t>;






// Note: Expand the main function to look at how the input is being handled.

// Input Format

// The first line of input contains the number of objects that are being
// created. If the first line of input for each object is , it means that
// the object being created is of the Professor class, you will have to
// input the name, age and publications of the professor.

// If the first line of input for each object is , it means that the
// object is of the Student class, you will have to input the name, age
// and the marks of the student in  subjects.

// Constraints

// , where  is the length of the name.
// , where marks is the marks of the student in each subject.

// Output Format

// There are two types of output depending on the object.

// If the object is of type Professor, print the space separated name,
// age, publications and id on a new line.

// If the object is of the Student class, print the space separated name,
// age, the sum of the marks in  subjects and id on a new line.

// Sample Input


struct Adder {
    uint32_t offset;
    Adder(uint32_t offset_=0) : offset(offset_) {}
    uint32_t operator()(const uint32_t a) { return a + offset;}
};


// The class Person should
// have data members name and age. The classes Professor and Student
// should inherit from the class Person.
struct Person {
    std::string name;
    uint16_t age;

    Person(const std::string& name_, const uint16_t age_) : name(name_), age(age_) {}

    virtual ~Person() {
        std::cout << "Person destructor" << std::endl;
    };

    virtual void getdata() {}
    virtual void putdata() {
        std::cout << name << " " << age;
    }
};


// The class Student should have two data members: marks, which is an
// array of size  and cur_id. It has two member functions: getdata and
// putdata. The function getdata should get the input from the user: the
// name, age, and the marks of the student in  subjects. The function
// putdata should print the name, age, sum of the marks and the cur_id of
// the student.
struct Student : Person {
    static uint32_t id;
    std::vector<uint16_t> marks;

    Student(const std::string& name_ = "", const uint16_t age_ = 0) : Person(name_, age_) {}
    virtual ~Student() {
        std::cout << "Student destructor" << std::endl;
    };

    virtual void getdata() {}
    virtual void putdata() {}
};

// The class Professor should have two integer members: publications and
// cur_id. There will be two member functions: getdata and putdata. The
// function getdata should get the input from the user: the name, age and
// publications of the professor. The function putdata should print the
// name, age, publications and the cur_id of the professor.
struct Professor : Person {
    uint32_t publications;
    static uint32_t id;

    Professor(const std::string& name_ = "", const uint16_t age_ = 0) : Person(name_, age_) {}
    virtual ~Professor() {
        std::cout << "Professor destructor" << std::endl;
    };

    virtual void getdata() {}
    virtual void putdata() {}
};


uint32_t Professor::id = 0;
uint32_t Student::id = 0;

int main()
{
    EMB_MAP embeddings;
    Adder add_functor(12);

    Professor professor;

    for (uint32_t i=0; i < 1000 * 1000; i++) {
        embeddings[std::to_string(i)] = add_functor(i);
    }

    for (uint32_t i = 0; const auto& [key, val] : embeddings) {
        std::cout << key << " : " << val << std::endl;
        if (i++ > 10)
            break;
    }
   
   return 0;

}
