 #include<iostream>             
 #include<stdio.h>
 #include<conio.h>
 #include<fstream>
 #include<string.h>
 #include<process.h>
#include<stdlib.h>      
#include<dir.h>        
#include<dos.h> 
using namespace std;      
 int count=1;
 class player
 {
 public:
    int match,cat;
    char fname[30],lname[30],con[30],file[30],filebat[30],filebowl[30];
 int age;
    void in()
    {
    cout<<"Enter whether the Player is a \n\n1.BATSMAN \n\n 2.BOWLER \n\n  3.ALL ROUNDER\n";
 cin>>cat;
    cout<<"Enter the file name for PLAYER profile\n"<<endl;
    cin>>file;
    fstream f1(file,ios::out);

    cout<<"\n\nEnter the players first name:";
    cin>>fname;
	cout<<"\n\nEnter the players last name:";
    cin>>lname;
    cout<<"\n\nEnter the age of the players:";
    cin>>age;
    cout<<"\n\nEnter the number of matches he played:";
    cin>>match;
    cout<<"\n\nEnter Country of the player:";
    cin>>con;

    f1<<"The name of the player is:"<<fname<<"  "<<lname<<endl;
    f1<<"\nThe age of the player :"<<age<<endl;
    f1<<"\nThe number of matches played"<< match<<endl;
    f1<<"\nThe country of the player is:"<<con<<endl;
    f1<<endl<<endl;
    f1.close();

    }
    int out1();

    player()
    {
    age=0;
    }

  };
  int player :: out1()
  {
   fstream a;
   int i=0,j;
	 char p;

	 a.open(file,ios::in);
	 if(!a)
	   {
	    cout<<"file error";
	    return 0;
	   }

	 cout<<"\n\nTHE PLAYER INFO :\n\n\n" ;
	 while(a)
	     {  if(i==660)
	       {
	     i=0;
	     getch();

	    }

	      a.get(p);
	      cout<<p;
	      i++;
	     }

  a.close();
  return 0;
  }
  class batsman:public virtual player
  {
  protected:
	int run,out,cen,halfcen;
	float avg,srbat;
  public:
    void openbat();
    int showbat();
  };

  void batsman :: openbat()
  {
  fstream f2;
  cout<<"Enter the file name for BATSMAN\n"<<endl;
  cin>>filebat;
  f2.open(filebat,ios::out);


  cout<<"\n\nEnter total runs of his career:";
  cin>>run;
  cout<<"\n\nhow many centuries he has:";
  cin>>cen;
  cout<<"\n\nHow many half centuries he has:";
  cin>>halfcen;
  cout<<"\n\nHow many times he got out?:";
  cin>>out;
  cout<<"\n\nEnter Strike Rate";
  cin>>srbat;
  avg=(float)run/out;

  f2<<"The number of runs hit"<<run<<endl;
  f2<<"\nThe number of centuries hit:"<<cen<<endl;
  f2<<"\nThe number of halcenturies hit:"<<halfcen<<endl;
  f2<<"\nThe number of times he got out:"<<out<<endl;
  f2<<"\nThe average of the batsman:"<<avg<<endl<<endl<<endl;
  f2<<"\nThe Strike Rate of the batsman:"<<srbat<<endl<<endl<<endl;
  f2.close();

  }


  int batsman :: showbat()
	{
	int i=0,j;
	 char p;
	 fstream u;
       u.open(filebat,ios::in);
	 if(!u)
	   {
	    cout<<"file error";
	    return 0;
	   }

	 cout<<"\n\nTHE BASTMAN INFO:\n\n\n" ;
	 while(u)
	     {  if(i==660)
	       {
	     i=0;
	     getch();

	    }

	      u.get(p);
	      cout<<p;
	      i++;
	     }
	  u.close();
	 getch();
	  return 0;
		}


  class bowler:virtual public player
  {
  protected:
	int wic,half,brun,ovr;
	float ecn,bavg,srbowl;

  public:
    void openbowl();
    int  showbowl();
  };

 void bowler :: openbowl()
 {
  fstream f3;
  cout<<"Enter the file name for BOWLER\n"<<endl;
  cin>>filebowl;
  f3.open(filebowl,ios::out);


  cout<<"\n\nEnter the number of wicket he got:";
  cin>>wic;
  cout<<"\n\nEnter the number of runs he gave:";
  cin>>brun;
  cout<<"\n\nHow many times he got 5 wickets:";
  cin>>half;
  bavg=(float)brun/wic;
  cout<<"\n\nHow many overs he bowld:";
  cin>>ovr;
  ecn=(float)brun/ovr;
  srbowl=(float)ovr*6/wic;
  f3<<"The number of wickets taken:"<<wic<<endl;
  f3<<"\nThe number of runs given:"<<brun<<endl;
  f3<<"\nThe number times he got 5 wickets:"<<half<<endl;
  f3<<"\nThe number of overs bowled:"<<ovr<<endl;
  f3<<"\nThe economy of the bowler is:"<<ecn<<endl<<endl<<endl;
   f3<<"\nThe Strike Rate of the bowler is:"<<srbowl<<endl<<endl<<endl;
  f3.close();

 }

 int bowler :: showbowl()
	{
	int i=0,j;
	 char p;
	 fstream c;

       c.open(filebowl,ios::in);
	 if(!c)
	   {
	    cout<<"file error";
	    return 0;
	   }

	 cout<<"\n\nTHE BOWLER INFO:\n\n\n" ;
	 while(c)
	     {  if(i==660)
	       {
	     i=0;
	     getch();

	    }

	      c.get(p);
	      cout<<p;
	      i++;
	     }
	  c.close();
	 getch();
	  return 0;
		}

 class general : public  batsman,  public bowler
 {
 protected:
       int runs,outs,cens,halfcens,wics,halfs,bruns,ovrs;
 public:
     void openprof();
     void editbat();
     void editbowl();
     int searchbat(int a,int b);
     int searchbowl(int a,int b);
	 int searchall(int a,int b,int c,int d);
     void show();
     void topbat();
     int topsbat();
     int topsbowl();
     void topbowl();
     float batval();
     float bowlval();
     void batrank();
     void bowlrank();
     int allval();
     void allrank();
 };

 void general :: openprof()
 {
 in();
 if(cat==1)
 openbat();
 else if(cat==2)
 openbowl();
 else if(cat==3)
 {
     openbat();
     openbowl();

 }
 else
 {
 cout<<"enter valid choice";
 }
 }

 void general :: show()
 {
 out1();
 if(cat==1)
 showbat();
 else if(cat==2)
 showbowl();
 else
 {
  showbat();
  showbowl();
 }
 }

 void general :: editbat()
 {
 fstream f7;
 // cout<<"Enter the file name for BATSMAN\n"<<endl;
 // cin>>filebat;
  f7.open(filebat,ios::out);


 cout<<"\n\nRuns to add:";
 cin>>runs;
 run=run+runs;
 cout<<"\n\nOuts to add:";
 cin>>outs;
 out=out+outs;
 cout<<"\n\nCenturies to add:";
 cin>>cens;
 cen=cen+cens;
 cout<<"\n\nHalf centuries to add:";
 cin>>halfcens;
 halfcen=halfcen+halfcens;
  avg=(float)run/out;
  cout<<"\nEnter Strike Rate\n";
  cin>>srbat;

  f7<<"The number of runs hit"<<run<<endl;
  f7<<"\nThe number of centuries hit:"<<cen<<endl;
  f7<<"\nThe number of halcenturies hit:"<<halfcen<<endl;
  f7<<"\nThe number of times he got out:"<<out<<endl;
  f7<<"\nThe average of the batsman:"<<avg<<endl<<endl<<endl;
   f7<<"\nThe Strike Rate of the batsman:"<<srbat<<endl<<endl<<endl;
  f7.close();
 }

 void general :: editbowl()
 {
  fstream f9;
  //cout<<"Enter the file name for BOWLER\n"<<endl;
  //cin>>filebowl;
  f9.open(filebowl,ios::out|ios::trunc);

 cout<<"\n\nWickets to add:";
 cin>>wics;
 wic=wic+wics;
 cout<<"\n\ntimes of getting 5 wickets to add:";
 cin>>halfs;
 half=half+halfs;
 cout<<"\n\nGiving runs to add:";
 cin>>bruns;
 brun=bruns+brun;
 cout<<"\n\novers to add:";
 cin>>ovrs;
 ovr=ovr+ovrs;
ecn=(float)brun/ovr;
srbowl=(float)ovr*6/wic;

  f9<<"The number of wickets taken:"<<wic<<endl;
  f9<<"\nThe number of runs given:"<<brun<<endl;
  f9<<"\nThe number times he got 5 wickets:"<<half<<endl;
  f9<<"\nThe number of overs bowled:"<<ovr<<endl;
  f9<<"\nThe economy of the bowler is:"<<ecn<<endl<<endl<<endl;
  f9<<"\nThe Strike Rate of bowler is:"<<srbowl<<endl<<endl;
  f9.close();
 }
 int general :: searchbat(int a,int b)
 {			


 if(avg>a && b<match)
{
   //cout<<endl<<fname<<" "<<lname;
   return 1;
   
   
}


  return 0;
 }

 int general :: searchbowl(int a,int b)
 {



 if(srbowl<a && b<match)
 {
	 //cout<<endl<<fname<<" "<<lname;
	 return 1;
 }
 return 0;
 }

		int general :: searchall(int a,int b,int c,int d)
 {



 if(a<bavg && b<match && c>srbowl && d<ovr)
 {
	 //cout<<endl<<fname<<" "<<lname;
	 return 1;
 }
 return 0;
 }
 
