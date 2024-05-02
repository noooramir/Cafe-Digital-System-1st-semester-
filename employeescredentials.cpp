#include <iostream>
#include <string>
#include <fstream>
#include <cstring> //used for strcpy, strcmp, etc

using namespace std;

void searchemployee()
{//searchemployee()
	
	const int size = 7;


	ifstream file1("employeeslogin.txt");

/*
	while (file1.get(ch))
	{
		if (ch == '\n')
		size++;
	}

	file1.clear();
	file1.seekg(0, ios::beg);
*/
	if (!file1.is_open())
	{
		cout << "Unable to open the file." << endl;
	}
	
	char username[size][20];
	char password[size][20];
	int i=0;
	
	while(file1>>username[i]>>password[i])	
	{
		i++;
	}
	cin.ignore();
	file1.close();
	
	
	int flag=0,k=0;
	char empname[100];
	
	cout<<endl<<"Enter the employee's name you want to search: ";
	cin.getline(empname,100);

	
	for(int i=0; i<20;i++)
	{//for 1

		if(!(strcmp(empname, username[i])==0) &&  flag==0)
		{//if
			k++;
		}//if
		
		if(strcmp(empname, username[i])==0)
		{
			flag=1;
			break;
		}

	}//for 1
	
	k=k+1;
	
	if (flag==1)
		cout<<"Employee Found."<<endl
		<<"At row "<<k<<endl;
	else
		cout<<endl<<"Employee Not Found."<<endl;	
	
}//searchemployee()

void removingemployeescredentials(const int size)
{//removingemployeescredentials()
	

	char username[size][20];
	char password[size][20];

	ifstream myfile("employeeslogin.txt", ios::in);

	int i = 0;

	while (myfile >>username[i] >> password[i]) 
	{
		i++;
	}

	myfile.close();

	char name[100];
	
	cin.ignore();
	
	cout << endl << "Enter the employee you want to remove: ";
	cin.getline(name, 100);

	ofstream myfile2("employeeslogin.txt", ios::out);

	for (int j = 0; j < i; j++) 
	{
		if (strcmp(name, username[j]) != 0) 
		{
			myfile2 << left << setw(20) << username[j]
				<< setw(20) << password[j]
				<< endl;
		}
	}

	myfile2.close();
	
	ifstream empcres("bestselleremployee.txt",ios::in);
	
	char ausername[size][20];
	char rank[size][20];

	i=0;
	
	
	while(empcres>>ausername[i] >> rank[i]) 
	{
		i++;
	}
	
	empcres.close();
	
	
	
	ofstream empcred("bestselleremployee.txt", ios::out);
	
	for (int j = 0; j < i; j++) 
	{
		if (strcmp(name, ausername[j]) != 0) 
		{
			empcred << left << setw(20) << username[j]
				<< setw(20) << rank[j]
				<< endl;
		}
	}
	empcred.close();
	
}//removingemployeescredentials()

void modifyemployeescredentials(const int size) 
{

	char actualusername[6][100],actualpassword[6][100];
	
	char ausername[size][20];
	char rank[size][20];

	
	ifstream myfile("employeeslogin.txt", ios::in);
	
	ifstream empcres("bestselleremployee.txt",ios::in);

	int i = 0;

	while (myfile >> actualusername[i] >> actualpassword[i]) 
	{
		i++;
	}
	
	myfile.close();
	
	int k=0;
	
	while(empcres>>ausername[k] >> rank[k]) 
	{
		k++;
	}
	
	empcres.close();


	
	int n;

	cout << "Enter the employee number you want to modify: ";
	cin >> n;

	n = n - 1; // array is from 0 not 1.

	cin.ignore();

	ofstream myfile2("employeeslogin.txt", ios::out);

	ofstream empcred("bestselleremployee.txt", ios::out);

	for (int j = 0; j < i; j++) 
	{//for
		if (n == j) 
		{
			cout << "Enter Username: ";
			cin.getline(actualusername[j], 100);

			cout << "Enter Password: ";
			cin.getline(actualpassword[j], 100);
        	}
        	
        	//writing into the file

		myfile2<<left<<setw(20)<<actualusername[j]
			<<setw(20)<<actualpassword[j]
			<<endl;
			
		empcred << left << setw(20) << actualusername[j]
				<< setw(20) << rank[j]
				<< endl;
			
	}//for

	myfile2.close();
	
	empcred.close();
	
}//modifyemployeescredentials()


void viewemployeescredentials()
{//viewemployeescredentials()

	char ch;
	ifstream myFile("employeeslogin.txt");
	
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

}//viewemployeescredentials()

void addemployees(const int size)
{//addemployees()

	
	ofstream myfile("employeeslogin.txt", ios::out | ios::app);
	
	if (!myfile.is_open()){
		cout<<"Unable to open the file."<<endl;
	}
	else
	{//else
		char employeename[size][50];
		int password[size];
	
	
		for (int i=0; i<size;i++)
		{
			cin.ignore();
			cout<<endl<<"Enter Username: ";
			cin.getline(employeename[i],50);
			
			cout<<endl<<"Enter Password: ";
			cin>>password[size];
			
			myfile <<left <<setw(10) << employeename[i]
		                <<setw(15) << password[size]
                		<<endl;
                	
                }//for
	}//else
}//addemployees()
