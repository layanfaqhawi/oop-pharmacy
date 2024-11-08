#include <iostream>
#include <string>
#include "pharmacy.h"
using namespace std;

//Defaulted Constructor
    Pharmacy::Pharmacy(int i, string n)
    {
        setID(0);
        setName(n);
        meds = NULL;
        shelf = NULL;
        pres = NULL;
        cust = NULL;
        msize = 0;
        smsize = 0;
        pmsize = 0;
        csize = 0;
        m = 0;
        sm = 0;
        pm = 0;
        c = 0;
    }


//Copy Constructor
    Pharmacy::Pharmacy(Pharmacy &src)
    {
        pharmacy_ID = src.pharmacy_ID;
        pharmacy_name = src.pharmacy_name;
        setInts(src.m, src.sm, src.pm, src.c, src.msize, src.smsize, src.pmsize, src.csize);
        copyMeds(src.meds, src.msize);
        copyShelf(src.shelf, src.smsize);
        copyPres(src.pres, src.pmsize);
        copyCusts(src.cust, src.csize);
    }


//Setters
    void Pharmacy::setID(int i)
    {
        if (i>=0)
        pharmacy_ID = i;
        else pharmacy_ID = 0;
    }
    void Pharmacy::setName(string s)
    {
        if (s!="")
        pharmacy_name = s;
        else pharmacy_name = "No Name";
    }
    void Pharmacy::setMedP(Medication *m)
    {
        meds = m;
    }
    void Pharmacy::setShelfP(OffTheShelf *sm)
    {
        shelf = sm;
    }
    void Pharmacy::setPresP(Prescription *pm)
    {
        pres = pm;
    }
    void Pharmacy::setCustP(Customer *c)
    {
        cust = c;
    }
    void Pharmacy::setInts(int a, int b, int c, int d, int e, int f, int g, int h)
    {
        this->m = a;
        this->sm = b;
        this->pm = c;
        this->c = d;
        this->msize = e;
        this->smsize = f;
        this->pmsize = g;
        this->csize = h;
    }


//Getters
    int Pharmacy::getID() const {return pharmacy_ID;}
    string Pharmacy::getName() const {return pharmacy_name;}
    Medication *Pharmacy::getMeds() const {return meds;}
    OffTheShelf *Pharmacy::getShelf() const {return shelf;}
    Prescription *Pharmacy::getPres() const {return pres;}
    Customer *Pharmacy::getCusts() const {return cust;}
    int Pharmacy::getMsize() const {return msize;}
    int Pharmacy::getSMsize() const {return smsize;}
    int Pharmacy::getPMsize() const {return pmsize;}
    int Pharmacy::getCsize() const { return csize; }
    

//Copy Functions
    void Pharmacy::copyMeds(Medication a[], int size)
    {
        if (this->meds!=NULL)
            delete[] this->meds;
        this->msize = size;
        this->meds = new Medication[msize];
        for (int i=0; i<msize; i++)
        {
            meds[i].setID(a[i].getID());
            meds[i].setMedName(a[i].getMedName());
            meds[i].setDes(a[i].getDes());
            meds[i].setPrice(a[i].getPrice());
            meds[i].setQuantity(a[i].getQuantity());
            meds[i].setBarcode(a[i].getBarcode());
            meds[i].setDate(a[i].getDate().getDay(), a[i].getDate().getMonth(), a[i].getDate().getYear());
        }
    }
    void Pharmacy::copyShelf(OffTheShelf a[], int size)
    {
        if (this->shelf!=NULL)
            delete[] this->shelf;
        this->smsize = size;
        this->shelf = new OffTheShelf[size];
        for (int i=0; i<size; i++)
        {
            shelf[i].setID(a[i].getID());
            shelf[i].setMedName(a[i].getMedName());
            shelf[i].setDes(a[i].getDes());
            shelf[i].setPrice(a[i].getPrice());
            shelf[i].setQuantity(a[i].getQuantity());
            shelf[i].setBarcode(a[i].getBarcode());
            shelf[i].setDate(a[i].getDate().getDay(), a[i].getDate().getMonth(), a[i].getDate().getYear());
            shelf[i].setBOGOF(a[i].getBOGOF());
        }
    }
    void Pharmacy::copyPres(Prescription a[], int size)
    {
        if (this->pres!=NULL)
            delete[] pres;
        this->pmsize = size;
        this->pres = new Prescription[size];
        for (int i=0; i<size; i++)
        {
            pres[i].setID(a[i].getID());
            pres[i].setMedName(a[i].getMedName());
            pres[i].setDes(a[i].getDes());
            pres[i].setPrice(a[i].getPrice());
            pres[i].setQuantity(a[i].getQuantity());
            pres[i].setBarcode(a[i].getBarcode());
            pres[i].setDate(a[i].getDate().getDay(), a[i].getDate().getMonth(), a[i].getDate().getYear());
            pres[i].setFDA(a[i].getFDA());
            pres[i].setAppDate(a[i].getAppDate().getDay(), a[i].getAppDate().getMonth(), a[i].getAppDate().getYear());
        }
    }
    void Pharmacy::copyCusts(Customer a[], int size)
    {
        if (this->cust!=NULL)
            delete[] this->cust;
        this->csize = size;
        this->cust = new Customer[csize];
        for (int i=0; i<csize; i++)
        {
            cust[i].setID(a[i].getID());
            cust[i].setName(a[i].getName());
            cust[i].setAddress(a[i].getAddress().getEmail(), a[i].getAddress().getCity(), a[i].getAddress().getMobile(), a[i].getAddress().getStreet());
        }
    }


