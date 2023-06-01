#include "Inventory.h" //you don't need this because it's all one big file for this demo
#include <iostream>
#include <string>

#include <fstream>

using namespace std;

//Function Prototypes
void appendItemToFille();
void deleteItemFromFille();
void displayAll();
void searchItem();
void increaseQuanity();
void updateFileItemName();


//Main Program
int main()
{
	int f=10;
	
	//Test Inventory Class
	string s = "Flour";
    char char_array[20]={'a','b','b','\0'};
    strcpy(char_array, s.c_str());
    cout<<"*******************************************************************" << endl;
    cout<<"Test Inventory Class" << endl;
    cout<<"*******************************************************************" << endl;
    cout << "Create Inventory Instance (default) and display" << endl;
	Inventory a;
	a.setId(2);
	a.setPrice(4);
	a.setLocation(1);
	a.setQuantity(3);
	a.setTotalPrice(a.getQuantity(),a.getPrice());
	
	
    strcpy(char_array, s.c_str());
	a.setName(char_array);
	cout <<"ID "<< a.getId() << ", Name " << a.getName() << ", Quantity " << a.getQuantity() << ", Location " << a.getLocation() << ", Price " << a.getPrice() << ", Total Price " <<a.getTotalPrice() <<endl;
	cout << "\nCreate Inventory Instance (explicit) and display" << endl;
	s = "Bread";
	strcpy(char_array, s.c_str());
	Inventory b(3, char_array, 2, 5,6); 
	cout <<"ID "<< b.getId() << ", Name " << b.getName() << ", Quantity " << b.getQuantity() << ", Location " << b.getLocation() << ", Price " << b.getPrice() << ", Total Price " <<b.getTotalPrice() <<endl;
	cout << endl;
	cout<<"*******************************************************************" << endl;
	cout << endl;
	cout << endl;
	//Check if file exists
	ifstream ifile;
   	ifile.open("inventory.txt");
   	if(ifile) 
	{
    	cout<<"inventory file exists"<<endl;
    	ifile.close();
   	} else 
	{
      	cout<<"inventory file doesn't exist"<<endl;
      	ifile.close();
      	//create a new one
  		fstream f;
		f.open("inventory.txt",ios::out|ios::app);
		f<<"id"<<"|"<<"Name"<<"|"<<"Qty"<<"|"<<"Loc"<<"Price"<<"|"<<"Total"<<"\n";	
		f.close();
		cout<<"created!"<<endl;
   	}
   	cout<<"*******************************************************************" << endl;


	while(f)
	{
		switch(f)
		{
			case 10:
				cout<<"\t\t\t************************"<<endl;
				cout<<"\t\t\t* To Insert press-> (1)*"<<endl;
				cout<<"\t\t\t* To view --------> (2)*"<<endl;
				cout<<"\t\t\t* To search ------> (3)*"<<endl;
				cout<<"\t\t\t* To Delete ------> (4)*"<<endl;
				cout<<"\t\t\t* To Update Name--> (5)*"<<endl;
				cout<<"\t\t\t* To Update Qty---> (6)*"<<endl;
				cout<<"\t\t\t* To Remove file--> (7)*"<<endl;
				cout<<"\t\t\t* To Exit --------> (0)*"<<endl;
				cout<<"\t\t\t************************"<<endl;
				cout<<"Your Choise : ";
				cin>>f;
				break;
			case 1:
				appendItemToFille();
    			cout<<"Continue insert press-->(1) *** (0) to exit *** (10) to restart : "<<endl;
    			cin>>f;
				break;
			case 2:
				displayAll();
			    cout<<endl;
			    cout<<"To continue (2) *** To exit (0) *** (10) to restart : "<<endl;
			    cin>>f;
				break;
			case 3:
				searchItem();
				cout<<"To continue (3) *** To exit (0) *** (10) to restart : "<<endl;
	    		cin>>f;
				break;
			case 4:
				deleteItemFromFille();
				cout<<"To continue (4) *** To exit (0) *** (10) to restart : "<<endl;
    			cin>>f;
				break;
			case 5:
				updateFileItemName();
				cout<<"To continue (5) *** To exit (0) *** (10) to restart : "<<endl;
	    		cin>>f;
				break;
			case 6:
				increaseQuanity();
				cout<<"To continue (6) *** To exit (0) *** (10) to restart : "<<endl;
	    		cin>>f;
				break;
			case 7:
				remove("inventory.txt");
				cout<<"To continue (7) *** To exit (0) *** (10) to restart : "<<endl;
	    		cin>>f;
				break;
			default:
				f =0;
				break;
		}
	}
	return 0;
}

