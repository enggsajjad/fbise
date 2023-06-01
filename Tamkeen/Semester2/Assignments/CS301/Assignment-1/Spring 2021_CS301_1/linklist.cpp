#include<iostream>
#include<string>

using namespace std;

struct Student
{
    int id;
    string name;
    string courseCode;
    struct Student* next;
};


int main(void)
{
    int x;

    Student* previous = NULL;
    Student* start = NULL;

    printf("Enter a sequence of integers, letter to end: ");
    while(cin>>x)
    {
        Student* student = new Student;
        student->next = NULL;

        if (start == NULL)
            start = student;

        cout<<"Enter Student ID: ";
        cin>>student->id;
        cin.sync();
        cout<<endl<<"Enter Student Name: ";
        getline(cin, student->name);
        cin.sync();
        cout<<endl<<"Enter Course Code: ";
        getline(cin, student->courseCode);
        cin.sync();

        if (previous != NULL)
            previous->next = student;

        previous = student;
    }

    cout<<endl<<"In reverse order, the following details were entered: "<<endl;


    for(Student* p = start; p != NULL; p = p->next)
    {
        cout<<p->id<<endl;
        cout<<p->name<<endl;
        cout<<p->courseCode<<endl;
    }
}