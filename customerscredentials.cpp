# include <iostream>
# include <fstream>
# include <cstring>

void searchcustomer()
{//searchcustomer()
	
	const int size = 7;


	ifstream file1("customerslogin.txt");

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
	char cusname[100];
	
	cout<<endl<<"Enter the employee's name you want to search: ";
	cin.getline(cusname,100);

	
	for(int i=0; i<20;i++)
	{//for 1

		if(!(strcmp(cusname, username[i])==0) &&  flag==0)
		{//if
			k++;
		}//if
		
		if(strcmp(cusname, username[i])==0)
		{
			flag=1;
			break;
		}

	}//for 1
	
	k=k+1;
	
	if (flag==1)
		cout<<"Customer Found."<<endl
		<<"At row "<<k<<endl;
	else
		cout<<endl<<"Customer Not Found."<<endl;	
	
}//searchcustomer()

void removingcustomerscredentials(const int size)
{//removingcustomerscredentials()
	

	char username[size][20];
	char password[size][20];

	ifstream myfile("customerslogin.txt", ios::in);

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

	ofstream myfile2("customerslogin.txt", ios::out);

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
	
	
}//removingcustomerscredentials()

/*void viewcustomerscredentials()
{//viewcustomercredentials()

	char ch;
	ifstream myFile("customerslogin.txt",ios::in);
	
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
		
		
		 cout << endl;						
	myFile.close();
	}

}//viewcustomercredentials()
*/
void modifycustomerscredentials(const int size) 
{//modifycustomerscredentials()

	char actualusername[6][100],actualpassword[6][100];
	
	ifstream myfile("customerslogin.txt", ios::in);
	

	int i = 0;

	while (myfile >> actualusername[i] >> actualpassword[i]) 
	{
		i++;
	}
	
	myfile.close();

	
	int n;

	cout << "Enter the customer number you want to modify: ";
	cin >> n;

	n = n - 1; // array is from 0 not 1.

	cin.ignore();

	ofstream myfile2("customerslogin.txt", ios::out);


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
			

	}//for

	myfile2.close();
	
}//modifycustomerscredentials()

void addcustomers(const int size)
{//addcustomers()

	
	ofstream myfile("customerslogin.txt", ios::out | ios::app);
	
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
			
			myfile <<left <<setw(20) << employeename[i]
		                <<setw(20) << password[size]
                		<<endl;
                	
                }//for
	}//else
}//addcustomers()
