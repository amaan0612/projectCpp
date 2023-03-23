#include<iostream>
#include<string.h>
using namespace std;

char buyedProduct[18][20];
int productQuantity[18];
int count=0;
int total_bill = 0,grandTotal = 0, discount;
bool calculated = false;
//Products name
char productName[18][20]={"sugar","milk","vegetable masala","washing powder","salt","poha","oil","tooth paste",
"hair conditionar","red chilli","maida","coffee","tea","butter","milk powder","turmeric powder",
"hair oil","ghee"};
//Product price
int sugar_p = 50, milk_p = 50, vegetable_masala_p = 50, wahing_powder_p = 100, salt_p = 20, poha_p = 50, 
oil_p = 200, tooth_paste_p = 40, hair_conditionar_p = 120, red_chilli_p = 40,maida_p = 45,coffee_p = 200,
tea_p = 100, butter_p = 100, milk_powder_p = 150, turnmeric_powder_p = 200, hair_oil_p = 60, ghee_p = 300;

class Store{
    public:
    void buyProduct();
    void calculateBill();
    void showBill();
};

void Store::buyProduct(){
    char name[20];
    int quantity;
    char ch;
    cout<<"\nAvailable Product in our Store\n";
    for (int i = 0; i < 9; i++)
    {
        cout<<i+1<<"."<<productName[i]<<"  ";
    }
    cout<<endl;
    for (int i = 9; i < 18; i++)
    {
        cout<<i+1<<"."<<productName[i]<<"  ";
    }
    cout<<endl<<endl;
    
    again:
    cout<<"Enter product name: ";
    cin.getline(name,19);
    cin.sync();
    cout<<"Enter Quantity: ";
    cin>>quantity;
    cin.sync();
    for (int i = 0; i < 18; i++)
    {
        if (!strcmp(productName[i],name))
        {
            strcpy(buyedProduct[count],name);
            productQuantity[count]=quantity;
            count++;
            repeat:
            cout<<"\nIf you want to buy more product then press Y otherwise N: ";
            cin>>ch;
            cin.sync();
            if (ch=='Y'||ch=='y')
            {
                goto again;
            }else if (ch=='N'||ch=='n')
            {
                return;
            }else{
                cout<<"\nInvalid Press try again\n";
                goto repeat;
            }                       
        }        
    }
    cout<<"\nProduct is not available try again\n";
    goto again;
}

void Store::calculateBill(){
    char choose;
    char temp[20];
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(buyedProduct[i],"sugar"))
        {
            total_bill += sugar_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"milk"))
        {
            total_bill += milk_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"vegetable masala"))
        {
            total_bill += vegetable_masala_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"washing powder"))
        {
            total_bill += wahing_powder_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"salt"))
        {
            total_bill += salt_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"poha"))
        {
            total_bill += poha_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"oil"))
        {
            total_bill += oil_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"tooth paste"))
        {
            total_bill += tooth_paste_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"hair conditionar"))
        {
            total_bill += hair_conditionar_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"red chilli"))
        {
            total_bill += red_chilli_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"maida"))
        {
            total_bill += maida_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"coffee"))
        {
            total_bill += coffee_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"tea"))
        {
            total_bill += tea_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"butter"))
        {
            total_bill += butter_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"milk powder"))
        {
            total_bill += milk_powder_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"turmeric powder"))
        {
            total_bill += turnmeric_powder_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"hair oil"))
        {
            total_bill += hair_oil_p * productQuantity[i];
        }
        else if (!strcmp(buyedProduct[i],"ghee"))
        {
            total_bill += ghee_p * productQuantity[i];
        }
    }
    if (total_bill >= 15000)
    {
        discount = (15 * total_bill) / 100;
        grandTotal = total_bill - discount;
        calculated = true;
        cout<<"\nBill is calculated successfully\n";
        return;
    }
    else if (total_bill >= 10000 && total_bill < 15000)
    {
        discount = (10 * total_bill) / 100;
        grandTotal = total_bill - discount;
        calculated = true;
        cout<<"\nBill is calculated successfully\n";
        return;
    }
    else if (total_bill >= 5000 && total_bill < 10000)
    {
        discount = (5 * total_bill) / 100;
        grandTotal = total_bill - discount;
        calculated = true;
        cout<<"\nBill is calculated successfully\n";
        return;
    }
    discount = 0;
    grandTotal = total_bill;
    calculated = true;
    cout<<"\nBill is calculated successfully\n";
}