//Resize Medication (DYNAMIC)
    void Pharmacy::resizeMeds(int n)
    {
        if (this->meds==NULL)
        {
            this->meds = new Medication[n];
            msize = n;
            for (int i=0; i<msize; i++)
            this->addMed();
        }
        else
        {
            msize+=n;
            Medication *temp = new Medication[msize];
            for (int i=0; i<msize-n; i++)
            {
                temp[i].setID(meds[i].getID());
                temp[i].setMedName(meds[i].getMedName());
                temp[i].setDes(meds[i].getDes());
                temp[i].setPrice(meds[i].getPrice());
                temp[i].setQuantity(meds[i].getQuantity());
                temp[i].setBarcode(meds[i].getBarcode());
                temp[i].setDate(meds[i].getDate().getDay(), meds[i].getDate().getMonth(), meds[i].getDate().getYear());
            }
            delete[] meds;
            meds = temp;
            temp = NULL;
            for (int i=0; i<n; i++)
            addMed();
        }
    }
    void Pharmacy::addMed()
    {
        string med, des, b;
        double p;
        int q, day, month, year;
        meds[m].setID(m);
        cout << "Enter Medication Name: ";
        cin.ignore(1000, '\n');
        getline(cin,med);
        meds[m].setMedName(med);
        cout << "Enter Description: ";
        getline(cin,des);
        meds[m].setDes(des);
        cout << "Enter Price: ";
        cin >> p;
        meds[m].setPrice(p);
        cout << "Enter Quantity in Stock: ";
        cin >> q;
        meds[m].setQuantity(q);
        cout << "Enter Expiry Date (in the order day, month, year): ";
        cin >> day >> month >> year;
        meds[m].setDate(day, month, year);
        cout << "Enter Barcode: ";
        cin >> b;
        meds[m].setBarcode(b);
        m++;
    }
    void Pharmacy::removeMed(int id)
    {
        if (this->meds!=NULL)
        {
            int index = -1;
            for (int i=0; i<msize; i++)
            {
                if (meds[i].getID()==id)
                index = i;
            }
            if (index==-1)
            cout << "ID Not Found!" << endl;
            else 
            {
                msize--;
                m--;
                Medication *temp = new Medication[msize];
                for (int i=0; i<index; i++)
                {
                    temp[i].setID(meds[i].getID());
                    temp[i].setMedName(meds[i].getMedName());
                    temp[i].setDes(meds[i].getDes());
                    temp[i].setPrice(meds[i].getPrice());
                    temp[i].setQuantity(meds[i].getQuantity());
                    temp[i].setBarcode(meds[i].getBarcode());
                    temp[i].setDate(meds[i].getDate().getDay(), meds[i].getDate().getMonth(), meds[i].getDate().getYear());
                }
                for (int i=index; i<msize; i++)
                {
                    temp[i].setID(meds[i+1].getID());
                    temp[i].setMedName(meds[i+1].getMedName());
                    temp[i].setDes(meds[i+1].getDes());
                    temp[i].setPrice(meds[i+1].getPrice());
                    temp[i].setQuantity(meds[i+1].getQuantity());
                    temp[i].setBarcode(meds[i+1].getBarcode());
                    temp[i].setDate(meds[i+1].getDate().getDay(), meds[i+1].getDate().getMonth(), meds[i+1].getDate().getYear());
                }
                delete[] meds;
                meds = temp;
                temp = NULL;
                cout << "Operation Successful!" << endl;
            }
        }
    }


