//********************************************************
//PROJECT        -->  COACHING INSTITUTE
//PREPARED BY    -->  AISHWARYA ARORA
//               -->  CHESHTA SHARMA
//CLASS          -->  XII-B
//*******************************************************
//______________________________________________________
// *       *    *         *    * * * * *
// *       *    * *     * *    *
// *       *    *   * *   *    *
// *       *    *    *    *    *
// *       *    *         *    *
//   *   *      *         *    *
//     *        *         *    * * * * *
//_______________________________________________________

//*******************************************************
//                    HEADER FILES
//*******************************************************
//THESE ARE THE HEADER FILES
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
//*******************************************************
//                         CLASS
//*******************************************************
class coaching
 {
   //PRIVATE MEMBERS
   int sno;
   long int phone;
   int fees[5],totfees;
   int nos;
   char add[20];
   int conc;
   int net_fees;
   int n;
   int dd,yy,dd1,yy1;
   char mm[10],mm1[10];
   float perc;
   char teacher_name[15][9];
   char subject[8][4];
   char student_name[20];

//*******************************************************
//    FUNCTION TO INPUT DATA
//*******************************************************
public:
//PUBLIC MEMBERS
void input();
//*******************************************************
//    FUNCTION TO SHOW THE INPUTTED DATA
//*******************************************************
void output();
//*******************************************************
//    FUNCTION TO GET THE SERIAL NUMBER
//*******************************************************
int get_sno()
{
return sno;
}
};
//DECLARING THE INPUTTING FUNCTION OUTSIDE THE CLASS
void coaching::input()
{
  cout<<endl<<"\t - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
  cout<<endl<<"\t\t********ENTER YOUR DETAILS********";
  cout<<endl<<"\t - -   - - - - - - - - - - - - - - - - - - - - - - - - ";
  cout<<"\n ENTER SERIALNO.:-" ;
  cin>>sno;
  cout<<"\n ENTER STUDENT NAME :-";
  gets(student_name);
  cout<<"\n ENTER STUDENT DATE OF BIRTH(in the format 22 august 2002):-";
  cin>>dd>>mm>>yy;
  cout<<"\nENTER YOUR ADDRESS :-";
  gets(add);
  cout<<"\nENTER YOUR LAST YEAR PERCENTAGE:-";
  cin>>perc;
   cout<<"\n ENTER STUDENT'S DATE OF JOINING(in the format 22 august 2002):-";
  cin>>dd1>>mm1>>yy1;
  cout<<"\n ENTER PHONE NUMBER:-";
  cin>>phone;
  cout<<"\n ENTER NUMBER OF SUBJECTS :-";
  cin>>nos;
  for(int i=0;i<nos;i++)
  {
  cout<<"\n ENTER SUBJECT" <<i+1<<":-";
  gets(subject[i]);
  cout<<"\t ENTER TEACHER NAME :-";
  gets(teacher_name[i]);
  }
  cout<<endl<<"______________________________________________________________________";
  }
 //DECLARING THE OUTPUT FUNCTION OUTSIDE THE CLASS
 void coaching::output()
{
  cout<<endl<<"\t - - - - - - - - - - - - - - - - - - - - - - - - ";
  cout<<endl<<"\t\t*******YOUR DETAILS ARE********";
  cout<<endl<<"\t - - - - - - - - - - - - - - - - - - - - - - - - ";
  cout<<"\n THE SERIALNO. :-"<<sno;
  cout<<"\n THE STUDENT NAME :-";
  puts(student_name);
  cout<<"\n STUDENT DATE OF BIRTH:-"<<dd<<"-"<<mm<<"-"<<yy;
  cout<<"\n THE NUMBER OF SUBJECTS :-"<<nos;
  cout<<"\n THE ADDRESS IS:-"<<add;
  cout<<"\n YOUR LAST YEAR PERCENTAGE:-"<<perc<<'%';
  cout<<"\n PHONE NUMBER:-"<<phone;
  cout<<"\n STUDENT'S DATE OF JOINING:-"<<dd1<<"-"<<mm1<<"-"<<yy1;
  for(int i=0;i<nos;i++)
  {
  cout<<"\n  SUBJECT "<<i+1<<":-";
  puts(subject[i]);
  cout<<"\t\t THE TEACHER NAME :-";
  puts(teacher_name[i]);
  }
  cout<<endl<<"__________________________________________________________________";
}
coaching s;
//*******************************************************
//          FUNCTION TO CREATE FILE
//*******************************************************
void createfile()
{
ofstream f("coaching.dat",ios::out|ios::binary);
if(!f)
{
 cout<<"not found";
 exit(0);
}
f.close();

}
//*******************************************************
//               FUNCTION TO APPEND FILE
//*******************************************************
void append()
{
coaching s;
s.input();
ofstream f("coaching.dat",ios::binary|ios::app);
if(!f)
{
cout<<"not found";
exit(0);
}
f.write((char *)&s,sizeof(s));
f.close();
}
//*******************************************************
//        FUNCTION TO DISPLAY THE CONTENTS OF FILE
//*******************************************************
void displayall()
{
coaching s;
ifstream fin("coaching.dat",ios::in|ios::binary);
if(!fin)
{
cout<<"not found";
return;
}
while(!fin.eof())
{
fin.read((char *)&s,sizeof(s));
if(fin.eof())
break;
s.output();
getch();
}
fin.close();
}
//*******************************************************
// FUNCTION TO SEARCH CONTENTS OF FILE
//*******************************************************
void search()
{
int rr;
coaching a1;
char found='n';
cout<<"\n\nEnter the serial no. of student whose record you want to search :: ";
cin>>rr;
ifstream fin;
fin.open("coaching.dat",ios::in|ios::binary);
if(!fin)
{
cout<<"not found";
exit(0);
}
else
{
while(!fin.eof())
{
fin.read((char*)&a1,sizeof(a1));
if(fin.eof())
break;
if(a1.get_sno()==rr)
{
found='y';
a1.output();
}
}
if (found=='n')
cout<<"\n\nSORRY!! Student has no record at our coaching centre.";
}
fin.close();
}
//*******************************************************
// FUNCTION TO MODIFY CONTENTS OF FILE
//*******************************************************

