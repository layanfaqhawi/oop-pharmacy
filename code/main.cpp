#include <iostream>
#include <string>
#include "medication.h"
#include "customer.h"
#include "pharmacy.h"
#include "date.h"
#include "address.h"
#include "offtheshelf.h"
#include "prescription.h"
using namespace std;

int p=0;
Pharmacy* phar = NULL;

void printMenu1();
void printMenu2(int);
void printMenu3(int);
void printMenu4();
int medType();

void setPharmacies(int&);
void resizePhar(int&);
void addPharDyn(int&);
void addPharmacy();
void removePharmacy(int&);

void editPharmacy(int&);
void addMed(int);
void addShelf(int);
void addPres(int);
void addCust(int);
void removeMed(int);
void removeShelf(int);
void removePres(int);
void removeCust(int);

void displayPharmacies();
void pharmDetails(int&);
void displayMeds(int);
void displayCusts(int);

int main()
{
    int choice, end=1, size = 0;

    cout << "PHARMACY MANAGEMENT SYSTEM" << endl;
 
    while (end)
    {
        cout << "Choose an operation:" << endl;
        printMenu1();
        cin >> choice;
        cin.ignore(1000, '\n');
        while (choice<=0 ||  choice>5)
        {
            cout << "Error: Please enter a number from 1 - 5" << endl;
            cin >> choice;
            cin.ignore(1000, '\n');
        }
        if (choice==1)
        {
            setPharmacies(size);
        }
        else if (choice==2)
        {
            resizePhar(size);
        }
        else if (choice==3)
        {
            editPharmacy(size);
        }
        else if (choice==4)
        {
            displayPharmacies();
        }
        else if (choice==5)
        {
            pharmDetails(size);
        }

        cout << "Enter 0 to exit and 1 to continue: " << endl;
        cin >> end;
    }

    return 0;
}


//Menus
void printMenu1()
{
    cout << "Menu:" << endl;
    cout << "1 - Set Pharmacy List" << endl;
    cout << "2 - Resize Pharmacy List" << endl;
    cout << "3 - Edit Pharmacy" << endl;
    cout << "4 - Display Pharmacies" << endl;
    cout << "5 - Display Pharmacy Details" << endl;
}
void printMenu2(int i)
{
    cout << "Pharmacy " << i << " Edit Menu:" << endl;
    cout << "1 - Add Medication(s)" << endl;
    cout << "2 - Add Customer(s)" << endl;
    cout << "3 - Remove a Medication" << endl;
    cout << "4 - Remove a Customer" << endl;
}
void printMenu3(int i)
{
    cout << "Pharmacy " << i << " Display Menu:" << endl;
    cout << "1 - Display Available Medication" << endl;
    cout << "2 - Display Customer List" << endl;
}
void printMenu4()
{
    cout << "Pharmacy Resize Menu:" << endl;
    cout << "1 - Add Pharmacy/Pharmacies" << endl;
    cout << "2 - Remove Pharmacy" << endl;
}
int medType()
{
    int choice;
    cout << "Choose Medication Type:" << endl;
    cout << "1 - Unspecified" << endl;
    cout << "2 - Off the Shelf" << endl;
    cout << "3 - Prescription" << endl;
    cin >> choice;
    cin.ignore(1000, '\n');
    while (choice<=0 ||  choice>3)
    {
        cout << "Error: Please enter a number from 1 - 3" << endl;
        cin >> choice;
        cin.ignore(1000, '\n');
    }
    return choice;
}


