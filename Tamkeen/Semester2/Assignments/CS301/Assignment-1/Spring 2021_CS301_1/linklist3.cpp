#include<iostream>
#include <string>

using namespace std;

struct node
{
	int courseID;
    string studentName;
	node *next;	
};

class list
{
		private:
		node *head, *tail;
		public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
		void createnode(int value, string name)
		{
			node *temp=new node;
			temp->courseID=value;
            temp->studentName=name;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<"("<<temp->courseID<<","<<temp->studentName<<")\t";
				temp=temp->next;
			}
            cout<<"\n";
		}
        void displayWithCourseID(int id)
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				if(temp->courseID == id)
                {
                    cout<<"("<<temp->courseID<<","<<temp->studentName<<")\t";
                }
                temp=temp->next;
			}
            cout<<"\n";
		}
		void insert_start(int value, string name)
		{
			node *temp=new node;
			temp->courseID=value;
            temp->studentName=name;
			temp->next=head;
			head=temp;
		}

		void insert_position(int pos, int value, string name)
		{
			node *pre=new node;
			node *cur=new node;
			node *temp=new node;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			temp->courseID=value;
            temp->studentName=name;
			pre->next=temp;	
			temp->next=cur;
		}

		void delete_first()
		{
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delete_last()
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			while(current->next!=NULL)
			{
				previous=current;
				current=current->next;	
			}
			tail=previous;
			previous->next=NULL;
			delete current;
		}
		void delete_position(int pos)
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
};
int main()
{
    list obj;
	string n;
    char opt;
    int cID;

    cout<<"Enter the name of the Student: ";
    cin>>n;
    cout<<"1. Introduction to Computing "<<endl;
    cout<<"2. Introduction to Programming "<<endl;
    cout<<"3. Data Structures "<<endl;
    cout<<"4. Object Oriented Programming "<<endl;
    cout<<"Enter the course code: ";
    cin>>cID;
    obj.createnode(cID,n);
    cout<<"Student's information saved sesseccfully!"<<endl;
    
    cout<<"Do you want to add another student? ";
    cin>>opt;

    while(opt=='y')
    {
        cout<<"Enter the name of the Student: ";
        cin>>n;
        cout<<"1. Introduction to Computing "<<endl;
        cout<<"2. Introduction to Programming "<<endl;
        cout<<"3. Data Structures "<<endl;
        cout<<"4. Object Oriented Programming "<<endl;
        cout<<"Enter the course code: ";
        cin>>cID;
        obj.createnode(cID,n);
        cout<<"Student's information saved sesseccfully!"<<endl;
        
        cout<<"Do you want to add another student? ";
        cin>>opt;
    }

    cout<<"0. Display all students enrolled"<<endl;
    cout<<"1. Display all students enrolled in Introduction to Computing "<<endl;
    cout<<"2. Display all students enrolled in Introduction to Programming "<<endl;
    cout<<"3. Display all students enrolled in Data Structures "<<endl;
    cout<<"4. Display all students enrolled in Object Oriented Programming "<<endl;
    cout<<"5. Close the program"<<endl;

    cout<<"Select an option for required operation: ";
    cin>>opt;

    do
    {
        switch(opt)
        {
            case '0':
                cout<<"Displaying all students enrolled"<<endl;
                cout<<"\n--------------------------------------------------\n";
                cout<<"---------------Displaying All nodes---------------";
                cout<<"\n--------------------------------------------------\n";
                obj.display();
            break;

            case '1':
                cout<<"Displaying all students enrolled in Introduction to Computing "<<endl;
                cout<<"\n--------------------------------------------------\n";
                cout<<"---------------Displaying All nodes---------------";
                cout<<"\n--------------------------------------------------\n";
                obj.displayWithCourseID(1);
            break;

            case '2':
                cout<<"Displaying all students enrolled in Introduction to Programming "<<endl;
                cout<<"\n--------------------------------------------------\n";
                cout<<"---------------Displaying All nodes---------------";
                cout<<"\n--------------------------------------------------\n";
                obj.displayWithCourseID(2);
            break;

            case '3':
                cout<<"Displaying all students enrolled in Data Structures "<<endl;
                cout<<"\n--------------------------------------------------\n";
                cout<<"---------------Displaying All nodes---------------";
                cout<<"\n--------------------------------------------------\n";
                obj.displayWithCourseID(3);
            break;

            case '4':
                cout<<"Displaying all students enrolled in Object Oriented Programming "<<endl;
                cout<<"\n--------------------------------------------------\n";
                cout<<"---------------Displaying All nodes---------------";
                cout<<"\n--------------------------------------------------\n";
                obj.displayWithCourseID(4);
            break;
            case '5':

            break;
        }
        cout<<"Select an option for required operation: ";
        cin>>opt;
    }while(opt!='5');

    cout<<"Closing the program"<<endl;

    /*list obj;
	obj.createnode(25,"Sajjad");
	obj.createnode(50,"Tamkeen");
	obj.createnode(90,"Tahir");
	obj.createnode(40,"Zainab");
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode(55,"Hussain");
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50,"Ashique");
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,60,"Bhatti");
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
    */
	system("pause");
	return 0;
}