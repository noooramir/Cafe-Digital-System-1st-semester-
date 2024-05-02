#include <iostream>
#include <string>
#include <fstream>
#include <cstring> //used for strcpy, strcmp, etc
#include"stock.h"
#include "complaints.h"
#include "onlineschedule.h"
#include "games.h"

using namespace std;

static int bill=0;

void search()
{//search()
	
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

	if (!file1.is_open())
	{
		cout << "Unable to open the file." << endl;
	}

	int i = 0;

	int *ID = new int[size];
	int *price = new int[size];
	int *quantity = new int[size];
	int *total = new int[size];
	char **name = new char *[size];

	for (int j = 0; j < size; j++)
	{
		name[j] = new char[100];
	}

		
	while (file1 >> ID[i] >> name[i] >> price[i] >> quantity[i] >> total[i]) 
	{
		i++; 
	}
	file1.close();
	
	
	int flag=0,k=0;
	char itemname[100];
	
	cout<<endl<<"Enter the item's name you want to search (IN CAPS): ";
	cin.getline(itemname,100);

	
	for(int i=0; i<20;i++)
	{//for 1

		if(!(strcmp(itemname, name[i])==0) &&  flag==0)
		{//if
			k++;
		}//if
		
		if(strcmp(itemname, name[i])==0)
		{
			flag=1;
			break;
		}

	}//for 1
	
	
	if (flag==1)
		cout<<"Item Found."<<endl
		<<"At row "<<k<<endl;
	else
		cout<<endl<<"Item Not Found."<<endl;	
		
	i=0;
	int userquantity;

	if (flag==1)
	{//if
	cout<<endl<<"Do you want to order the particular Item?"<<endl
		<<"Enter '1' for yes and '2' for no. ";
	cin>>i;
	
	switch(i)
	{//switch
		case 1:
		{//case 1
		
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

			if (!file1.is_open())
			{
				cout << "Unable to open the file." << endl;
			}


			int *ID = new int[size];
			int *price = new int[size];
			int *quantity = new int[size];
			int *total = new int[size];
			char **name = new char *[size];

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

			file1.close();
			
			
//			cin.ignore();

			cout<<endl<<"Enter the quantity: ";
			cin>>userquantity;
			
			cin.ignore();
			
			ofstream file2("stock.txt", ios::out);

		//	cout<<endl<<"1";

			for (int j = 0; j < i; j++) 
			{
		//	cout<<endl<<"2";			
				if (strcmp(itemname, name[j]) == 0)
				{// if comparison
				/*	if (quantity[j] < 0) 
					{	
						quantity[j] = 0;  // Ensure quantity doesn't go negative
					}
				*/	
				//	quantity[j] = quantity[j] - userquantity;
			
			//	cout<<endl<<"3";		
					if (quantity[j]< userquantity) //check for insufficient stock.
					{
						cout<<endl<<"NOT ENOUGH STOCK."<<endl;
					}
					
					else if (quantity[j]==0) //check for out of stock
					{
						cout<<endl<<"OUT OF STOCK."<<endl;
					}
					else 
						quantity[j] = quantity[j] - userquantity;
						
					if (quantity[j] < 0) 
					{	
						quantity[j] = 0;  // Ensure quantity doesn't go negative
					}
					
					
				}// if comparison
			
			bill=userquantity * price[j];
			
			total[j] = quantity[j] * price[j];
		
			file2<<left<<setw(10)<<ID[j]
				<<setw(15)<<name[j]
				<<setw(15)<<price[j]
				<<setw(15)<<quantity[j]
				<<setw(15)<<price[j] * quantity[j]
				<<endl;

		
			}

			file2.close();
			
			
		}//case 1
		
		break;//case 1
		
		case 2:
		{//case 2
			//cout<<endl<<"Thank You for your time. We hope you have a lovely day!"<<endl;
		break;//case 2				
			
		}//case 2
		
	//	case 3:
	//	case 4:
		default:
		{
			cout<<endl<<"Invalid Input."<<endl;
		}
		
		break;
	
	}//switch
	}//if
	
	
}//search()