//Resize OffTheShelf Medication (DYNAMIC)
    void Pharmacy::resizeShelf(int n)
    {
        if (this->shelf==NULL)
        {
            this->shelf = new OffTheShelf[n];
            smsize = n;
            for (int i=0; i<smsize; i++)
            this->addShelf();
        }
        else
        {
            smsize+=n;
            OffTheShelf *temp = new OffTheShelf[smsize];
            for (int i=0; i<smsize-1; i++)
            {
                temp[i].setID(shelf[i].getID());
                temp[i].setMedName(shelf[i].getMedName());
                temp[i].setDes(shelf[i].getDes());
                temp[i].setPrice(shelf[i].getPrice());
                temp[i].setQuantity(shelf[i].getQuantity());
                temp[i].setBarcode(shelf[i].getBarcode());
                temp[i].setDate(shelf[i].getDate().getDay(), shelf[i].getDate().getMonth(), shelf[i].getDate().getYear());
                temp[i].setBOGOF(shelf[i].getBOGOF());
            }
            delete[] shelf;
            shelf = temp;
            temp = NULL;
            for (int i=0; i<n; i++)
            addShelf();
        }
    }
    void Pharmacy::addShelf()
    {
        string med, des, b;
        double p;
        int q, day, month, year;
        bool bg;
        shelf[sm].setID(sm);
        cout << "Enter Medication Name: ";
        cin.ignore(1000, '\n');
        getline(cin,med);
        shelf[sm].setMedName(med);
        cout << "Enter Description: ";
        getline(cin,des);
        shelf[sm].setDes(des);
        cout << "Enter Price: ";
        cin >> p;
        shelf[sm].setPrice(p);
        cout << "Enter Quantity in Stock: ";
        cin >> q;
        shelf[sm].setQuantity(q);
        cout << "Enter Expiry Date (in the order day, month, year): ";
        cin >> day >> month >> year;
        shelf[sm].setDate(day, month, year);
        cout << "Enter Barcode: ";
        cin >> b;
        shelf[sm].setBarcode(b);
        cout << "Enter buy 1 get 1 free offer (only 0 or 1): ";
        cin >> bg;
        shelf[sm].setBOGOF(bg);
        sm++;   
    }
    void Pharmacy::removeShelf(int id)
    {
        if (this->shelf!=NULL)
        {
            int index = -1;
            for (int i=0; i<smsize; i++)
            {
                if (shelf[i].getID()==id)
                index = i;
            }
            if (index==-1)
            cout << "Index Not Found!" << endl;
            else 
            {
                smsize--;
                sm--;
                OffTheShelf *temp = new OffTheShelf[msize];
                for (int i=0; i<index; i++)
                {
                    temp[i].setID(shelf[i].getID());
                    temp[i].setMedName(shelf[i].getMedName());
                    temp[i].setDes(shelf[i].getDes());
                    temp[i].setPrice(shelf[i].getPrice());
                    temp[i].setQuantity(shelf[i].getQuantity());
                    temp[i].setBarcode(shelf[i].getBarcode());
                    temp[i].setDate(shelf[i].getDate().getDay(), shelf[i].getDate().getMonth(), shelf[i].getDate().getYear());
                    temp[i].setBOGOF(shelf[i].getBOGOF());
                }
                for (int i=index; i<msize; i++)
                {
                    temp[i].setID(shelf[i+1].getID());
                    temp[i].setMedName(shelf[i+1].getMedName());
                    temp[i].setDes(shelf[i+1].getDes());
                    temp[i].setPrice(shelf[i+1].getPrice());
                    temp[i].setQuantity(shelf[i+1].getQuantity());
                    temp[i].setBarcode(shelf[i+1].getBarcode());
                    temp[i].setDate(shelf[i+1].getDate().getDay(), shelf[i+1].getDate().getMonth(), shelf[i+1].getDate().getYear());
                    temp[i].setBOGOF(shelf[i+1].getBOGOF());
                }
                delete[] shelf;
                shelf = temp;
                temp = NULL;
                cout << "Operation Successful!" << endl;
            }
        }
    }


