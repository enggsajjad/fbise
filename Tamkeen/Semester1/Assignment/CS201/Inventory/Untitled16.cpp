#include <iostream>      // <iostream> is standard, <iostream.h> is not
#include <cstring>        //   need functions to work with C strings

using namespace std;
class Dummy{
char Name[256];

public:    // for main() to use a member function, it must be public
void setName(char *nam)       // arrays are passed to function as pointers
    {strcpy(Name, nam);
    cout << "set name is:" << Name <<endl;
	}   // and char arrays are copied using string functions like strcpy()

char getName()
{
return *Name;
}
char* getName1()
{
	
return Name;

}
};

int main(){
char temp[256];           //   the declaration char [256] temp is invalid
cout << "Name?\n" <<endl;
cin >>  temp;
Dummy some_object;   //  non-static member functions act on objects
some_object.setName(temp);  // this is how non-static member functions act on objects
cout << "get name is:" << some_object.getName() <<endl;
cout << "get name is:" << some_object.getName1() <<endl;
}
