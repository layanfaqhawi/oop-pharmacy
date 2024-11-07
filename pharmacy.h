#pragma once
#include <iostream>
#include "medication.h"
#include "customer.h"
#include "offtheshelf.h"
#include "prescription.h"
using namespace std;

class Pharmacy
{
    private:
    int pharmacy_ID, m, sm, pm, c, msize,  smsize, pmsize, csize;
    string pharmacy_name;
    Medication *meds;
    OffTheShelf *shelf;
    Prescription *pres;
    Customer *cust;
    
    public:
    Pharmacy(int i = 0, string n = "No Name");
    Pharmacy(Pharmacy& src);

    void setID(int);
    void setName(string);

    void setMedP(Medication*);
    void setShelfP(OffTheShelf*);
    void setPresP(Prescription*);
    void setCustP(Customer*);

    void copyMeds(Medication a[], int);
    void copyShelf(OffTheShelf a[], int);
    void copyPres(Prescription a[], int);
    void copyCusts(Customer a[], int);
    
    void setInts(int, int, int, int, int, int, int, int);

    int getID() const;
    string getName() const;

    Medication* getMeds() const;
    OffTheShelf* getShelf() const;
    Prescription* getPres() const;
    Customer* getCusts() const;

    int getMsize() const;
    int getSMsize() const;
    int getPMsize() const;
    int getCsize() const;

    void resizeMeds(int);
    void addMed();
    void removeMed(int);

    void resizeShelf(int);
    void addShelf();
    void removeShelf(int);

    void resizePres(int);
    void addPres();
    void removePres(int);

    void resizeCust(int);
    void addCust();
    void removeCust(int);

    int numMeds() const;
    int numShelf() const;
    int numPres() const;
    int numCusts() const;

    void print() const;
    void printMeds() const;
    void printShelf() const;
    void printPres() const;
    void printCust() const;

    double totalValM();
    double totalValS();
    double totalValP();

    ~Pharmacy();
};