//Set and Resize Pharmacies
void setPharmacies(int &size)
{
    cout << "Enter number of pharmacies: ";
    cin >> size;
    cin.ignore(1000, '\n');

    if (phar!=NULL)
    {
        p = 0;
        delete[] phar;
    }
    phar = new Pharmacy[size];

    for (int i=0; i<size; i++)
    {
        addPharmacy();
    }
}
void addPharDyn(int &size)
{
    int n;
    cout << "Enter number of pharmacies: ";
    cin >> n;
    cin.ignore(1000, '\n');
        size+=n;
        Pharmacy *temp = new Pharmacy [size];
        for (int i=0; i<size-n; i++)
        {
            temp[i].setID(phar[i].getID());
            temp[i].setName(phar[i].getName());
            if (phar[i].getMeds()==NULL)
            temp[i].setMedP(NULL);
            else temp[i].copyMeds(phar[i].getMeds(), phar[i].numMeds());
            if (phar[i].getShelf()==NULL)
            temp[i].setShelfP(NULL);
            else temp[i].copyShelf(phar[i].getShelf(), phar[i].numShelf());
            if (phar[i].getPres()==NULL)
            temp[i].setPresP(NULL);
            else temp[i].copyPres(phar[i].getPres(), phar[i].numPres());
            if (phar[i].getCusts()==NULL)
            temp[i].setCustP(NULL);
            else temp[i].copyCusts(phar[i].getCusts(), phar[i].numCusts());
            temp[i].setInts(phar[i].numMeds(), phar[i].numShelf(), phar[i].numPres(), phar[i].numCusts(), phar[i].getMsize(), phar[i].getSMsize(), phar[i].getPMsize(), phar[i].getCsize());
        }
        delete[] phar;
        phar = temp;
        temp = NULL;
        for (int i=0; i<n; i++)
        addPharmacy();
}
void addPharmacy()
{
    string s;
    cout << "Enter Pharmacy Name: ";
    getline(cin,s);
    phar[p].setName(s);
    phar[p].setID(p);
    p++;
}
void removePharmacy(int &size)
{
    int id;
    if (p==0)
    {
        cout << "No Pharmacies to remove." << endl;
        return;
    }
    cout << "Enter Pharmacy ID to remove: ";
    cin >> id;
    if (phar!=NULL)
    {
        int index = -1;
        for (int i=0; i<size; i++)
        {
            if (phar[i].getID()==id)
            index = i;
        }
        if (index==-1)
        cout << "ID not found!" << endl;
        else
        {
            p--;
            size--;
            Pharmacy *temp = new Pharmacy[size];
            for (int i=0; i<index; i++)
            {
                temp[i].setID(phar[i].getID());
                temp[i].setName(phar[i].getName());
                if (phar[i].getMeds()==NULL)
                temp[i].setMedP(NULL);
                else temp[i].copyMeds(phar[i].getMeds(), phar[i].numMeds());
                if (phar[i].getShelf()==NULL)
                temp[i].setShelfP(NULL);
                else temp[i].copyShelf(phar[i].getShelf(), phar[i].numShelf());
                if (phar[i].getPres()==NULL)
                temp[i].setPresP(NULL);
                else temp[i].copyPres(phar[i].getPres(), phar[i].numPres());
                if (phar[i].getCusts()==NULL)
                temp[i].setCustP(NULL);
                else temp[i].copyCusts(phar[i].getCusts(), phar[i].numCusts());
                temp[i].setInts(phar[i].numMeds(), phar[i].numShelf(), phar[i].numPres(), phar[i].numCusts(), phar[i].getMsize(), phar[i].getSMsize(), phar[i].getPMsize(), phar[i].getCsize());
            }
            for (int i=index; i<size; i++)
            {
                temp[i].setID(phar[i+1].getID());
                temp[i].setName(phar[i+1].getName());
                if (phar[i+1].getMeds()==NULL)
                temp[i].setMedP(NULL);
                else temp[i].copyMeds(phar[i+1].getMeds(), phar[i+1].numMeds());
                if (phar[i+1].getShelf()==NULL)
                temp[i].setShelfP(NULL);
                else temp[i].copyShelf(phar[i+1].getShelf(), phar[i+1].numShelf());
                if (phar[i+1].getPres()==NULL)
                temp[i].setPresP(NULL);
                else temp[i].copyPres(phar[i+1].getPres(), phar[i+1].numPres());
                if (phar[i+1].getCusts()==NULL)
                temp[i].setCustP(NULL);
                else temp[i].copyCusts(phar[i+1].getCusts(), phar[i+1].numCusts());
                temp[i].setInts(phar[i+1].numMeds(), phar[i+1].numShelf(), phar[i+1].numPres(), phar[i+1].numCusts(), phar[i+1].getMsize(), phar[i+1].getSMsize(), phar[i+1].getPMsize(), phar[i+1].getCsize());
            }
            delete[] phar;
            phar = temp;
            temp = NULL;
            cout << "Operation Successful!" << endl;
        }
    }
}
void resizePhar(int &size)
{
    int choice;
    cout << "Choose an operation:" << endl;
        printMenu4();
        cin >> choice;
        cin.ignore(1000, '\n');
        while (choice<=0 ||  choice>2)
        {
            cout << "Error: Please enter 1 or 2" << endl;
            cin >> choice;
            cin.ignore(1000, '\n');
        }
        if (choice==1)
        {
            addPharDyn(size);
        }
        else if (choice==2)
        {
            removePharmacy(size);
        }
}


