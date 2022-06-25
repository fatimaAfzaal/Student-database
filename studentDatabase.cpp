#include<iostream>
#include<string>
using namespace std;
bool arrayFull();
bool arrayEmpty();
int errorChoice(int &choice);
int errorId(int &id);
int errorAttendence(int &attendence);
double errorCgpa(double &cgpa);
void insert(string name ,string fatherName,string dob,string religon,int id,string dep,string address,double attendence,double cgpa,string fee);
void display();
void searchByName(string name);
void searchById(int id);
void searchByDep(string dep);
void searchByReligon(string religon);
void maxCgpa();
void feeStatus(string fee);
struct student
{
	string s_name;
	string s_fatherName;
	string s_dob;
	string s_religon;
	int s_id;
	string s_dep;
	int s_attendence;
	string s_address;
	double s_cgpa;
	string s_fee;
}s_array[50];
int count=0;

int main()
{
	string name;
    string fatherName;
    string dob;
    string religon;
    int id;
    string dep;
    int attendence;
	double cgpa;
    string address;
    string fee;
	int choice;
	cout<<"\n\t\tWelcome to student database program"<<endl;
	do
	{
		cout<<"\n\n\nEnter your choice"<<endl;
		cout<<"*Insertion of data-----------------------------------------------------(Press 1 to select)"<<endl;
		cout<<"*Display of data of all students---------------------------------------(Press 2 to select)"<<endl;
		cout<<"*Search student(e.g by name,by department e.t.c)-----------------------(Press 3 to select)"<<endl;
		cout<<"*Search student whose cgpa is maximum in all students------------------(Press 4 to select)"<<endl;
		cout<<"*Display student's fee status------------------------------------------(Press 5 to select)"<<endl;
		cout<<"*For continue on fresh screen------------------------------------------(Press 6 to select)"<<endl;		
		cout<<"*Exit------------------------------------------------------------------(Press 7 to select)"<<endl;
	    errorChoice(choice);                                      //function for incorrect input.	   
	    switch(choice)
	    {
	    case 1:
	    	{
	    		if(arrayFull())
	    		{
	    			cout<<"\aNo more space for insertion of data"<<endl;
	    			break;
				}
				else
				{
				cout<<"\n\t*Data for student "<<(count+1)<<"*"<<endl;	
	    		cout<<"\nEnter name : ";
	    		getline(cin,name);
				cout<<"Enter father name : ";
	    		getline(cin,fatherName);
	    		cout<<"Enter Date of Birth : ";
	    		getline(cin,dob);
	    		cout<<"Enter religon : ";
	    		getline(cin,religon);
	    		errorId(id);                                        //function for incorrect input.
	    		cout<<"Enter department : ";
	    		getline(cin,dep);
	    		cout<<"Enter address : ";
	    		getline(cin,address);
	    		errorAttendence(attendence);                        //function for incorrect input.
	    		errorCgpa(cgpa);
	    		cout<<"If fee is submitted press y otherwise press n : ";
	    		getline(cin,fee);
	    	    insert(name, fatherName, dob,religon, id, dep, address, attendence, cgpa, fee );
	    	    break;
				}
	    	}
	    	case 2:
	    		{
	    			if(arrayEmpty())
	    			{
	    				cout<<"\t\aNo data is entered.First enter the data"<<endl<<endl;
						break;
	    				
					}
					else
					{
						display();
						break;
					}
				}
				case 3:
					{
					    if(arrayEmpty())
					    {
					    	cout<<"\t\aNo data is entered.First enter the data."<<endl;
					    	break;
						}
						else
						{
							int search;
							cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
							cout<<"^Search by name------------(Press 1 to select)^"<<endl;
							cout<<"^Search by id--------------(Press 2 to select)^"<<endl;
							cout<<"^Search by department------(Press 3 to select)^"<<endl;
							cout<<"^Search by religon---------(Press 4 to select)^"<<endl;
							cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
							cout<<"Enter choice : ";
							cin>>search;
							cin.ignore();
							switch(search)
							{
								case 1:
									{
										cout<<"Enter name for which you want detail : ";
										getline(cin,name);
										searchByName(name);
										break;
										
									}
								case 2:
									{
										cout<<"Enter id for which you want detail : ";
										cin>>id;
										searchById(id);
										break;
									}
								case 3:
									{
										cout<<"Enter department for displaying student of that department : ";
										getline(cin,dep);
										searchByDep(dep);
										break;
									}
								case 4:
									{
										cout<<"Enter religon for displaying student of that religon : ";
										getline(cin,religon);
										searchByReligon(religon);
										break;
									}
								default:
								    {
									    cout<<"\aInvalid input";
									    break;
									}	
							}
									
						}
						break;
					}
				   case 4:
				   	{
				   		if(arrayEmpty())
	    			{
	    				cout<<"\aNo data is entered.First enter the data"<<endl<<endl;
						break;
	    				
					}
					else
					{
						maxCgpa();
						break;
					}
					}
					case 5:
						{
							if(arrayEmpty())
							{
								cout<<"\aNo data is entered.First enter the data"<<endl<<endl;
						        break;
							}
							else
							{
								cout<<"Detail of fee status press y : ";
								cin>>fee;
								feeStatus(fee);
								break;
							}
						}
						case 6:
							{
								system("CLS");
								break;
							}
						case 7:
						{
							system("cls");
							cout<<"\n\n\n                          ^THANKYOU^ "<<endl<<endl;
							cout<<"\t\t***********************************"<<endl;
							cout<<"\t\t* Submitted to : SIR KHWAJA BILAL. *"<<endl;
							cout<<"\t\t* Submitted by : \t\t   *"<<endl;
							cout<<"\t\t*\t\t^FATIMA AFZAAL     *"<<endl;
							cout<<"\t\t*\t\t^SANA SHOUKAT      *"<<endl;
							cout<<"\t\t*\t\t^FATIMA JAVEED     *"<<endl;
							cout<<"\t\t************************************"<<endl<<endl<<endl;
							
							break;
						}
					   default:
					   {
					   	    cout<<"\aInvalid input";
	     			   }				
			}
 
	}
	while(choice!=7);
	return 0;
}

