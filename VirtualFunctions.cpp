#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
public:
    string name;
    int age;
    static int numProf;
    static int numStud;
    virtual void getdata(){}
    virtual void putdata(){}
    
};
int Person::numProf = 0;
int Person::numStud = 0;

class Professor : public Person{
    public:
    int publications;
    int cur_id;
    Professor(){
        numProf++;
        cur_id = numProf;
    }
    void getdata(){
        cin>>name;
        cin>>age;
        cin>>publications;
    }
    void putdata(){
        cout << name << " " << age << " " << publications << " "
        << cur_id << endl;
    }
};

class Student : public Person{
    public:
    int marks[6];
    int cur_id;
    Student(){
        numStud++;
        cur_id = numStud;
    }
    void getdata(){
        cin>>name;
        cin>>age;
        for(int i = 0 ; i < 6 ; i++){
            cin>>marks[i];
        }
    }
    void putdata(){
        int sum = 0;
        for(int i = 0 ; i < 6 ; i++){
            sum = sum + marks[i];
        }
        cout << name << " " << age << " " 
             << sum << " " << cur_id << endl;
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
