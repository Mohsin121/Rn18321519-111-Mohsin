 #include<iostream>             //programe for uploading lecture by teacher
 #include<string>
 using namespace std;
 #include<conio.h>
#include <fstream>
#include<windows.h>


 class Teacher_portal{
 	protected:
 	  string teach_name;	
 	  //long teach_id;
 	  string teach_id;
 	  	string u,p, username,password;
	   public:	   	
	   virtual void get_info()
 	  	{
 	  		cout<<"Enter YOur(Teacher) Name:";
 	  		cin>>teach_name;
			cout<<endl;
 	  		cout<<"Enter Your Identification No:";
 	  		cin>>teach_id;
 	  			char a;
				a=getch();
				while(a!=13){             //this procees is for securing pass
					cout<<"*";           //pass will show as asteric
					p.push_back(a);
					a=getch();
 	  }
 	  
 }
 	  	 void check_pass()
 	  	 {
		   	ifstream file;
			//	int n=9;
				file.open("teacher_log.txt");
				while(!file.eof()){
				file>>username>>password;
				if(username==teach_name && password==teach_id)
				{
				cout<<"\nLogged In Successfully!!!\n\n"<<endl;
				system("pause");
				system("cls");
			}
						else if(username!=u&& password!=p)
				{
				cout<<"Invalid."<<endl;
				system("pause");
				system("cls");
				
			}
}

} //login proccess ends here

 };
 
 
  class Course: public file_data
  	{
	  protected:
  	 string course_name;
  	 int lecture_no;
  	 string dep_name;
    public:
    	void get_info()
    	{
    		cout<<"Enter Course Name:";
    		cin>>course_name;
    		cout<<endl;
    		cout<<"Enter LEcture Number :";
    		cin>>lecture_no;
    		cout<<"Enter Departement name :";
    		cin>>dep_name;
    		   
		  
    }
		 };
		 
		 
		 
 class file_data: public Course,public Teacher_portal
 {
 protected:
 
		string username,password;
 	public:

//uploading lectures
void upload_lecture()
		  {
		    ofstream upload_lecture("lectures.txt",ios::app);
              if ( ! upload_lecture)
           cout<<"File Opening error\n";
         upload_lecture<<lecture_no<<endl;upload_lecture<<course_name<<"\t"<<dep_name<<"\t"<<endl;
        upload_lecture.close();
        }
//Removing data
     void Remove(){
       	system ("cls");
        	string line,deleteline;
	ifstream rem;
    rem.open("lectures.txt");
    ofstream temp;
    temp.open("temp.txt");
     int t;
			while (!rem.eof())
			{
				rem>>deleteline;      
				getline(rem,line);
				cout<<deleteline<<":  "<<line<<endl;
			}
    cout << "Enter lecture.# to be Removed:";
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
    remove("lectures.txt");
    rename("temp.txt","lectures.txt");
    cout<<endl;
    Sleep(500);
    } 
    
//searching by given id
 void Search (){
    	againsearch:
    		system ("cls");
        string id;
        char searchagain;
        cout<<"Enter Id No to be Searched:";
				cin>>id;
				string  searchroll;
					string temp1=id;
				ifstream searching("lectures.txt");
				while (!searching.eof())
				{
                    getline (searching,id);
					if (temp1==id)
					{
						getline (searching,id);
						system("cls");
						cout<<"\nYour id is "<<id<<"\nLecture no: "<<lecture_no;
						cout<<endl;
						break;
					}
				else
				{
			 system ("cls");
                    cout<<"\n\tInvalid ID No!!! / Record not found"<<endl;   }
                    cout<<"To search again\n1:Yes\t\t2:No\n";
                    cin>>searchagain;
                    if (searchagain=='1')
                        goto againsearch;   
			}
		}

 	  
 };
 
  
  
 //static file_data::total=0;                 //static data mebmber for all files data
    int main()
    {
    	Course c1;
        Teacher_portal t1;
        file_data f1;
    	Teacher_portal *ptr[3];
    	char confirmation;
		ptr[0]=new t1;
    	t1->get_info();// applying Polymorpphism by virtual function given at first class
		t1->login();
		t1->check_pass();       // checking login id and pass
		ptr[1]=new c1;
		c1->get_info();
		ptr[3]=new f1;
		f1->upload_lecture();
		f1->Search();
		f1->Remove();
		   
          return 0;
		
    //	soryy sir time is short   
    	
    	
	}