bool arrayFull()                    //function use when array is full
{
	if(count==50)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool arrayEmpty()                       //function used when array is empty
{
	if(count==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int errorChoice(int &choice)                                       //function for entering incorrect choice.
{	
while(true) 
{
	cout<<"Enter choice here: ";
	cin>>choice;
	if( cin.good() )
	{
		cin.ignore(10, '\n');
	    break;
	}
	cin.clear();
	cerr<< "\a\tIncorrect input!!!!!!\nEnter choice in numbers.\n";
	cin.ignore(10, '\n');
}
}

int errorId(int &id)                                       //function for entering incorrect id.
{	
while(true) 
{
	cout<<"Enter id : ";
	cin>>id;
	if( cin.good() )
	{
		cin.ignore(10, '\n');
	    break;
	}
	cin.clear();
	cerr<< "\a\tIncorrect input!!!!!!\n";
	cin.ignore(10, '\n');
}
}

int errorAttendence(int &attendence)                                       //function for entering incorrect attendence.
{	
while(true) 
{
	cout<<"Enter attendence: ";
	cin>>attendence;
	if( cin.good() )
	{
		cin.ignore(10, '\n');
	    break;
	}
	cin.clear();
	cerr<< "\a\tIncorrect input!!!!!!\n";
	cin.ignore(10, '\n');
}
}

double errorCgpa(double &cgpa)                                  //function for entering incorrect cgpa.
{
	while(true) 
{
	cout<<"Enter cgpa: ";
	cin>>cgpa;
	if( cin.good() )
	{
		cin.ignore(10, '\n');
	    break;
	}
	cin.clear();
	cerr<< "\a\tIncorrect input!!!!!!\n";
	cin.ignore(10, '\n');
}
}

void insert(string name ,string fatherName,string dob,string religon,int id,string dep,string address,double attendence,double cgpa,string fee)       //function for insertindg data
{
	s_array[count].s_name = name;
	s_array[count].s_fatherName = fatherName;
	s_array[count].s_dob = dob;
	s_array[count].s_religon = religon;
	s_array[count].s_id = id;
	s_array[count].s_dep = dep;
	s_array[count].s_address = address;
	s_array[count].s_attendence = attendence;
	s_array[count].s_cgpa = cgpa;
	s_array[count].s_fee = fee;
	count++;
	cout<<"\t\n\nData has been saved successfully"<<endl;
}

void display()                //Function for displaying data of all students
{
	for(int i=0;i<count;i++)
	{
		cout<<"\tData of student "<<i+1<<endl<<endl; 
		cout<<"Name : "<<s_array[i].s_name<<endl;
		cout<<"Father name : "<<s_array[i].s_fatherName<<endl;
		cout<<"Date of birth : "<<s_array[i].s_dob<<endl;
		cout<<"Religon : "<<s_array[i].s_religon<<endl;
		cout<<"ID : "<<s_array[i].s_id<<endl;
		cout<<"Department : "<<s_array[i].s_dep<<endl;
		cout<<"Address : "<<s_array[i].s_address<<endl;
		cout<<"attendence : "<<s_array[i].s_attendence<<endl;
		cout<<"cgpa : "<<s_array[i].s_cgpa<<endl;
		cout<<"Fee :"<<s_array[i].s_fee<<endl;
	}
}

void searchByName(string name)                  //function for search by name
{
	bool flag=true;
	for(int i=0;i<count;i++)
	{
		if(s_array[i].s_name==name)
		{
			cout<<"\tData of student "<<name<<endl<<endl; 
	    	cout<<"Name : "<<s_array[i].s_name<<endl;
    		cout<<"Father name : "<<s_array[i].s_fatherName<<endl;
    		cout<<"Date of birth : "<<s_array[i].s_dob<<endl;
    		cout<<"Religon : "<<s_array[i].s_religon<<endl;
    		cout<<"ID : "<<s_array[i].s_id<<endl;
    		cout<<"Department : "<<s_array[i].s_dep<<endl;
    		cout<<"Address : "<<s_array[i].s_address<<endl;
    		cout<<"attendence : "<<s_array[i].s_attendence<<endl;
    		cout<<"cgpa : "<<s_array[i].s_cgpa<<endl;
    		cout<<"Fee :"<<s_array[i].s_fee<<endl;
			flag=false;
			break;
		}
	}
		if(flag)
		{
			cout<<"The data of "<<name<<" is not entered";
		}
}

void searchById(int id)               //function for search by id
{
	bool flag=true;
	for(int i=0;i<count;i++)
	{
		if(s_array[i].s_id==id)
		{
			cout<<"\tDetails of student "<<id<<endl<<endl; 
	    	cout<<"Name : "<<s_array[i].s_name<<endl;
    		cout<<"Father name : "<<s_array[i].s_fatherName<<endl;
    		cout<<"Date of birth : "<<s_array[i].s_dob<<endl;
    		cout<<"Religon : "<<s_array[i].s_religon<<endl;
    		cout<<"ID : "<<s_array[i].s_id<<endl;
    		cout<<"Department : "<<s_array[i].s_dep<<endl;
    		cout<<"Address : "<<s_array[i].s_address<<endl;
    		cout<<"attendence : "<<s_array[i].s_attendence<<endl;
    		cout<<"cgpa : "<<s_array[i].s_cgpa<<endl;
    		cout<<"Fee :"<<s_array[i].s_fee<<endl;
			flag=false;
			break;
		}
	}
		if(flag)
		{
			cout<<"The data of "<<id<<" is not entered";
		}	
}

void searchByDep(string dep)             //function for search by department
{
	cout<<"\n\tstudents of department "<<dep<<" are"<<endl;
	bool flag = true;
	for(int i=0;i<count;i++)
	{
		if(s_array[i].s_dep==dep)
		{
			cout<<"\t* "<<s_array[i].s_name<<endl; 
	        flag = false;
	        if(flag = false)
			continue;    
		}
	}
	if(flag)
	{
		cout<<"\t\t\t\t\tnot entered"<<endl;
	}
		
}

void searchByReligon(string religon)             //function for search by religon
{
	cout<<"\tstudents of religon "<<religon<<" are"<<endl;
	bool flag = true;
	for(int i=0;i<count;i++)
	{
        
		if(s_array[i].s_religon==religon)
		{
			cout<<"\t* "<<s_array[i].s_name<<endl;
			flag = false;
			if (flag = false)
			continue;
		}	
	}
	if(flag)
	{
		cout<<"\t\t\t\tnot entered"<<endl;
	}
}

void maxCgpa()                //function for max cgpa
{
	double cgpa = s_array[0].s_cgpa;
	int countGpa=0;
	for(int i=0;i<count;i++)
	{
		if (cgpa<s_array[i].s_cgpa)
		{
			cgpa=s_array[i].s_cgpa;
			countGpa=i;
		}
	}
	cout<<"Max cgpa is "<<cgpa<< " of student "<<s_array[countGpa].s_name;
}

void feeStatus(string fee)
{
	cout<<"\tstudents whose fee is submitted  are"<<endl;
	for(int i=0;i<count;i++)
	{
		
		if(s_array[i].s_fee == fee)
		{
			cout<<"\t* "<<s_array[i].s_name<<endl;	
		}
		continue;
		break;
	}
	cout<<"\tstudents whose fee is not submitted  are"<<endl;
	for(int i=0;i<count;i++)
	{
		
		if(s_array[i].s_fee!=fee)
		{
			cout<<"\t* "<<s_array[i].s_name<<endl;
		}
	}		
}