//Resize Prescription Medication (DYNAMIC)
    void Pharmacy::resizePres(int n)
    {
        if (this->pres==NULL)
        {
            this->pres = new Prescription[n];
            pmsize = n;
            for (int i=0; i<pmsize; i++)
            this->addPres();
        }
        else
        {
            pmsize+=n;
            Prescription *temp = new Prescription[pmsize];
            for (int i=0; i<pmsize-n; i++)
            {
                temp[i].setID(pres[i].getID());
                temp[i].setMedName(pres[i].getMedName());
                temp[i].setDes(pres[i].getDes());
                temp[i].setPrice(pres[i].getPrice());
                temp[i].setQuantity(pres[i].getQuantity());
                temp[i].setBarcode(pres[i].getBarcode());
                temp[i].setDate(pres[i].getDate().getDay(), pres[i].getDate().getMonth(), pres[i].getDate().getYear());
                temp[i].setFDA(pres[i].getFDA());
                temp[i].setAppDate(pres[i].getAppDate().getDay(), pres[i].getAppDate().getMonth(), pres[i].getAppDate().getYear());
            }
            delete[] pres;
            pres = temp;
            temp = NULL;
            for (int i=0; i<n; i++)
            addPres();
        }
    }
    void Pharmacy::addPres()
    {
        string med, des, b;
        double p;
        int q, day, month, year, f, d, m, y;

        pres[pm].setID(pm);
        cout << "Enter Medication Name: ";
        cin.ignore(1000, '\n');
        getline(cin,med);
        pres[pm].setMedName(med);
        cout << "Enter Description: ";
        getline(cin,des);
        pres[pm].setDes(des);
        cout << "Enter Price: ";
        cin >> p;
        pres[pm].setPrice(p);
        cout << "Enter Quantity in Stock: ";
        cin >> q;
        pres[pm].setQuantity(q);
        cout << "Enter Expiry Date (in the order day, month, year): ";
        cin >> day >> month >> year;
        pres[pm].setDate(day, month, year);
        cout << "Enter Barcode: ";
        cin >> b;
        pres[pm].setBarcode(b);
        cout << "Enter FDA Number: ";
        cin >> f;
        pres[pm].setFDA(f);
        cout << "Enter Appointment Date (in the order day, month, year): ";
        cin >> d >> m >> y;
        pres[pm].setAppDate(d, m, y);
        pm++;
    }
    void Pharmacy::removePres(int id)
    {
        if (this->pres!=NULL)
        {
            int index = -1;
            for (int i=0; i<pmsize; i++)
            {
                if (pres[i].getID()==id)
                index = i;
            }
            if (index==-1)
            cout << "Id Not Found!" << endl;
            else 
            {
                pmsize--;
                pm--;
                Prescription *temp = new Prescription[pmsize];
                for (int i=0; i<index; i++)
                {
                    temp[i].setID(pres[i].getID());
                    temp[i].setMedName(pres[i].getMedName());
                    temp[i].setDes(pres[i].getDes());
                    temp[i].setPrice(pres[i].getPrice());
                    temp[i].setQuantity(pres[i].getQuantity());
                    temp[i].setBarcode(pres[i].getBarcode());
                    temp[i].setDate(pres[i].getDate().getDay(), pres[i].getDate().getMonth(), pres[i].getDate().getYear());
                    temp[i].setFDA(pres[i].getFDA());
                    temp[i].setAppDate(pres[i].getAppDate().getDay(), pres[i].getAppDate().getMonth(), pres[i].getAppDate().getYear());
                }
                for (int i=index; i<pmsize; i++)
                {
                    temp[i].setID(pres[i+1].getID());
                    temp[i].setMedName(pres[i+1].getMedName());
                    temp[i].setDes(pres[i+1].getDes());
                    temp[i].setPrice(pres[i+1].getPrice());
                    temp[i].setQuantity(pres[i+1].getQuantity());
                    temp[i].setBarcode(pres[i+1].getBarcode());
                    temp[i].setDate(pres[i+1].getDate().getDay(), pres[i+1].getDate().getMonth(), pres[i+1].getDate().getYear());
                    temp[i].setFDA(pres[i+1].getFDA());
                    temp[i].setAppDate(pres[i+1].getAppDate().getDay(), pres[i+1].getAppDate().getMonth(), pres[i+1].getAppDate().getYear());
                }
                delete[] pres;
                pres = temp;
                temp = NULL;
                cout << "Operation Successful!" << endl;
            }
        }
    }


