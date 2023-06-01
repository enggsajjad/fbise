//Deleting existing file
void deleteExistingFile()
{
	
}

//Appending item in file
void appendItemToFille()
{
	cout<<"\t*******************************************************************"<<endl;
	char id[5];
	
	char included_id[5];
	int flag=0;
	Inventory d;
	
	
	fstream myfile;
	myfile.open("test.txt",ios::out|ios::app);
	cout<<endl;
	cout<<"Enter Prouduct ID : ";
	cin>>id;
	
	fstream myfile2;
	myfile2.open("test.txt",ios::in);
	while(!myfile2.eof())
	{
		myfile2.getline(included_id,4,'|');	
		myfile2.getline(d.itemName,4,'|');
		myfile2.getline(d.quantity,8,'|');
		myfile2.getline(d.itemPrice,11,'\n');
		myfile2.getline(d.itemLocation,11,'\n');;
		if(strcmp(id,included_id)==0)
		{
			flag=1;
	
			myfile2.close();
			break;
		} 

	}
	if(flag==1)
	{
		cout<<"******************************************************************"<<endl;
		cout<<"This id already included by the file change id"<<endl;
		cout<<"******************************************************************"<<endl;
	
		cout<<"Enter Prouduct ID : ";
		cin>>id;
		flag=0;
	}


	cout<<endl<<"Enter Prouduct Name : ";
	cin>>d.itemName;
	cout<<endl<<"Enter Prouduct Ammount : ";
	cin>>d.quantity;
	cout<<endl<<"Enter Prouduct Price : ";
	cin>>d.itemPrice;
	cout<<endl<<"Enter Prouduct Shelf : ";
	cin>>d.itemLocation;
	cout<<endl;
	myfile<<id<<"|"<<d.itemName<<"|"<<d.quantity<<"|"<<d.itemPrice<<"|"<<d.Prouduct_shelf<<"\n";	
	

	myfile.close();
}
void deleteItemFromFille(){
cout<<"\t*******************************************************************"<<endl;
	int way;
	int u=0;
	
	char name[20];
    char id[5];
	char ee[1];
    
    cout<<"\t\t\t****************************"<<endl;
	cout<<"\t\t\t* delete by id press--->(1)*"<<endl;
	cout<<"\t\t\t* delete by name press->(2)*"<<endl;
	cout<<"\t\t\t****************************"<<endl;
cout<<"Enter your choise : ";
	cin>>way;	 
	 	if(way==1){
        cout<<"enter product id to delete : ";
	 	cin>>id;
		 }
	 	else 
		 	if(way==2){
	 		cout<<"enter product name to delete : ";
	 	cin>>name;}
	 	Inventory s;
        fstream myfile;
	 	fstream mymyfile;
	 	myfile.open("test.txt",ios::in);//read
	 	mymyfile.open("Temp.txt",ios::out);//write

        while(!myfile.eof()){
		    myfile.getline(s.itemID,4,'|');	
			myfile.getline(s.itemName,5,'|');
	 		myfile.getline(s.quantity,9,'|');
	 		myfile.getline(s.itemPrice,12,'|');
	 		myfile.getline(s.itemLocation,12,'\n');
         	
		 	if(way==1&&strcmp(id,s.itemID	)!=0&&strcmp(ee,s.itemID	)!=0){{
         
		 	mymyfile<<s.itemID<<"|"<<s.itemName<<"|"<<s.quantity<<"|"<<s.itemPrice<<"|"<<s.itemLocation<<"\n";

		 } if(strcmp(id,s.itemID)==0){
			flag=1;
 		}}else
 		
		 	if(way==2&&strcmp(name,s.itemName	)!=0&&strcmp(ee,s.itemName	)!=0){{
         
		 	mymyfile<<s.itemID<<"|"<<s.itemName<<"|"<<s.quantity<<"|"<<s.itemPrice<<"|"<<s.itemLocation<<"\n";

		 } if(strcmp(name,s.itemName)==0){
			flag=1;
 		}}

        }
         myfile.close();
		 mymyfile.close();
         remove("test.txt");
         rename("Temp.txt","test.txt");
	 	 if(flag==0)
		  {cout<<"Not found"<<endl;}

  		}
  		
