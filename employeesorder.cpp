#include <iostream>
#include <string>
#include <fstream>
#include <cstring> //used for strcpy, strcmp, etc
#include"stock.h"


using namespace std;

void order()
{//order()
	
//UPDATED STOCK CODE
	
	//READIND THE STOCK FILE
	char ch;
	int size = 0;

	ifstream file1("stock.txt");

	while (file1.get(ch))
	{
		if (ch == '\n')
		size++;
	}

	file1.clear();
	file1.seekg(0, ios::beg);		
	
//	ifstream file1("stock.txt");

	if (!file1.is_open()) 
	{
		cout << "Unable to open the file." << endl;
	}
	
	int *ID = new int[size];
	int *price = new int[size];
	int *total = new int[size];
	int *quantity = new int[size];
	char **name = new char* [size]; 
	

	for (int j = 0; j < size; j++) 
	{
		name[j] = new char[100];
	}	
/*	
	ifstream file1("stock.txt");

	if (!file1.is_open()) 
	{
		cout << "Unable to open the file." << endl;
	}
	
	int i = 0;
	int ID[20], price[20], quantity[20], total[20];
	char name[20][100];
*/
	
	int i=0;	
	while (file1 >> ID[i] >> name[i] >> price[i] >> quantity[i] >> total[i]) 
	{
		i++; //using it for bubble sorting
	}
    
	//B U B B L E  S T O C K
	
//	bubblesort(ID,name,quantity,price,total,i);
	for (int k=0;k<i;k++) //n=i ; line 110
	{//for 1
		for (int j=0;j<i-k-1;j++)
		{//for 2
			if( quantity[j] > quantity [j+1] )
			{//if

				swap(quantity[j],quantity[j+1]);
				swap(ID[j], ID[j + 1]);
				swap(price[j], price[j + 1]);
				swap(total[j], total[j + 1]);
//				swap(name[j], name[j + 1]);
				
//since its better to use strcpy instead of swap, we'll use a temprorary variable to store the name
//and then cpy the contents.
				char temporary[100];
				strcpy(temporary,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],temporary);
//the reason we're not using temporary[j] is because its contents will keep on changing.
				
				
				
			}//if
		}//for 2
	}//for 1
	
	cout<<colorhead
		<<left<<setw(10)<<"ID"
		<<setw(15)<<"NAME"
		<<setw(15)<<"PRICE"
		<<setw(15)<<"QUANTITY"
		<<setw(15)<<"TotalPrice"
		<<colorreset
		<<endl; 
         
	for (int j=0;j<i;j++)
	{//for
	
//for H I G H L I G H T I N G items==0 red
		if (quantity[j]==0)
		{
			cout<<colorred
				<<left<<setw(10)<< ID[j]
				<<setw(15)<<name[j]
				<<setw(15)<<price[j]
				<<setw(15)<<quantity[j]
				<<setw(15)<<price[j] * quantity[j]
				<<colorreset
				<<endl;
		}

//for H I G H L I G H T I N G items>100 green.
		else if (quantity[j]>100)
		{
			cout<<colorgreen
				<<left<<setw(10)<< ID[j]
				<<setw(15)<<name[j]
				<<setw(15)<<price[j]
				<<setw(15)<<quantity[j]
				<<setw(15)<<price[j] * quantity[j]
				<<colorreset
				<<endl;
		}
		
		else if(quantity[j]<=15)
		{
			cout<<coloryellow
				<<left<<setw(10)<< ID[j]
				<<setw(15)<<name[j]
				<<setw(15)<<price[j]
				<<setw(15)<<quantity[j]
				<<setw(15)<<price[j] * quantity[j]
				<<colorreset
				<<endl;
		}
		
		else
		{
			cout<<left<<setw(10)<< ID[j]
				<<setw(15)<<name[j]
				<<setw(15)<<price[j]
				<<setw(15)<<quantity[j]
				<<setw(15)<<price[j] * quantity[j]
				<<endl;
		}
	
	}//for 
    
	
	//file1.clear();	
//	file1.seekg(0, ios::beg);	
    
	int userquantity, userID;
   
	cout<<endl<<"ENTER ITEM ID: ";
	cin>>userID;
	
	cout<<endl<<"ENTER THE QUANTITY YOU WANT: ";
	cin>>userquantity;

	file1.close();  //close the file after reading else it will create problems.
    
	ofstream file2("stock.txt", ios::out);

	for (int j = 0; j < i; j++) 
	{
		if (userID == ID[j]) 
		{
			quantity[j] = quantity[j] - userquantity;
			
			if (quantity[j] < 0) 
			{
				quantity[j] = 0;  // Ensure quantity doesn't go negative
			}
		}
		
		total[j] = quantity[j] * price[j];
		
		file2<<left<<setw(10)<<ID[j]
				<<setw(15)<<name[j]
				<<setw(15)<<price[j]
				<<setw(15)<<quantity[j]
				<<setw(15)<<price[j] * quantity[j]
				<<endl;

		
    }

    file2.close();
//UPDATED STOCK CODE
	
 char usersname[50];

    cout <<endl << "Enter your username again for security purpose: ";
    cin.ignore();
    cin.getline(usersname, 50);

    ifstream myfile("bestselleremployee.txt", ios::in);
    if (!myfile.is_open())
    {
        cout << "Unable to open the file." << std::endl;
    }

   //for best seller employee

    i = 0;
    int rank[20];
    char employeesname[5][100];

    while (myfile >> employeesname[i] >> rank[i])
    {
        i++;
    }
    
    myfile.close();
    
    ofstream myfile2("bestselleremployee.txt", ios::out);

    for (int j = 0; j < i; j++)
    {
        if (strcmp(usersname, employeesname[j]) == 0)
        {
            rank[j] = rank[j] + userquantity;
        }

        myfile2 <<left <<setw(10) << employeesname[j]
                <<setw(15) << rank[j]
                <<endl;
    }

    
    myfile2.close();
}
