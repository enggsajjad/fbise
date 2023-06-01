#include <iostream>
#include <string>
  
using namespace std;

//Function Prototypes
void showElements();
void percentageBiden(int state);
void percentageTrump(int state);
void percentageJorgensen(int state);

//void PercentageTrump(int state);
//void PercentageJorgensen(int state);

//Global Variables
string StateName[3]={"Florida","Georgia","Michigan"};

long  votes[3][4] = { 	{5284453,	5658847,	70046,	11013346}, 
						{2465781,	2455428,	61894,	4983103}, 
						{2790648,	2644525,	60287,	5495460}};
/*
State Code	Joe Biden Votes	Donald Trump Votes	Jo Jorgensen Votes	Total Votes
1			5,284,453		5,658,847				70,046			11,013,346
2			2,465,781		2,455,428				61,894			4,983,103
3			2,790,648		2,644,525				60,287			5,495,460
*/





  int main()
  {
      int currentState=0;
	  cout << "Assignment No.2 by Tamkeen Sajjad\n\n" << endl;
	  while (currentState!=4)
	  {
		  
		  showElements();
		  cout << "Press the state code to calculate percentage of Trum, Biden, and Jorgensen votes:\n" << endl;
	      cout << "Press 1 for Florida." << endl;
	      cout << "Press 2 for Georgia." << endl;
	      cout << "Press 3 for Michigan." << endl;
	      cout << "Press 4 for Exit\n" << endl;
	
		  
		  cout << "Please select an option, use numbers from 1 to 4:";
		  cin >> currentState;
		  cout << "-----------------------------------------------------" << endl;;
		  
		  switch(currentState)
		  {
		  	case 1:
		  		cout << "In the State: " << StateName[currentState-1] <<endl;
		  		percentageBiden(0);
		  		percentageTrump(0);
		  		percentageJorgensen(0);
		  		break;
		  	case 2:
		  		cout << "In the State: " << StateName[currentState-1] <<endl;
		  		percentageBiden(1);
		  		percentageTrump(1);
		  		percentageJorgensen(1);
		  		break;
		  	case 3:
		  		cout << "In the State: " << StateName[currentState-1] <<endl;
		  		percentageBiden(2);
		  		percentageTrump(2);
		  		percentageJorgensen(2);
		  		break;
		  	case 4:
		  		cout << "Exiting..." <<endl;
		  		break;
		  	default:
		  		cout << "Invalid choice, re-enter!" <<endl;
		  		break;
		  }
		cout  << "\n"<< endl;
	  }
      system("PAUSE");
      return 0;
  }
  
void showElements()
{
	cout << "Source Data:" << endl;
	cout << "State Code	Joe Biden Votes	Donald Trump Votes	Jo Jorgensen Votes	Total Votes" << endl;
	for (int i=0;i<3;i++)
	{
		cout << i+1 << "\t\t" << votes[i][0]  << "\t\t" << votes[i][1]  << "\t\t\t" <<votes[i][2]  << "\t\t" <<votes[i][3]  << endl;
	}
	cout  << "\n"<< endl;
}

void percentageBiden(int state)
{
	double percetage = votes[state][0];
	percetage = percetage/votes[state][3]*100;
	cout << "Percentage of Jo Biden votes is. " << percetage << endl;
}
void percentageTrump(int state)
{
	double percetage = votes[state][1];
	percetage = percetage/votes[state][3]*100;
	cout << "Percentage of Donald Trump votes is. " << percetage << endl;
}
void percentageJorgensen(int state)
{
	double percetage = votes[state][2];
	percetage = percetage/votes[state][3]*100;
	cout << "Percentage of Jo Jorgensen votes is. " << percetage << endl;
}
