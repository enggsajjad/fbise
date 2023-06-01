#include <iostream>
#include <string>
  
using namespace std;

  int main()
  {
      int employee = 10;
	  int salary[10] = {125000,125000,80000,80000,80000,45000,45000,45000,45000,45000};
	  int monthlyTax[10] = {0,0,0,0,0,0,0,0,0,0};
	  int welfare = 600;
	  for (int i=0;i<10;i++)
	  {
	  	if ((salary[i]*12)>600000)
	  	monthlyTax[i] = salary[i]/100;
	  }
	  
	  int totalWelfare = welfare * employee;
	  int totalMonthlyTax = (monthlyTax[0]+monthlyTax[1]+monthlyTax[2]+monthlyTax[3]+monthlyTax[4]+monthlyTax[5]+monthlyTax[6]+monthlyTax[7]+monthlyTax[8]+monthlyTax[9]);

      cout << "Total Monthly Tax deduction of all employees:" << totalMonthlyTax<< endl;
      cout << "Total amount of welfare fund collected each month from all employees:" << totalWelfare<< endl;
      cout << "Net monthly salary of an employee A:" << salary[0]-monthlyTax[0]-welfare<< endl;
      cout << "Net monthly salary of an employee B:" << salary[2]-monthlyTax[2]-welfare<< endl;
      cout << "Net monthly salary of an employee C:" << salary[9]-monthlyTax[9]-welfare<< endl;
      
      cout << "Total amount which organization pays to its employees each month." << 2*(salary[0]-monthlyTax[0]-welfare) + 3*(salary[2]-monthlyTax[2]-welfare)+5*(salary[9]-monthlyTax[9]-welfare)<< endl;
      
	  
      cout << "Enter 1 to knwo the tax collection of Level A Employees"<< endl;
      cout << "Enter 2 to knwo the tax collection of Level B Employees"<< endl;
      cout << "Enter 3 to knwo the tax collection of Level C Employees"<< endl;
	  
	  int x;
	  cout << "Enter a number: ";
	  cin >> x;

      
	  if (x==1)
	  cout << "tax collection of Level A Employees in Rs."<< monthlyTax[0]*2<< endl;
	  else if (x==2)
	  cout << "tax collection of Level B Employees in Rs."<< monthlyTax[2]*3<< endl;
	  else if (x==3)
	  cout << "tax collection of Level C Employees in Rs."<< monthlyTax[9]*5<< endl;
	  else
	  cout << "Invalid Option"<< endl;
	  system("PAUSE");
      return 0;
  }
