#include<iostream>
using namespace std;
#include<fstream>
 class Person{
 	          protected :
 	          	long id;
 	             string name;
 	             public:
 	             	      void screen()
    {
		cout<<("--------------lOGIN PANEL--------------  ");
		cout<<("");
		cout<<("\n1-\t  TEACHER");
		cout<<("\n2-\t  STUDENT\n");
		cout<<("");
		cout<<("---------------------------------------");
		
	}
		             	      void screen2()
    {
		cout<<("--------------Teacher PANEL--------------  ");
		cout<<("");
		cout<<("\n1-\t  Upload Result");
		cout<<("\n2-\t Add record of STUDENT\n");
		cout<<("\n2-\t Search Student Record\n");
		cout<<("\n2-\t Delete Student Record\n");
		cout<<("");
		cout<<("---------------------------------------");
		
	}
	     void screen3()
    {
		cout<<("--------------Student PANEL--------------  ");
		cout<<("");
		cout<<("\n2-\t Search Student Record\n");
		cout<<("\n2-\t Search Result by roll number\n");
		cout<<("");
		cout<<("---------------------------------------");
		
	}
 	             virtual void getdata()=0;
 	             //	virtual void getName()=0;
 	
 	
 };
 
 class Teacher : public Person {
 	             protected:
 	             	int scale;
 	             	string courseCode;
 	           	string courseName;
 	           	int creditHour;
 	             	public:
 	             void getdata()
 	                 {
 	                 	cout<<"Enter the Teacher Id :";
 	                 	cin>>id;
				      	cout<<"Enter teacher Name :";
 	                 	cin>>name;
 	                 	cout<<"Enter teacher Scale:";
 	                 	cin>>scale;
 	                 	cout<<endl;
				}
 	void courseinfo()
 	           		{
 	           				
 	           			cout<<"Enter the  course code :";
 	           			cin>>courseCode;
 	           			cout<<"\nEnter the Course name:";
 	           			cin>>courseName;
 	           			cout<<"\nEnter credit hour:";
 	           			cin>>creditHour;
						}
 	
 	           			void teacherrec()
 	           			{
 	           				ofstream in;
 	           				in.open("Teacherrecord.txt",ios::out|ios::app);
 	           			 cout<<"Teacher Id\t"<<"Course code\t"<<"Teach Scale\t"<<"Course name\t"<<"Credit Hour\n";
								in<<id<<"\t";
 	           			
 	           				in<<name<<"\t"<<scale<<"\t"<<courseCode<<"\t"<<courseName<<"\t"<<creditHour<<endl;
 	           				
 	           		
							}
 	           			
 	           			
 	           	void uploadmarks()
 	           	{
						marksaddion:
							char confirmation;
                system ("cls");
                int rollno;
                int marks[3];
                ofstream marksadd;
                 marksadd.open("Finals.txt",ios::out|ios::app);
                cout<<"Enter Roll # to Add  Marks.\n";
                cin>>rollno;
                cout<<"\nEnter OOP marks\t";
                cin>>marks[0];
                 cout<<"\nEnter OOP Sessional marks";
                cin>>marks[1];
                 cout<<"\nEnter OOP project maarks\t";
                cin>>marks[2];
                 cout<<"\nEnter OOP Final marks\t";
                cin>>marks[3];
                   cout<<"To save data\n1:yes\t\t2:No\n";
                cin>>confirmation;
                if (confirmation=='1'){
                        marksadd<<rollno<<" ";
                        for (int i=0;i<4;i++)
                        
                        marksadd<<marks[i]<<" ";			
                }
                else goto marksaddion;
                    marksadd<<endl;
                    marksadd.close();
                 cout<<"\nTo add more data\n1:Yes\t\t2:No\n";
                cin>>confirmation;
                if (confirmation=='1')
                    goto marksaddion;
    }
 	       Addrecord (){
    ofstream add_name("Studentrecord.txt",ios::app);
    if ( ! add_name)
        cout<<"File Opening error\n";
       add:
       	system ("cls");
        cout<<"Enter Name:";
        cin.ignore();
        getline (cin,name);
        cout<<"Enter Roll No: ";
        try{
        	cin>>roll_no;
        	if(roll_no<=0)
        	throw 0;
		}
		catch(int){
			cout<<"Error\n";
			return 1;
		}
    
        cin>>id;
       cout<<"\nTo save data:\n1:Yes\t\t2:No\n";
        cin>>confirmation;
        if (confirmation=='1')
       {
        add_name<<roll_no<<endl;add_name<<name<<;
       roll_no++;
   }
        cout<<"To add More:\n1:yes\t\t2:Menu:\n";
        cin>>more;
        if (more=='1')
        goto add;
        add_name.close();
        }
 	         		
 	
 };
 
 class Student : public Person{
 	
 		public:
 	               void getdata()
 	                 {
 	                 	cout<<"Enter the student Id :";
 	                 	cin>>id;
				      	cout<<"Enter student Name :";
 	                 	cin>>name;
				}
				
					void studentrec()
 	           			{
 	           				ofstream ins;
 	           				ins.open("Studentrecord.txt",ios::out|ios::app);
 	           			 cout<<"Student Id\t|Student Name"<<endl;
								ins<<id<<"\t";
 	           			
 	           				ins<<name<<endl; 	           		
							}
				
 };
 
 
 class filedata : public Teacher,public Student
 {

 		
 	
	 public:
 	void  searchbyid()
 	{
	 int marks[3];
    	againsearch:
    		system ("cls");
    		char searchagain;
        string rollno;
        cout<<"Enter ID to be Searched:";
				cin>>rollno;
				string temp1=rollno;
				string  searchroll;
				ifstream searching("Studentrecord.txt");
				ifstream marksearch("Finals.txt");
				if (!marksearch)
				cout<<"Processing Error.....\n";
				while (!searching.eof())
				{
                    getline (searching,rollno);
					if (temp1==rollno)
					{
						getline (searching,name);
						system("cls");
						cout<<"\nYour Roll No is "<<rollno<<"\n\nName: "<<name;
						cout<<endl;
						break;
					}
					 marksearch>>searchroll>>marks[0]>>marks[1]>>marks[2]>>marks[3];
                     cout<<searchroll<<endl;     
                    if (rollno==searchroll)
                    {
                    	
                       for(int i=0;i<7;i++){
                       	cout<<marks[i]<<"\t";
					   }
                    }
				}
				if (temp1==rollno)
				cout<<"\n\n\n\tMatched!!!!\n";
				else
				{
			 system ("cls");
                    cout<<"\n\tInvalid Roll No!!! / Record not found"<<endl;   }
                    cout<<"To search again\n1:Yes\t\t2:No\n";
                    cin>>searchagain;
                    if (searchagain=='1')
                        goto againsearch;   
			}
			
			      Addrecord (){
    ofstream add_name("Studentrecord.txt",ios::app);
    if ( ! add_name)
        cout<<"File Opening error\n";
       add:
       	system ("cls");
        cout<<"Enter Name:";
        cin.ignore();
        getline (cin,name);
        cout<<"Enter Roll No: ";
        try{
        	cin>>roll_no;
        	if(roll_no<=0)
        	throw 0;
		}
		catch(int){
			cout<<"Error\n";
			return 1;
		}
        
        cout<<"Enter Contact No:";
        cin>>id;
       cout<<"\nTo save data:\n1:Yes\t\t2:No\n";
        cin>>confirmation;
        if (confirmation=='1')
       {
        add_name<<roll_no<<endl;add_name<<name<<;
       roll_no++;
   }
        cout<<"To add More:\n1:yes\t\t2:Menu:\n";
        cin>>more;
        if (more=='1')
        goto add;
        add_name.close();
        }
 	            void Remove(){
       	system ("cls");
        	string line,deleteline;
	ifstream rem;
    rem.open("Students_data.txt");
    ofstream temp;
    temp.open("temp.txt");
    cout << "Enter Roll No to be Removed:";
    cin >> deleteline;
    while (!rem.eof())
    {
    	getline(rem,line);
        if (line != deleteline)
        	 temp << line << endl;		
      if (line==deleteline)
       	getline(rem,line);
    	
   }
    temp.close();
    rem.close();
    remove("Students_data.txt");
    rename("temp.txt","Students_data.txt");
    cout<<endl;
    Sleep(500);
    }    		
 	           		
 	
 };   
   
	   
	            	
 	int main()
 	{
 		int opt;
 		 system("Color 0A");
 		Student s;
 		Teacher t;
 		//filedata d;
 		//d.searchbyid();
 		Person *ptr;
 		ptr=&t; 
 		l1:
 			ptr->screen();
 		cout<<"\nEnter your choice:";
 		cin>>opt;
 		system("cls");
        ptr->screen2();
		if(opt==1)
 		{//ptr->getdata();
 		  t.courseinfo();
 		  t.uploadmarks();
 		  t.teacherrec();
 		  t.uploadmarks();
		   }
 	    else if(opt==2)
		{
			 ptr=&s;
 		ptr->getdata();
 		s.studentrec();
 		
 	}
 	else
 	{ system("cls");
 		cout<<"\ninvalid option Please try again\n\n";
	
 	goto l1;
 }
		 return 0;
 		
 	}
 		
 		
 		


