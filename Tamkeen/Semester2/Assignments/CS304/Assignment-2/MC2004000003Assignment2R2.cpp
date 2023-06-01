
#include<iostream>
#include<math.h>
#include<cstdlib>
#include<string>

using namespace std;


//////////////////////////////////////////////////
/////////////// Person Class  ////////////////////
//////////////////////////////////////////////////
class Person
{
  private :
          
    string FirstName;    
    string LastName;
    int PersonalID ;      
    double Salary ;
    double WorkingHours ;
    double CostPerHour ; 
      
  public :  
              
    void setFieldName();
    void getFieldName();
    void setFirstName();
    void setFamilyName();
    void set_PersonalID();
    void setWorkingHour();
    void setCostPerHour();
    void confirmFieldName();

};
                                    

//////////////////////////////////////////////////
/////// Human Resource Management Class  /////////
//////////////////////////////////////////////////
class HRM
{
  private :               
    Person e[100] ;      
    Person temp[100]; 
  public : 
    void AddPerson();
    void DeletePerson();
    void SearchPerson();
    void UpdatePerson();
    void ReportList();

};

////global variables declared for class HRM
int n=0,i=0,x=8248001,y[100];
bool flag=0;
int  z[100];
string h[100];
double sal[100];
int check=0;


/////////////////////////////////////////////////////////////////////
// Add an employee

void ::HRM::AddPerson() {
       
  int x;
  char repeate;
         
  do
  {
    n++;
    e[i].setFieldName();
    i++;
                
    cout<<"\nThe employee with the following information has been added to the system:"<<endl;
    cout<<"\nFirst Name       Last Name       Personal ID         Salary per year (Rupees)"; 
    cout<<"\n--------------   --------------  ------------       -------------------------"<<endl; 
  
    for(int i=0; i<n; i++){      
      e[i].getFieldName();
    }  
                                 
    cout<<"Do you wont to add another employee(y/n): "<<endl;  
    cin>>repeate;
  }
  while((repeate=='y'||repeate=='Y'));
        
}
        
        
        
/////////////////////////////////////////////////////////////////////
//  Delete an Employee
        
void HRM::DeletePerson() {
  //      Show all of the current employees
  //      Ask the user the ID of which employee that they wish to
  //      delete.
          
  int empId;
  bool lol;
  char repeate1,repeate2;
  lol =false;
  start:
  cout << "ID of Employee to remove: ";
        
  while(!(cin>>empId))  //Reciving vaiables from input : is it no/character ?
  {
    cout << "Please  enter a number!  Try again: ";
    cin.clear ();   
    cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                                            // whichever comes first.
  }
  for ( i = 0; i < n; ++i) {
    if (y[i]==empId) {     
      e[i]=e[i+1];
      lol=true;
      e[i].confirmFieldName();
      cin>>repeate2;
      if(repeate2=='Y'||repeate2=='y'){
        int a;
        a=n;                           
        cout<<"\nThe employee with the following information has been added to the system:"<<endl;
        cout<<"\nFirst Name       Last Name       Personal ID         Salary per year (Rupees)"; 
        cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
        for(int i=0; i<a; i++){       
          e[i].getFieldName();
          //cout<<"hahahahah="<<n<<endl;
          a--;
          n=a;
          n++;
        } 
        ///      goto start1;
      }                        
      cout <<endl;   
      //Delete function
    }            
  }         
  if (lol==false) {
    cout<<"Sorry, there is not any employee with requested personal number."
    <<" Do you want to repeat delete by entering the new personal number (y/n)? ";
    cin>>repeate1;
    if(repeate1=='Y'||repeate1=='y'){
      goto start;
      cout<<endl<<endl;
    }
  }
  //      Delete the chosen employee from the array of employees
  //      as represented in this class. 
  // Actually remove the entry from memory so as to not leak objects
  //nextIndex--;      
}

