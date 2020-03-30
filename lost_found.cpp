#include<iostream>
#include<string>
#include <string>
#include<algorithm>
using namespace std;
class node
{
	string person;
	string name;
    int date;
    int month;
    int year;
    int building;
    int floor;
    string colour;
    node *next;
    node()             //node constructor
    {
    	person="";
    	name=" ";
    	date=0;
    	year=0;
    	month=0;
    	building=0;
    	floor=0;
    	colour="";
    	next=NULL;
    }

    friend class lost;
    friend class found;
};
class found
{
	friend class lost;
	node *fstart=NULL;

public:
	void insert_found_property();             //insert found item in list
	void search_from_found_list();            //search in found list



};
class lost
{
	node *lstart=NULL;
public:
	void insert(found);                       		//insert in lost list
	void delete_lost_request();              		//delete lost request
	int search_from_found_list(string,int,int,string,found);     /*if item found in found list then don't
	                                                              add the item in lost list*/
	void display_lost_list();                       //display list of all items

	friend class found;
};

void lost::insert(found f1)
{
	node *temp=new node();
	int f=0;
	cout<<"Enter your name: "; //insert all details of lost item
	cin.ignore();
	getline(cin,temp->person);
	cout<<endl;
	cout<<"Enter lost item name: ";
	getline(cin,temp->name);
	cout<<endl;
	do
	{
		f=0;
		cout<<"enter year on which you lost(2018/2019) "<<temp->name<<": ";
		cin>>temp->year;
		if(temp->year<2018 || temp->year>2019)
		{
			f=1;
			cout<<"\nrequest can not be accepted. please change the year"<<endl;
		}
	}while(f==1);
	do{
		f=0;
		cout<<"enter month on which you lost(1-12) "<<temp->name<<": ";
		cin>>temp->month;
		if(temp->month<1 || temp->month>12)
		{
			f=1;
			cout<<"\nrequest can not be accepted. please change the month";
		}
	}while(f==1);
	do
	{
		f=0;
		cout<<"enter date on which you lost "<<temp->name<<": ";
		cin>>temp->date;
		if(temp->date<1 || temp->date>31)
		{
			f=1;
			cout<<"\nrequest can not be accepted. please change the date";
		}

	}while(f==1);
	cout<<endl;
	do

	{
		cout<<"enter building no. where you lost your "<<temp->name<<" according to menu"<<endl<<endl;
		cout<<"1 MECHANICAL BUILDING"<<endl;
		cout<<"2 INSTRUMENTATION BUILDING"<<endl;
		cout<<"3 IT BUILDING"<<endl;
		cout<<"4 COMPUTER BUILDING"<<endl;
		cout<<"5 DON'T REMEMBER"<<endl;
		cin>>temp->building;
	}while(1>temp->building||temp->building>5);
	cout<<endl;
	do
	{
		cout<<"enter floor no(0-5) where you lost your and enter 6 for 'DONT REMEMBER' "<<temp->name<<": "<<endl;
		cin>>f;
		cout<<endl;
		temp->floor=f;
	}while(0>temp->floor||temp->floor>6);

	cout<<"Enter colour of "<<temp->name<<": ";
	cin>>temp->colour;
	cout<<endl;
	temp->next=NULL;
	int a=search_from_found_list( temp->name,temp->building,temp->floor,temp->colour,f1);   /*if item found in found list then don't
	                                                                                       add the item in lost list*/
	if(a==1)
	{
		cout<<"your property found .Collect the same from lost and found section"<<endl;
		return;
	}

	if(lstart==NULL)
	{
		lstart=temp;
		cout<<"your request has been accepted"<<endl;
	}
	else
	{
		node *ptr;
		ptr=lstart;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		cout<<"your request has been accepted"<<endl;
	}


}
int lost::search_from_found_list(string name,int b,int f,string c,found f1)
{
	node *ptr;

	ptr=f1.fstart;


	while(ptr!=NULL)
	{
		transform(ptr->name.begin(), ptr->name.end(), ptr->name.begin(), ::toupper);
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		transform(ptr->colour.begin(), ptr->colour.end(), ptr->colour.begin(), ::toupper);
		transform(c.begin(), c.end(), c.begin(), ::toupper);
		//ptr->name=toupper(ptr->name);
		if(b==5||f==6)
		{
			if(ptr->name==name&&ptr->colour==c)
				return 1;
		}
		if(ptr->name==name && ptr->building==b && ptr->floor==f)
		{
			return 1;
		}
		ptr=ptr->next;
	}

	return 0;

}

