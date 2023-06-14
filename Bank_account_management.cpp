#include<iostream>
#include<string.h>
#include<cstdlib>
#include<conio.h>
using namespace std;

class node		
{
	public:
		int acc_no;
		string acc_name;
		float acc_bal;
		int top;
		int acc_pin;
		int stack[1000];
		int a[1000];
		int b[1000];
		node *link;
};
node *head=NULL,*temp,*New,*last,*prevv,*next,*loop;

class bank			//creating bank class
{
	public:
		void create();				//creating a node
		void findlast();			//finding last node
		void getdata();			//getting account details 
		void showdata();			
};
class Modification:public bank
{
	public:
		void search(int a);					//function overloading passing int parameter
		void search(string *n);				//function overloading passing string 
		void update();
		void del();
};
class Transactions: public Modification
{
	public:
		void transaction();					//transactions
		void w_or_d(int c);
};
void bank::create()		//create function to create a node
{
	int no;
	string name;
	float bal;
	int pin;
	cout<<"\nEnter account number: ";
	cin>>no;
	cout<<"\nEnter account holder name: ";
	cin.ignore();
	getline(cin,name);
	cout<<"\nEnter amount you want add in your account: ";
	cin>>bal;
	cout<<"\nEnter your four digit security pin: ";
	cin>>pin;
	New= new node;
	New->acc_no=no;
	New->acc_name=name;
	New->acc_bal=bal;
	New->acc_pin=pin;
	New->top=0;
	New->a[New->top]=1;
	New->b[New->top]=bal;
	New->stack[New->top]=bal;
	New->link=NULL;
}
void bank::findlast()		//find last function to find last node
{
	last=head;
	while(last->link!=NULL)
	{
		last=last->link;
	}
}
void bank::getdata()		//getdata to create an account
{
	create();
	int z1=0,z2=0;
	if(head==NULL)
	{
		if(New->acc_no>=1000000 && New->acc_no<=9999999)
		{
			z1=1;
	     }
	     else
	     {
	     	cout<<"\n\nInvalid account number format!"<<endl;
			cout<<"Please enter seven digit account number!"<<endl;
		}
		if(New->acc_pin>=1000 && New->acc_pin<=9999)
		{
			z2=1;
	     }
	     else
	     {
	     	cout<<"\n\nInvalid pin format!"<<endl;
			cout<<"Please enter four digit pin!"<<endl;
		}
		if((z1+z2)==2)
		{
			head=New;
			cout<<"\n\nAccount has been successfully created!";
		}
	}					//using singly linked list insert at end logic 
	else
	{
		int c1=0,c3=0;
		temp=head;
		while(temp!=NULL)
		{
			if(temp->acc_no==New->acc_no)
			{
				cout<<"\n\nThis account number already exist in list!"<<endl;
				cout<<"Please enter different account number!"<<endl;
				++c1;
			}
			if(New->acc_pin>=1000 && New->acc_pin<=9999){
			
				c3=0;}
			else
				c1=4;
			
			if(New->acc_no>=1000000 && New->acc_no<=9999999){
		
				c3=0;	}
			else
				c3=5;
				
			temp=temp->link;
		}
		if(c1==0)
		{
			findlast();
			last->link=New;
			cout<<"\n\nAccount has been successfully created!";
		}
		else if(c1==4)
		{
			cout<<"\n\nInvalid pin format!"<<endl;
			cout<<"Please enter four digit pin!"<<endl;
		}
		if(c3==5)
		{
			cout<<"\n\nInvalid account number format!"<<endl;
			cout<<"Please enter seven digit account number!"<<endl;
		}
	}
	
}
void bank::showdata()			//using showdata to show data
{
	cout<<"\n\nAccount number      : "<<temp->acc_no<<endl;
	cout<<"\nAccount holder name : "<<temp->acc_name<<endl;
	cout<<"\nAccount balance     : "<<temp->acc_bal<<endl;
	cout<<"\nSecurity pin        : "<<temp->acc_pin;
}
void Modification::search(int a)
{
	if(head==NULL)							//checking if list is empty
	{
		cout<<"\n\nAccount's record is empty!";
	}
	else
	{
		int count=0;
		temp=head;
		while(temp!=NULL)					//traversing linked list upto null
		{
			if(a==temp->acc_no)				
			{
				showdata();				//if acc no matches then print followiing data
				count++;
			}
			temp=temp->link;
		}
		if(count==0)
		{
			cout<<"\n\nBank Account not found!"<<endl;
		}
	}
}
void Modification::search(string *n)
{
	if(head==NULL)							//checking if list is empty
	{
		cout<<"\n\nAccount's record is empty!";
	}
	else
	{
		int count=0;
		temp=head;
		while(temp!=NULL)					//traversing linked list upto null
		{
			if(temp->acc_name==*n)				
			{
				showdata();				//if acc no matches then print followiing data
				count++;
			}
			temp=temp->link;
		}
		if(count==0)
		{
			cout<<"\n\nBank Account not found!"<<endl;
		}
	}
}
void Modification::update()
{
	if(head==NULL)
	{
		cout<<"\n\nAccount's record is empty!";
	}
	else
	{
		int a,count=0,n;
		cout<<"\n\nEnter account number you want to Update: ";
		cin>>a;
		cout<<"\nEnter four digit security pin: ";
		cin>>n;
		temp=head;
		while(temp!=NULL)
		{
			if(n==temp->acc_pin)
			{
				if(a==temp->acc_no)
				{
					cout<<"\nEnter new account holder name: ";
					cin.ignore();
					getline(cin,temp->acc_name);
					cout<<"\nEnter your new four digit security pin: ";
					cin>>temp->acc_pin;
					cout<<"\n\nAccount has been updated!";
					count++;
				}
				else
				{
					count=2;	
				}
		     }
			temp=temp->link;
		}
		if(count==0)
		{
			cout<<"\n\nBank Account not found!"<<endl;
		}
		else if(count==2)
		{
			cout<<"\n\nInvalid security pin!"<<endl;
		} 
	}
}
void Transactions::transaction()			//using transcation function to show transactions of bank owner
{
	if(head==NULL)
	{
		cout<<"\n\nAccount's record is empty!";
	}
	else
	{
		int a,i,j=1,count=0,n;
		cout<<"\n\nEnter account number you want see transactions: ";
		cin>>a;
		cout<<"\nEnter four digit security pin: ";
		cin>>n;
		temp=head;
		while(temp!=NULL)
		{
			if(a==temp->acc_no)
			{
				if(temp->acc_pin==n)
				{
					cout<<"\n\nAvailable balance: "<<temp->acc_bal<<endl;
					cout<<"\n\nTransactions  Withdraw or Deposited\t Balance \n"<<endl;
					for(i=temp->top;i>=0;i--)
					{
						if(temp->a[i]==0)
						{
							cout<<j<<". "<<temp->stack[i]<<"      Withdraw\t\t\t"<<temp->b[i]<<endl;
						     j++;
						}
						else
						{
							cout<<j<<". "<<temp->stack[i]<<"       Deposited\t\t\t"<<temp->b[i]<<endl;
						     j++;	
						}
					}
					count++;
			     }
				else
				{
					count=2;	
				}  
			}
			temp=temp->link;		
		}
		if(count==0)
		{
			cout<<"\n\nBank Account not found!"<<endl;
		}
		else if(count==2)
		{
			cout<<"\n\nInvalid security pin!"<<endl;
		}
	}
	
}
void Transactions::w_or_d(int c)
{
	if(head==NULL)
	{
		cout<<"\n\nAccount's record is empty!";
	}
	else
	{
		int a,am,p,count=0;
		cout<<"\n\nEnter account number: ";
		cin>>a;
		cout<<"\nEnter ammount: ";
		cin>>am;
		cout<<"\nEnter your security pin: ";
		cin>>p;
		temp=head;
		while(temp!=NULL)
		{
			if(a==temp->acc_no)
			{
				if(p==temp->acc_pin)
				{
					if(c==1)
					{
						if(am > temp->acc_bal)
						{
							cout<<"\n\nInsufficiant balance!";
							cout<<"\n\nAvailable balance: "<<temp->acc_bal;
						}
						else
						{
							temp->acc_bal = temp->acc_bal-am;
							++temp->top;
							temp->b[temp->top]=temp->acc_bal;
							temp->stack[temp->top]=(-1)*am;
							temp->a[temp->top]=0;
							cout<<"\n\nTransaction is sucessful!";
							cout<<"\n\nAvailable balance: "<<temp->acc_bal;
						}
					}
					else if(c==2)
					{
						temp->acc_bal = temp->acc_bal+am;
						++temp->top;
						temp->b[temp->top]=temp->acc_bal;
						temp->stack[temp->top]=am;
						temp->a[temp->top]=1;
						cout<<"\n\nTransaction is sucessful!";
						cout<<"\n\nAvailable balance: "<<temp->acc_bal;
					}
					else
					{
						cout<<"\n\nInvalid input!";
					}
			     }
			     else
			     {
			     	cout<<"\n\nInvalid security pin!";
				}
				count++;
			}
			temp=temp->link;
		}
		if(count==0)
		{
			cout<<"\n\nBank Account not found!"<<endl;
		}
	}
}
void Modification::del()
{
	if(head==NULL)
	{
		cout<<"\n\nAccount's record is empty!";
	}
	else
	{
		int a,h,count=0,z=0;
		cout<<"\n\nEnter account number you want to Delete: ";
		cin>>a;
		cout<<"\nEnter four digit security pin: ";
		cin>>h;
		loop=head;
		while(loop!=NULL)
		{
			if(loop->acc_pin==h)
			{
				z++;
				if(a== head->acc_no)
				{
					temp=head;
					head=head->link;
					cout<<"\n\nAccount has been successfully Deleted!";
					count++;
					delete temp;
				}
				else
				{
					prevv=head;
					temp=head->link;
					while(temp!=NULL)
					{
						if(a==temp->acc_no)
						{
							prevv->link=temp->link;
							count++;
							cout<<"\n\nAccount has been successfully Deleted!";
							delete temp;
							break;
						}
						prevv=temp;
						temp=temp->link;
					}
					if(count==0)
					{
						cout<<"\n\nBank Account not found!"<<endl;
					}
				}
			}
			
			loop=loop->link;
		}
		if(count==0 && z==0)
		{
			cout<<"\n\nInvalid security pin!"<<endl;
			cout<<"\n\nBank Account not found!"<<endl;
		}
		
	}
}
inline void menu()
{
	cout<<"\n\n\t\tww       ww  eeeeee  ll      cccccc    oooooo    mm        mm  eeeeee"<<endl;
	cout<<"\t\tww       ww  ee      ll      cc       o      o   mm mm  mm mm  ee"<<endl;
	cout<<"\t\tww   ww  ww  eeee    ll      cc      o        o  mm   mm   mm  eeee"<<endl;
	cout<<"\t\tww ww ww ww  ee      ll      cc       o      o   mm        mm  ee"<<endl;
	cout<<"\t\tww       ww  eeeeee  llllll  cccccc    oooooo    mm        mm  eeeeee"<<endl;
	
	cout<<"\n\n\n1.Create Account:";
	cout<<"\n\n2.Search Account:";
	cout<<"\n\n3.Update Account:";
	cout<<"\n\n4.Withdraw or deposit";
	cout<<"\n\n5.Show transaction";
	cout<<"\n\n6.Delete account";
	cout<<"\n\n7.Exit";
}
inline void wd()
{
	cout<<"\n\n1.Withdraw money";
	cout<<"\n\n2.Deposit Money";
}
inline void search()
{
	cout<<"\n\n1.Search by account number";
	cout<<"\n\n2.Search by account holder name";
}
int main()
{
	Transactions b;			//creating an object class bank
	p:
	system("cls");
	int x,c,k,a;
	string n;
	menu();
	cout<<"\n\nEnter choice: ";
	cin>>x;
	switch(x)
	{
		case 1:
			system("cls");
			b.getdata();
			break;
		case 2:
			system("cls");
			search();
			cout<<"\n\nEnter choice: ";
			cin>>k;
			if(k==1)
			{
				cout<<"\n\nEnter account number you want to search: ";			//taking user input of acc number
				cin>>a;
				b.search(a);
			}
			else if(k==2)
			{
				cout<<"\n\nEnter account holder name you want to search: ";			//taking user input of acc holders name
				cin.ignore();
				getline(cin,n);
				b.search(&n);
			}
			else
				cout<<"\n\nEnter valid input!"<<endl;
			break;
		case 3:
			system("cls");
			b.update();
			break;
		case 4:
			system("cls");
			wd();
			cout<<"\n\nEnter choice: ";
			cin>>c;
			b.w_or_d(c);
			break;
		case 5:
			system("cls");
			b.transaction();
			break;
		case 6:
			system("cls");
			b.del();
			break;
		case 7:
			cout<<"\n\nThankyou :)";
			exit(0);
		default:cout<<"\n\n\nEnter valid choice!"<<endl;	
	}
	getch();
	goto p;	
}