void modify()
{
clrscr();
coaching a1,a2;
int i;
char found='n';
ifstream fin;
fin.open("coaching.dat",ios::binary);
ofstream fout;
fout.open("folder1.dat",ios::binary);
int n;
cout<<"\n\nEnter the serial no of student whose record is to be modified :: "<<endl;
cin>>n;
while(!fin.eof())
{
fin.read((char*)&a1,sizeof a1);
if(fin.eof())
break;
if(a1.get_sno()==n)
{
found='f';
a1.output();
getch();
cout<<"\n\nEnter the new details of the student :: ";
a2.input();
fout.write((char*)&a2,sizeof a2);
}
else
fout.write((char*)&a1,sizeof a1);
}
if(found=='n')
cout<<"\n\nSORRY!! Student has no record at our coaching center.";
fin.close();
fout.close();
remove("coaching.dat");
rename("folder1.dat","coaching.dat");
}
//*******************************************************
//        FUNCTION TO DELETE THE CONTENTS OF FILE
//*******************************************************
void deletion()
{
int r,x;
fstream fin;
ofstream fout;
coaching s;
fin.open("coaching.dat",ios::in|ios::binary);
fout.open("tp.dat",ios::out|ios::binary);
if(!fin)
 {
  cout<<"\n\tfile can't opened";
  exit(0);
 }
else
 {
  cout<<"\n\t Enter the roll number you wanted to delete:";
  cin>>r;
   while(!fin.eof())
	 {
	  fin.read((char*)&s,sizeof(s));
	  if(s.get_sno()!=r)
	  fout.write((char*)&s,sizeof(s));
	  }
fout.close();
remove("coaching.dat");
rename("tp.dat","coaching.dat");
}
}
//*******************************************************
//  FUNCTION TO DISLAY THE INFORMATION ABOUT COURSE 1
//*******************************************************
void course1()
{
cout<<"\n\tVMC's offering for medical preparations is a result of a lot of";
cout<<" careful research about the needs of medical aspirants.The course structure";
cout<<" has been planned and designed in such a way that can be of great help";
cout<<" to students in building their dreams. ";
cout<<"\nDO YOU WANNA GIVE ADMISSION TEST (y/n) :-";
char ch;
cin>>ch;
clrscr();
if(ch=='y'||ch=='Y')
{
cout<<"\nAdmission test on 19th october,2019(only for students who are in class ";
cout<<"class 11 and would be starting their 12 in 2020)";
cout<<endl<<"Enter your class(11/12)";
int x;
cin>>x;
if(x==11)
{
cout<<endl<<"you can register for admission test either online or can contact us";
cout<<endl<<"THANK YOU !!!";
}
else
{
cout<<endl<<"SORRY!!! we can't register for admission test";
cout<<endl<<"THANK YOU!!!";
}
}
else
{
cout<<"WANNA KNOW ABOUT ADMISSION TEST SELECT OPTION 8";
cout<<endl<<"THANK YOU!!!";
}
}
//*******************************************************
//  FUNCTION TO DISLAY THE INFORMATION ABOUT COURSE 2
//*******************************************************
void course2()
{
cout<<endl<<"Founders' classroom course is the flagship course of VMC ,which ";
cout<<"was earlier called the regular classroom program and has consistently";
cout<<" achieved a success rate of more than 60%. the course is of 2 year ";
cout<<"program where all the classes are conducted by three founder of VMC";
cout<<"\nDO YOU WANNA GIVE ADMISSION TEST (y/n):-";
char ch;
cin>>ch;
clrscr();
if(ch=='y'||ch=='Y')
{
cout<<"\nAdmission test on 19th october,2019(only for students who are in class ";
cout<<"class 11 and would be starting their 12 in 2020)";
cout<<endl<<"Enter your class(11/12)";
int x;
cin>>x;
if(x==11)
{
cout<<endl<<"you can register for admission test either online or can contact us";
cout<<endl<<"THANK YOU!!!";
}
else
{
cout<<endl<<"SORRY!!! we can't register for admission test";
cout<<endl<<"THANK YOU!!!";
}
}
else
{
cout<<"WANNA KNOW ABOUT ADMISSION TEST SELECT OPTION 8";
cout<<endl<<"THANK YOU!!!";
}
}
//*******************************************************
//  FUNCTION TO DISLAY THE INFORMATION ABOUT COURSE 3
//*******************************************************
void course3()
{
cout<<endl<<"Started around more than two years back, the target extreme classroom";
cout<<" course(TxCC) is a two year rigorous program, where each center would";
cout<<" have a selective batch of 40 students.These students would be given";
cout<<"extensive training on IITJEE,to enable them to aim for top ranks inIITJEE.";
cout<<"\nDO YOU WANNA GIVE ADMISSION TEST (y/n):-";
char ch;
cin>>ch;
clrscr();
if(ch=='y'||ch=='Y')
{
cout<<"\nAdmission test on 19th october,2019(only for students who are in class ";
cout<<"class 11 and would be starting their 12 in 2020)";
cout<<endl<<"Enter your class(11/12)";
int x;
cin>>x;
if(x==11)
{
cout<<endl<<"you can register for admission test either online or can contact us";
cout<<endl<<"THANK YOU!!!";
}
else
{
cout<<endl<<"SORRY!!! we can't register for admission test";
cout<<endl<<"THANK YOU!!!";
}
}
else
{
cout<<"WANNA KNOW ABOUT ADMISSION TEST SELECT OPTION 8";
cout<<endl<<"THANK YOU!!!";
}
}
//*******************************************************
//  FUNCTION TO DISLAY THE INFORMATION ABOUT COURSE 4
//*******************************************************
void course4()
{
cout<<endl<<"IITJEE/MEDICAL classroom program is a three-year program for class";
cout<<"10 students.This program is designed for those who want to get an extra ";
cout<<"edge which would go a long way in their journey towards securing a top rank";
cout<<"\nDO YOU WANNA GIVE ADMISSION TEST(y/n) :-";
char ch;
cin>>ch;
clrscr();
if(ch=='y'||ch=='Y')
{
cout<<"\nAdmission test on 19th october,2019(only for students who are in class ";
cout<<"class 11 and would be starting their 12 in 2020)";
cout<<endl<<"Enter your class(11/12):";
int x;
cin>>x;
if(x==11)
{
cout<<endl<<"you can register for admission test either online or can contact us";
cout<<endl<<"THANK YOU!!!";
}
else
{
cout<<endl<<"SORRY!!! we can't register for admission test";
cout<<endl<<"THANK YOU!!!";
}
}
else
{
cout<<"WANNA KNOW ABOUT ADMISSION TEST SELECT OPTION 8";
cout<<endl<<"THANK YOU!!!";
}
}
//*******************************************************
//  FUNCTION TO DISLAY THE INFORMATION ABOUT COURSE 5
//*******************************************************
void course5()
{
char ch;
int y;
cout<<endl<<"The correspondence course of VMC are one of the most sought after";
cout<<"distance learning programs for JEE preparation.A major emphasis has been ";
cout<<"given to self study and the lesson have been designed to keep the fundamentals ";
cout<<"and approch simple and straight forward";
getch();
clrscr();
cout<<endl<<"*************************************************";
cout<<endl<<"\t\tCORRESPONDENCE COURSES";
cout<<endl<<"*************************************************";
cout<<endl<<"1.Premium correspondence-2year program:Rs 25000";
cout<<" (plus service tax and CESS)";
cout<<endl<<"1.Regular correspondence-2 year program:Rs 25000";
cout<<" (plus service tax and CESS)";
cout<<endl<<"DO YOU WANNA BUY";
cin>>ch;
if(ch=='y'||ch=='Y')
{
 cout<<endl<<"ENTER THE CLASS";
 cin>>y;
 if(y==9)
 cout<<"pay 4130/-";
 else if(y==10)
 cout<<"pay 9440/-";
 else if(y==11)
 cout<<"pay 11800/-";
 else if(y==12)
 cout<<"pay 17700/-";
 cout<<endl<<"THANKYOU!!!";
 }
else
cout<<"WANNA KNOW ABOUT THIS COURSE YOU CAN EITHER CONTACT US OR CHECK ONLINE";
}
//*******************************************************
//  FUNCTION TO DISLAY THE INFORMATION ABOUT COURSES
//*******************************************************
void courses()
{  int n;
char ch='y';
cout<<"\n**********************************************************************";
cout<<"\n\t-----------------DISPLAYING COURSES--------------------";
cout<<"\n**********************************************************************";
getch();
clrscr();
do
{
cout<<endl<<"1.MEDICAL COURSE";
cout<<endl<<"2.FOUNDERS CLASSROOM COURSE";
cout<<endl<<"3.TARGET EXTREME CLASSROOM";
cout<<endl<<"4.IITJEE/MEDICAL";
cout<<endl<<"5.CORRESPONDENCE COURSES";
cout<<endl<<"--------------------------------------------------------";
cout<<endl<<"ENTER THE COURSE YOU WANT TO OPT :-";
cin>>n;
getch();
clrscr();
switch(n)
{
case 1:
	  course1();
	  getch();
	  clrscr();
	  break;
case 2:
	  course2();
	  getch();
	  clrscr();
	  break;
case 3:
	  course3();
	  getch();
	  clrscr();
	  break;
case 4:
	  course4();
	  getch();
	  clrscr();
	  break;
case 5:
	  course5();
	  getch();
	  clrscr();
	  break;

}
cout<<endl<<"DO YOU WANNA KNOW MORE ABOUT ANY COURSE???";
cin>>ch;
}
while(ch=='y'||ch=='Y');
}
//*******************************************************
//     TO GET CONCESSION FOR WEAKER SECTION
//*******************************************************
void conc()
{
 cout<<"\n--------------------------------------------------";
 cout<<"\n\tCONCESSIONS";
 cout<<"\n--------------------------------------------------";
 cout<<"\n1)no concession for general";
 cout<<"\n2)25% for OBC";
 cout<<"\n3)50% for SC and ST";
 cout<<"\n4)10% if you have cleared scolarship test";
 cout<<"\nTO CALCULATE NET FEES YOU SHOULD OPT OPTION 9!!!";
 cout<<"\nTHANK YOU!!!";
}
//*******************************************************
//     TO CALCULATE NET FEES
//*******************************************************
void fees()
{
long int fees;
cout<<endl<<"--------------------------------------------";
cout<<endl<<"\t\tDISPLAYING COURSES";
cout<<endl<<"---------------------------------------------" ;
getch();
clrscr();

cout<<"1.MEDICAL COURSE";
cout<<endl<<"2.FOUNDER CLASSROOM COURSE";
cout<<endl<<"3.TARGET EXTREME COURSE";
cout<<endl<<"4.IITJEE";
cout<<endl<<"5.MEDICAL";
cout<<endl<<"6.CORRESPONDENCE COURSE";
cout<<endl<<"7.ANY OTHER COURSE";
cout<<endl<<"----------------------------------------------------";
int n;
char temp;
cout<<"\nWHICH COURSE DO YOU WANNA OPT(PER PACKAGE):";
cin>>n;
clrscr();
switch(n)
{
case 1:
	  cout<<endl<<"FEES :-  300000";
	  fees=300000;
	  break;
case 2:
	   cout<<endl<<"FEES :-  200000";
	  fees=200000;
	  break;
case 3:
	   cout<<endl<<"FEES :-  400000";
	  fees=100000;
	  break;
case 4:
	   cout<<endl<<"FEES :-  400000";
	  fees=400000;
	  break;
case 5:
	   cout<<endl<<"FEES :-  300000";
	  fees=300000;
	  break;
case 6:
	  cout<<"REFERRED IN OPTION 6";
	  fees=250000;
	  break;
case 7:
	  cout<<"FOR ANY OTHER COURSE YOU CAN CONTACT US";
	  cout<<"\nTHANK YOU!!!";
	  break;
}
getch();
clrscr();
float conc;
char cat[20];
cout<<endl<<"WHICH CATEGORY YOU BELONG TO(General,OBC,SC,ST)??:";
cin>>cat;
if(strcmp(cat,"General")==0)
{
conc=0;
cout<<endl<<"Do you have cleared scholarship test(y/n)??:";
cin>>temp;
if(temp=='y')
{
fees=fees-0.1*fees;
}
}
else if(strcmp(cat,"OBC")==0)
{
conc=0.25;
fees=fees-fees*conc;
cout<<endl<<"Do you have cleared sco;arship test(y/n)??:";
cin>>temp;
if(temp=='y')
{
fees=fees-0.1*fees;
}
}
else if(strcmp(cat,"SC")==0)
{
conc=0.50;
fees=fees-fees*conc;
cout<<endl<<"Do you have cleared scolarship test(y/n)??:";
cin>>temp;
if(temp=='y')
{
fees=fees-0.1*fees;
}
}
else if(strcmp(cat,"ST")==0)
{
conc=0.50;
fees=fees-fees*conc;
cout<<endl<<"Do you have cleared scolarship test(y/n)??:";
cin>>temp;
if(temp=='y')
{
fees=fees-0.1*fees;
}
}
cout<<endl<<"NET FEES :-"<<fees;
}
//*******************************************************
//            SCHOLARSHIP TEST1
//*******************************************************
void information()
{
 cout<<endl<<"IT IS ONLY APPLICABLE FOR STUDENTS WHO PASSED 11 AND JUST STARTED THEIR";
 cout<<endl<<"12.";
 cout<<endl<<"For more information login to our site or contact us.";
 cout<<endl<<"For filling the form of schlorship test visit our website and follow the";
 cout<<endl<<"properly.Any doubt regarding our test contact us";
 cout<<endl<<"______________________________________________________________________";
 }
 //*******************************************************
