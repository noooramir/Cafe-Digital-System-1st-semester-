#include <iostream>
#include <string>
#include <fstream>
#include"stock.h"
#include "onlineschedule.h"
#include "employeesorder.h"

using namespace std;

void employeefunctions(int count)
{	

	int inputt;

	if(count>0)
	{//if cds
		cout<<" _______________________________________________________________________________________________________ "<< endl;
		cout<<"|                                                                                                       |"<<endl;
		cout<<"|                                           W E L C O M E  T O                                          |"<<endl;
		cout<<"|                                                C  D  S                                                |"<<endl;
		cout<<"|_______________________________________________________________________________________________________|"<<endl;

		cout<<endl<<"WELCOME TO CDS"<<endl;
		
		cout<<endl<<"1. Order."<<endl //C O M P L E T E D
			<<"2. View Stock."<<endl //C O M P L E T E D
			<<"3. Online/Scheduled Orders."<<endl //C O M P L E T E D
		/*	<<"4. Custom Orders."<<endl	*/
			<<"Enter number for your choice: ";
		cin>>inputt;
		
		cin.ignore();
	}//if cds
	

	switch(inputt)
	{
		case 1:
		{//case 1 
			
			//C O M P L E T E D
			
//			cout<<"Order: ";
			cout<<endl<<endl<<endl;
			order();

//			cout<<order;
		}//case 1
		
		break;
		
		case 2:
		{//case 2
			
			//C O M P L E T E D
		
			cout<<endl<<"STOCK: "<<endl<<endl;
			viewstock();
		}//case 2
		
		break;
		
		case 3:
		{//case 3
		
			//C O M P L E T E D
			
			int n;

			cout<<endl<<"ONLINE SCHEDULE/ORDERS: "<<endl<<endl;

			cout<<endl<<"1. Take Scheduled Order."<<endl
				<<"2. View Online Scheduled Orders."<<endl
				<<"Enter your choice: ";
			cin>>n;
			switch(n)
			{//switch

				case 1:
				{
					takeonlinescheduleadmin();
				}
				
				break;
				
				case 2:
				{
					viewonlinescheduleadmin();
				}
				
				break;
				
				default: cout<<"Invalid Input."<<endl;
				break;
			}//switch
			
		}//case 3

		break;
		
		case 4:
		{//case 4
			cout<<"Order: ";

		}//case 4
		break;
		
		default: cout<<endl<<"Invalid Input.";
		break;
	}

	
	


//return 0;
}

void employeelogin() 
{
	int count=0,inputt,op;
//reading and comparing from the .txt file

	fstream login2;
	login2.open("employeeslogin.txt", ios::in);
	char user[100];
	char pass[100];
	char actualusername[100];
	char actualpassword[100];
	int count1=0;
	
	if ( !login2.is_open() )
	{
		cout<<"File not open."<<endl;
	}
	else
	{//else
	
		cout<<"_______________________________________________________________________________________________________ "<< endl;
		cout<<"                                                                                                       "<<endl;
		cout<<"                                              E M P L O Y E E                                          "<<endl;
		cout<<"                                                 L O G I N                                             "<<endl;
		cout<<"_______________________________________________________________________________________________________"<<endl;	


//		cout<<"!!LOGIN!!"<<endl;
		
		loginagain:
		cout<<endl<<"Enter Username: ";
		cin.getline(user,100);
			
		
		cout<<"Enter Password: ";
		cin.getline(pass,100);
		

		while(login2>>actualusername>>actualpassword)
		{//login2 while
			
			if (strcmp(user,actualusername)==0 && strcmp(pass,actualpassword)==0)
			{
				count++;
				break;
			}
			
		}//login2 while
		login2.close();
		
		
		if (count>0)
		{
			cout<<endl<<"LOGIN SUCCESSFUL."<<endl;
		}
		else
		{
			cout<<endl<<"LOGIN FAILED."<<endl;
			
			count1++;
			
			if (count1>=3)
			{
				// "\033[40;31m" sets the color to red and background to black.
				cout<<endl<<"\033[40;31m"<<"S E C U R I T Y  A L E R T ! ! !"<<"\033[0m"<<endl
					<<endl<<"You have failed "<<"\033[40;31m"<<"THREE"<<"\033[0m"<<" times."<<endl /*resets the color back to original*/
					<<endl<<"Come back again Later."<<endl;
					exit(0);
			}
			
			//jumps back to loginagain part if login is failed.
			
			goto loginagain;
			
			
					
		}
		
		employeefunctions(count);

	}//else
	
}//reading and comparing from the .txt file
