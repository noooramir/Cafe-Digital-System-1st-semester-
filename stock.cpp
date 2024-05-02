#include <iostream>
#include <fstream>
#include <cstring>
#include<iomanip>
#include<string>

using namespace std;

const char* colorhead="\033[40;37m";
const char* colorred="\033[40;31m";
const char* colorgreen="\033[40;32m";
const char* coloryellow="\033[40;33m";
const char* colorreset="\033[0m";


void bubblesort(int ID[],char name[][100],int quantity[],int price[],int total[],int n)
//void bubblesort(int *ID, char **name, int *quantity, int *price, int *total, int n)
{//bubblesort
	
	for (int i=0;i<n;i++) //n=i ; line 110
	{//for 1
		for (int j=0;j<n-i-1;j++)
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
	

}//bubblesort


void searchstock()
{//search()

	int ID[20], price[20], quantity[20], total[20];
	char name[20][100];
	int i=0;
	
	ifstream file1;
	file1.open("stock.txt", ios::in);
	
	while (file1 >> ID[i] >> name[i] >> price[i] >> quantity[i] >> total[i]) 
	{
		i++; 
	}
	file1.close();
	
	cin.ignore();	
	
	int flag=0,k=0;
	char itemname[100];
	
	cout<<endl<<"Enter the item's name you want to search (IN CAPS): ";
	cin.getline(itemname,100);
	
	//clearing any garbage value//input left in buffer
	cin.ignore();
	
	for(int i=0; i<20;i++)
	{//for 1
//		for(int j=0;j<5;j++)
//		{//for 2
		if(!(strcmp(itemname, name[i])==0) &&  flag==0)
		{//if
			k++;
		}//if
		
		if(strcmp(itemname, name[i])==0)
		{
			flag=1;
			break;
		}
//		}//for 2
	}//for 1
	
	
	if (flag==1)
		cout<<"Item Found."<<endl
		<<"At row "<<k<<endl;
	else
		cout<<endl<<"Item Not Found."<<endl;	
}//search(0

void orderandupdate()
{//orderandupdatestock()

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

	for (int j = 0; j < i; j++)
	{
		if (quantity[j] == 0)
		{
			cout << "Order: " << coloryellow
				<< name[j] << colorreset << endl
				<< "Quantity left in stock: " << quantity[j]
				<< endl;
		}
		else if (quantity[j] <= 15 && quantity[j] > 0)
		{
			cout << "Order: " << colorred
				<< name[j] << colorreset << endl
				<< "Quantity left in stock: " << quantity[j]
				<< endl;
		}
	}

	int userID, userquantity;

	ofstream file2("stock.txt", ios::out);

	cout << "Enter the item ID you want to update: ";
	cin >> userID;

	for (int j = 0; j < i; j++)
	{////for
		if (userID == ID[j])
		{
			cout << "Enter the quantity you want to update it to: ";
			cin >> userquantity;

			quantity[j] = quantity[j] + userquantity;

			file2 << left << setw(10) << ID[j]
				<< setw(15) << name[j]
				<< setw(15) << price[j]
				<< setw(15) << quantity[j]
				<< setw(15) << price[j] * quantity[j]
				<< endl;
		}
		
		else
		{
			file2 << left << setw(10) << ID[j]
				<< setw(15) << name[j]
				<< setw(15) << price[j]
				<< setw(15) << quantity[j]
				<< setw(15) << price[j] * quantity[j]
				<< endl;
		}
	}//for

	file2.close();

	for (int j = 0; j < size; j++)
	{
		delete[] name[j];
	}

	delete[] ID;
	delete[] price;
	delete[] quantity;
	delete[] total;
	delete[] name;

	
}//orderandupdatestock()

void removingstock() 
{//removingstock() 

	
	
	ifstream file1("stock.txt", ios::in);

	int size = 0;
	char ch;

	while (file1.get(ch)) 
	{
		if (ch == '\n')
		size++;
	}
	
	

	file1.clear(); //reset the end-of-file flag
	file1.seekg(0, ios::beg); //moving the pointer back to the beginning.

	int *ID = new int[size];
	int *price = new int[size];
	int *total = new int[size];
	int *quantity = new int[size];
	char **name = new char* [size]; 
	

	for (int j = 0; j < size; j++) 
	{
		name[j] = new char[100];
	}

	int i = 0;

	while (file1 >> ID[i] >> name[i] >> price[i] >> quantity[i] >> total[i]) 
	{
		i++;
	}

	file1.close();

	ofstream file2("stock.txt", ios::out);

	if (!file2.is_open()) 
	{
		cout << endl << "Unable to open the file." << endl;
	} 
	
	else 
	{
		int k;
		cout << endl << "Enter the stock you want to remove: ";
		cin >> k;

		k = k - 1; // array starts from 0 not 1.

		for (int j = 0; j < i; j++) 
		{
			if (k != j) 
			{
				file2 << left << setw(10) << ID[j]
					<<setw(15)<<name[j]
					<<setw(15)<<price[j]
					<<setw(15)<<quantity[j]
					<<setw(15)<<price[j] * quantity[j]
					<<endl;

                delete[] name[j];
	            }
        }

        file2.close();
    }

    delete[] ID;
    delete[] price;
    delete[] total;
    delete[] quantity;
    delete[] name;
}


void newstock()
{
//TO ADD NEW STOCK

	int size;
	cout<<"enter the number of stocks you want to add: ";	
	cin>>size;
	
	
	int *ID = new int[size];
	int *price = new int[size];
	int *total = new int[size];
	int *quantity = new int[size];
	char **name = new char* [size]; 
	

	for (int j = 0; j < size; j++) 
	{
		name[j] = new char[100];
	}
	
	fstream file;
	file.open("stock.txt", ios::out | ios::app);
	if (!file.is_open()){
		cout<<"Unable to open the file."<<endl;
	}
	else
	{//else

//		cout<<"ID\t\tNAME\t\tPRICE\t\tQUANTITY\t\tTotalPrice"<<endl;

		for (int i=0;i<size;i++)
		{//for loop
			cout<<endl<< "ITEM ID: ";
			cin>>ID[i];
			
			cin.ignore(); //ignoring the newline character
			
			cout<<"ITEM NAME: ";
			cin.getline(name[i], 100);
			
			cout<<"ITEM PRICE: ";
			cin>>price[i];
			
			cout<<"ITEM QUANTITY: ";
			cin>>quantity[i];

//			cout<<"ITEM TOTAL PRICE: ";
//			cin>>totalprice[i];

			file<<left<<setw(10)<<ID[i]
				<<setw(15)<<name[i]
				<<setw(15)<<price[i]
				<<setw(15)<<quantity[i]
				<<setw(15)<<price[i]*quantity[i]
				<<endl;
		}//for loop
	}//else
	
	file.close();
	
	for (int j = 0; j < size; j++)
	{
		delete[] name[j];
	}

	delete[] ID;
	delete[] price;
	delete[] quantity;
	delete[] total;
	delete[] name;
	
//TO ADD NEW STOCK
}//void newstock

void viewstock()
{//viewstock()

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
	
	int i=0;
	
	while (file1 >> ID[i] >> name[i] >> price[i] >> quantity[i] >> total[i]) 
	{
		i++; //using it for bubble sorting
	}
    
    
	//B U B B L E S O R T

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
	
//for H I G H L I G H T I N G items==0 yellow.
		if (quantity[j]==0)
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

//for H I G H L I G H T I N G items>0 and less than 16 red.
		else if (quantity[j]<=15 && quantity[j]>0)
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
	
	file1.close();
	
	for (int j = 0; j < size; j++)
	{
		delete[] name[j];
	}

	delete[] ID;
	delete[] price;
	delete[] quantity;
	delete[] total;
	delete[] name;
	
}//viewstock()

void updatedstock() 
{

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
	
	for (int j = 0; j < size; j++)
	{
		delete[] name[j];
	}

	delete[] ID;
	delete[] price;
	delete[] quantity;
	delete[] total;
	delete[] name;
}


/*
int main ()
{
	int n;
	cout<<"enter the number of stocks you want to add: ";	
	cin>>n;
	newstock(n);
	updatedstock();
	return 0;
}
*/
