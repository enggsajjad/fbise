#include <iostream>
#include <iomanip>

#define MAX_REC 10
//using namespace std;
class Inventory{
    char itemName[15];
    int code;
    double cost;
    public:
    void getdata();
    void showdata();
};

void Inventory :: getdata(){
    cout<<"\nEnter Item Name : ";
    cin>>itemName;
    cout<<"Enter Code : ";
    cin>>code;
    cout<<"Enter Cost : ";
    cin>>cost;
}

void Inventory :: showdata(){
    cout<<endl;
    cout.width(15);
    cout.setf(ios::left, ios::adjustfield);
    cout<<itemName;

    cout.width(8);
    cout<<code;

    cout.width(15);
    cout.setf(ios::right, ios::adjustfield);
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout<<cost;
}

int main(){
    Inventory record[MAX_REC];
    int i,n;

    cout<<"\n=====Inventory Management=====\n";
    cout<<"\nHow many Records to be created : ";
    cin>>n;

    cout<<"Enter "<<n<<" Records\n";
    for(i=0;i<n;i++)
        record[i].getdata();

    cout<<"\n\n---Stock Information---\n";
    cout<<"\n"<<setw(8)<<"Item Name"
        <<setw(10)<<"Code"
        <<setw(19)<<"Cost"<<endl;
    cout<<"-------------------------------------------";

    for(i=0;i<n;i++)
        record[i].showdata();

    return 0;
}