///////////////// Function Definitions ///////////////////////////////////

//Appending item in file
void appendItemToFille()
{
	cout<<"\t*******************************************************************" << endl;
	string idd;
	char buf[10];
	char included_id[5];
	int flag=0;
	Inventory d;
	
	cout<<"Enter Item ID : ";
	cin>>idd;

	flag=1;
	while(flag)
	{
  		ifstream file("inventory.txt");
		string str;
  		while (getline(file, str)) 
	  	{
		    string delimiter = "|";
			string token = str.substr(0, str.find(delimiter));
			flag=0;
			if (idd.compare(token) == 0)
			{
				flag=1;				
				break;
			}
		}

		if(flag==1)
		{
			cout<<"******************************************************************"<<endl;
			cout<<"This id already included by the file change id"<<endl;
			cout<<"******************************************************************"<<endl;
		
			cout<<"Enter Item ID : ";
			cin>>idd;
			file.close();
		}
	}

	cout<<endl<<"Enter Item Name : ";
	cin>>buf;
	d.setName(buf);
	cout<<endl<<"Enter Item Quantity : ";
	float tf;
	cin>>tf;
	d.setQuantity(tf);
	cout<<endl<<"Enter Item Price : ";
	cin>>tf;
	d.setPrice(tf);
	int ti;
	cout<<endl<<"Enter Item Location : ";
	cin>>ti;
	d.setLocation(ti);
	cout<<endl;
	d.setTotalPrice(d.getQuantity(),d.getPrice());
	fstream f;
	f.open("inventory.txt",ios::out|ios::app);
	f<<idd<<"|"<<d.getName()<<"|"<<d.getQuantity()<<"|"<<d.getLocation()<<"|"<<d.getPrice()<<"|"<<d.getTotalPrice()<<"\n";	
	
	f.close();
}

//Delete item from the file
void deleteItemFromFille()
{
	cout<<"\t*******************************************************************"<<endl;
	int way;
    string idd,name;
    int flag;
    cout<<"\t\t\t****************************"<<endl;
	cout<<"\t\t\t* delete by id press--->(1)*"<<endl;
	cout<<"\t\t\t* delete by name press->(2)*"<<endl;
	cout<<"\t\t\t****************************"<<endl;
	cout<<"Enter your choise : ";
	cin>>way;	 
 	if(way==1)
	{
    	cout<<"enter product id to delete : ";
 		cin>>idd;
	}
 	else  if(way==2)
	{
 		cout<<"enter product name to delete : ";
 		cin>>name;
	}
 	Inventory s;
	fstream myf;
	myf.open("Temp.txt",ios::out);//write
	 	
	ifstream file("inventory.txt");
	string str;
  	while (getline(file, str)) 
  	{
	    if (way==1)
		{
			cout << str << "\n";
		    string delimiter = "|";
			string token = str.substr(0, str.find(delimiter));
			if (idd.compare(token) == 0)
			{
				flag=1;
				cout<<"Found, record being deleted is: "<<endl;
				cout<<str<<"\n";
			}else
			{
				myf<<str<<"\n";
			}
		}else if (way==2)
		{
			cout << str << "\n";
		    string delimiter = "|";
		    int a = str.find(delimiter,0);
		    int b = str.find(delimiter,a+1);
			string token = str.substr(a+1, b-a-1);
			if (name.compare(token) == 0)
			{
				flag=1;
				cout<<"Found, record being deleted is: "<<endl;
				cout<<str<<"\n";
			}else
			{
				myf<<str<<"\n";
			}
		}
	}


	file.close();
	myf.close();
	remove("inventory.txt");
	rename("Temp.txt","inventory.txt");
	if(flag==0)
	{cout<<"Not found"<<endl;}

}
  		