void Store::showBill(){
    if (!calculated)
    {
        cout<<"\nBill is not calculated\n";
        return;
    }    
    cout<<"\n\t           **** AKSHAY GROCERY STORE BILL ****\n";
    cout<<" ---------------------------------------------------------------------\n";
    cout<<"|  Product\t\tQuantity\t\tPrice\t    Total    |\n";
    cout<<"|---------------------------------------------------------------------\n";
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(buyedProduct[i],"sugar"))
        {
            cout<<"|   sugar\t\t  "<<productQuantity[i]<<" kg\t\t         "<<sugar_p<<"\t     "
            <<(sugar_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"milk"))
        {
            cout<<"|   milk\t\t  "<<productQuantity[i]<<" pac\t\t         "<<milk_p<<"\t     "
            <<(milk_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"vegetable masala"))
        {
            cout<<"| vegetable masala\t  "<<productQuantity[i]<<" pac\t\t         "<<vegetable_masala_p
            <<"\t     "<<(vegetable_masala_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"washing powder"))
        {
            cout<<"| washing powder\t  "<<productQuantity[i]<<" kg\t\t         "<<wahing_powder_p<<"\t     "
            <<(wahing_powder_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"salt"))
        {
            cout<<"|   salt\t\t  "<<productQuantity[i]<<" pac\t\t         "<<salt_p<<"\t     "
            <<(salt_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"poha"))
        {
            cout<<"|   poha\t\t  "<<productQuantity[i]<<" kg\t\t         "<<poha_p<<"\t     "
            <<(poha_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"oil"))
        {
            cout<<"|   oil\t\t          "<<productQuantity[i]<<" ltr\t\t         "<<oil_p<<"\t     "
            <<(oil_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"tooth paste"))
        {
            cout<<"|  tooth paste\t\t  "<<productQuantity[i]<<" pac\t\t         "<<tooth_paste_p<<"\t     "
            <<(tooth_paste_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"hair conditionar"))
        {
            cout<<"| hair conditionar\t  "<<productQuantity[i]<<" pac\t\t         "<<hair_conditionar_p
            <<"\t     "<<(hair_conditionar_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"red chilli"))
        {
            cout<<"|  red chilli\t\t  "<<productQuantity[i]<<" pac\t\t         "<<red_chilli_p<<"\t     "
            <<(red_chilli_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"maida"))
        {
            cout<<"|   maida\t\t  "<<productQuantity[i]<<" kg\t\t         "<<maida_p<<"\t     "
            <<(maida_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"coffee"))
        {
            cout<<"|   coffee\t\t  "<<productQuantity[i]<<" pac\t\t         "<<coffee_p<<"\t     "
            <<(coffee_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"tea"))
        {
            cout<<"|   tea\t\t          "<<productQuantity[i]<<" pac\t\t         "<<tea_p<<"\t     "
            <<(tea_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"butter"))
        {
            cout<<"|   butter\t\t  "<<productQuantity[i]<<" pac\t\t         "<<butter_p<<"\t     "
            <<(butter_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"milk powder"))
        {
            cout<<"|  milk powder\t\t  "<<productQuantity[i]<<" pac\t\t         "<<milk_powder_p<<"\t     "
            <<(milk_powder_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"turmeric powder"))
        {
            cout<<"| turmeric powder\t  "<<productQuantity[i]<<" kg\t\t         "<<turnmeric_powder_p<<"\t     "
            <<(turnmeric_powder_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"hair oil"))
        {
            cout<<"|  hair oil\t\t  "<<productQuantity[i]<<" pac\t\t         "<<hair_oil_p<<"\t     "
            <<(hair_oil_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
        else if (!strcmp(buyedProduct[i],"ghee"))
        {
            cout<<"|   ghee\t\t  "<<productQuantity[i]<<" kg\t\t         "<<ghee_p<<"\t     "
            <<(ghee_p * productQuantity[i])<<endl;
            cout<<"|---------------------------------------------------------------------\n";
        }
    }
    cout<<"|         \t\t\t\tTotal amount         "<<total_bill<<endl;
    cout<<"|---------------------------------------------------------------------\n";
    cout<<"|         \t\t\t\tDiscount             "<<discount<<endl;
    cout<<"|---------------------------------------------------------------------\n";
    cout<<"|         \t\t\t\tPayable ammount      "<<grandTotal<<endl;
    cout<<"|---------------------------------------------------------------------\n";
}

int main(){
    int choose;
    Store akshay;
    cout<<"\n\n  ***WELCOME TO AKSAHY GROCERY STORE***\n\n";
    cout<<"    Here are our store discount rates\n";
    cout<<"******************************************\n";
    cout<<"|  less than 5000 buy 0%% discount       |\n";
    cout<<"|----------------------------------------|\n";
    cout<<"|  greater than 5000 buy 5%% discount    |\n";
    cout<<"|----------------------------------------|\n";
    cout<<"|  greater than 10000 buy 10%% discount  |\n";
    cout<<"|----------------------------------------|\n";
    cout<<"|  greater than 15000 buy 15%% discount  |\n";
    cout<<"******************************************\n";
    do
    {
        cout<<"\nPress 1 to buy product\n";
        cout<<"Press 2 to calculate bill\n";
        cout<<"Press 3 to show bill\n";
        cout<<"Press 4 to Exit\n";
        again:
        cout<<"Please choose any option: ";
        cin>>choose;
        cin.sync();
        switch (choose)
        {
        case 1:
            akshay.buyProduct();
            break;
        case 2:
            akshay.calculateBill();
            break;
        case 3:
            akshay.showBill();
            break;
        case 4:
            break;        
        default:cout<<"Invalid option Please tyr again\n";
        goto again;
            break;
        }
    } while (choose!=4);
    return 0;
}