void general::topbat()
 {
     cout<<"\n"<<fname<<" "<<lname<<"\t"<<run;
 }

 int general::topsbat()
 {
 return run;
 }
 void general::topbowl()
 {
     cout<<"\n"<<fname<<" "<<lname<<"\t"<<wic;
 }

 int general::topsbowl()
 {
 return wic;
 }
  float general::batval()
 {
 return srbat*avg*run/100000;
 }
  float general::bowlval()
 {
 return wic/(srbowl*ecn);
 }
  int general::allval()
 {
 return (run+wic*5);
 }
 void general::batrank()
 {
     cout<<"\n"<<fname<<" "<<lname<<"\t"<<run<<"\t"<<avg<<"\t\t"<<srbat;;
 }
 void general::bowlrank()
 {
     cout<<"\n"<<fname<<" "<<lname<<"\t"<<wic<<"\t"<<ecn<<"\t"<<srbowl;
 }
      void general::allrank()
 {
     cout<<"\n"<<fname<<" "<<lname<<"\t"<<run<<"\t"<<wic;
 }

 int main ()
 {
  int bam,dam,kim,rof,kla,bog,net,no,code_arr[100],f,k,i,tam,j,ch,chl,ch2,mavg,mmatch,mage,mbavg,mbmatch,mecn,mage1,r,temp,h;
 //static int no;
 struct arr
 {
 int val,pos;
 };
 struct arr *p=(struct arr *)calloc(100,(sizeof(struct arr)));


 char nam[20],ctry[30],nam1[30];


 cout<<"\n\n\nWELCOME TO  PLAYER MANAGEMENT  SOFT.."<<endl;



 general ge[100];


 t:for (i=0;  ;i++)
 {
 cout<<"\n\n\nWhat do you want to do?"<<endl<<"\n1.Add profile"<<"\n2.Edit Profile";

 cout<<"\n3.To show"<<"\n4.Search"<<"\n5.Search By Country"<<"\n6.All Time Records"<<"\n7.Player Form rankings"<<"\n8.Exit"<<endl;
 cin>>ch;



 switch(ch)
 {

 case 1:


    for(j=0;j<100;j++)
    {
    if(ge[j].age==0)
    {
    ge[j].openprof();
    break;
    }
    }

    break;

 case 2:
    cout<<"\n\nEnter first name:";
    cin>>nam;

    for(j=0;j<100  ;j++)
    {
    if(strcmp(ge[j].fname,nam)==0)
    {
    cout<<"\n\n PLEASE EDIT THE PLAYERS PROFILE";
    if(ge[j].cat==1)
    {
    ge[j].editbat();
    break;
    }
    if(ge[j].cat==2)
    {
    ge[j].editbowl();
    break;
    }
    else if(ge[j].cat==3)
    {
	ge[j].editbat();
	ge[j].editbowl();
	break;
    }
    }
    }
    break;
 case 3:
    {
    cout<<"\n\nEnter first name:";
    cin>>nam;
    cout<<"\nEnter last name:";
    cin>>nam1;
    dam=0;
    for(j=0;j<100;j++)
    {
    if(strcmp(ge[j].lname,nam1)==0)
    {
    if(strcmp(ge[j].fname,nam)==0)
    {
    dam=1;
    ge[j].show();
    }
    }
    }
    if(dam==0)
    {
    cout<<"\n"<<nam<<" "<<nam1<<" does not exist in records";
    }
    break;
     }
 case 4:
    {
		kane:  cout<<"\n1.Batsman\t2.Bowler\t3.All-Rounder\n";
		kla=0;
		cin>>rof;
		if(rof==0||rof>3)
		{
			cout<<"\nPlease Enter a Valid Option\n";
			goto kane;
		}

	else if(rof==1)
    {
   cout<<"\nBatting Performance:";

    cout<<"\n\nFix the minimum average:";
    cin>>mavg;
     cout<<"\n\nFix his minimum match playing:";
    cin>>mmatch;
 dan:     kla=0;
 for(j=0;j<100;j++)
     {
		 if(ge[j].cat==1)
		 {
			 
		 
	 bog=ge[j].searchbat(mavg,mmatch);
	  if(bog==1)
	  {
			cout<<"\n"<<ge[j].fname<<" "<<ge[j].lname<<"\t"<<"code- "<<j;
		  code_arr[kla]=j;
		  kla++;

	  }
	 }
	 }
      if(kla>0)
	  {
		  cout<<endl<<"enter player code"<<endl;
	   cin>>net;
	   cout<<endl;
	   tam=0;
	   for(no=0;no<kla;no++)
	   {

	   if(net==code_arr[no])
	   {
	   tam=1;
	   ge[net].show();
	   break;

	   }
	   }
	   if(tam==0)
	   {
	   cout<<"\nPlease enter a valid code\n";

	   }
	   cout<<endl<<endl<<"press 1 to go to main menu"<<endl<<"press 2 to search result ";
	   cout<<endl;
	   cin>>f;
	   if(f==1)
	   goto t;
	   else if(f==2)
	   goto dan;
	   }
	   else
	   cout<<"\nNo player satisfies the given criteria";
	   break;
     }
	 else if(rof==2)
	 {
		cout<<"\nBowling Performance:";

    cout<<"\n\nFix the maximum bowling strike rate:";
    cin>>mbavg;
    cout<<"\n\nFix the minimum match played:";
    cin>>mbmatch;
    mar: kla=0;
	for(j=0;j<100;j++)
     {
		 if(ge[j].cat==2)
		 {
			 
		 
	bog=ge[j].searchbowl(mbavg,mbmatch);
	if(bog==1)
	{
		cout<<"\n"<<ge[j].fname<<" "<<ge[j].lname<<"\t"<<"code- "<<j;
		  code_arr[kla]=j;
		  kla++;
	}
	    }
	 }
		if(kla>0)
	  {
		  cout<<endl<<"enter player code"<<endl;
	   cin>>net;
	   cout<<endl;
	   tam=0;
	   for(no=0;no<kla;no++)
	   {

	   if(net==code_arr[no])
	   {
	   tam=1;
	   ge[net].show();
	   break;

	   }
	   }
	   if(tam==0)
	   {
	   cout<<"\nPlease enter a valid code\n";
	   }
	   cout<<endl<<endl<<"press 1 to go to main menu"<<endl<<"press 2 search result";
	   cout<<endl;
	   cin>>f;
	   if(f==1)
	   goto t;
	   else if(f==2)
	   goto mar;
	   }
	   else
	   cout<<"\nNo player belongs to"<<ctry;
	   break;
     }
	 else if(r==3)
	 {
		cout<<"\nBatting Performance:";
	 cout<<"\n\nFix the minimum average:";
    cin>>mavg;
     cout<<"\n\nFix his minimum matches played:";
    cin>>mmatch;
    cout<<"\nBowling Performance:";
    cout<<"\n\nFix the maximum bowling strike rate:";
    cin>>mbavg;
    cout<<"\n\nFix the minimum overs bowled:";
    cin>>mbmatch;
    rol: kla=0;
	for(j=0;j<100;j++)
     {
      bog=ge[j].searchall(mavg,mmatch,mbavg,mbmatch);
      if(bog==1)
	  {
		cout<<"\n"<<ge[j].fname<<" "<<ge[j].lname<<"\t"<<"code- "<<j;
		  code_arr[kla]=j;
		  kla++;
	  }

       }
	   if(kla>0)
	  {
		  cout<<endl<<"enter player code"<<endl;
	   cin>>net;
	   cout<<endl;
	   tam=0;
	   for(no=0;no<kla;no++)
	   {

	   if(net==code_arr[no])
	   {
	   tam=1;
	   ge[net].show();
	   break;

	   }
	   }
	   if(tam==0)
	   {
	   cout<<"\nPlease enter a valid code\n";
	   }
	   cout<<endl<<endl<<"press 1 to go to main menu"<<endl<<"press 2 to search results";
	   cout<<endl;
	   cin>>f;
	   if(f==1)
	   goto t;
	   else if(f==2)
	   goto rol;
	   }
	   else
	   cout<<"\nNo player belongs to"<<ctry;
	   break;

	 }
	}
    /*
     }
     if(ge[j].cat==2)
     {
    cout<<"\nBowling Performance:";
	{
    cout<<"\n\nFix the maximum bowling average:";
    cin>>mbavg;
    cout<<"\n\nFix the minimum match played:";
    cin>>mbmatch;
     for(j=0;j<100;j++)
     {
	ge[j].searchbowl(mbavg,mbmatch);
	 if(count==1)
      {
	  break;
      }
     }

    }

    break;
     }

      if(ge[j].cat==3)
      {
	 cout<<"\nBatting Performance:";
	 cout<<"\n\nFix the minimum average:";
    cin>>mavg;
     cout<<"\n\nFix his minimum match playing:";
    cin>>mmatch;
    cout<<"\nBowling Performance:";
    cout<<"\n\nFix the maximum bowling average:";
    cin>>mbavg;
    cout<<"\n\nFix the minimum match played:";
    cin>>mbmatch;
     for(j=0;j<100;j++)
     {
      ge[j].searchbat(mavg,mmatch);
      ge[j].searchbowl(mbavg,mbmatch);
      if(count==1)
      {
	  break;
      }
     }
      break;
 }
    }*/

case 8:cout<<"THANK YOU FOR USING THIS SOFT..."<<endl;
       cout<<"CREDIdTS:";
       cout<<"A.S KARTHIKK"<<endl;
       cout<<"\tK.V ABHISHEK"<<endl;
       cout<<"\tAJIT R"<<endl;
       cout<<"\tABHISHEK M.P"<<endl;
	   getch();
      exit(0);
  case 5:
	  cout<<"enter country\n";
	  cin>>ctry;
	q:  r=0;
	 for(k=0;k<100;k++)
	  {
	   if(strcmp(ge[k].con,ctry)==0)
	   {
	   cout<<ge[k].fname<<" "<<ge[k].lname<<"      code - "<<k<<endl;
	   code_arr[r]=k;
	   r++;
	     }

	  }
	 rep: if(r>0)
	  {
	   cout<<endl<<"enter player code"<<endl;
	   cin>>h;
	   cout<<endl;
	   tam=0;
	   for(no=0;no<r;no++)
	   {

	   if(h==code_arr[no])
	   {
	   tam=1;
	   ge[h].show();
	   break;

	   }
	   }
	   if(tam==0)
	   {
	   cout<<"\nPlease enter a valid code\n";
	   goto rep;
	   }
	  pal: cout<<endl<<endl<<"press 1 to go to main menu"<<endl<<"press 2 to country player";
	   cout<<endl;
	   cin>>f;
	   if(f==1)
	   goto t;
	   else if(f==2)
	   goto q;
       else
   {
	   cout<<"\nEnter valid choice\n";
	   goto pal; 
   }
	   }
	   else
	   cout<<"\nNo player belongs to"<<ctry;
	   break;

    case 6://cout<<"7.All time records\n";
	      jim:	cout<<"\n1.Top Run getters  \n2.Top Wicket takers \n";
		cin>>bam;
		if(bam==0||bam>=3)
		{
		cout<<"\nEnter Valid Choice\n";
		goto jim;
		}

		cout<<"\n\nHow many records do you require\n\n";
		cin>>kim;
		i=0;j=0;
		if(bam==1)
		{
		while(ge[i].age)
		{
		if(ge[i].cat==1)
		{
		p[j].val=ge[i].topsbat();
		p[j].pos=i;
		j++;
		}
		i++;
		}


		for(i=0;i<j;i++)
		{
		for(k=i+1;k<j+1;k++)
		{
		    if(p[k].val>p[i].val)
		    {
		    temp=p[i].val;
		    p[i].val=p[k].val;
		    p[k].val=temp;
		    temp=p[i].pos;
		    p[i].pos=p[k].pos;
		    p[k].pos=temp;
		    }
		}
		 }
		 if(kim<=j)
		 {
		 cout<<"\nName\t\tRuns";
		 for(i=0;i<kim;i++)
		 {
		    temp=p[i].pos;
			ge[temp].topbat();
		  }
		 }
		 else
		{
		if(j==0)
		{
		cout<<"\nNo batsman records exist\n";
		}
		else
		{
		 cout<<"\n\n Only"<<j<<" records exist";
		 }
		 }
		 }

		 else if(bam==2)
		 {
			while(ge[i].age)
		{
		if(ge[i].cat==2)
		{
		p[j].val=ge[i].topsbowl();
		p[j].pos=i;
		j++;
		}
		i++;
		}


		for(i=0;i<j;i++)
		{
		for(k=i+1;k<j;k++)
		{
		    if(p[k].val>p[i].val)
		    {
		    temp=p[i].val;
		    p[i].val=p[k].val;
		    p[k].val=temp;
		    temp=p[i].pos;
		    p[i].pos=p[k].pos;
		    p[k].pos=temp;
		    }
		}
		 }
		 if(kim<=j)
		 {
		 cout<<"\nName\t\tWickets\n";
		 for(i=0;i<kim;i++)
		 {
		    temp=p[i].pos;
			ge[temp].topbowl();
		  }
		 }
		 else
		{
		  if(j==0)
		  {
		  cout<<"\nNo Bowler Record Exists\n";
		  }
		  else
		  {
		 cout<<"\n\n Only"<<j<<"records exist";
		 }
		 }
		 }
		 else
		 {
		 cout<<"\n\nPlease Enter a Valid Choice";
		 goto jim;
		 }


	     break;


	   case 7:
	  tim: cout<<"\n\n1.Batsman Ranking\n2.Bowler Ranking\n3.All Rounder Ranking\n";
	   cin>>bam;
	   if(bam==0||bam>3)
		{
		cout<<"\nEnter valid choice\n";
		goto tim;
		}
		
		cout<<"\n\nHow many records do you require\n\n";
		cin>>kim;
		i=0;j=0;

		if(bam==1)
		{
		while(ge[i].age)
		{
		if(ge[i].cat==1)
		{
		p[j].val=ge[i].batval();
		p[j].pos=i;
		j++;
		}
		i++;
		}


		for(i=0;i<j;i++)
		{
		for(k=i+1;k<j;k++)
		{
		    if(p[k].val>p[i].val)
		    {
		    temp=p[i].val;
		    p[i].val=p[k].val;
		    p[k].val=temp;
		    temp=p[i].pos;
		    p[i].pos=p[k].pos;
		    p[k].pos=temp;
		    }
		}
		 }
		 if(kim<=j)
		 {
		 cout<<"  name\t\trun\taverage\t\tstrike rate";
		 for(i=0;i<kim;i++)
		 {
		    temp=p[i].pos;
			ge[temp].batrank();
		  }
		 }
		 else
		{
		if(j==0)
		{
		cout<<"\nNo Batsman Record Exists\n";
		}
		else
		 {
		 cout<<"\n\n Only"<<j<<" records exist";
		 }
		 }
		 }

		 else if(bam==2)
		 {
			while(ge[i].age)
		{
		if(ge[i].cat==2)
		{
		p[j].val=ge[i].bowlval();
		p[j].pos=i;
		j++;
		}
		i++;
		}


		for(i=0;i<j;i++)
		{
		for(k=i+1;k<j;k++)
		{
		    if(p[k].val>p[i].val)
		    {
		    temp=p[i].val;
		    p[i].val=p[k].val;
		    p[k].val=temp;
		    temp=p[i].pos;
		    p[i].pos=p[k].pos;
		    p[k].pos=temp;
		    }
		}
		 }
		 if(kim<=j)
		 {
		 cout<<"\n  Name\t\tWickets\tEconomy\tStrike Rate\n";
		 for(i=0;i<kim;i++)
		 {
		    temp=p[i].pos;
			ge[temp].bowlrank();
		  }
		 }

		 else
		{
			if(j==0)
		{
		cout<<"\nNo Batsman Record Exists\n";
		}
		else
		 {
		 cout<<"\n\n Only"<<j<<" records exist";
		 }
		 }
		 }
		 else if(bam==3)
		  {
			while(ge[i].age)
		{
		if(ge[i].cat==3)
		{
		p[j].val=ge[i].allval();
		p[j].pos=i;
		j++;
		}
		i++;
		}


		for(i=0;i<j;i++)
		{
		for(k=i+1;k<j;k++)
		{
		    if(p[k].val>p[i].val)
		    {
		    temp=p[i].val;
		    p[i].val=p[k].val;
		    p[k].val=temp;
		    temp=p[i].pos;
		    p[i].pos=p[k].pos;
		    p[k].pos=temp;
		    }
		}
		 }
		 if(kim<=j)
		 {
		 cout<<"\nName\t\tRuns\tWickets\n";
		 for(i=0;i<kim;i++)
		 {
		    temp=p[i].pos;
			ge[temp].allrank();
		  }
		 }
		 else
		{
			if(j==0)
		{
		cout<<"\nNo All-Rounder Record Exists\n";
		}
		else
		 {
		 cout<<"\n\n Only"<<j<<" records exist";
		 }
		 }
		 }

		 else
		 {
		 cout<<"\n\nPlease Enter a Valid Choice";
		 goto tim;

		 }
		 break;
}
 }
p:return 0;
}
