#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;
void stringToUpper(char *str);
int main()
{
	char str[80];
	char str1[10]={'s','a','j','j','a','d','\0'};
	strcpy(str, "this is a test");
	cout << str  << endl;
	stringToUpper(str);
	cout << str << endl;
	
	cout << str1 << endl;
	stringToUpper(str1);
	cout << str1 << endl;
	
	return 0; 
}
void stringToUpper(char *str)
{
	while(*str) {
	*str = toupper(*str); // one character
	str++; /* move on to next char */ 
	}
}