void customers() 
{
	int n;
	int count=0,inputt,op;
	
	cout<<endl<<endl<<"CUSTOMER!"<<endl
		<<"Are you"<<endl
		<<"1. New (Sign UP)"<<endl
		<<"2. Old (Login)"<<endl
		<<"Enter one of the following choice: ";
	cin>>n;
	
	switch(n)
	{//switch login
		
		case 1:
		{//case 1
				//writing into .txt file

		cout<<"_______________________________________________________________________________________________________ "<< endl;
		cout<<"                                                                                                       "<<endl;
		cout<<"                                              C U S T O M E R                                          "<<endl;
		cout<<"                                          R E G I S T R A T I O N                                      "<<endl;
		cout<<"_______________________________________________________________________________________________________"<<endl;				
				
				fstream login1;
				login1.open("customerslogin.txt", ios::out | ios::app);
				
				cin.ignore();
				
				char username[100];
				char password[100];	
				
				if ( !login1.is_open() )
				{
					cout<<"File not open."<<endl;
				}
				else
				{
					
					cout<<endl<<"Enter Username: ";
					cin.getline(username,100,'\n');
					
					cout<<"Enter Password: ";
					cin.getline(password,100,'\n');

					login1<<username<<"\t"<<password<<endl;
					
					login1.close();
				}
				
			//writing into .txt file
			
//				int count=0,inputt,op;

		cout<<"_______________________________________________________________________________________________________ "<< endl;
		cout<<"                                                                                                       "<<endl;
		cout<<"                                              C U S T O M E R                                          "<<endl;
		cout<<"                                                 L O G I N                                             "<<endl;
		cout<<"_______________________________________________________________________________________________________"<<endl;
						
				//reading and comparing from the .txt file

					fstream login2;
					login2.open("customerslogin.txt", ios::in );
					char user[100];
					char pass[100];
					char actualusername[100];
					char actualpassword[100];
					
					if ( !login2.is_open() )
					{
						cout<<"File not open."<<endl;
					}
					else
					{//else
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
						}

					}//else
					
				//reading and comparing from the .txt file
				
		}//case 1
		
		break; //case 1
		
		case 2:
		{//case 2
//						int count=0,inputt,op;

		cout<<"_______________________________________________________________________________________________________ "<< endl;
		cout<<"                                                                                                       "<<endl;
		cout<<"                                              C U S T O M E R                                          "<<endl;
		cout<<"                                                 L O G I N                                             "<<endl;
		cout<<"_______________________________________________________________________________________________________"<<endl;
						
				//reading and comparing from the .txt file
					cin.ignore();
					fstream login2;
					login2.open("customerslogin.txt", ios::in );
					char user[100];
					char pass[100];
					char actualusername[100];
					char actualpassword[100];
					
					if ( !login2.is_open() )
					{
						cout<<"File not open."<<endl;
					}
					else
					{//else
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
						}

					}//else
					
				//reading and comparing from the .txt file
		}//case 2
		
		break;//case 2
		
		default: cout<<endl<<"INVALID INPUT"<<endl;
		break;
		
	}//switch login
	
