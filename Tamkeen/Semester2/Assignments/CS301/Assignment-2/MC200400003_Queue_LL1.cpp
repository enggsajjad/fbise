#include<iostream>
#include <string>

using namespace std;

///////////////////////////
// Customer Node
///////////////////////////
class Node {
  public:
    int cID;
    string cName;
    int cItem; // value
  	Node * next;

      ///////////////////////////
    //Constructor default
    Node() 
    {
        cID = 0;
        cName = "";
        cItem = 0;
        next = NULL;
    }
  
    ///////////////////////////
    //Constructor
    Node(int k, string n, int d) {
        cID = k;
        cName = n;
        cItem = d;
        next = NULL;
    }
};

///////////////////////////
//Customer Queue
///////////////////////////
class Queue 
{
  public:
  	Node *front;
  	Node *rear;
  	
    ///////////////////////////
    Queue() 
	{
        front = NULL;
        rear = NULL;
    }
    
    ///////////////////////////
    bool isEmpty()
    {
    	if(front==NULL && rear==NULL)
    	{
    		return true;
		}
		else
		{
			return false;
		}
	}
	
    ///////////////////////////
	bool checkIfNodeExist(Node *n)
	{
	 	Node *temp = front;
	 	bool exist=false;
	 	while(temp!=NULL)
	 	{
	 		if(temp->cID==n->cID)
        	{
          exist=true;
          break;
      	}
      	temp=temp->next;
		}
		return exist;
	}
	
    ///////////////////////////
    void addCustomer(Node *n)
    {
        enQueue(n);
    }

    ///////////////////////////
    void enQueue(Node *n) 
    {
        if (isEmpty())
        {
            front = n;
            rear = n;
            cout<<"Customer Node  ENQUEUED successfully"<<endl;
        }
        else if(checkIfNodeExist(n))
        {
            cout<<"Customer Node already exist with this ID value." 
            <<"Enter different ID value"<<endl;
        }
        else
        {
            rear->next=n;
            rear=n;
            //top = n;
            cout<<"Customer Node  ENQUEUED successfully"<<endl;
        }
    }
	
    ///////////////////////////
    Node* removeCustomer() 
    {
        return(deQueue());
    }

    ///////////////////////////
	Node* deQueue() 
    {
        Node *temp=NULL;
        if (isEmpty()) 
        {
            cout << "Queue is Empty" << endl;
            return NULL;
        } 
        else 
        {
            if(front==rear)
            {
            temp=front;
            front = NULL;
            rear = NULL;  
            return temp;
            }
            else
            {
            temp=front;
            front = front->next;  
            return temp;
            }
       }
    }
	 
    ///////////////////////////
	int countQueue() 
    {
      int count=0;
      Node *temp=front;
      while(temp!=NULL)
      {
        count++;
        temp=temp->next;
    	}
     return count;
    }
	
    ///////////////////////////
	void displayQueue() 
    {
      if(isEmpty())
      {
        cout << "Queue is Empty" << endl;
      }
    else
    {
      cout << "All values in the Queue are :" << endl;
        Node *temp=front;
        while(temp!=NULL)
        {
          cout<<"("<<temp->cID<<","<<temp->cName<<","<<temp->cItem<<")"<<" -> ";
          temp=temp->next;
      	}
      cout<<endl;
    }
    
    }
	 
  	
};

///////////////////////////
//Main Application
///////////////////////////
int main() {
  Queue nq;//normal Queue
  Queue eq;//express Queue
  Queue q;//temp Queue
  int option,cID, cItem;
  string cName;
 
  do {
    cout << "\n\nWhat operation do you want to perform?"<<"Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue() into Customer Queue" << endl;
    cout << "2. Dequeue() from Customer Queue" << endl;
    cout << "3. IsEmpty() Customer Queue check?" << endl;
    cout << "4. Count() Customer Queue" << endl;
    cout << "5. Display() Customer Queue" << endl;
    cout << "6. Clear Screen" << endl << endl;
    cin >> option;
 	 
	  //Node n1 = new Node();
	 Node * new_node = new Node();
	 
    
    switch (option) 
    {
    case 0:
      break;
    case 1:
    	cout << "ENQUEUE Function Called -" <<endl;
        cout << "Enter Customer ID to ENQUEUE in the Queue"	<<endl;
        cin >> cID;
        cout << "Enter Customer Name to ENQUEUE in the Queue"	<<endl;
        cin >> cName;
        cout << "Enter Grocery items to ENQUEUE in the Queue"	<<endl;
        cin >> cItem;
        new_node->cID = cID;
        new_node->cName = cName;
        new_node->cItem = cItem;
        if (cItem>5)
        {
            nq.enQueue(new_node);
            cout << "Customer added into normal customer Queue!"	<<endl;
        }
        else
        {
            eq.enQueue(new_node);
            cout << "Customer added into express customer Queue!"	<<endl;
        }
        break;
    case 2:
      cout << "DEQUEUE Function Called - " <<endl;
      cout << "DEQUEUE Normal Queue - " <<endl;
      
      new_node = nq.deQueue();
      if (new_node != NULL)
      cout<<"Dequeued Customer is: ("<<new_node->cID<<","<<new_node->cName<<","<<new_node->cItem<<")";
      cout << "DEQUEUE Express Queue - " <<endl;
      
      new_node = eq.deQueue();
      if (new_node != NULL)
      cout<<"Dequeued Customer is: ("<<new_node->cID<<","<<new_node->cName<<","<<new_node->cItem<<")";
      delete new_node;
      cout<<endl;
      
      break;
    case 3:
    	cout << "isEmpty Function Called - " << endl;
        if (nq.isEmpty())
            cout << "Normal Queue is Empty" << endl;
        else
            cout << "Normal Queue is NOT Empty" << endl;
        if (eq.isEmpty())
            cout << "Express Queue is Empty" << endl;
        else
            cout << "Express Queue is NOT Empty" << endl;
      break;
    case 4:
    	cout << "Count Function Called - " << endl;
        cout << "No of nodes in the Normal Queue: " <<nq.countQueue()<<endl;
        cout << "No of nodes in the Express Queue: " <<eq.countQueue()<<endl;
      break;
    case 5:
        cout << "Display Function Called - " << endl;
        cout << "Displayig node as: (id,name,items) " << endl;
        cout << "- - - - - - " << endl;
        cout << "Normal Queue - " << endl;
        nq.displayQueue();
        cout << "- - - - - - " << endl;
        cout << "Express Queue - " << endl;
        eq.displayQueue();
        cout << endl;
        break;
    
    case 6:
        system("cls");
        break;
    default:
        cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}