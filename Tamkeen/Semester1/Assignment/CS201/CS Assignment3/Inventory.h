#include <cstring>
class Inventory
{
private:
    int iid;
    char name[20];
	float quantity;
	int location;
    float price;
    float totalPrice;
    
public:
    Inventory()     // declare the Inventory object using the default constructor
    {
        iid = 0;
        quantity = 0;
        price = 0;
        totalPrice = 0;
        location = 0;
        name[0] = '\0';
    }
    Inventory(int newItemNumber, char* newItemName, float newQuantity, float newCost,int newloc) 
    {
    	setName(newItemName);
		setId(newItemNumber);
        setQuantity(newQuantity);
        setPrice(newCost);
        setLocation(newloc);
        setTotalPrice(newQuantity, newCost);
    }
    
    void setName(char* nam)
    {
        strcpy(name, nam);
    }
    void setId(int id)   
    {
        iid = id;
    }
    void setQuantity(float q)	
    {
        quantity = q;
    }
    void setPrice(float p)  
    {
        price = p;
    }
    void setLocation(int loc)  
    {
        location = loc;
    }
    void setTotalPrice(int q, float p)
    {
        totalPrice = q * p;
    }
    
    int getId()
    {
        return iid;
    }
    char* getName()
	{
		
	return name;
	
	}
    int getLocation()
    {
        return location;
    }
    float getQuantity()
    {
        return quantity;
    }
    float getPrice()
    {
        return price;
    }
    float getTotalPrice()
    {
        return totalPrice;
    }


};

