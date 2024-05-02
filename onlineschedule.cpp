#include <iostream>
#include <string>
#include <fstream>
#include <cstring> //used for strcpy, strcmp, etc
#include"stock.h"
#include "complaints.h"

void takeonlinescheduleadmin()
{//takeonlinescheduleadmin()
	
	char time[20];
	int totalprice;
	char usersname[100]; //name input
	char txtfile[]={"_onlineschedule.txt"};
	
	cin.ignore();

	cout<<endl<<"Enter Your Name: ";
	cin.getline(usersname,100);
	
	strcat(usersname,txtfile);
	
	//read stock.txt
	ifstream file1("stock.txt");

	if (!file1.is_open()) 
	{
		cout << "Unable to open the file." << endl;
	}
	
	int i = 0;
	int ID[20], price[20], quantity[20], total[20];
	char name[20][100];
	
	while (file1 >> ID[i] >> name[i] >> price[i] >> quantity[i] >> total[i]) 
	{
		i++; //using it for bubble sorting
	}
	
	int userquantity, userID;
   
	cout<<endl<<"ENTER ITEM ID: ";
	cin>>userID;
	
	cout<<endl<<"ENTER THE QUANTITY YOU WANT: ";
	cin>>userquantity;
	
	cin.ignore();
	
	cout<<endl<<"ENTER THE TIME YOU WANT: ";
	cin.getline(time,10);

	file1.close();  //close the file after reading else it will create problems.
    
	ofstream file2("stock.txt", ios::out);
	
	for (int j = 0; j < i; j++) 
	{
		if (userID == ID[j]) 
		{
			quantity[j] = quantity[j] - userquantity;
			
			
			if (quantity[j] < 0) 
			{
				quantity[j] = 0;  // ensure quantity doesn't go negative
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
    
    
    //for user 
    ofstream myfile1;
    myfile1.open(usersname, ios::out | ios::app);
    
    //for admin
    ofstream myfile2;
    myfile2.open("onlineschedule.txt", ios::out | ios::app);
    
    if ( !myfile1.is_open() && !myfile2.is_open() )
    {
    	cout<<endl<<"Unable to open the file."<<endl;
    }
    else 
    {//else
    	myfile1<<setw(30)<<"******************************"<<endl
		<<setw(6)<<"******"<<setw(18)<<"Y O U R  O R D E R"<<setw(6)<<"******"<<endl
		<<setw(30)<<"******************************"<<endl;
		
    	for (int j = 0; j < i; j++) 
	{//for
		if (userID == ID[j]) 
		{

			//writing into user's file
			
			myfile1<<left<<setw(20)
				<<"I T E M"<<setw(20)
				<<"T O T A L"<<setw(15)
				<<"T I M E"
				<<endl;
				
				
			myfile1<<left<<setw(20)
			<<name[j]<<setw(20)
			<<userquantity*price[j]
			<<setw(15)<<time
			<<endl;
			
			//writing into admin's file
			
			myfile2<<left<<setw(20)
			<<name[j]<<setw(20)
			<<userquantity*price[j]
			<<setw(15)<<time
			<<endl;
			
			break;
			
		}
	}//for
    
    }//else
    
    myfile1.close();
    myfile2.close();    

	char empname[50];

	cin.ignore();	

	cout<<endl<<"FOR EMPLOYEES ONLY"<<endl<<endl;
	cout<<"Enter your username: ";
	cin.getline(empname, 50);
	
	ifstream bestemp("bestselleremployee.txt", ios::in);
    if (!bestemp.is_open())
    {
        cout << "Unable to open the file." << std::endl;
    }

   //for best seller employee

    i = 0;
    int rank[20];
    char employeesname[6][100];

    while (bestemp >> employeesname[i] >> rank[i])
    {
        i++;
    }
    
    bestemp.close();
    
    ofstream bestemployee("bestselleremployee.txt", ios::out);

    for (int j = 0; j < i; j++)
    {
        if (strcmp(usersname, employeesname[j]) == 0)
        {
            rank[j] = rank[j] + userquantity;
        }

        bestemployee <<left <<setw(10) << employeesname[j]
                <<setw(15) << rank[j]
                <<endl;
    }

    
    bestemployee.close();
	
	
	
}//takeonlinescheduleadmin()

void viewonlinescheduleadmin()
{
	char ch;
	ifstream myFile("onlineschedule.txt");
	
	if (!myFile.is_open()) 
	{
		cout << "Unable to open the file." << endl;
	} 
	else 
	{
		while (myFile.get(ch)) 
		{
			cout << ch;
		}
										
		myFile.close();
	}
}

void viewonlineschedulecustomer()
{//viewonlineschedulecustomer()
	
	char usersname[100]; //name input
	char txtfile[]={"_onlineschedule.txt"};

	cout<<endl<<"Enter Your Name for Security Reasons: ";
	cin.getline(usersname,100);
	
	strcat(usersname,txtfile);
	
	
	char ch;
	ifstream myFile(usersname, ios::in);
	
	if (!myFile.is_open()) 
	{
		cout << "Unable to open the file." << endl;
	} 
	else 
	{
		while (myFile.get(ch)) 
		{
			cout << ch;
		}
										
		myFile.close();
	}	
	
}//viewonlineschedulecustomer()

void onlineschedule()
{//onlineschedule

	viewstock();
	
//	char itemsname[20];
	char time[20];
	int totalprice;
	char usersname[100]; //name input
	char txtfile[]={"_onlineschedule.txt"};

	cout<<endl<<"Enter Your Name for Security Reasons: ";
	cin.getline(usersname,100);
	
	strcat(usersname,txtfile);
	
	//read stock.txt
	ifstream file1("stock.txt");

	if (!file1.is_open()) 
	{
		cout << "Unable to open the file." << endl;
	}
	
	int i = 0;
	int ID[20], price[20], quantity[20], total[20];
	char name[20][100];
	
	while (file1 >> ID[i] >> name[i] >> price[i] >> quantity[i] >> total[i]) 
	{
		i++; //using it for bubble sorting
	}
	
	int userquantity, userID;
   
	cout<<endl<<"ENTER ITEM ID: ";
	cin>>userID;
	
	cout<<endl<<"ENTER THE QUANTITY YOU WANT: ";
	cin>>userquantity;
	
	cin.ignore();
	
	cout<<endl<<"ENTER THE TIME YOU WANT: ";
	cin.getline(time,10);

	file1.close();  //close the file after reading else it will create problems.
    
	ofstream file2("stock.txt", ios::out);
	
	for (int j = 0; j < i; j++) 
	{
		if (userID == ID[j]) 
		{
			quantity[j] = quantity[j] - userquantity;
			
//			itemsname=name[j];
			
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
    
    //for user 
    ofstream myfile1;
    myfile1.open(usersname, ios::out | ios::app);
    
    //for admin
    ofstream myfile2;
    myfile2.open("onlineschedule.txt", ios::out | ios::app);
    
    if ( !myfile1.is_open() && !myfile2.is_open() )
    {
    	cout<<endl<<"Unable to open the file."<<endl;
    }
    else 
    {//else
    	myfile1<<setw(30)<<"******************************"<<endl
		<<setw(6)<<"******"<<setw(18)<<"Y O U R  O R D E R"<<setw(6)<<"******"<<endl
		<<setw(30)<<"******************************"<<endl;
		
    	for (int j = 0; j < i; j++) 
	{//for
		if (userID == ID[j]) 
		{

			//writing into user's file
			
			myfile1<<left<<setw(20)
				<<"I T E M"<<setw(20)
				<<"T O T A L"<<setw(15)
				<<"T I M E"
				<<endl;
				
				
			myfile1<<left<<setw(20)
			<<name[j]<<setw(20)
			<<userquantity*price[j]
			<<setw(15)<<time
			<<endl;
			
			//writing into admin's file
			
			myfile2<<left<<setw(20)
			<<name[j]<<setw(20)
			<<userquantity*price[j]
			<<setw(15)<<time
			<<endl;
			
			break;
			
		}
	}//for
    
    }//else
    
    myfile1.close();
    myfile2.close();    
    

	
}//onlineschedule
