#include<iostream>
#include<conio.h>
using namespace std;
class CustomerNode { 
private:
	//customer information
	string customerName;
	int customerId;
	int groceryItems;
	CustomerNode* next;  //next customer node
public:
	void setcustomerName(string name){
		customerName = name;
	}
	string getcustomerName(){
		return customerName;
	}
	void setcustomerId(int id){
		customerId = id;
	}
	int getcustomerId(){
		return customerId;
	}
	void setgroceryItems(int items){
		groceryItems = items;
	}
	int getgroceryItems(){
		return groceryItems;
	}
	void setcustomerNode(CustomerNode* customerNode){
		next = customerNode;
	}
	CustomerNode* getcustomerNode(){
		return next;
	} 
}; 
class CustomerQueue {  //Customer Queue class to handle express and normal queues
    
	CustomerNode *front, *rear;
	int expressCount,normalCount; // express and normal queue customers counter variables
	public:
    CustomerQueue() //constructor
    { 
        front = rear = NULL;
        expressCount = normalCount = 0;        
    } 
    void addCustomer(string name, int id, int no_of_items) //enqueue method
    {
        CustomerNode* temp = new CustomerNode;
		temp->setcustomerId(id);
		temp->setcustomerName(name);
		temp->setgroceryItems(no_of_items); 
		temp->setcustomerNode(NULL);
        if (rear == NULL) {  //here if condition is used to check whether first node of queue is created or not
            front = rear = temp;         
        } 
        else {
        //code if queue already contains nodes
        rear->setcustomerNode(temp); 
        rear = temp;
    }
        // check for items count if the no of items is above 5 then normal
        // queue counter will be incremented and message will be displayed that
        //customer has been entered in normal queue else express queue counter will
        // incremented and express queue customer entrance message will be printed
            if(no_of_items>5){    
            normalCount++;
            cout<<"----------Customer Entered in Normal Queue -------------------"<<endl;
            cout<<"Total customers in Normal Queue = "<<normalCount<<endl;
        }
        else{
        	expressCount++;
            cout<<"----------Customer Entered in Express Queue -------------------"<<endl;
            cout<<"Total customers in Express Queue = "<<expressCount<<endl;
		}
	}  
    void removeCustomer() //dequeue method
    { 
        if (front == NULL) 
            return; 
        CustomerNode* temp = front; 
        front = front->getcustomerNode(); 
        if (front == NULL) 
            rear = NULL; 
        //customer information display statements first the customer information will be displayed and then node 
        //will be deleted
        cout<<"Customer Name = "<<temp->getcustomerName()<<endl;
        cout<<"Customer ID = "<<temp->getcustomerId()<<endl;
        cout<<"Number of Grocery Items Purchased = "<<temp->getgroceryItems()<<endl;
        	if(temp->getgroceryItems()>5){
            normalCount--;
            cout<<"Total customers in Normal Queue = "<<normalCount<<endl<<endl;
			}
            else{
            expressCount--;
            cout<<"Total customers in Express Queue = "<<expressCount<<endl<<endl;
			}
        delete (temp); 
    } 
    int isEmpty() {
			return ( front == NULL );
		}
};
int main(){
	string name;
	int id,itemsQuanity;
	CustomerQueue expressCustomer; //variable for handling express queue
	CustomerQueue normalCustomer;  // variable for handling normal queue
	char choice;
    do{
    	cout<<"-------------Enter Customer Information-------------"<<endl;
		cout<<"Customer ID = ";
		cin>>id;
		cout<<"Customer Name = ";
		cin>>name;
		cout<<"Grocery Items Purchased = ";
		cin>>itemsQuanity;
		if(itemsQuanity<5){
			expressCustomer.addCustomer(name,id,itemsQuanity);
		}
		else{
			normalCustomer.addCustomer(name,id,itemsQuanity);
		}
		cout<<endl;	
		cout<<"Do want to enter another Customer? input y or Y for Yes and n or N for No: ";
		cin>>choice;
	}while(choice == 'y' || choice == 'Y');
    //display and remove all the customers one by one of both queues
    cout<<"-------Normal Queue Customers information----"<<endl;
    while(!normalCustomer.isEmpty()){
    normalCustomer.removeCustomer();   	
   }
	cout<<"-------Express Queue Customers information----"<<endl;
	while(!expressCustomer.isEmpty()){
	expressCustomer.removeCustomer();   	
	}
	return 0;
}
