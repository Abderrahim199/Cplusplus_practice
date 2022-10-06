#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int student_id=1,professor_id = 1;
class Person {
protected:
    char name[100];
    int age;
public:

    virtual void getdata(){};
    virtual void putdata(){};
};
class Professor : public Person {
    int publications;
    int cur_id;

public:
    Professor(){
        this->cur_id=professor_id;
    }
    void getdata(){
        cin >> name;
        cin >> age;
        cin >> publications;
        professor_id++;
    }
    void putdata(){
        cout << name << " " << age << " " << publications <<  " " <<cur_id << endl;

    }

};
class Student : public Person {
    int marks[6];
    int cur_id;
    int sum_marks=0;
public:
    Student(){
        this->cur_id=student_id;
    }
    void getdata(){
        student_id++;
        cin >> name;
        cin >> age;
        for (int i =0;i< 6;i++){
            cin >> marks[i];
            sum_marks +=marks[i];
        }
    }
    void putdata(){
        cout << name << " " << age << " " << sum_marks <<  " " << cur_id<< endl;

    }
};


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

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