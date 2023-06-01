class Inventory
{
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;
public:
    Inventory()     // declare the Inventory object using the default constructor
    {
        itemNumber = 0;
        quantity = 0;
        cost = 0;
        totalCost = 0;
        
    }
    Inventory(int newItemNumber, int newQuantity, double newCost) 
    {
        itemNumber = newItemNumber;
        quantity = newQuantity;
        cost = newCost;
        setTotalCost(quantity, cost);
    }
    
    void setItemNumber(int)   
    {
        itemNumber = itemNumber;
    }
    void setQuantity(int)	
    {
        quantity = quantity;
    }
    void setCost(double)  
    {
        cost = cost;
    }
    void setTotalCost(int, double)
    {
        totalCost = quantity * cost;
    }
    
    int getItemNumber()
    {
        return itemNumber;
    }
    int getQuantity()
    {
        return quantity;
    }
    double getCost()
    {
        return cost;
    }
    double getTotalCost()
    {
        return totalCost;
    }
};