//Edit Pharmacies
void editPharmacy(int &size)
{
    int id, choice;
    cout << "Enter Pharmacy ID to display details:" << endl;
    cin >> id;
    int index = -1;
    while (index==-1)
    {
        for (int i=0; i<size; i++)
        {
            if (phar[i].getID()==id)
            index = i;
        }
        if (index==-1)
        {
            cout << "ID not found. Please Enter new Pharmacy ID:" << endl;
            cin >> id;
        }
    }
    cout << "Choose an operation:" << endl;
        printMenu2(id);
        cin >> choice;
        cin.ignore(1000, '\n');
        while (choice<=0 ||  choice>4)
        {
            cout << "Error: Please enter a number from 1 - 4" << endl;
            cin >> choice;
            cin.ignore(1000, '\n');
        }
    if (choice == 1)
    {
        addMed(id);
    }
    else if (choice == 2)
    {
        addCust(id);
    }
    else if (choice == 3)
    {
       removeMed(id);
    }
    else if (choice == 4)
    {
        removeCust(id);
    }
}
void addMed(int id)
{
    int num;
    int c = medType();
    if (c == 1)
    {   
        cout << "Enter number of medications to add: ";
        cin >> num;
        phar[id].resizeMeds(num);
    }
    else if (c == 2)
    addShelf(id);
    else if (c == 3)
    addPres(id);
}
void addShelf(int id)
{
    int num;
    cout << "Enter number of off the shelf medications to add: ";
    cin >> num;
    phar[id].resizeShelf(num);
}
void addPres(int id)
{
    int num;
    cout << "Enter number of prescription medications to add: ";
    cin >> num;
    phar[id].resizePres(num);
}
void addCust(int id)
{
    int num;
    cout << "Enter number of customers to add: ";
    cin >> num;
    phar[id].resizeCust(num);
    
}
void removeMed(int id)
{
    int c = medType();
    int i;
    if (c == 1)
    {
        if (phar[id].numMeds()==0)
        cout << "No unspecified medications in this pharmacy." << endl;
        else
        {
            cout << "Enter medication ID to remove: ";
            cin >> i;
            phar[id].removeMed(i);
        }
    }
    else if (c == 2)
    removeShelf(id);
    else if (c == 3)
    removePres(id);
}
void removeShelf(int id)
{
    int i;
    if (phar[id].numShelf()==0)
    cout << "No off the shelf medications in this pharmacy." << endl;
    else
    {
        cout << "Enter off the shelf medication ID to remove: ";
        cin >> i;
        phar[id].removeShelf(i);
    }
}
void removePres(int id)
{
    int i;
    if (phar[id].numPres()==0)
    cout << "No prescription medications in this pharmacy." << endl;
    else
    {
        cout << "Enter prescription medication ID to remove: ";
        cin >> i;
        phar[id].removePres(i);
    }
}
void removeCust(int id)
{
    int i;
    if (phar[id].numCusts()==0)
    cout << "Customer list is empty." << endl;
    else
    {
        cout << "Enter customer ID to remove: ";
        cin >> i;
        phar[id].removeCust(i);
    }
}


//Displays
void displayPharmacies()
{
    for (int i=0; i<p; i++)
    {
        phar[i].print();
    }
}
void pharmDetails(int &size)
{
    int id, choice;
    cout << "Enter Pharmacy ID to display details:" << endl;
    cin >> id;
    int index = -1;
    while (index==-1)
    {
        for (int i=0; i<size; i++)
        {
            if (phar[i].getID()==id)
            index = i;
        }
        if (index==-1)
        {
            cout << "ID not found. Please Enter new Pharmacy ID:" << endl;
            cin >> id;
        }
    }
    cout << "Choose an operation:" << endl;
        printMenu3(id);
        cin >> choice;
        cin.ignore(1000, '\n');
        while (choice<=0 ||  choice>2)
        {
            cout << "Error: Please enter 1 or 2" << endl;
            cin >> choice;
            cin.ignore(1000, '\n');
        }
    if (choice==1)
    {
        displayMeds(index);
    }
    else if (choice==2)
    {
        displayCusts(index);
    }
}
void displayMeds(int id)
{
    int c = medType();
    if (c == 1)
    phar[id].printMeds();
    else if (c == 2)
    phar[id].printShelf();
    else if (c == 3)
    phar[id].printPres();
}
void displayCusts(int id)
{
    phar[id].printCust();
}