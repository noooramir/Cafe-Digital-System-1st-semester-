# include <iostream>
# include <fstream>
# include <cstring>
#include<iomanip>
#include"stock.h"
#include "complaints.h"
#include "onlineschedule.h"
#include "employeescredentials.h"
#include "customerscredentials.h"

using namespace std;

void admin()
{//admin();

	cout<<"_______________________________________________________________________________________________________ "<< endl;
	cout<<"                                                                                                       "<<endl;
	cout<<"				 		A D M I N 						"<<endl;
	cout<<"						L O G I N						"<<endl;
	cout<<"_______________________________________________________________________________________________________"<<endl;

	int count=0,count1=0,inputt,op;
		
//reading and comparing from the .txt file

	fstream login2;
	login2.open("adminlogin.txt", ios::in);
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
		cout<<endl<<endl<<setw(57)<<"!!LOGIN!!"<<endl;

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

	}//else
	
//reading and comparing from the .txt file
	
	if (count == 1) 
	{//if count==1
		cout<<endl
		<< "1. Stock." << endl //C O M P L E T E D
		<< "2. Employee's Credential." << endl //C O M P L E T E D
		<< "3. Notifications." << endl //C O M P L E T E D
		<< "4. Online/Scheduled Order." << endl //C O M P L E T E D
		<< "5. Complaints." << endl //C O M P L E T E D
		<< "6. Best Seller Employee." << endl //C O M P L E T E D
		<< "7. Customer's Credentials."<<endl //C O M P L E T E D
		<< "8. Sales."<<endl
		<< "Enter the number to select the following choice: ";
		cin >> inputt;
		
		cin.ignore();


		switch (inputt) 
		{//input switch
			case 1: 
			{//case 1
				//C O M P L E T E D
				int n;
				cout<<endl
					<<"1. View Stock."<<endl
					<<"2. Add New Stock."<<endl
					<<"3. Stock Removal."<<endl	
					<<"4. Order and Update Stock."<<endl
					<<"5. Search."<<endl
					<<"Enter the number to select the following choice: ";
				cin>>n;
				
				switch(n)
				{//swtich 2
					case 1:
					{//case 1
						viewstock();
					}//case 1
					
					break; //case 1
					
					case 2	:
					{//case 2

				
						newstock();
	
					}//case 2
					
					break; //case 2
					
					case 3:
					{//case 3
							viewstock();			
							removingstock();

					}//case 3
					
					break;//case 3
					
					case 4:
					{//case 4
						//Order and Update Stock
						
						viewstock();
						orderandupdate();
					
					}//case 4
					
					case 5:
					{//case 5
						searchstock();
					}//case 5
					
					break;//case 5
					
					break;//case 4
					
					default:
					{
						cout<<endl<<"Invalid Input.";
					}
				
					break;
				
				}//swtich 2
				
				break;//case 1
			
				}//case 1

				case 2: 
				{//case 2 
					//C O M P L E T E D
					
					cout<<endl<< "Employees' Credential: "<<endl<<endl<<endl;
					
					int n;
					cout<<"1. View Employees' Credentials."<<endl
						<<"2. Add Employee."<<endl
						<<"3. Modify Credentials."<<endl
						<<"4. Remove an Employee."<<endl
						<<"5. Search an Employee"<<endl
						<<"Enter your choice: ";
						
					cin>>n;
					
					cout<<endl<<endl;
					
					switch(n)
					{//switch
						case 1: //View Employees' Credentials.
							viewemployeescredentials();
						break;
						
						case 2:
						{//case 2
							//Add Employee.
							
							int i=0;
							cout<<endl<<"Enter the number of employees you want to add: ";
							cin>>i;
							
							addemployees(i);
						
						}//case 2
						
						break;//case 2
						
						case 3:
						{//case 3
							//Modify Credentials.
							
							const int size=6;
				
							modifyemployeescredentials(size);
							
							
						}//case 3
						
						break;//case 3
						
						case 4:
						{//case 4
							//Remove an Employee.
							
							const int size=6;
							
							removingemployeescredentials(size);
							
						
						}//case 4
						
						break;//case 4
						
						case 5:
						{//case 5
							//Search an Employee
							
							searchemployee();
							
						}//case 5
						
						break;//case 5
						
						default: cout<<endl<<"Invalid Input."<<endl;
						break;
					
					}//switch
				
				break;//case 2
			
				}//case 2

				case 3: 
				{//case 3
					//C O M P L E T E D
					
					cout << endl 
						<< "1. SHOW NOTIFICATIONS" << endl 
						<< "2. ADD NOTIFICATION." << endl 
						<< "3. REMOVE NOTIFICATION." << endl 
						<< "Enter your choice: ";
					cin >> op;
	
					switch (op) 
					{//notification switch
						case 1: //SHOW NOTIFICATIONS
						{//case 1
							char ch;
							ifstream myFile("notification.txt");
	
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
						
						break;//case 1
						
						}//case 1
	
						case 2: //ADD NOTIFICATIONS
						{//case 2
							cout << "Enter text to add to notifications: ";
							cin.ignore();
							
							char notification[100];
							cin.getline(notification,100,'/');
	
							ofstream file("notification.txt", ios::out | ios::app);
	
							if (!file.is_open()) 
							{
								cout << "Unable to open the file." << endl;
							} 
							else 
							{
								file<<notification<<" "<<endl;
							file.close();
							
							}
						break;//case 2
						
						}//case 2
						break;//case 2
	
						case 3: //REMOVE NOTIFICATIONS
						{//case 3
							//reading the notification.txt file first.
							char notification[50][500];
						//	char notificationremoval[50][500];
							
							int i=0;
							
							ifstream myfile("notification.txt", ios::in);
							
							if (!myfile.is_open()) 
							{
								cout << "Unable to open the file." << endl;
							} 
							
							else 
							{
								
								while (myfile.getline(notification[i], 500)) 
								{
									i++;
								}
							}

							myfile.close();
							
							ofstream myfile2("notification.txt", ios::out);
							if (!myfile2.is_open()) 
							{
								cout<<"Unable to open the file."<<endl;
							} 
							
							else 
							{//else
							//	cin.ignore();

								int n=0;
								cout << endl << "Enter the notification you want to remove: " << endl;
								cin>>n;
								
								n=n-1; //array starts from 0 not 1.
								
								for(int j=0; j<i;j++)
								{
									if (n==j)
										continue;
									else
										myfile2<<notification[j]<<endl;
								}
								myfile2.close();

							
							}//else
							
							
	            				}//case 3
	            			}//notification switch
				}//CASE3 NOTIFICATIONS 
			
			break;//CASE3 NOTIFICATIONS 
			
				case 4: 
				{
					//C O M P L E T E D
					cout<<endl<<"Online/Scheduled Order"<<endl<<endl;
					viewonlinescheduleadmin();

				break;
				}

				case 5: 
				{
					//C O M P L E T E D
					
					cout<<endl<<"COMPLAINTS:"<<endl<<endl;
					viewcomplaintsadmin();

				break;
				}

				case 6: 
				{
					//C O M P L E T E D
					
					cout << endl << "B E S T  S E L L E R  E M P L O Y E E" << endl;
					
					ifstream bestseller("bestselleremployee.txt", ios::in);
					
					if (!bestseller.is_open())
						cout<<endl<<"Unable to open the file."<<endl;
					else
					{//else
						char bestemp[50];

						char employeesname[5][50];
						int rank[5];
						
						int k=0;
						
						while (bestseller >> employeesname[k]>>rank[k]) 
						{
							k++; //using it for bubble sorting
						}
						
						for (int i=0;i<k;i++) //n=i ; line 110
						{//for 1
							for (int j=0;j<k-i-1;j++)
							{//for 2
								if( rank[j] < rank [j+1] )
								{//if

									swap(rank[j],rank[j+1]);
				
									char temporary[100];
									strcpy(temporary,employeesname[j]);
									strcpy(employeesname[j],employeesname[j+1]);
									strcpy(employeesname[j+1],temporary);
									
						
								}//if
							}//for 2
						}//for 1
						
						cout<<endl<<left<<setw(20)<<"EMPLOYEE'S NAME"
							<<setw(5)<<"SALE"<<endl<<endl;	
	
						for (int j=0;j<k;j++)
						{//for
							if (j==0)
							{
								
							
							cout<<endl<<left<<"\033[40;32m"<<setw(20)<<employeesname[j]
							<<setw(5)<<rank[j]
							<<"\033[0m"<<endl;
							}
							else 
							{
							cout<<endl<<left<<setw(20)<<employeesname[j]
							<<setw(5)<<rank[j]
							<<endl;
							}
							
						}//for

				//		cout<<endl<<endl<<"The Best Employee Goes to "<<bestemp<<endl;
					}//else
					

				break;
				}
				
				case 7:
				{//case 7
					//C O M P L E T E D
					
					cout<<endl<< "Customer's Credential: "<<endl<<endl<<endl;
					
					int n;
					cout<<"1. Search Customer."<<endl //C O M P L E T E D
						<<"2. Add Customer."<<endl //C O M P L E T E D
						<<"3. Modify Credentials."<<endl //C O M P L E T E D
						<<"4. Remove an Customer."<<endl //C O M P L E T E D
					/*	<<"5.  View Customer's Credentials."<<endl	*/
						<<"Enter your choice: ";
						
					cin>>n;
					
					cout<<endl<<endl;
					
					switch(n)
					{//switch
						case 1:
						{
							searchcustomer();
						}
						
						break;
						
						case 2:
						{
							
							int i=0;
							cout<<endl<<"Enter the number of employees you want to add: ";
							cin>>i;
							
						addcustomers(i);
						}
						
						break;
						
						case 3:
						{
							const int size=6;
							modifycustomerscredentials(size);
						}
						
						break;
						
						case 4:
						{
							const int size=6;
							removingcustomerscredentials(size);
						}
						
						case 5:
						{
						
						}
						
						break;
					}//switch
					
				}//case 7
				
				break;//case 7
				
				case 8:
				{//case 8
					//C O M P L E T E D
					
					//S A L E S
						//reading the file first.
						
						char ch;
						int size = 0;

						ifstream file1("stock.txt");

						if (!file1.is_open()) 
						{
							cout << "Unable to open the file." << endl;
						}

						while (file1.get(ch)) 
						{
							if (ch == '\n')
								size++;
						}

						file1.clear();
						file1.seekg(0, ios::beg);

						int* ID = new int[size];
						int* price = new int[size];
						int* total = new int[size];
						int* quantity = new int[size];
						char** name = new char*[size];

						for (int j = 0; j < size; j++) {
						name[j] = new char[100];
						}

						int i = 0;

						while (file1 >> ID[i] >> name[i] >> price[i] >> quantity[i] >> total[i]) {
							i++;
						}

						file1.close();

						ofstream sales("average.txt", ios::out | ios::app);

						int sum = 0, avg=0;

							/*
						    cout << left << setw(20) << "ITEM NAME"
							 << setw(20) << "ITEM QUANTITY" << endl;
							 */

						for (int j = 0; j < i; j++) {
						sum = sum + quantity[j];

						sales << left << setw(20) << name[j]
						<< setw(20) << quantity[j]
						<< endl;
						}

						avg=sum/i;
						
						sales << endl << setw(20) << sum
							<< setw(20) << avg
							<< endl<<endl<<endl;
							

						sales.close();
	

						    // Deallocate memory
							delete[] ID;
							delete[] price;
							delete[] total;
							delete[] quantity;
	
						for (int j = 0; j < size; j++) 
						{
							delete[] name[j];
						}

						delete[] name;
						
						ifstream orders("average.txt", ios::in);
						
						if(!orders.is_open())
						{
							cout<<endl<<"Unable to open the file."<<endl;
						}
						
						else
						{
							char ch;
							
							while(orders.get(ch))
							{
								cout<<ch;
							}
							cout<<endl;
						}
						orders.close();
						
						
						}//case 8
				
				break; //case 8

				default:
				{
					cout << endl << "Invalid Input.";
				break;
				}
			}//input switch
    		}//if count==1
}//admin();
