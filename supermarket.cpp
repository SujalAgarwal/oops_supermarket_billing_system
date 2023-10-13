#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "_________________" << endl;
    cout << "                 " << endl;
    cout << "                 " << endl;
    cout << "SUPERMARKET MAIN MENU " << endl;
    cout << "                 " << endl;
    cout << "                 " << endl;
    cout << "_________________" << endl;
    cout << "\t\t\t\t 1)ADMINISTRATOR" << endl;
    cout << "                 " << endl;
    cout << "\t\t\t\t 2)BUYER" << endl;
    cout << "                 " << endl;
    cout << "\t\t\t\t 3)EXIT" << endl;
    cout << "                 " << endl;
    cout << "\t\t\t\t PLEASE SELECT!!!" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "\t\t\t\t PLEASE LOGIN" << endl;
        cout << "                 " << endl;
        cout << "\t\t\t\t PLEASE ENTER EMAIL" << endl;
        cin >> email;
        cout << "                 " << endl;
        cout << "\t\t\t\t PLEASE ENTER PASSWORD" << endl;
        cin >> password;
        if (email == "sujal@gmail.com" and password == "sujal123@")
        {
            administrator();
        }
        else
        {
            cout << "\t\t\t\t PLEASE ENTER VALID EMAIL AND PASSWORD" << endl;
        }
        break;
    }
    case 2:
    {
        buyer();
        break;
    }
    case 3:
    {
        exit(0);
        break;
    }
    default:
    {
        cout << "PLEASE SELECT FROMT HE GIVEN OPTIONS!!!!" << endl;
        break;
    }
    }
    goto m; // this is like a jump statement it helps us to run the given meny againand again..
}
void shopping::administrator()
{
m:
    int choice;
    cout << "\t\t\t_____ADMINISTRATOR MENU" << endl;
    cout << "\t\t\t\t_1)ADD THE PRODUCT" << endl;
    cout << "\t\t\t\t_                 " << endl;
    cout << "\t\t\t\t_2)DELETE THE PRODUCT" << endl;
    cout << "\t\t\t\t_                    " << endl;
    cout << "\t\t\t\t_3)BACK TO MAIN MENU.." << endl;
    cout << "\t\t\t\t_PLEASE ENTER YOUR CHOICE!!" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
 
    case 2:
        rem();
        break;
    case 3:
        menu();
        break;
    default:
        cout << "INVALID CHOICE!!!" << endl;
    }
    goto m;
}
void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t_----------------" << endl;
    cout << "\t\t\t\t_1)BUY PRODUCT" << endl;
    cout << "\t\t\t\t_                 " << endl;
    cout << "\t\t\t\t_2)BACK TO MAIN MENU" << endl;
    cout << "\t\t\t\t_PLEASE ENTER YOUR CHOICE!!" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;

    default:
        cout << "INVALID CHOICE!!!" << endl;
    }
    goto m;
}
void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\t\t\t ADD NEW PRODUCT" << endl;
    cout << "\t\t\t Product code of the product" << endl;
    cin >> pcode;
    cout << "\t\t\t Name of the product" << endl;
    cin >> pname;
    cout << "\t\t\t  Price of the product" << endl;
    cin >> price;
    cout << "\t\t\t Discount on the product" << endl;
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " "
             << " " << pname << " "
             << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " "
             << " " << pname << " "
             << " " << price << " " << dis << "\n";
        data.close();
    }
    cout << "\t\t\t Record Inserted.." << endl;
}
void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n;
    cout << "\t\t\t Modify the record" << endl;
    cout << "\t\t\t Enter the product code.." << endl;
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\tfile does not exist.." << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\t\t\t Product New Code: " << endl;
                cin >> c;
                cout << "\t\t\t Enter the Name: " << endl;
                cin >> n;
                cout << "\t\t\t Price:" << endl;
                cin >> p;
                cout << "\t\t\t Discount:: " << endl;
                cin >> dis;
                data1 << " " << c << " " << n << " " << p << " "
                      << " " << d << endl;
                cout << "\t\t\t Record Edited Successfully" << endl;
                token++;
                break;
            }
            else
            {
                data << " " << pcode << " "
                     << " " << pname << " "
                     << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\t\t\t Sorry Record Not Found!!!" << endl;
        }
    }
}
void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\t\t\t Remove the Product" << endl;
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t File Does not Exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\t\t\t Product Deleted SuccessFully" << endl;
                token++;
            }
            else
            {
                data1 << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\t\t\t Record Not Found" << endl;
        }
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n --------------------------------------------" << endl;
    cout << "\t\t Product_No \t\t Product_Name \t\t Price" << endl;
    cout << "\n\n --------------------------------------------" << endl;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shopping::receipt()
{
m:
    fstream data;
    vector<int> arrc;
    vector<int> arrq;
    char choice;
    int c = 0;
    float amount;
    float dis = 0;
    float total = 0;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t Empty Database" << endl;
    }
    else
    {
        data.close();
        list();
        cout << "_________________________" << endl;
        cout << "|                        " << endl;
        cout << " Please Place the Order.." << endl;
        cout << "|                        " << endl;
        cout << "_________________________" << endl;
        do
        {
            int k;
            cout << "Enter The Product Code" << endl;
            cin>>k;
            arrc.push_back(k);
            cout << "Enter The Product Quantity" << endl;
            cin>>k;
            arrq.push_back(k);
           
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "Duplicate Product..! Please Try Again" << endl;
                    goto m;
                }
            }
            c++;
            cout << "To buy another product press y else press n " << endl;
            cin >> choice;

        } while (choice == 'y');
        cout << "\t\t\t____________RECEIPT____________" << endl;
        cout << "\t\t Product_number \t Product_name \tProduct Quantity\t Price\t Amount \t Amount With Discount" << endl;
        data.open("database.txt", ios::in);
        for (int i = 0; i < c; i++)
        {
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis << endl;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\t\t Total Amount::" ;
    cout << total << endl;
}
int main()
{
    shopping s;
    s.menu();
    return 0;
}