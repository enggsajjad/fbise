#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    string name;
    name = "Sajjad Hussain";
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    cout << "Testing..."<<endl;
    cout << name << endl;
}