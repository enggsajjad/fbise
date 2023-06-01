#include<iostream>
#include<math.h>
#include<cstdlib>
#include<string>
#include<limits>

using namespace std;

class Person
{
private:

    string FirstName;
    string LastName;
    int PersonalID; 
    double Salary;


public:

    void set_FirstName(string firstName);
    string get_FirstName();

    void set_LastName(string lastName);
    string get_LastName();

    void set_PersonalID(int personalID);
    int get_PersonalID();

    void set_Salary(double salary);
    double get_Salary();
};

void Person::set_FirstName(string firstName)
{
    FirstName = firstName;
}
void Person::set_LastName(string lastName)
{
    LastName = lastName;
}
void Person::set_PersonalID(int personalID)
{
    PersonalID = personalID;
}
void Person::set_Salary(double salary)
{
    Salary = salary;
}
string Person::get_FirstName()
{
    return FirstName;
}
string Person::get_LastName()
{
    return LastName;
}
int Person::get_PersonalID()
{
    return PersonalID;
}
double Person::get_Salary()
{
    return Salary;
}

class HRM
{
private:

    Person persons[10];
    int currentEmp;
    int const Size;
    int initialPersonalID;

public:
    HRM();
    bool AddPerson(Person *person);
    bool DeletePerson(int employeeID);
    bool UpdatePerson(Person* person);
    void ListPersons();
    Person* FindPerson(int personID);

};

bool HRM::DeletePerson(int employeeID)
{
    int index = -1;
    int i = -1;
    for (i = 0;i < currentEmp; i++)
    {
        if (persons[i].get_PersonalID() == employeeID)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        return false; // record not found
    }
    else
    {
        currentEmp--;
        for (i = index; i < currentEmp; i++)
        {
            persons[i].set_PersonalID(persons[i + 1].get_PersonalID());
            persons[i].set_FirstName(persons[i + 1].get_FirstName());
            persons[i].set_LastName(persons[i + 1].get_LastName());
            persons[i].set_Salary(persons[i + 1].get_Salary());
        }
        persons[i].set_PersonalID(-1);
        persons[i].set_FirstName("");
        persons[i].set_LastName("");
        persons[i].set_Salary(-1);

        return true;
    }

}

bool HRM::UpdatePerson(Person* person)
{
    Person* temp = NULL;
    bool isSaved = false;
    temp = this->FindPerson(person->get_PersonalID());
    if (temp != NULL)
    {
        temp->set_FirstName(person->get_FirstName());
        temp->set_LastName(person->get_LastName());
        temp->set_Salary(person->get_Salary());
        isSaved = true;
    }
    return isSaved;
}

Person* HRM::FindPerson(int personID)
{
    bool isFound = false;
    for (int i = 0;i < currentEmp; i++)
    {
        if (persons[i].get_PersonalID() == personID)
        {
            return &persons[i];
        }
    }
    return NULL;
}
bool HRM::AddPerson(Person *person)
{
    if (currentEmp == Size)
    {
        return false; // Limit of Maximum Employees 10 has reached
    }
    else
    {
        persons[currentEmp].set_PersonalID(initialPersonalID);
        initialPersonalID++;

        persons[currentEmp].set_FirstName(person->get_FirstName());
        persons[currentEmp].set_LastName(person->get_LastName());
        persons[currentEmp].set_Salary(person->get_Salary());
        currentEmp++;
        return true;
    }
}

void HRM::ListPersons() {
    cout << " First Name\t\tLast Name\t\tPersonal ID\t\tSalary per Year (Rupees)" << endl;
    cout << " ----------\t\t---------\t\t-----------\t\t------------------------  " << endl;

    for (int i = 0;i < currentEmp; i++)
    {
        cout << persons[i].get_FirstName() << "\t\t\t" << persons[i].get_LastName() << "\t\t\t" << persons[i].get_PersonalID() << "\t\t\t" << persons[i].get_Salary() << endl;

    }
}

HRM::HRM() : Size(10), currentEmp(0), initialPersonalID(8248001) {
    
}


string GetString();
double GetIDInput();
char GetConfirmation();
void GetPersonRecord(Person *person);
void UpdatePersonRecord(Person* person);


