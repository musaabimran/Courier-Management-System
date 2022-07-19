#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <time.h>
#include <cmath>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
class invoice;
class person
{
	protected:
	string ID;
	string password;
	
	public:
	void setLogInID(string st);
	void setPassword(string st);
	string getLogInID(string st);
	string getPassword(string st);
	bool passwordValidation();
	
	// polymorphism
	virtual void login()=0;

};


void person :: setPassword(string st)
{
	password = st;
}

void person :: setLogInID(string st)
{
	ID = st;
}

string person :: getLogInID(string st)
{
	return ID;
}
string person :: getPassword(string st)
{
	return password;
}


bool person :: passwordValidation()
{
	int size= 8;
	bool cNum=0;
	bool cChar=0;
	bool cAlphabet=0;
	bool cLen=0;
	if(size<=8)
	{
		cLen=1;
	}
	for(int i=0; i<size;i++)
	{
		// checking of all types of characters
		if(password[i]>='0' && password[i]<='9')
		{
			cNum=1;
		}
		if(password[i]>='a' && password[i]<='z')
		{
			cAlphabet=1;
		}
		if(password[i]>='A' && password[i]<='Z')
		{
			cAlphabet=1;
		}
		else
		{
			cChar=1;
		}
	}
	
	if(cChar==1 && cAlphabet==1 && cNum==1 && cLen==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class customer : public person
{
	private:

	public:
	
	void login();	
	void menu();
	
	
};
void customer::menu()
{
	int shop;
	cout << " \t\t\t\t ****** WELCOME TO THE CUSTOMER PORTAL ****** " <<endl;	
	cout << " \t\t\t\t 1. To check the Stock " << endl;
	cout << " \t\t\t\t ENTER : ";
	cin >> shop;
	
	cout << endl;
	
	if (shop==1)
	{
		cout << " \t\t\t\t 1. Oreo " << endl;
		cout << " \t\t\t\t 2. Wheat " << endl;
		cout << " \t\t\t\t 3. Caramel " << endl;
		cout << " \t\t\t\t 4. Rice " << endl;
		cout << " \t\t\t\t 5. Grains " << endl;
		cout << " \t\t\t\t 6. Nuts " << endl;
		cout << " \t\t\t\t 7. Yogurt " << endl;
		cout << " \t\t\t\t 8. Apples " << endl;
		cout << " \t\t\t\t 9. Meat " << endl;
		cout << " \t\t\t\t 10. Chicken " << endl;
	}
	
}
		
void customer::login()
{
bool x=0;
char check;
	
{
		// login for the customer
		fstream data("customer.txt", ios::app);
		cout << "\t\t\t\t REGISTER NOW\n";
		cout << "\t\t\t\t Enter log in ID: ";
		cin >> ID;
		
		cout << "\t\t\t\t Enter password with atleast 1 digit, 1 alphabet and 1 special character: ";
		cin >> password;
			
		data << ID << endl;
		data << password << endl;
		data.close();
	}
}

class  invoice
{
	private :
	int item;
	double total;
	string name;
	string contact;
	
	public:
		void inputdata();
		void writedata();
		invoice();
	
};

invoice :: invoice()
{
	
}
void invoice :: inputdata()
{
	cout << " Hello im your cashier today: " << endl;
	
	item=rand()%10;
	cout << " \t\t\t\t Number of items: " << item;
	cout << endl;
	
	total = rand()%20000;
	cout << " \t\t\t\t Total: " << total;
	cin.ignore();
	cout << endl;
	
	cout << " Can you please tell me: " << endl;
	
	cout << "\t\t\t\t Your name:  ";
	getline(cin,name);
	cout << endl;
	
	cout << "\t\t\t\t Your contact: ";
	getline(cin,contact);
	cout << endl;
	
	cout << " This information will be stored in your account " << endl;
	cout << " Have a nice day!! " << endl;
	cout << " BYE!!! " << endl;
}


void invoice::writedata()
{
	fstream wrdata ("invoices.txt",ios::app);
	wrdata << name << "\t" <<contact << "\t"  << total << "\t" << item << endl;
	wrdata.close();
	
}


class employee : public person
{
	private:
	string designation;
		
	public:
	void setDes(string n);
	void login();
	void menu1();
	
	
};

void employee  :: setDes(string n)
{
	designation=n;
}

void employee ::menu1()
{
	menu:
	int num2;
	cout << endl;
	cout << " \t\t\t\t ****** WELCOME TO THE ADMIN PORTAL ****** " <<endl;
	cout << " \t\t\t\t 1. Work on employee datababase " << endl;
	cout << " \t\t\t\t 2. Work on customer database " << endl;
	cout << " \t\t\t\t 3. View the invoice "  << endl;
	cout << "\t\t\t\t ENTER:";
	cin >> num2;
	cout << endl;
	
	if (num2==1)
	{
		int c1;
		{
		cout << "\t\t\t\t 1. Do you want to hire an employee: "	<< endl;
		cout << "\t\t\t\t 2. Do you want to fire an employee: "	<< endl;	
		cout << "\t\t\t\t ENTER:";
		cin >> c1;	
		cout << endl;
		
		if (c1==1)
		{
			string s1,s2;
			string filename("worker.txt");
			fstream file;
	
			file.open("worker.txt",ios_base::app);
			cout << "\t\t\t\t Enter name of the employee you want to hire: ";
			cin >> s1 ;
			   		 
			cout << "\t\t\t\t Enter default password of the employee you want to hire: ";
			cin >> s2 ;
			file << "Post-man " << endl;
			file << s1 << endl;
			file << s2 << endl;
			file.close();
			
			goto menu;
		}	
		
		if (c1==2)
		{
		string point, name;
		cout << "Please Enter the name of employee you want to fire: ";
		cin >> name;
		ifstream myfile;
		myfile.open("worker.txt");
		ofstream temp1;
		
		temp1.open("temp1.txt");
		while (getline(myfile, point))
		{
		if (point==name)
		{
			getline(myfile, point);
		}
			
		else 
		temp1 << point << endl;
		}
		
		cout << "The credentials of this name " << name << " has been deleted." << endl;
		myfile.close();
		temp1.close();
		
		remove("worker.txt");
		rename("temp1.txt", "worker.txt");
		goto menu;
		}				  	
		}
		}
	
	if (num2==2)
	{
		int c2;
		{
		cout << "\t\t\t\t 1. Do you want to add a customer: "	<< endl;
		cout << "\t\t\t\t 2. Do you want to delete a customer: " << endl;

		cout << "\t\t\t\t ENTER:";
		cin >> c2;	
		cout << endl;
		
		if (c2==1)
		{
			string s1,s2;
			string filename("customer.txt");
			fstream c;
	
			c.open("customer.txt",ios_base::app);
			cout << "\t\t\t\t Enter name of the customer you want to add: ";
			cin >> s1 ;
			   		 
			cout << "\t\t\t\t Enter default password of the employee you want to add: ";
			cin >> s2 ;
			
			int i;
			i = rand()%999;
			c << " CUSTOMER " << " "<< i << endl;
			c << s1 << endl;
			c << s2 << endl;
			c.close();
			
			goto menu;
		}	
		
		if (c2==2)
		{
		string point, name;
		cout << "Please Enter the name of customer you want to delete: ";
		cin >> name;
		ifstream myfile;
		myfile.open("customer.txt");
		ofstream temp2;
		
		temp2.open("temp2.txt");
		while (getline(myfile, point))
		{
		if (point==name)
		{
			getline(myfile, point);
		}
			
		else 
		temp2 << point << endl;
		}
		
		cout << "The credentials of this name " << name << " has been deleted." << endl;
		myfile.close();
		temp2.close();
		
		remove("customer.txt");
		rename("temp2.txt", "customer.txt");
		goto menu;
		}				  	
		}
		}
	
	
	if (num2==3)
	{
		
	}
}

void employee  :: login()
{
	
	bool x=1;
	cout << endl;
	cout << "\t\t\t\t Enter designation: ";
	cin >> designation;
	
		
	if( designation == "admin")
	{
	do{
	cout << "\t\t\t\t Enter user name: ";
	cin >> ID;
	cout << "\t\t\t\t Enter password: ";
	cin >> password;
	fstream data("admin.txt", ios::in);
	int size=20;
	
	if(!data.is_open())
		cout<<"\t\t\t\t File not found\n";
	else
	{
	
		int count=0;
		bool str=0;	
		while(!data.eof()&&count<size)
		{
				string buff="\0";
				getline(data, buff);
				if(buff==ID)
				{
					string pass="\0";
					getline(data, pass);
					if(pass==password)
					{
					
						cout << "\t\t\t\t Successful log in\n" << endl;
						x=1;
						break;
					}
					else
					{
						cout << "\t\t\t\t Successful log in\n" << endl;
						count++;
					}
				}
				else 
					count +=2;
		}
	}
	}while(x==0);

}


// login in for the clerk of the post office
else if( designation == "worker")
	{
	do{
	cout << "\t\t\t\t Enter log in ID (username): ";
	cin >> ID;
	cout << "\t\t\t\t Enter password: ";
	cin >> password;
	fstream data("worker.txt", ios::in);
	int size=20;
	
	if(!data.is_open())
		cout<<"\t\t\t\t File not found\n";
	else
	{
	
		int count=0;
		bool str=0;	
		while(!data.eof()&&count<size)
		{
				string empty="\0";
				getline(data, empty);
				if(empty==ID)
				{
					string pass="\0";
					getline(data, pass);
					if(pass==password)
					{
						cout << "\t\t\t\t Successful log in\n" << endl;
						x=1;
						break;
					}
					else
					{
						cout << "\t\t\t\t PASSWORD DOES NOT MATCH\n" << endl;
						count++;
					}
				}
				else 
					count +=2;
		}
	}
	}while(x==0);
}

}



class portal
{
	private:
	employee emp;
	customer cus;	
	
	public:
	portal();
	void menu1();
};

portal :: portal()
{
	m:
	int num;
	do
	{
		cout << endl;
	cout << " \t\t\t\t ****** WELCOME TO THE SHOPING PORTAL ****** " <<endl;
	cout << " \t\t\t\t\t ****** MAIN MENU ******* " << endl;
	cout << " \t\t\t\t Enter '1', to log in as an employee " << endl;
	cout << " \t\t\t\t Enter '2', to log in as a customer " << endl;
	cout << " \t\t\t\t Enter '3', to do payment" << endl;
	cout << " \t\t\t\t Enter '4', TO exit " << endl;
	cout << " \t\t\t\t Enter: ";
	cin >> num;
	
	if ( num==1)
	{
		
		emp.login();
		emp.menu1();
		goto m;
		
	}
	
	else if (num==2)
	{
		cus.login();
		cus.menu();
		goto m;
	}

	else if(num==3)
	{
		char option;
		cout << "\t\t\t\t Do you want to place your ORDER:[y/n]\n ";
		cout << "\t\t\t\t ENTER:";
		cin >> option;
		cin.ignore();
		cout << endl;
		if(option=='y')
		{
		
		invoice in;
		in.inputdata();
		in.writedata();
		goto m;
		}
		}

	else if (num==4)
	{
		cout << " EXITING PROGRAM!!! " << endl;;
	}

	
	}
	while (num!=4);
}



int main ()
{
	srand(time(NULL));
	portal p;
}
