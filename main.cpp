#include<iostream>
#include<fstream>
#include"admin.h"
#include"employees.h"
#include"customers.h"
#include "employeesorder.h"

int main()
{
	cout<<"_______________________________________________________________________________________________________ "<< endl;
	cout<<"                                                                                                       "<<endl;
	cout<<"				 		W E L C O M E  T O 						"<<endl;
	cout<<"						    C   D   S						"<<endl;
	cout<<"_______________________________________________________________________________________________________"<<endl;	
	
	
	int option;
	cout<<endl<<"Are you"<<endl<<"1. ADMIN"<<endl<<"2.EMPLOYEE"<<endl<<"3.CUSTOMER"<<endl<<"Press the respective number. ";
	cin>>option;
	cin.ignore ();
	
	switch (option)
	{//switch
		case 1: admin();
		
		break;
		
		case 2: 
			employeelogin();
		break;
		
		case 3: customers();
		
		break;
		
		default: cout<<"Invalid Input.";
		
//		break;
	}//swtich

return 0;
}