void found::search_from_found_list()             //to search in found list
{

	string name;
	string colour;
	int building;
	int floor;
	cout<<"enter property name you want to search in found list ";
	cin.ignore();
	getline(cin,name);
	cout<<endl;
	cout<<"enter colour of your "<<name<<" lost: ";
	cin>>colour;
	cout<<endl;
	do{
		cout<<"enter building according to menu where your "<<name<<" was lost"<<endl;
		cout<<" 1 MECHANICAL BUILDING"<<endl;
		cout<<" 2 INSTRUMENTATION BUILDING"<<endl;
		cout<<" 3 IT BUILDING"<<endl;
		cout<<" 4 COMPUTER BUILDING"<<endl;
		cout<<" 5 DONT REMEMBER"<<endl;
		cin>>building;
	}while(1>building||5<building);

	cout<<"enter floor where your "<<name<<" was lost:(0-5) AND 6 for 'DONT REMEMBER' ";
	cin>>floor;
	cout<<endl;
	node *ptr;
	node *prev;
	int flag=0;
	//int f;
	ptr=fstart;

	while(ptr!=NULL)
	{
		transform(ptr->name.begin(), ptr->name.end(), ptr->name.begin(), ::toupper);
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		transform(ptr->colour.begin(), ptr->colour.end(), ptr->colour.begin(), ::toupper);
		transform(colour.begin(), colour.end(), colour.begin(), ::toupper);
		if(building==5||floor==6)
		{
			if(ptr->name==name && ptr->colour==colour)
			{
				flag=1;
				cout<<"Your property found.Kindly collect it and you are requested to delete your lost application "<<endl<<endl;
				cout<<"Follow the following steps to delete your lost application"<<endl;
				cout<<"LOST->OLD APPLICATION->DELETE LOST APPLICATION"<<endl;

				if(ptr==fstart)           //if item found in found list then deleting item from found list
				{
					ptr=fstart;
					fstart=fstart->next;
					delete ptr;
					break;
				}
				else
				{
					prev->next=ptr->next;
					delete ptr;
					break;
				}
			}
		}
		if(ptr->name==name && ptr->building==building && ptr->floor==floor && ptr->colour==colour)
		{
			flag=1;
			cout<<"Your property found.Kindly collect it and you are requested to delete your lost application "<<endl<<endl;
			cout<<"Follow the following steps to delete your lost application"<<endl;
			cout<<"LOST->OLD APPLICATION->DELETE LOST APPLICATION"<<endl;

			if(ptr==fstart)           //if item found in found list then deleting item from found list
			{
				ptr=fstart;
				fstart=fstart->next;
				delete ptr;
				break;
			}
			else
			{
				prev->next=ptr->next;
				delete ptr;
				break;
			}
		}
		prev=ptr;
		ptr=ptr->next;
	}
	if(flag==0)                //if flag=0 then item  not present in found list
	{
		cout<<"No such entry exist in found list"<<endl;
	}
	return ;
}

