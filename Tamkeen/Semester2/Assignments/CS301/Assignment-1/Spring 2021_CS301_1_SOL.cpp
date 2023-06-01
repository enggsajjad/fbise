#include <iostream>
#include <stdlib.h>
using namespace std;

// global function to display code and names of courses
void displayCoursesList(){
	cout<<"\n1. Introduction to Computing\n"; 
	cout<<"2. Introduction to Programming\n";
	cout<<"3. Data Structures\n";
	cout<<"4. Object Oriented Programming\n";
}

/* The Student or Node class */
class Student {
    private:
       string name;
	   short int course;              
       Student *nextStudent;
       
    public:
        // constructor of Student class to initialize data members of class   
        Student(){
            name = "";            
            course = 0;          
            nextStudent = NULL;
        } 
          
        // destructor of Student class this place is used to release memory allocated dynamically
        ~Student(){
        
        }
            
        // Student class method to set name of student
        void setName(string val){
             name = val;
        };
        
        //Student class method to get name of student
        string getName(){
             return name;
        }; 
        
        // Student class method to set course code
        void setCourse(short int val){
             course = val;
        };
        
        //Student class method to get course code
        short int getCourse(){
             return course;
        }; 
                                
         //Student class method to point the nextStudent pointer to next Student
         void setNext(Student *nextStudent) { 
             this->nextStudent   =   nextStudent; 
         };
         
         // Student class method to get or read memory address where nextStudent pointer is pointing
         Student *getNext() { 
             return   nextStudent; 
         };        
};


/* The List class */
class List {
    
    private:
        int      	size;
        Student *   headStudent;
        Student *   currentStudent;
        Student *   lastCurrentStudent;
    
    public:
        // constructor of list class to initialize data members of class
        List() {
            size   				= 0;
            headStudent			= new Student();
            headStudent->setNext(NULL);
            currentStudent   	= NULL;
            lastCurrentStudent  = NULL;            
        }                
        
        // list class method to add a student into list
        void   add () {
            Student *newStudent = new Student();
            short int loc_course = 0;
            string loc_name = "";		
            
            cout<<"Enter the name of Student: ";
            cin>>loc_name;
            newStudent->setName(loc_name);
            
            displayCoursesList();
            
            cout<<"Enter the course code: ";            
            cin>>loc_course;
            while(loc_course < 1 || loc_course > 5){
            	cout<<"Code is not correct, please enter again: ";            
            	cin>>loc_course;            
        	}
            newStudent->setCourse(loc_course);                              
           
            if( currentStudent != NULL) {
               newStudent->setNext(currentStudent->getNext());
               currentStudent->setNext( newStudent );
               lastCurrentStudent   =   currentStudent;
               currentStudent   =   newStudent;
            } 
			else {
               newStudent->setNext(NULL);
               headStudent->setNext(newStudent);
               lastCurrentStudent   =   headStudent;
               currentStudent   =   newStudent;
            }
            size ++;
        };        
               
        // list class method to move lastcurrentStudent and currentStudent pointers to next Student
        bool   next() {
            if (currentStudent  ==  NULL){
                return  false;
            }
            
            lastCurrentStudent  =  currentStudent;
            currentStudent  	=  currentStudent->getNext();
            
            if (currentStudent == NULL || size == 0) {
                return  false;
            } else {
                return  true;
            }
        };        
        
        friend List addStudents();
		friend void displayStudent(List, int);
};

// friend method of list class used to add students into list 
// this function have access to all public / private data members and methods of list class 
List addStudents(){
	List   list;	
	char more = '\0';
    
	do{
		list.add();
        cout<<"Student's information saved successfully.\n";
		
		cout<<"\nDo you want to add another student? ";
    	cin>>more;
	}while(more == 'y' || more == 'Y');		
    
    return  list;
};

// friend method of list class used to traverse the list and 
// display number of students in a course and their names
// this function have access to all public / private data members and methods of list class
void displayStudent(List list, int choice){
    Student* savedCurrentStudent  =  list.currentStudent;
    list.currentStudent  =  list.headStudent;
    int counter = 0;
    
    if(list.size > 0){
    	if(choice == 0)
    		cout<<"\nFollowing students are enrolled in all courses."<<endl;
		else if(choice == 1)
    		cout<<"\nFollowing students are enrolled in Introduction to Computing course."<<endl;
    	else if(choice == 2)
    		cout<<"\nFollowing students are enrolled in Introduction to Programming course."<<endl;
    	else if(choice == 3)
    		cout<<"\nFollowing students are enrolled in Data Structures course."<<endl;
    	else if(choice == 4)
    		cout<<"\nFollowing students are enrolled in Object Oriented Programming course."<<endl;	
	}
    
    for(int i = 1; list.next(); i++)
    {
        if (list.currentStudent  !=  NULL)
		if(choice == 0) {
			cout<<"Student Name: "<<list.currentStudent->getName()<<"\n";
			counter++;
		}
		else if(choice == 1 && list.currentStudent->getCourse() == choice) {
			cout<<"Student Name: "<<list.currentStudent->getName()<<"\n";
			counter++;
		}
		else if(choice == 2 && list.currentStudent->getCourse() == choice) {
			cout<<"Student Name: "<<list.currentStudent->getName()<<"\n";
			counter++;
		}
		
		else if(choice == 3 && list.currentStudent->getCourse() == choice) {
			cout<<"Student Name: "<<list.currentStudent->getName()<<"\n";
			counter++;
		}
		
		else if(choice == 4 && list.currentStudent->getCourse() == choice) {
			cout<<"Student Name: "<<list.currentStudent->getName()<<"\n";
			counter++;
		}	             
    }
    cout<<"Enrollment Count: "<<counter<<endl;
    list.currentStudent  =  savedCurrentStudent;
};
    
main() {
	
    List list = addStudents(); 
    int choice = 0;
    
    repeat:   
 
	cout<<"\n0. Display all students\n";
	cout<<"1. Display all Students enrolled in Introduction to Computing\n"; 
	cout<<"2. Display all Students enrolled in Introduction to Programming\n";
	cout<<"3. Display all Students enrolled in Data Structures\n";
	cout<<"4. Display all Students enrolled in Object Oriented Programming\n";
	cout<<"5. Close the program\n\n";
	
   cout<<"Select an option for required operation: ";
   cin>>choice;
   
   while(choice < 0 || choice > 5){
   		cout<<"Selected choice is incorrect, please select again: ";            
        cin>>choice;   
	}
	
	if(choice == 0){
		displayStudent(list, 0);
	}
	else if(choice == 1) {
		displayStudent(list, 1);
	}
	else if(choice == 2) {
		displayStudent(list, 2);
	}
	else if(choice == 3) {
		displayStudent(list, 3);
	}
	else if(choice == 4) {
		displayStudent(list, 4);
	}			
	else if(choice == 5){
		exit(0);
	}          
    
	goto repeat;    
    system("pause");
}