//Displaying items
void displayAll()
{
	cout<<"\t*******************************************************************"<<endl;

	ifstream file("inventory.txt");
	string str;
  	while (getline(file, str)) 
  	{
	    cout << str << "\n";
	}
	file.close();
}
//Search an item
void searchItem()
{
	cout<<"\t*******************************************************************"<<endl;
	int way;
    string idd,name;
    int flag;
    cout<<"\t\t\t****************************"<<endl;
	cout<<"\t\t\t* search by id press--->(1)*"<<endl;
	cout<<"\t\t\t* search by name press->(2)*"<<endl;
	cout<<"\t\t\t****************************"<<endl;
	cout<<"Enter your choise : ";
	cin>>way;	 
 	if(way==1)
	{
	    cout<<"enter product id to search : ";
	 	cin>>idd;
	}
 	else if(way==2)
	{
 		cout<<"enter product name to search : ";
 		cin>>name;
	}
	
	ifstream file("inventory.txt");
	string str;
  	while (getline(file, str)) 
  	{
	    if (way==1)
		{
			//cout << str << "\n";
		    string delimiter = "|";
			string token = str.substr(0, str.find(delimiter));
			if (idd.compare(token) == 0)
			{
				cout<<"Found, searched record is "<<endl;
				flag=1;
				cout<<str<<"\n";
			}
		}else if (way==2)
		{
			//cout << str << "\n";
		    string delimiter = "|";
		    int a = str.find(delimiter,0);
		    int b = str.find(delimiter,a+1);
			string token = str.substr(a+1, b-a-1);
			if (name.compare(token) == 0)
			{
				cout<<"Found, searched record is "<<endl;
				flag=1;
				cout<<str<<"\n";
			}
		}
	}

    file.close();

	if(flag==0)
	{cout<<"Not found"<<endl;}

  
}

//Increasing Quantity of item
void increaseQuanity()
{
	cout<<"\t*******************************************************************"<<endl;
 	int flag;
 	string qty, qty1,idd;
 	int x;
 	cout<<"To Update Quanity press 1 :";
 	cin>>x;
    if(x==1)
	{
        cout<<"Enter the the Item ID to update Quantity : ";
        cin>>idd;
       	//cout<<"Enter the the Quanity : ";
       	//cin>>qty;
       	cout<<"Enter the new Quanity: ";
       	cin>>qty1;
    }
           
	fstream myf;
	myf.open("Temp.txt",ios::out);//write
	 	
	ifstream file("inventory.txt");
	string str;
  	while (getline(file, str)) 
  	{

			//cout << str << "\n";
		    string delimiter = "|";
			string token = str.substr(0, str.find(delimiter));
			int a = str.find(delimiter,0);
		    int b = str.find(delimiter,a+1);
		    int c = str.find(delimiter,b+1);
			if (idd.compare(token) == 0)
			{
		    	token = str.substr(b+1, c-b-1);
				cout<<"Found, record being updated is: "<<endl;
				cout<<str<<"\n";
				flag=1;
				str.replace(b+1, c-b-1,qty1);
			}
			
			myf<<str<<"\n";
	}


	file.close();
	myf.close();
	remove("inventory.txt");
	rename("Temp.txt","inventory.txt");
	if(flag==0)
	{cout<<"Not found"<<endl;}
 
}
//Update the item name in the file
void updateFileItemName()
{
	cout<<"\t*******************************************************************"<<endl;
 	int flag;
 	string name, name1;
 	int x;
 	cout<<"To Update Name press 1 :";
 	cin>>x;
   	if(x==1)
	{
	   	cout<<"Enter the the name : ";
	   	cin>>name;
	   	cout<<"Enter the new : ";
	   	cin>>name1;
   	}
           
 	fstream myf;
 	myf.open("Temp.txt",ios::out);//write

	ifstream file("inventory.txt");
	string str;
  	while (getline(file, str)) 
  	{
		//cout << str << "\n";
	    string delimiter = "|";
	    int a = str.find(delimiter,0);
	    int b = str.find(delimiter,a+1);
		string token = str.substr(a+1, b-a-1);

		if (name.compare(token) == 0)
		{
			flag=1;
			str.replace(a+1, b-a-1,name1);
			//cout<<"Found, record being updated is: "<<endl;
			//cout<<str<<"\n";
		}
		
		myf<<str<<"\n";
	}
	
	file.close();
	myf.close();
	remove("inventory.txt");
	rename("Temp.txt","inventory.txt");
	if(flag==0)
	{cout<<"Not found"<<endl;}
  
}


