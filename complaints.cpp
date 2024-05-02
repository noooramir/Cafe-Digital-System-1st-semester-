# include <iostream>
# include <fstream>
# include <cstring>

using namespace std;

void viewcomplaintsadmin()
{//viewcomplaints()

	char ch;
	ifstream myFile("complaints.txt",ios::in);

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

}//viewcomplaints()

void viewcomplaintscustomer()
{//viewcomplaints()
	char ch;
	char name[100];
	char txtfile[]={"_complaint.txt"};

	cin.ignore();

	cout<<endl<<"Enter Your Name for Security Reasons: ";
	cin.getline(name,100);
	
//	cin.ignore();	
	
	strcat(name,txtfile);
	
	
	ifstream myFile(name, ios::in);

	cin.ignore();
	

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
}//viewcomplaints()

void addcomplaints()
{//addcomplaints()

	char complaint[500];
	char name[100];
	char txtfile[]={"_complaint.txt"};

	cout<<endl<<"Enter Your Name for Security Reasons: ";
	cin.getline(name,100);
	
	strcat(name,txtfile);

	//for user
	ofstream file;
	file.open(name, ios::out | ios::app);
			
	//for admin
	ofstream file1;
	file1.open("complaints.txt", ios::out | ios::app);

	if ( !file.is_open() && !file1.is_open() ) 
	{
		cout << "Unable to open the file." << endl;
	} 
	else 
	{
		cout<<endl<<"Enter your complaint."<<endl
			<<"\033[40;31m"
			<<"!!WARNING!!"
			<<"\033[0m"<<endl
			<<"Once entered, it can not be removed!"
			<<endl;
	
			cin.getline(complaint,500);
				
			file<<complaint<<" "<<endl;
			file1<<complaint<<" "<<endl;
				
			file.close();
				
			file1.close();
						
			}
			

			

}//addcomplaints()
