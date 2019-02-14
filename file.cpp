#include <iostream> 
#include <fstream>
#include <string>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

struct PERSON{
    char Name[20];
    float Balance;

};

void display(PERSON per[100], int num);
void findRichest(PERSON p[100], int num);
void deposit(string fullName, PERSON p[100], int num);
void newCopy(string filename, PERSON p[100], int num);

int main()
{
    string fname, lname, fullName, line;
    int n = 0;
    PERSON p[100];
    ifstream inData;
    inData.open("data.txt");


    for(int i = 0; i < n; i++)
    {
        inData >> fname;
        inData >> lname;
        inData >> p[i].Balance;
        fullName = fname + " " + lname;
        strcpy(p[i].Name, fullName.c_str());
    }

    inData.close();
    display(p, n);    
    findRichest(p, n);
    deposit(fullName, p, n);
    newCopy("data.txt", p, n);

    
    
}

void display(PERSON per[100], int num)
{
    cout << "Name" << "       " << "Balance" << endl;
    cout << "********************************" << endl;
    for(int i = 0; i < num; i++)
    {
        cout << per[i].Name << " " << per[i].Balance << endl;
    }

}
void findRichest(PERSON p[100], int num)
{
    cout << "*********************************" << endl;
    float max = 0.0;
    for(int i = 0; i < num; i ++)
    {
        if(p[i].Balance > max)
        max = p[i].Balance;
    }
    //cout << max << endl;
    for (int i = 0; i < num; i++)
    {
        if(max == p[i].Balance)
        {
            cout << "The maximum balance is " << p[i].Name << endl;
        }
    }

  
}
void deposit(string person, PERSON p[100], int num)
{
    cout << "****************************"<< endl;
    char name[20];
    float deposit = 0;
    cout << "Enter your full name to deposit money: ";
    getline(cin, person);
    cout << "How much money do you want to deposit?" << endl;
    cin >> deposit;
    strcpy(name, person.c_str());
    for(int i = 0; i < num; i ++)
    {
        if (strcmp(person.c_str(), p[i].Name) == 0)
        {
            p[i].Balance = p[i].Balance + deposit;
            cout << "You're new balance is: " << p[i].Balance << endl;
        }

    }
}
void newCopy(string file, PERSON p[100], int num)
{
    ofstream outData;
    outData.open(file.c_str());
    for(int i = 0; i < num; i++)
    {
        outData << p[i].Name; 
        outData << " ";
        outData << p[i].Balance;
        outData << endl;
    }

    outData.close();

}