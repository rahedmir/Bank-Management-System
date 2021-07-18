
//Simple Bank Management System in C++

#include <stdio.h>
#include <iostream>

using namespace std;

class bank
{
	private:
	  string name, address;
	  char account_type;
	  float balance;
	
	public:
		void open_account();
		void deposit_money();
		void withdraw_money();
		void display_account();
		
};

void bank::open_account()
{
	cout<<"Enter your full name "<<endl;
	cin.clear(); 
	getline(cin,name);
	
	while(name.empty())
	{
		getline(cin,name); //Avoid blank entry (name)
	}
	
	cout<<"Enter your address "<<endl;
	cin.clear(); 
	getline(cin,address);
	
	while(address.empty())
	{
		getline(cin,address); //Avoid blank entry (address)
	}
	
	cout<<"What type of account do you want to open?  Saving(S) or Current(C)..."<<endl;
    cin.clear(); 
	cin>>account_type;
	
	while(account_type!='S' && account_type!='s'&& account_type!='C' && account_type!= 'c')
	{
		cout<<"invalid input!!!... Press 'S' or 'C' key "<<endl; //avoid invalid account selection
		cin.clear(); 
		cin.ignore(100, '\n'); ////Stop infinite loop for invalid input!
		cin>>account_type;
	}
	
	cout<<"Enter the amount for the first deposit "<<endl;
	cin.clear(); 
	cin>>balance;
	
	while(cin.fail() || balance<0)
	{
		cout<<"invalid input!!!... Please enter a positive number "<<endl; //Only allow positive numbers to input
		cin.clear(); 
        cin.ignore(100, '\n');
        cin>>balance;	
	}
	
	cout<<"Your account is created successfully!"<<endl;	
}

void bank::deposit_money()
{
	float deposit;
	
	cout<<"Enter the amount you want to deposit "<<endl;
	cin>>deposit;
	
	while(cin.fail() || deposit<0)
	{
		cout<<"invalid input!!!... Please enter a positive number "<<endl; //Only allow positive numbers to input
		cin.clear(); 
        cin.ignore(100, '\n');
		cin>>deposit;	
	}
	
	balance = balance + deposit;
	
	cout<<deposit<<" is successfully deposited into your account "<<endl;
}

void bank::withdraw_money()
{
	float withdraw;
	
	cout<<"Enter the amount you want to withdraw "<<endl;
	cin>>withdraw;
	
		while(cin.fail() || withdraw<0)
	{
		cout<<"invalid input!!!... Please enter a positive number "<<endl; //Only allow positive numbers to input
		cin.clear(); 
        cin.ignore(100, '\n');
		cin>>withdraw;			
	}
	
	if(withdraw>balance)
	{
		cout<<"Sorry...you don't have sufficient balance to withdraw!!! "<<endl; //Check your balance
	}
	else
	{
		balance = balance - withdraw;
		
		cout<<withdraw<<" is successfully withdrawn from your account "<<endl;
	}
	
	
}

void bank::display_account()
{
	std::cout<<"Your name : "<<name<<endl;
	cout<<"Your address : "<<address<<endl;
	
	if(account_type=='c'|| account_type=='C')
	{
			cout<<"Type of your account : Current "<<endl;
	}
	else if(account_type=='s' || account_type=='S')  //Check your account type
	{
			cout<<"Type of your account : Saving "<<endl;
	}
	else
	{
		 	cout<<"Invalid account!!! "<<endl;
	}

	cout<<"Your current balance : "<<balance<<endl;
}

int main()
{
	int choice;
	bank obj;
	
	cout<<"Opening your account... "<<endl;
	
	obj.open_account();
	
	do {
		
		cout<<"--------------------------"<<endl;	
		
		cout<<"Press 1 to deposit money "<<endl;
		cout<<"Press 2 to withdraw money "<<endl;
		cout<<"Press 3 to display account "<<endl;
		cout<<"Press 4 to exit "<<endl;
		
		cout<<"--------------------------"<<endl;
		
		
		cin>>choice;
		cin.clear(); //Stop infinite loop for invalid input!
		cin.ignore(100, '\n');
		
		switch(choice)
		{
		
			case 1: obj.deposit_money();
			break;
			case 2: obj.withdraw_money();
			break;
			case 3: obj.display_account();
			break;
			case 4: 
			exit(3);
		
			default:
				cout<<"Invalid input!!!..."<<endl;
				
		}
		
	} while(true);
	
	return 0;
}