//	int count=0, inputt;
	if(count==1) 
	{//if cds
		cout<<endl<<"WELCOME TO CAFE"<<endl;
		
		cout<<endl<<"1. Search and Order."<<endl //C O M P L E T E D
			<<"2. Online/Scheduled Orders."<<endl //C O M P L E T E D
			<<"3. View Notifications"<<endl //C O M P L E T E D
			<<"4. Play Games."<<endl
			<<"5. Complaints"<<endl //C O M P L E T E D
			<<endl<<"Enter number for your choice: ";
			
		cin>>inputt;
		cin.ignore();
		
//		customer(inputt);
	
	}//if cds
	
		string order;
	switch(inputt)
	{
		case 1:
		{//case 1 
//			cout<<"Search and Order: ";
			search();
			
			int n;
			cout<<endl<<"Do you want to order again? "<<endl
				<<"Enter '1' for yes and '2' for no.";
			cin>>n;
			
			switch(n)
			{//switch
				case 1:
				{//case 1
					search();
					
					
					cout<<left<<setw(40)<<"****************************************"<<endl
						<<setw(16)<<"*"<<setw(8)<<"B I L L"<<right<<setw(16)<<"*"<<endl
						<<setw(40)<<"****************************************"<<endl;
			
					cout<<endl<<left<<setw(30)<<"Thank You for your time. We hope you have a lovely day!"<<endl
						<<setw(15)<<"Your Total: "
						<<setw(15)<<bill
						<<endl;
				}//case 1
				
				break;//case 1
				
				case 2:
				{//case 2
			//		cout<<endl<<"Thank You. We hope you a lovely day!"<<endl;
			
					cout<<left<<setw(40)<<"****************************************"<<endl
						<<setw(16)<<"*"<<setw(8)<<"B I L L"<<right<<setw(16)<<"*"<<endl
						<<setw(40)<<"****************************************"<<endl;
			
					cout<<endl<<left<<setw(30)<<"Thank You for your time. We hope you have a lovely day!"<<endl
						<<setw(15)<<"Your Total: "
						<<setw(15)<<bill
						<<endl;
				}//case 2
				
				break;//case 2
				
				default:
				{
					cout<<endl<<"INVALID INPUT."<<endl;
				}
				
				break;
			
			}//switch
			
			

		}//case 1
		
		break;
		
		case 2:
		{//case 2
			//C O M P L E T E D
			
			int n;
			
			cout<<endl<<"1. Schedule an Order."<<endl
				<<"2. View Scheduled Order."<<endl
				<<"Enter a number to select: ";
			cin>>n;	
			
			switch(n)
			{//switch
				case 1:
				{//case 1
					onlineschedule();
				}//case 1
				
				break;//case 1
				
				case 2:
				{//case 2
					viewonlineschedulecustomer();
				}//case 2
				
				break;//case 2
				
				default: cout<<endl<<"INVALID INPUT"<<endl;
				
				break;
			
			}//switch
			
		}//case 2
		
		break;
		
		case 3:
		{//case 3
			//C O M P L E T E D
			
			cout<<"View Notifications: ";
			char ch;
						ifstream myFile;
						myFile.open("notification.txt", ios::in);

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

		}//case 3

		break;
		
		case 4:
		{//case 4
			cout<<endl<<endl<<"Play Games: "<<endl<<endl;
			
			int n;
			
			cout<<endl<<"1. Play with Binary."<<endl
				<<"2. Patterns."<<endl
				<<"3. High and Low."<<endl
				<<"4. Guess the Number."<<endl
				<<"Enter your choice: ";
			cin>>n;
			
			switch (n)
			{//switch
				case 1:
					playwbinary();
				break;
				
				case 2: 
					seepatters();			
				break;
				
				case 3:
					playHandL();
				break;
				
				case 4: 
					guessnumber();
				break;
				
				default: cout<<endl<<"INVALID INPUT."<<endl;
				break;
			}//switch
			
		}//case 4
		break;
		
		case 5:
		{//case 5
			//C O M P L E T E D
			
			int n; 
			cout<<"1. View Your Complaints."<<endl
				<<"2. Add a New Complaint.";
			cin>>n;
			
			switch (n)
			{//swtich 1
				case 1:
				{//case 1
					viewcomplaintscustomer();
				}//case 1
				
				break;//case 1
				
				case 2:
				{//case 2
					addcomplaints();
				}//case 2
				
				break;//case 2
				
				default:
				{
					cout<<endl<<"Invalid Input.";
				}
				
				break;
			}//switch 1
			
			
		}//case 5
		
		break;
		
		default: cout<<endl<<"Invalid Input.";
		break;
	}

//return 0;
}