/////////////////////////////////////////////////////////////////////
//    Update an Employee
/////////////////////////////////////////////////////////////////////
void HRM::UpdatePerson(){
     
  int empId;
  char repeate1,repeate2;
        
  start:
  cout << "ID of employee to modify data: ";
    
  while(!(cin>>empId))  //Reciving vaiables from input : is it no/character ?
  {
    cout << "Please  enter a number!  Try again: ";
    cin.clear ();   
    cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                      // whichever comes first.
  }     
  int flag1=0;
  for (int i = 0; i < n; ++i) {          
    if (y[i]!=empId) {    
      flag1++;   
    }
  } 
  /*  if (flag1==n){  
  // cout<<" not     matching="<< y[i];
  cout<<"Sorry, there is not any employee with requested personal number. Do you want to repeat delete by entering the new personal number (y/n)?:";
  cin>>repeate1;
  if(repeate1=='Y'||repeate1=='y'){
  goto start;
  }
  } */         
  cout <<endl;   
  start1:
  for (int i = 0; i < n; ++i) {              
    if (y[i]==empId) {
      cout<<"Matching: "<< y[i];                 
      flag=true;
      int choice = 0;
      char repeate;
       
      do {
        cout << endl << endl;
        cout << "Please enter the related number of field which you would like to update" << endl;
        cout <<"1. First name" << endl;
        cout << "2. Family name" << endl;
        cout << "3. Working hours per week" << endl;
        cout << "4. Payment for one hour" << endl;
        cout << std::endl;

        cin >> choice;
        if (choice == 1) {
          cout << " First name: ";
          e[i].setFirstName();
        }
        else if (choice == 2) {
          cout << " Family name: ";
          e[i].setFamilyName();
        }
        else if (choice == 3) {
          cout << " Working hours per week: ";
          e[i].setWorkingHour();
        }
        else if (choice == 4) {
          cout << " Payment for one hour: ";
          e[i].setCostPerHour();
        }
        cout<<"Do you want to update another field (Y/N)? ";
        cin>>repeate;
      } while (repeate=='y'||repeate=='Y');
    }
  }
  int a;
  a=n;
  cout<<"\nThe employee with the following information has been updated to the system:"<<endl;
  cout<<"\nFirst Name       Last Name       Personal ID         Salary per year (Rupees)"; 
  cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
  for(int i=0; i<a; i++){
    e[i].getFieldName();
        
    //cout<<"hahahahah="<<n<<endl;
    
  } 
}


/////////////////////////////////////////////////////////////////////

void ::Person::setFirstName()
{
  cin>>FirstName ;
}
/////////////////////////////////////////////////////////////////////
void::Person::setFamilyName()
{
  cin>>LastName;
}
/////////////////////////////////////////////////////////////////////
void::Person::setWorkingHour()
{
  cin>>WorkingHours;
  Salary=WorkingHours*CostPerHour*52;
}
/////////////////////////////////////////////////////////////////////
void::Person::setCostPerHour()
{
  cin>>CostPerHour;
  Salary=WorkingHours*CostPerHour*52;
}

/////////////////////////////////////////////////////////////////////
void HRM::ReportList() {
     
 char op;
 bool doMore;
 cout<<"\nPlease enter the related number of the field which you would like to sort the list based on it.\n(1. Family name, 2.Salary)?\n "<<endl;                       
 //cin>>op;
while(!(cin>>op))  //Reciving vaiables from input : is it no/character ?
{
  cout << "Please  enter a number!  Try again: ";
  cin.clear ();   
  cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                            // whichever comes first.
}   
switch(op)
{
  case '1':
    cout<<"\nSorting based on Family Name. \n"<<endl;
    for(int i=0;i<=n;i++)
    {
      for(int j=i+1;j<=n-1;j++)      
      {  
        if(h[i]>h[i+1])
        {
          temp[i]=e[i];                       
          e[i]=e[j];
          e[j]=temp[i];
        }
      }
    }
    for(int i=0;i<n;i++)
    {
      e[i].getFieldName();
    }
    cout<<"\nsorted! \n";                   
    break;
  case'2':
    cout<<"\nSorting based on Salary. \n"<<endl;
    for(int h=0;h<n;h++)
    {
      for(int q=h+1;q<n;q++)    
      {     
        if(sal[h]>sal[h+1]);
        {
          temp[h]=e[h];                       
          e[h]=e[q];
          e[q]=temp[h];
        }
      }
    }
    for(int j=0;j<n;j++)
    {
      e[j].getFieldName();
    }
    cout<<"\nSortedlist is printed above. \n";                  
    break;        
  }
}
      
      

/////////////////////////////////////////////////////////////////////
void HRM::SearchPerson(){
  int c;
  char repeate1;
  string fname;
  double min,max;
  do{  
    cout<<"Search is based on two different fields (1. Family Name, 2. Salary), please enter your choice? "<<endl;
    //cin>>c;
    while(!(cin>>c))  //Reciving vaiables from input : is it no/character ?
    {
      cout << "Please  enter a number!  Try again: ";
      cin.clear ();   
      cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                                // whichever comes first.
    }  
    if(c==2) 
    {
      cout<<"Please define your search range for salary of employees ."<<endl;
      cout<<"What is minimum salary for search (S_min)? "<<endl;
      //cin>>min;
      while(!(cin>>min))  //Reciving vaiables from input : is it no/character ?
      {
        cout << "Please  enter a number!  Try again: ";
        cin.clear ();   
        cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                                  // whichever comes first.
      }
      cout<<"What is maximum salary for search (S_max)? "<<endl; 
      //cin>>max;
      while(!(cin>>max))  //Reciving vaiables from input : is it no/character ?
      {
        cout << "Please  enter a number!  Try again: ";
        cin.clear ();   
        cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                                  // whichever comes first.
      }
      int a;
      a=n;
      cout<<"\nThe employee with the following information has been added to the system:"<<endl;
      cout<<"\nFirst Name       Last Name       Personal ID         Salary per year (Rupees)"; 
      cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
      for(int i=0; i<n; i++) {                
        if (z[i]>min && z[i]<max) {                       
          cout<<"naaaaaaaaaaaam"<< n<<endl;   
          e[i].getFieldName();             
          cout<<"matching: "<< z[i];           
        }
      }        
    }  
    else if(c==1)
    {
      cout<<"Please enter the family name of employee? "<<endl;
      cin>>fname;
      cout<<"\nThe employee with the following information has been added to the system:"<<endl;
      cout<<"\nFirst Name       Last Name       Personal ID         Salary per year (Rupees)"; 
      cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
      for(int i=0; i<n; i++) {            
        if (h[i]==fname) {                      
          cout<<"naaaaaaaaaaaam"<< n<<endl;   
          e[i].getFieldName();             
          cout<<"matching: "<< z[i];           
        }
      }
    }
     
    cout<<"\nDo you want to Search any other field (y/n)? \n"<<endl;
    cin>>repeate1;
  }while(repeate1=='y'||repeate1=='Y');   
}
     