//Displaying items
void displayAll()
{
cout<<"\t*******************************************************************"<<endl;
 Inventory s;
fstream file1;
file1.open("test.txt",ios::in);

while(!file1.eof()){
file1.getline(s.itemID,4,'|');	
file1.getline(s.itemName,4,'|');
file1.getline(s.quantity,8,'|');
file1.getline(s.itemPrice,11,'|');
file1.getline(s.itemLocation,11,'\n');;


cout<<"ID:("<<s.itemID<<")=Prouduct name:("<<s.itemName<<")=Prouduct ammount:("<<s.quantity<<")=Prouduct Price:("<<s.itemPrice<<")=Prouduct shelf :("<<s.itemLocation<<")"<<endl;
}
file1.close();
}
//*****************************************************************************
void searchItem(){
	cout<<"\t*******************************************************************"<<endl;
	Inventory s;
	char ser[10];
	char ch[10];
	int choise;
	int found=0;
	cout<<"\t\t\t*************************"<<endl;
	cout<<"\t\t\t* To search by id--->(1)*"<<endl;
	cout<<"\t\t\t* To Search by name->(2)*"<<endl;
	cout<<"\t\t\t*************************"<<endl;
	cout<<"Enter your choise : ";
	cin>>choise;
	if(choise==1){
		cout<<"Enter the id : ";
		cin>>ch;
	} else if(choise==2){
		cout<<"Enter the name : ";
        cin>>ch;	
	}
	
	
	fstream myfile;
	myfile.open("test.txt",ios::in);
	while(!myfile.eof()){
		myfile.getline(s.itemID,4,'|');	
		myfile.getline(s.itemName,4,'|');
		myfile.getline(s.quantity,4,'|');
		myfile.getline(s.itemPrice,4,'|');
		myfile.getline(s.itemLocation,4,'\n');
		if(choise==1){
			if(strcmp(ch,s.itemID)==0){
				cout<<"Found and his record is "<<endl;
			cout<<s.itemID<<" "<<s.itemName<<" "<<s.quantity<<" "<<s.itemPrice<<" "<<s.itemLocation<<" "<<endl;
			found=1;
			}
		}
			else if(choise==2){
			if(strcmp(ch,s.itemName)==0 ){
			cout<<"Found and his record is "<<endl;
			cout<<s.itemID<<"|"<<s.itemName<<" "<<s.quantity<<" "<<s.itemPrice<<" "<<s.itemLocation<<" "<<endl;
			found=1;
		}}

	}if(found=0)
		cout<<"Record not found";
		myfile.close();
		cout<<endl;
		}

//Increasing Quantity of item
void increaseQuanity()
{
}

void updateFileItemName(){
cout<<"\t*******************************************************************"<<endl;
		 	int h=0;
			 Inventory s;
		 	char comp[10];
		 	char ch[10];
		 	int x;
		 	cout<<"To Update Name press 1 :";
		 	cin>>x;
           if(x==1){
           	cout<<"Enter the the name : ";
           	cin>>comp;
           	cout<<"Enter the new : ";
           	cin>>ch;
           }
		   fstream myfile , mymyfile ;
         myfile.open("Temp.txt",ios::out);//write
         mymyfile.open("test.txt",ios::in);//read
         while(!mymyfile.eof()){
           mymyfile.getline(s.itemID,4,'|');	
 	       mymyfile.getline(s.itemName,4,'|');
           mymyfile.getline(s.quantity,8,'|');
           mymyfile.getline(s.itemPrice,11,'|');
           mymyfile.getline(s.itemLocation,11,'\n');
       if(strcmp(comp,s.itemName)!=0){
       	myfile<<s.itemID<<"|"<<s.itemName<<"|"<<s.quantity<<"|"<<s.itemPrice<<"|"<<s.itemLocation<<"\n";
      
	   }
      else if(strcmp(comp,s.itemName)==0){
     h++;	
    char k;
    if(h>0){
    	cout<<"is that record you want to update"<<endl;
    	cout<<s.itemID<<"|"<<s.itemName<<"|"<<s.quantity<<"|"<<s.itemPrice<<"|"<<s.itemLocation<<"\n";
        
		cout<<" y-n";
		cin>>k;   
    }
 	if(k=='y'){
	 	
	 	myfile<<ch<<"|"<<s.quantity<<"|"<<s.itemPrice<<"|"<<s.itemLocation<<"\n";}  }

	 	}

      myfile.close();
	  mymyfile.close();
	  remove("test.txt");
         rename("Temp.txt","test.txt");
	  
 	}
