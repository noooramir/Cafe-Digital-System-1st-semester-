#include <iostream>
#include <fstream>
#include <cstring>
#include<iomanip>
#include<cstdlib>
#include<string>

using namespace std;

void playwbinary()
{//playwbinary()

	int b,r,s,dec;
	
	dec=0;
	
	cout<<"Input a binary digit(s) of a positive number: ";
	cin>>b;
	
	for (int i=0; b>0;i++)
	{
		//for remainder
		r=b%10;
		
		//for qoutient
		b=b/10;
		
		s=r<<i;
		
		dec=dec+ s;
		
//		cout<<endl<<"Conversion process left to right."<<endl<<endl;
		cout<<" "<<r<<" * 2 * "<<i;
		
		if (b>0)
			cout<<" +  ";
			
		s=0;
		
	}
		
		cout<<endl<<"The binary number is written as "<<dec<<" in decimal system."<<endl;

}//playwbinary()

void seepatters()
{//seepatters()
	int n;
	n=5;
	
	for (int i=1;i<=7;i++)
	{
		
		for(int s=100-(i*12-7);s>0;s=s-7)//spaces
		{
			cout<<" ";
		}
		
		for (int j=1;j<=i;j++)//cubes
		{
//			cout<<"__"<<endl;
			cout<<" __ ";
		}
		cout << endl;
	
		for(int s=100-(i*12-7);s>0;s=s-7)//spaces
		{
			cout<<" ";
		}
		
		
		
		for (int j=1;j<=i;j++)//cubes
		{
//			cout<<"__"<<endl;
			cout<<"|__|";
		}
		
	cout<<endl;
	}

	cout<<endl<<endl;
	
	for (int i=1;i<=n;i++)
	{

		for (int j=1;j>0; j--)
			cout<<" __ ";
		for (int s=n-(i-3);s<=6;s++)
			cout<<" ";		
		for (int j=1;j>0; j--)
			cout<<" __ ";	
		cout<<endl;
		for (int j=1;j>0; j--)
			cout<<"|__|";
		for (int s=n-(i-3);s<=6;s++)
			cout<<" ";

		for (int j=1;j>0; j--)
			cout<<"|__|";
		
		cout<<endl;
		
	
	}

}//seepatters()

void playHandL()
{//playHandL()
	
	int g, n1,n2,n3, a,b,c;
	char ch;
	
	srand(time(0));
	
	n1=rand();
	
	n2=rand();
	
	n3=rand();
	
	
	//GAME 1
	
		n1=(n1 %21)+1;
		n2=(n2 %21)+1;
		cout<<"The first number is "<<n1<<endl;
	//	cout<<"The second number is "<<n2<<endl;		

		cout<<"Do you think that the number will be higher or lower than "<<n1<<"? Enter 'H' for higher and 'L' for lower. ";
		cin>>ch;
		if (ch=='H')
		{
			if(n2<n1)
				cout<<"Congratulation!!! You won!"<<endl;
			else
				cout<<"Better luck next time!"<<endl;
		}
		
		else if (ch=='L')
		{
			if(n2<n1)
				cout<<"Congratulation!!! You won!"<<endl;
			else
				cout<<"Better luck next time!"<<endl;
		}
		else
			cout<<"Invalid Input. Please enter only H or L"<<endl;
		

}//playHandL()

void guessnumber()
{//guessnumber()

	int g, n1,n2,n3, a,b,c;
	char ch;

	srand(time(0));
	
	n1=rand();
	
	n2=rand();
	
	n3=rand();

	
		n1=(n1 %10);
		n2=(n2 %10);
		n3=(n3 %10);
		
	//	cout<<n1<<endl<<n2<<endl<<n3<<endl; RANDOM NUMBERS
		
		cout<<"Enter three numbers you think are randomly generated (0-9): ";
		cin>>a>>b>>c;
		
		if ( ( (a<0) || (a>9) ) || ( (b<0) || (b>9) ) || ( (c<0) || (c>9) ) )
			cout<<"Invalid Input. Please enter numbers from 0-9"<<endl;
		else
		{
			//three matching, exact order
			if ( (n1==a) && (n2==b) && (n3==c) )
			{
				cout<<"Wohoo! You got all of them right! And in exact same order!!!"<<endl;		
			}
			
			//three matching, no order
			else if ( ( (n1==a) || (n1==b) || (n1==c) ) && ( (n2==a) || (n2==b) || (n2==c) ) && ( (n3==a) || (n3==b) || (n3==c) ) ) 
			{
				cout<<"Wohoo! You got all of them right! But not in exact order, though :("<<endl;
			}
			
			//any two matching		
			else if ( ( (n1==a) && (n2==b) ) || ( (n2==b) && (n3==c) ) || (n1==a) && (n3==c) )
			{
				cout<<"Wohoo! You got two right!"<<endl;		
			}
			
			//any one matching		
			else if  ( (n1==a) || (n2==b) || (n3==c) )
			{
				cout<<"One of the numbers is matching"<<endl;
			}
			
			//no match
			else
				cout<<"Awe, the numbers dont match :( Better luck next time<3"<<endl;
		}
	
	

}//guessnumber()
