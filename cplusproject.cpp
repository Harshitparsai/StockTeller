// CSE project stock teller 
// prepared by harshit parsai , k17FB, roll no. 6

#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//this a stock class which has been used to work with the files and do all the operation using its object
class stock{
	protected :
	int S_NO;
	float total;
	char pro_name[40];
	int quantity;
	float cost;
	public :
		stock(){
			S_NO=0;
			pro_name[40];
			quantity=0;
			cost=0;
		    total=0;
		}
		void getdata()
		{   system("color 3E");
			 cout<<" \t Enter the serial number of the product : ";
	   	  cin>>S_NO;
	   	  cout<<"\t Enter the name of the product : ";
	   	  fflush(stdin);
	   	  cin>>pro_name;
	   	  cout<<"\t Enter the number of the product : ";
	   	  cin>>quantity;
	   	  cout<<"\t Enter the cost of the product : ";
	   	  cin>>cost;
		}
		void putdata()
		{    system("color 3E");
			cout<<setw(20)<<S_NO<<" ";
		fflush(stdin);
		cout<<setw(20)<<pro_name<<" ";
		cout<<setw(28)<<quantity<<" ";
		cout<<setw(30)<<cost<<"\n";
		total =total+ cost;
		}
		void changequantity(int num)
		{
			quantity-=num;
		}
		void showtotal()
		{
			cout<<" \t\t\t\t\t\t\t\t\t\t\t TOTAL : - "<< total<<"\n\n";
		}
		void show();
	    void add();
	    void buy();
	    void modify();
	    void bill();
};
// class bucket which is publically inherited by stock 
class bucket : public stock
{
};
// structure which has been used to keep the detail about customer
struct detail{
	char name[30];
	int date;
}b1;
// fuction to clear all the contents in  files
void truck()
{   fstream file,f1,f2;
	file.open("stock.txt",ios::out);
    f2.open("stocktemp.txt",ios::out);
    f1.open("bill.txt",ios::out);
    cout<<"\t\t\n ALL RECORD IS CLEAR : -";
    
}
// menu fuction all the function has been called inside it
void menu()
{    stock S;
     char ch;
     int choice;
     system("color 4A");
	cout<<"\n\tEnter Your Choice : -\n\n";
	cout<<"\t1. To see available product \n\t2. To Add A new Stock Material \n\t3. To Select Bucket  products \n\t4. To modify any material \n\t5. To print your bill \n\t6. TO clear whole record \n\t7.Exit\n\t";
	cin>>choice;
	system("color 4B");
	switch(choice)
	{
		case 1 : S.show();
		          system("color 6A");
		         cout<<"\n\tIf you wnat to clear screen then press Y :- ";
				 cin>>ch;
				 if(ch=='Y'||ch=='y')
				 system("cls");
		         menu();
		         break;
	    case 2 : S.add();
	             system("color 6A");
	            system("cls");
		         menu();
		         break;
		case 3 : S.buy();
		         system("color D3");
		         system("cls");
		         menu();
		         break;
		case 4 : S.modify();
		         system("color 6A");
		        system("cls");
		         menu();
		         break;  
		case 5 : S.bill();
		         system("color D0");
		        cout<<"\n\tIf you wnat to clear screen then press Y :- ";
				 cin>>ch;
				 if(ch=='Y'||ch=='y')  
				 system("cls");
				 menu();
		         break;
	    case 7 : cout<<"\t\t\t\t\t ******* THANKS FOR USING ******* ";
		         break;   
		case 6 : 
		          truck();
		          system("color 1E");
		           system("cls");
				 menu();
		         break;
		default: cout<<"Sorry Wrong Choice You Are redirected to home page";
		          menu();
	
	}
	
}
// main fuction from where all the execution begin
int main()
{   //system("color 6C");
	cout<<"\n\t\t\t\t\t******** CSE PROJECT WORK ********\n\n";
	cout<<"\t\t\t\t    ******** STOCK MANAGEMENT/TELLER SYSTEM ********\n\n";
	cout<<"\t\t\t\t******** PREPARED BY :- HARSHIT PARSAI ********\n\n";
	cout<<"\t\t\t\t******** SECTION:- K17FB , ROll NO. A06 ********\n\n";
	cout<<"\t\t * Note read every instruction carefully for better result and clear data after every attempt THANKYOU :- \n\n";
	menu();
	return 0;
}
// this fuction is used to add the stock in a shop
void stock :: add()
{ int n;
   char ch;
   stock s;
  fstream file;
  
  file.open("stock.txt",ios::app);
  cout<<"\n\t Press Y to get enter to entry boot else press N to return to main menu \t ";
  cin>>ch;
  if(ch=='Y'||ch=='y')
  {  
       cout<<"\t Enter the number of material you want to add \t";
       cin>>n;
	   for(int i=0;i<n;i++)
	   {  
	   	  cout<<"\n\t Enter the details of the "<<i+1<<"th object \t \n";
	   	   s.getdata();
	   	  file.write((char *)&s,sizeof(s));
	   	  cout<<"\n";
	   }
   }
   else{ file.close();
   	}
   file.close();

}
// this is used to show the available stock in the market
void stock :: show()
{
	stock s;
	char ch;
	fstream file;
	file.open("stock.txt",ios::in);
	cout<<"\n";
	cout<<setw(25)<<" Serial NO."<<setw(25)<<" Product name"<<setw(25)<<" Quantity"<<setw(25)<<" cost"<<"\n";
	while( file.read((char *) & s,sizeof ( s )))
	{   
		s.putdata();
		  
	}
	file.close();
}
// this is actually a bucket in which user can add his choosed items
void stock :: buy()
{  
   //d.getdata();
   bucket b;
    //system("color 4A");
    stock s;
    char ch;
    int n,q,c=0;
    fstream file,f1;
    //file.open("stock.txt",ios::in);
    f1.open("bill.txt",ios::app);
    cout<<"\n\n \t\t\t\t***** welcome to sopping mode :- ";
    cout<<"\n \tEnter your name :- ";
    cin>>b1.name;
    cout<<"\n\t Enter today's date :- ";
    cin>>b1.date;
    
    cout<<"\n\tPress Y to add to chart :- ";
    cin>>ch;
    while(ch=='Y'||ch=='y')
    {   file.open("stock.txt",ios::in);
    	cout<<"\t enter the serial number of the product you want to buy :-  ";
    	cin>>n;
    	cout<<"\t Enter the number of the product you want to buy :-  ";
    	cin>>q;
    	while(file.read((char *)&s,sizeof(s)))
    	{     
    	   if(s.S_NO==n)
    	   {
    	   	    b.S_NO=n;
    	   	    b.cost= q*s.cost;
    	   	    b.quantity=q;
    	   	    strcpy(b.pro_name,s.pro_name);
    	   	    f1.write((char *)&b,sizeof(b));
    	   	    //s.putdata();
		   }
    	
		}
		cout<<"\t press Y to continue :- ";
		cin>>ch;
    	 file.close();   		
	}

}
//this fuction has been used to modify any of the entry
void stock :: modify()
{
     fstream file;
     system("color 5A");
     file.open("stock.txt",ios::in|ios::out);
     stock s;
      int n,p;
      n=file.tellg()/sizeof(s);      
      cout<<"\n\t\t Enter the serial number of the product you want to modify :- \t";
      cin>>n;
     
      p=(n-1)* sizeof(s);  
      file.seekg(p);
      s.getdata();
      file.write((char *)&s,sizeof(s));
      file.close();
}
// this fuction has been used to print the bill
void stock :: bill()
{   stock s1;
    cout<<"\n \n";
    cout<<"****************************************************************************************************************************************************";
	cout<<"\n\n\n\t\tHarshit & Sons                                                      \t\tCustomer Satisfiction is primary";
	cout<<"\n\n\n\t Address :- LPU Uni mall \n";
	cout<<"\t\t Jalandhar ,Punjab";
	cout<<"\n\n\t Sold to:- customer Id I1123214 \n";
    cout<<"\n\t Name :- "<<b1.name;
    cout<<"\n\t Date :- "<<b1.date<<" /03"<<" /2018";
	cout<<"\n\n\tSales Tax Rate = 5 % + 18 % GST\n\n";
	cout<<setw(25)<<"Serial NO."<<setw(25)<<" Product name"<<setw(25)<<" Quantity"<<setw(25)<<" cost"<<"\n\n\n";
	fstream f;
	f.open("bill.txt",ios::in);
	while(f.read((char * ) &s1,sizeof(s1)))
	{
		s1.putdata();
	}
	system("color 1A");
//	s1.showtotal();
	f.close();
	cout<<"\n\t Drop Again Soon !\n";
	cout<<"\n\t Contact Us :- \n";
	cout<<"\n\t 555555565656\n";
	cout<<"\n\temail :- harshitandsons@gmail.com\n";
	cout<<"\n\n\n********************* THANKS FOR SHOWING YOUR INTEREST **************************";
}