//            SCHOLARSHIP TEST2
//*******************************************************
void information1()
{
 cout<<endl<<"IT IS ONLY APPLICABLE FOR STUDENTS WHO PASSED 11 AND JUST STARTED THEIR";
 cout<<endl<<"12.";
 cout<<endl<<"For more information login to our site or contact us.";
 cout<<endl<<"For filling the form of schlorship test visit our website and follow the";
 cout<<endl<<"properly.Any doubt regarding our test contact us";
 cout<<endl<<"______________________________________________________________________";
 }
 //*******************************************************
//            SCHOLARSHIP TEST3
//*******************************************************
void information2()
{
 cout<<endl<<"IT IS ONLY APPLICABLE FOR STUDENTS WHO PASSED 11 AND JUST STARTED THEIR";
 cout<<endl<<"12.";
 cout<<endl<<"For more information login to our site or contact us.";
 cout<<endl<<"For filling the form of schlorship test visit our website and follow the";
 cout<<endl<<"properly.Any doubt regarding our test contact us";
 cout<<endl<<"______________________________________________________________________";
 }
//*******************************************************
//     TO KNOW MORE ABOUT SCHOLARSHIP TEST
//*******************************************************
void scholarship()
{
cout<<"\tDIFFERENT TEST YOU CAN GIVE";
cout<<endl<<".................................................";
cout<<endl<<"1.NATIONAL ADMISSIN TEST";
cout<<endl<<"2.NEET";
cout<<endl<<"3.JEE";
int ch;
char n,no,nn;
cout<<endl<<"ENTER THE SCHOLARSHIP TEST YOU WANT TO GIVE :-";
cin>>ch;
clrscr();
getch();
switch(ch)
{
case 1:cout<<endl<<"TEST WILL BE ON 19 OCTOBER 2019";
cout<<endl<<"DO U WANNA KNOW MORE..";
cin>>n;
if(n=='y'||n=='Y')
{
 information();
 }
 break;
 case 2:cout<<endl<<"TEST WILL BE ON 21 OCTOBER 2019";
cout<<endl<<"DO U WANNA KNOW MORE..";
cin>>no;
if(no=='y'||no=='Y')
{
 information1();
 }
 break;
case 3:cout<<endl<<"TEST WILL BE ON 23 OCTOBER 2019";
cout<<endl<<"DO U WANNA KNOW MORE..";
cin>>nn;
if(nn=='y'||nn=='Y')
{
 information2();
 }
 break;
 }
 }