void lost::delete_lost_request()
{
	string name;                   //input details to delete the item
	string person;
	string colour;
	cout<<"enter your name: ";
	cin.ignore();
	getline(cin,person);
	cout<<endl;
	cout<<"enter your property name: ";
	//cin.ignore();
	getline(cin,name);
	cout<<endl;
	cout<<"enter colour of your "<<name<<" lost: ";
	cin>>colour;
	cout<<endl;
	node *ptr;
	node *prev;
	int flag=0;

	ptr=lstart;
	while(ptr!=NULL)          //search item in lost list
	{
		//ptr->name.toupper()
		transform(ptr->name.begin(), ptr->name.end(), ptr->name.begin(), ::toupper);
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		transform(ptr->person.begin(), ptr->person.end(), ptr->person.begin(), ::toupper);
		transform(person.begin(), person.end(), person.begin(), ::toupper);
		transform(ptr->colour.begin(), ptr->colour.end(), ptr->colour.begin(), ::toupper);
		transform(colour.begin(), colour.end(), colour.begin(), ::toupper);

		if(ptr->name==name && ptr->person==person &&ptr->colour==colour)//comparison ignoring cases
		{                                                                 //if item found then delete it from lost list
			flag=1;
			node *ptr1;
			ptr1=lstart;
			if(ptr==lstart)                                   //delete 1st item
			{
				ptr1=lstart;
				lstart=lstart->next;
				delete ptr1;
				cout<<"Your request is successfully deleted"<<endl;
				return ;
			}
			else                                           //delete other than 1st item
			{

				prev->next=ptr->next;
				delete ptr;
				cout<<"Your request is successfully deleted"<<endl;
				return;

			}


		}
		prev=ptr;
		ptr=ptr->next;
	}
	if(flag==0)
	{
		cout<<"No such entry exist in lost list"<<endl;
	}
	return ;
}
void found::insert_found_property()
{
	node *temp=new node();
	cout<<"enter found item name: "; //input details of found item
	cin.ignore();
	getline(cin,temp->name);
	cout<<endl;
	int f=0;
	do
	{
		cout<<"enter building no. according to menu"<<endl<<endl;
		cout<<"1 MECHANICAL BUILDING"<<endl;
		cout<<"2 INSTRUMENTATION BUILDING"<<endl;
		cout<<"3 IT BUILDING"<<endl;
		cout<<"4 COMPUTER BUILDING"<<endl;
		cin>>temp->building;
	}while(1>temp->building||temp->building>4);
	do
	{
		cout<<"enter floor no(0-5)"<<endl;
		cin>>temp->floor;
	}while(0>temp->floor||temp->floor>5);
	do
		{
			f=0;
			cout<<"enter year on which you found "<<temp->name<<": ";
			cin>>temp->year;
			if(temp->year<2018 || temp->year>2019)
			{
				f=1;
				cout<<"\nrequest can not be accepted. please change the year"<<endl;
			}
		}while(f==1);
		do{
			f=0;
			cout<<"enter month on which you found (1-12)"<<temp->name<<": ";
			cin>>temp->month;
			if(temp->month<1 || temp->month>12)
			{
				f=1;
				cout<<"\nrequest can not be accepted. please change the month";
			}
		}while(f==1);
		do
		{
			f=0;
			cout<<"enter date on which you found "<<temp->name<<": ";
			cin>>temp->date;
			if(temp->date<1 || temp->date>31)
			{
				f=1;
				cout<<"\nrequest can not be accepted. please change the date";
			}

		}while(f==1);
	cout<<"enter colour of "<<temp->name<<" found"<<endl;
	cin>>temp->colour;
	temp->next=NULL;


	if(fstart==NULL)
	{
		fstart=temp;
	}
	else
	{
		node *ptr;
		ptr=fstart;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;

	}
	cout<<"Your found request has been accepted"<<endl;
	cout<<"Thank You for the deposit of "<<temp->name<<" "<<endl;


}
void lost::display_lost_list()
{
	node *ptr=lstart;
	if(lstart==NULL)
	{
		cout<<"lost list is empty"<<endl;
	}
	else
	{
		while(ptr!=NULL)
		{
			cout<<"\nname of the lost item: "<<ptr->name<<endl;
			cout<<"\ndate of the lost item: "<<ptr->date<<endl;
			cout<<"\nfloor of the lost item: "<<ptr->floor<<endl;
			cout<<"\nbuilding of the lost item: "<<ptr->building<<endl;
			cout<<"\ncolour of the lost item: "<<ptr->colour<<endl;
			cout<<"----------------------------------------------------------"<<endl;
			ptr=ptr->next;
		}


	}

}
int main()
{


	int ch;
	int ch1,ch2;
	lost l1;
	found f1;

	do
	{
		cout<<endl<<endl;
		cout<<"******************** MENU *********************"<<endl;     //display main menu
		cout<<"    1. LOST "<<endl;
		cout<<"    2. FOUND "<<endl;
		cout<<"    3. EXIT"<<endl<<endl;

		cout<<"Enter your choice"<<endl;
		cin>>ch;
		cout<<"-------------------------------------------------"<<endl;

		switch(ch)
		{
		case 1:
			cout<<"    1. OLD APPLICATION"<<endl;                        //display lost menu
			cout<<"    2. NEW APPLICATION"<<endl<<endl;
			cout<<"Enter your choice"<<endl;
			cin>>ch1;

			switch(ch1)
			{
			case 1:
				cout<<"    1. SEARCH FROM FOUND LIST"<<endl;            //display old application menu
				cout<<"    2. DELETE YOUR LOST APPLICATION"<<endl;
				cout<<"    3. SEE THE LOST LIST"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>ch2;
				cout<<"-------------------------------------------------"<<endl;

				switch(ch2)
				{
				case 1:
					f1.search_from_found_list();        /*search an old application in found list
														 (search whether lost property found or not)*/


					break;


				case 2:
					l1.delete_lost_request();           //delete lost application
					break;
				case 3:
					l1.display_lost_list();             //display lost list
					break;
				default:
					cout<<"INVALID CHOICE!!"<<endl;
				}
				break;
			case 2:
				l1.insert(f1);                         //insertion in lost list
				break;
			default:
				cout<<"INVALID CHOICE!!"<<endl;
			}
			break;
		case 2:
			f1.insert_found_property();                 //insertion in found list
			break;
		case 3:
			cout<<"THANK YOU"<<endl;
			break;
		default:
			cout<<"INVALID CHOICE!!"<<endl;

		}

	}while(ch!=3);


	return 0;
}
/*
 *

******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
1
-------------------------------------------------
    1. OLD APPLICATION
    2. NEW APPLICATION

Enter your choice
2
Enter your name: rutuja dharankar

Enter lost item name: watch

enter year on which you lost watch: 2019
enter month on which you lost watch: 10
enter date on which you lost watch: 5

enter building no. where you lost your watch according to menu

1 MECHANICAL BUILDING
2 INSTRUMENTATION BUILDING
3 IT BUILDING
4 COMPUTER BUILDING
5 DON'T REMEMBER
1

enter floor no(0-5) where you lost your and enter 6 for 'DONT REMEMBER' watch:
1

Enter colour of watch: steel

your request has been accepted


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
1
-------------------------------------------------
    1. OLD APPLICATION
    2. NEW APPLICATION

Enter your choice
2
Enter your name: bhagyashri

Enter lost item name: pouch

enter year on which you lost pouch: 2018
enter month on which you lost pouch: 12
enter date on which you lost pouch: 12

enter building no. where you lost your pouch according to menu

1 MECHANICAL BUILDING
2 INSTRUMENTATION BUILDING
3 IT BUILDING
4 COMPUTER BUILDING
5 DON'T REMEMBER
2

enter floor no(0-5) where you lost your and enter 6 for 'DONT REMEMBER' pouch:
2

Enter colour of pouch: green

your request has been accepted


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
1
-------------------------------------------------
    1. OLD APPLICATION
    2. NEW APPLICATION

Enter your choice
2
Enter your name: siddhi k

Enter lost item name: pen

enter year on which you lost pen: 2019
enter month on which you lost pen: 1
enter date on which you lost pen: 1

enter building no. where you lost your pen according to menu

1 MECHANICAL BUILDING
2 INSTRUMENTATION BUILDING
3 IT BUILDING
4 COMPUTER BUILDING
5 DON'T REMEMBER
3

enter floor no(0-5) where you lost your and enter 6 for 'DONT REMEMBER' pen:
3

Enter colour of pen: black

your request has been accepted


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
2
-------------------------------------------------
enter found item name: Watch

enter building no. according to menu

1 MECHANICAL BUILDING
2 INSTRUMENTATION BUILDING
3 IT BUILDING
4 COMPUTER BUILDING
1
enter floor no(0-5)
1
enter year on which you found Watch: 2019
enter month on which you found Watch: 10
enter date on which you found Watch: 5
enter colour of Watch found
steel
Your found request has been accepted
Thank You for the deposit of Watch


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
2
-------------------------------------------------
enter found item name: pen

enter building no. according to menu

1 MECHANICAL BUILDING
2 INSTRUMENTATION BUILDING
3 IT BUILDING
4 COMPUTER BUILDING
3
enter floor no(0-5)
3
enter year on which you found pen: 2019
enter month on which you found pen: 11
enter date on which you found pen: 18
enter colour of pen found
black
Your found request has been accepted
Thank You for the deposit of pen


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
2
-------------------------------------------------
enter found item name: keys

enter building no. according to menu

1 MECHANICAL BUILDING
2 INSTRUMENTATION BUILDING
3 IT BUILDING
4 COMPUTER BUILDING
3
enter floor no(0-5)
3
enter year on which you found keys: 2019
enter month on which you found keys: 11
enter date on which you found keys: 18
enter colour of keys found
grey
Your found request has been accepted
Thank You for the deposit of keys


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
1
-------------------------------------------------
    1. OLD APPLICATION
    2. NEW APPLICATION

Enter your choice
2
Enter your name: sam

Enter lost item name: keys

enter year on which you lost keys: 2019
enter month on which you lost keys: 17

request can not be accepted. please change the monthenter month on which you lost keys: 11
enter date on which you lost keys: 17

enter building no. where you lost your keys according to menu

1 MECHANICAL BUILDING
2 INSTRUMENTATION BUILDING
3 IT BUILDING
4 COMPUTER BUILDING
5 DON'T REMEMBER
3

enter floor no(0-5) where you lost your and enter 6 for 'DONT REMEMBER' keys:
3

Enter colour of keys: grey

your property found .Collect the same from lost and found section


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
1
-------------------------------------------------
    1. OLD APPLICATION
    2. NEW APPLICATION

Enter your choice
1
    1. SEARCH FROM FOUND LIST
    2. DELETE YOUR LOST APPLICATION
    3. SEE THE LOST LIST
Enter your choice
1
-------------------------------------------------
enter property name you want to search in found list watch

enter colour of your watch lost: steel

enter building according to menu where your watch was lost
 1 MECHANICAL BUILDING
 2 INSTRUMENTATION BUILDING
 3 IT BUILDING
 4 COMPUTER BUILDING
 5 DONT REMEMBER
1
enter floor where your watch was lost:(0-5) AND 6 for 'DONT REMEMBER' 1

Your property found.Kindly collect it and you are requested to delete your lost application

Follow the following steps to delete your lost application
LOST->OLD APPLICATION->DELETE LOST APPLICATION


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
1
-------------------------------------------------
    1. OLD APPLICATION
    2. NEW APPLICATION

Enter your choice
1
    1. SEARCH FROM FOUND LIST
    2. DELETE YOUR LOST APPLICATION
    3. SEE THE LOST LIST
Enter your choice
2
-------------------------------------------------
enter your name: rutuja dharankar

enter your property name: watch

enter colour of your watch lost: steel


SUCCESSFULLY DELETED
******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
1
-------------------------------------------------
    1. OLD APPLICATION
    2. NEW APPLICATION

Enter your choice
1
    1. SEARCH FROM FOUND LIST
    2. DELETE YOUR LOST APPLICATION
    3. SEE THE LOST LIST
Enter your choice
3
-------------------------------------------------

name of the lost item: pouch

date of the lost item: 12

floor of the lost item: 2

building of the lost item: 2

colour of the lost item: green
----------------------------------------------------------

name of the lost item: pen

date of the lost item: 1

floor of the lost item: 3

building of the lost item: 3

colour of the lost item: black
----------------------------------------------------------


******************** MENU *********************
    1. LOST
    2. FOUND
    3. EXIT

Enter your choice
 *
 */


