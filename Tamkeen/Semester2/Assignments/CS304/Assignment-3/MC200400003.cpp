//NAME: TAMKEEN SAJJAD
//ID:         MC200400003
//Course: MIT
#include<iostream>
#include<string>
using namespace std;
class Employee
{
      private:
          string name;
          int age;
      public:
          Employee()
          {
               name = "xyz";
               age = 19;
          }
          setEmployee()
          {
               cout << "Enter the Employee Name: ";
               cin >> name;
               cout << "Enter the Employee Age: ";
               cin >> age;
          }
          string getEmployeeName()
          {
               return(name);
          }
          int getEmployeeAge()
          {
               return(age);
          }
          virtual void calculateSalary () = 0 ;
          virtual void Print() = 0 ;
};
//////////////////////////////////////////////////
///////  Salaried Person            //////////////
//////////////////////////////////////////////////
class salariedEmployee : public Employee
{
      private:
              double weeklySalary;
      public:
             void calculateSalary()
             {
                  cout << "Enter weekly rate of " << this->getEmployeeName() <<": ";
                  cin >> weeklySalary;
                  cout << endl;
             }
             void Print()
             {
                  cout << "\n---------------------------------" << endl;
                  cout << "Displaying Employee's Information" << endl;
                  cout << "---------------------------------" << endl;
                  cout << "Employee's Name: " << this->getEmployeeName() << endl;
                  cout << "Employee's Age: " << this->getEmployeeAge() << endl;
                  cout << "Employee's Salary: " << weeklySalary << endl;
             }
};
//////////////////////////////////////////////////
///////  Hourly Person            //////////////
//////////////////////////////////////////////////
class hourlyEmployee : public Employee
{
      private:
              double salary; 
              double hours;
              double wage; 
      public:
             void calculateSalary()
             {
                  cout << "Enter hours " << this->getEmployeeName() << " worked  " << ": ";
                  cin >> hours;
                  cout << "Enter hourly rate of " << this->getEmployeeName() << ": ";
                  cin >> wage;
                  cout << endl;

                  if (hours<=40)
                  {
                       salary = wage * hours;
                  }
                  else
                  {
                       salary = ((wage*40)) + ((hours-40)*wage*1.5);
                  }
             }
             void Print()
             {
               cout << "\n---------------------------------" << endl;
               cout << "Displaying Employee's Information" << endl;
               cout << "---------------------------------" << endl;
               cout << "Employee's Name: " << this->getEmployeeName() << endl;
               cout << "Employee's Age: " << this->getEmployeeAge() << endl;
               cout << "Employee's Salary: " << salary << endl;
             }
};


int main ()
{
    int T=1;
    char ch = 's';
    cout << "How many Employee's Data you want to enter: ";
    cin >> T;
    Employee *e[T];
    salariedEmployee s;
    hourlyEmployee h;

    for(int i=0;i<T;i++)
    {
         cout << "\nEnter your Choice, s=Weekly Salaried, h=houly Salaried: ";
         cin >> ch;
         if (ch=='s')
         {
              e[i]=&s;
         }
         else if (ch=='h')
         {
              e[i]=&h;
         }
          e[i]->setEmployee();
          e[i]->calculateSalary();
    }
    for(int i=0;i<T;i++)
    {
          e[i]->Print();
    }

    system("pause");
    return 0;
}


      