int main() {
    // variable definitions
    int ch; //to take user choice
    Person *person = NULL;
    Person *temp = NULL;
    HRM hrm;
    bool isSaved = false;
    int employeeID;
    char canContinue = 'n';
    cout << "Welcome Aboard..." << endl;
    cout << "**************************************************************************" << endl;
    cout << endl << endl << endl;
    cout << "Welcome to Human Resource Management (HRM) Software of Company XYZ.";
    cout << "To do specific task please choose one of the following commands." << endl << endl << endl;

    do
    {
        // Menue

        cout << "    1. Add new employee" << endl;
        cout << "    2. Delete employee information" << endl;
        cout << "    3. Update employee information" << endl;
        cout << "    4. Quit" << endl << endl;
        ch = GetIDInput();


        switch (ch)
        {
        case 1:
            canContinue = 'n';
            cout << "\nEnter the information of the new employee" << endl;
            do {
                person = new Person();
                GetPersonRecord(person);
                isSaved = hrm.AddPerson(person);
                if (isSaved)
                {
                    cout << "Record Added successfully" << endl;
                    hrm.ListPersons();
                }
                else
                {
                    cout << "Could not save the recoed, Limit reached" << endl;
                }
                // info.AddPerson();
                delete person;
                person = NULL;
                cout << "do u want to add another employee" << endl;
                canContinue = GetConfirmation();
            } while ((canContinue == 'y' || canContinue == 'Y'));
            break;
        case 2:
            
            canContinue = 'n';
            isSaved = false;
            do
            {
                cout << "ID of the employee to remove : ";
                employeeID = GetIDInput();
                cout << "Do you really want to delete employee (y/n): ";
                canContinue = GetConfirmation();

                if (canContinue == 'y' || canContinue == 'Y')
                {
                    isSaved = false;
                    isSaved = hrm.DeletePerson(employeeID);
                    if (isSaved)
                    {
                        cout << "The employee with the given id has been removed from the system:" << endl;
                        hrm.ListPersons();
                    }
                    else
                    {
                        cout << "Record not deleted. Either id not found or error occur" << endl;
                    }
                }
                cout << "do u want to continue" << endl;
                canContinue = GetConfirmation();

            } while ((canContinue == 'y' || canContinue == 'Y'));
            break;
        case 3:
            int employeeID;
            isSaved = false;
            cout << "Enter an ID of employee to modify data: ";
            employeeID = GetIDInput();
            temp = hrm.FindPerson(employeeID);
            if (temp != NULL)
            {
                person = new Person();
                person->set_PersonalID(temp->get_PersonalID());
                person->set_FirstName(temp->get_FirstName());
                person->set_LastName(temp->get_LastName());
                person->set_Salary(temp->get_Salary());

                UpdatePersonRecord(person);
                isSaved = hrm.UpdatePerson(person);
                delete person;
                person = NULL;
                if (isSaved)
                {
                    cout << "The employee information has been updated in the system : " << endl;
                    hrm.ListPersons();
                }
                else
                {
                    cout << "Couldnot update the Record" << endl;
                }

            }
            else
            {
                cout << "Record Not Found" << endl;
            }
            break;
        case 4:
            cout << "You requested to Quit the Application...." << endl;
            break;
        default:
            cout << endl << "Invalid option try again" << endl;

        }
    } while (ch!= 4);
    //system("pause");

}

string GetString()
{
    string input = "";
    bool valid = false;
    do
    {
        cout << flush;
        cin >> input;
        if (cin.good())
        {
            valid = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please  enter a string!  Try again: " << endl;
        }
    } while (!valid);

    return (input);
}

double GetIDInput()
{
    double input = -1;
    bool valid = false;
    do
    {
        cout << flush;
        cin >> input;
        if (cin.good())
        {
            valid = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please  enter a number!  Try again: "<<endl;
        }
    } while (!valid);

    return (input);
}

char GetConfirmation()
{
    char input;
    bool valid = false;
    do
    {
        cout << flush;
        cin >> input;
        if (cin.good())
        {
            if (input != 'y' && input != 'Y' && input != 'n' && input != 'N')
                cout << "Try again: " << endl<< "Please  enter a choice [y/Y/n/N]!  ";
            else
                valid = true;
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please  enter a string!  Try again: " << endl;
        }
    } while (!valid);

    return (input);
}
void UpdatePersonRecord(Person* person)
{
    int ch = 0;
    char isContinue = 'y';
    string inputString;
    double Salary;


    do
    {

        cout << "please enter the related number of field which you would like to update" << endl;
        cout << "1. First name" << endl;
        cout << "2. Family name" << endl;
        cout << "3. Monthly Salary" << endl << endl;

        cout << "Enter your choice...";
        ch = GetIDInput();
        
        switch (ch)
        {
            case 1:
                cout << "First Name=";
                inputString = GetString();
                person->set_FirstName(inputString);
                break;
            case 2:
                cout << "Family Name=";
                inputString = GetString();
                person->set_LastName(inputString);
                break;
            case 3:
                cout << "Salary : ";
                Salary = GetIDInput();
                person->set_Salary(Salary);
                break;
            default:
                break;
        }
        cout << "Do you want to update another field(Y / N) ";
        isContinue = GetConfirmation(); 
    } while (isContinue == 'y' || isContinue == 'Y');
}


void GetPersonRecord(Person *person)
{
    string FirstName;
    string LastName;
    double Salary;

    cout << "First Name=";
    FirstName = GetString();

    cout << "Last Name ";
    LastName = GetString();

    cout << "Salary ";
    Salary = GetIDInput();

    person->set_FirstName(FirstName);
    person->set_LastName(LastName);
    person->set_Salary(Salary);
}