/////////////////////////////////////////////////////////////////////
void::Person ::getFieldName(){              
  cout<<FirstName<<"\t\t"<<LastName<<"\t\t\t"<<PersonalID<<"\t\t\t"<<Salary<<"\t"<<endl;
}

/////////////////////////////////////////////////////////////////////
void::Person ::confirmFieldName(){    
  cout<<"Do you really want to delete employee "<<FirstName<<" "<< LastName<< " (y/n)? ";   //PersonalID=y[i];
}
                              
                              
int k=0;      
/////////////////////////////////////////////////////////////////////
void::Person ::setFieldName(){
  PersonalID=x;
  x++;
  cout<<n;
  cout<<"\nFirst Name: ";
         
  while(!(cin>>FirstName))  //Reciving vaiables from input : is it no/character ?
  {
    cout << "Please  enter a string!  Try again: ";
    cin.clear ();   
    cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                  // whichever comes first.
  }
  cout<<"Last Name: ";
        
  while(!(cin>>LastName))  //Reciving vaiables from input : is it no/character ?
  {
    cout << "Please  enter a string!  Try again: ";
    cin.clear ();   
    cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                                  // whichever comes first.
  }
         
  cout<<"How many hours a week is his/her work? ";
  ;
  while(!(cin>>WorkingHours))  //Reciving vaiables from input : is it no/character ?
  {
    cout << "Please  enter a number!  Try again: ";
    cin.clear ();   
    cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                                  // whichever comes first.
  }
  cout<<"How much per hour is his/her salary? ";
      
  while(!(cin>>CostPerHour))  //Reciving vaiables from input : is it no/character ?
  {
    cout << "Please  enter a number!  Try again: ";
    cin.clear ();   
    cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                            // whichever comes first.
  }
           
  Salary=WorkingHours*CostPerHour*52;
  z[i]= Salary;
  sal[i]=Salary;
  h[i]=LastName;
  y[k]=PersonalID;

  k++;
}




/////////////////////////////////////////////////////////////////////
int main()
{
  //-------defining variables and initializing them-------------    
  HRM info ;
    
  int c;
  char operation,ch;
  //--------Printing my name on screen----------------    
  cout<<        "Welcome to the  HRM written by TAMKEEN SAJJAD"<<endl;
  cout<<"**************************************************************************"<<endl;
  cout<<endl<<endl<<endl;
  do
  {
                   
    cout<<"Welcome to Human Resource Management (HRM) Software of Company XYZ.";
    cout<<"To perform specific task please choose one of the following commands!"<<endl<<endl<<endl;
    cout<<"    1. Add new Employee"<<endl;
    cout<<"    2. Delete Employee information"<<endl;
    cout<<"    3. Update Employee information"<<endl;
    cout<<"    4. Make Sorting based on specific field"<<endl;
    cout<<"    5. Search Employee"<<endl;
    cout<<"    6. Quit"<<endl<<endl;
    
    
    while(!(cin>>c))  //Reciving vaiables from input : is it no/character ?
    {
      cout << "Please  enter a number!  Try again: ";
      cin.clear ();   
      cin.ignore (1000, '\n');  // Skip to next newline or 1000 chars,
                                  // whichever comes first.
    }
    switch(c)
    {
      case 1:
        cout<<"\nEnter the Information of the new Employee: "<<endl;
        info.AddPerson(); 
        break;
      case 2: 
        cout<<"\nEnter an Item to delete: ";
        info.DeletePerson();
        break;
      case 3:
        cout<<"\nEnter an Item to update: ";    
        info.UpdatePerson();
        break;
      case 4:
        cout<<"\nEnter an Element to sort: ";
        info.ReportList();
        break;
      case 5:
        cout<<"\nEnter an Element to Search: ";
        info.SearchPerson();
        break;
      default :
        cout<<"\nInvalid option try again: ";  
    }
    cout<<"\nDo you Want to Continue(y/n)? ";
    cin>>ch;
  }
  while(ch=='y'||ch=='Y');
  system("pause");
  return 0;
}