//*******************************************************
//                MAIN FUNCTION
//*******************************************************
void main()
{
clrscr();
int n,i;
char choice,ch='y';
coaching s;
cout<<endl<<"\t - - - - - - - - - - - - - - - - - - - - - - - - ";
cout<<endl<<"\t\tWELCOME TO VMC INSTITUTE!!!!";
cout<<endl<<"\t - - - - - - - - - - - - - - - - - - - - - - - - ";
cout<<"\n\t-----------A RELIABLE AND TRUSTED NAME------------";
getch();
clrscr();
cout<<"\n\n  Press enter for further querries    ^_^ ";
getch();
clrscr();
cout<<"\n\t_______________________________________________________";
cout<<"\n\t\tSOME IMFORMATION ABOUT OUR INSTITUTE";
cout<<"\n\t_______________________________________________________";
cout<<"\nVidyamandir Classes(VMC) is synonymous with success in IIT-JEE";
cout<<"in Delhi/NCR. Our coaching institute is considered as one of the best";
cout<<"when it comes in best engineering coaching centers in Delhi.The centre";
cout<<"has over the years designed,delivered,perfected and innovated the art and";
cout<<"science of teaching and guiding students for the aim of our classes is";
cout<<"to provide knowledge and guidance and thereby create an environment";
cout<<"that guide students to the path of success.The centre is run by";
cout<<"a group of ex-IITians,who have over the years guided thousands of";
cout<<"IIT aspirants to fulfill their dream of getting admission in IITs.";
getch();
clrscr();
cout<<endl<<"Do you want to proceed (y or n):";
cin>>choice;
clrscr();
while (choice=='y'||choice=='Y')
{
cout<<endl<<".^.^.^.^.^.^.^.MAIN MENU.^.^.^.^.^.^.^.";
cout<<endl<<"1.To take admission in our institute";
cout<<endl<<"2.To see your information";
cout<<endl<<"3.To do any kind of modification";
cout<<endl<<"4.To search student record";
cout<<endl<<"5.To delete a student record";
cout<<endl<<"6.To display information about courses";
cout<<endl<<"7.Concession for the weaker section";
cout<<endl<<"8.To know about scholarship test";
cout<<endl<<"9.To calculate net fees";
cout<<endl<<"10.Exit";
cout<<endl<<"Enter your choice :-";
cin>>n;

clrscr();
switch(n)
{
case 1:
	append();
	getch();
	clrscr();
	break;
	case 2:
	displayall();
	getch();
	clrscr();
	break;
	case 3:
	modify();
	getch();
	clrscr();
	break;
	case 4:
	search();
	getch();
	clrscr();
	break;
	case 5:
	deletion();
	getch();
	clrscr();
	break;
	case 6:
	courses();
	getch();
	clrscr();
	break;
	case 7:
	conc();
	getch();
	clrscr();
	break;
	case 8:
	scholarship();
	getch();
	clrscr();
	break;
	case 9:
	fees();
	getch();
	clrscr();
	break;
	case 10:
	exit(0);
}
}
}