//Resize Customer (DYNAMIC)
    void Pharmacy::resizeCust(int n)
    {
        if (this->cust==NULL)
        {
            this->cust = new Customer[n];
            csize = n;
            for (int i=0; i<csize; i++)
            this->addCust();
        }
        else
        {
            csize+=n;
            Customer *temp = new Customer[csize];
            for (int i=0; i<csize-n; i++)
            {
                temp[i].setID(cust[i].getID());
                temp[i].setName(cust[i].getName());
                temp[i].setAddress(cust[i].getAddress().getEmail(), cust[i].getAddress().getCity(), cust[i].getAddress().getMobile(), cust[i].getAddress().getStreet());
            }
            delete[] cust;
            cust = temp;
            temp = NULL;
            for (int i=0; i<n; i++)
            addCust();
        }
    }
    void Pharmacy::addCust()
    {
        cin.ignore(1000, '\n');
        string s, e, city, m, str;
        cout << "Enter Customer Name: ";
        getline(cin,s);
        cust[c].setName(s);
        cout << "Enter Email: ";
        getline(cin,e);
        cout << "Enter City: ";
        getline(cin,city);
        cout << "Enter Mobile Number: ";
        getline(cin,m);
        cout << "Enter Street Name: ";
        getline(cin,str);
        cust[c].setAddress(e, city, m, str);
        c++;
    }
    void Pharmacy::removeCust(int id)
    {
        if (this->cust!=NULL)
        {
            int index = -1;
            for (int i=0; i<csize; i++)
            {
                if (cust[i].getID()==id)
                index = i;
            }
            if (index==-1)
            cout << "Index Not Found!" << endl;
            else 
            {
                csize--;
                c--;
                Customer *temp = new Customer[csize];
                for (int i=0; i<index; i++)
                {
                    temp[i].setID(cust[i].getID());
                    temp[i].setName(cust[i].getName());
                    temp[i].setAddress(cust[i].getAddress().getEmail(), cust[i].getAddress().getCity(), cust[i].getAddress().getMobile(), cust[i].getAddress().getStreet());
                }
                for (int i=index; i<csize; i++)
                {
                    temp[i].setID(cust[i+1].getID());
                    temp[i].setName(cust[i+1].getName());
                    temp[i].setAddress(cust[i+1].getAddress().getEmail(), cust[i+1].getAddress().getCity(), cust[i+1].getAddress().getMobile(), cust[i+1].getAddress().getStreet());
                }
                delete[] cust;
                cust = temp;
                temp = NULL;
                cout << "Operation Successful!" << endl;
            }
        }
    }


//Array Counters Getters
    int Pharmacy::numMeds() const {return m;}
    int Pharmacy::numShelf() const {return sm;}
    int Pharmacy::numPres() const {return pm;}
    int Pharmacy::numCusts() const {return c;}


//Print
    void Pharmacy::print() const
    {
        cout << "Pharmacy ID: " << pharmacy_ID << endl;
        cout << "Pharmacy Name: " << pharmacy_name << endl;
        cout << "Number of Unspecified Medications: " << m << endl;
        cout << "Number of Off The Shelf Medications: " << sm << endl;
        cout << "Number of Prescription Medications: " << pm << endl;
        cout << "Number of Customers: " << c << endl;
    }
    void Pharmacy::printMeds() const
    {
        if (m==0)
        cout << "No Medications Available." << endl;
        else
        {
            cout << "Available Medications:" << endl;
            for (int i=0; i<m; i++)
            {
                meds[i].printInfo();
            }
        }
    }
    void Pharmacy::printShelf() const
    {
        if (sm==0)
        cout << "No Off the Shelf Medications Available." << endl;
        else
        {
            cout << "Available Off the Shelf Medications: " << endl;
            for (int i=0; i<sm; i++)
            {
                shelf[i].printInfo();
            }
        }
    }
    void Pharmacy::printPres() const
    {
        if (pm==0)
        cout << "No Prescription Medications Available." << endl;
        else
        {
            cout << "Available Prescription Medications: " << endl;
            for (int i=0; i<pm; i++)
            {
                pres[i].printInfo();
            }
        }
    }
    void Pharmacy::printCust() const
    {
        if (c==0)
        cout << "Customer List is Empty." << endl;
        {
            cout << "Customer List:" << endl;
            for (int i=0; i<c; i++)
            {
                cust[i].printInfo();
            }
        }
    }


//Total value of all Medications
    double Pharmacy::totalValM()
    {
        double sum = 0;
        for (int i=0; i<m; i++)
        {
            sum += meds[i].getPrice() * meds[i].getQuantity();
        }
        return sum;
    }
    double Pharmacy::totalValS()
    {
        double sum = 0;
        for (int i=0; i<sm; i++)
        {
            sum += shelf[i].getPrice() * shelf[i].getQuantity();
        }
        return sum;
    }
    double Pharmacy::totalValP()
    {
        double sum = 0;
        for (int i=0; i<pm; i++)
        {
            sum += pres[i].getPrice() * pres[i].getQuantity();
        }
        return sum;
    }


//Destructor
    Pharmacy::~Pharmacy() 
    {
        if (meds!=NULL)
            delete[] meds;
        if (shelf!=NULL)
            delete[] shelf;
        if (pres!=NULL)
            delete[] pres;
        if (cust!=NULL)
            delete[] pres;
    }