#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

int dice()
{
   int die;
   die=1+rand()%6;
   return die;

}
void playerpos(int n,int p[],int x,int y)
{
 char str[100];
 for(int i=0;i<n;i++)
 {
    if(i==2)
    setcolor(MAGENTA);
    else
    setcolor(i+1);
    sprintf(str,"pos of p%d-%d ",i+1,p[i]);
    outtextxy(x*10+10,y+10+(i*10),str);
 }
 setcolor(WHITE);
}
void posupdate(int n, int p[],int x,int y)
{
 int i,j,k,l=1;
 for(i=9;i>=0;i--)
 {
	if(i%2!=0)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<n;k++)
			{
				if(p[k]==l)
				{
					if(k==2)
					setcolor(MAGENTA);
					else
					setcolor(k+1);
					for(int m=0;m<=5;m++)
					circle(j*x+25+k*3,i*y+20+k*3,m);

				}

			}
			l++;
		}
	}

	else
	{
		for(j=9;j>=0;j--)
		{
			for(k=0;k<n;k++)
			{
				if(p[k]==l)
				{
					if(k==2)
					setcolor(MAGENTA);
					else
					setcolor(k+1);
					for(int n=0;n<=5;n++)
					circle(j*x+25+k*3,i*y+20+k*3,n);
				}
			}
			l++;
		}
       }
 }
 setcolor(WHITE);
}
void sandl(int x,int y)
{
  //LADDERS
  setcolor(BROWN);
  for(int j=0;j<=10;j+=10)
  {
  line(0+20+j,y*9+10,x*2+20+j,y*6+30);

  line(x*3+20,y*9+10+j,x*6+20,y*8+20+j);

  line(x*7+20+j,y*9+10,x*9+20+j,y*7+30);

  line(20+j,y*7+10,x+20+j,y*5+30);

  line(x*7+20+j,y*7+10,x*4+20+j,y*2+30);

  line(x*9+20,y*5+15+j,x*6+20,y*3+20+j);

  line(x*9+20+j,y*2+10,x*8+20+j,30);

  line(20+j,y*2+10,x+20+j,30);

  }

  //SNAKES
  setcolor(YELLOW);

  for(int u=1;u<6;u++)
  {
   for(int i=-2;i<3;i++)
   {
   line(x*5+20,y*9+10,x*4+20+i,y*6+30);
   circle(x*4+20,y*6+30,u);

   line(x*9+20,y*9+10,x*8+20+i,y*6+30);
   circle(x*8+20,y*6+30,u);

   line(x*5+20,y*7+10,x*7+20+i,y*5+30);
   circle(x*7+20,y*5+30,u);

   line(x*2+20,y*8+10,x+20+i,y*3+30);
   circle(x+20,y*3+30,u);

   line(x*3+20,y*7+10,x*7+20+i,y+30);
   circle(x*7+20,y+30,u);

   line(x*4+20,y*4+10,x*5+20+i,30);
   circle(x*5+20,30,u);

   line(x*2+20,y*2+10,x*3+20+i,30);
   circle(x*3+20,30,u);
  }
  }

  setcolor(WHITE);
}

void board()
{

 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 int x=getmaxx()/12,y=getmaxy()/12;
 int k=1,f=0;
 char s[3];
 setcolor(WHITE);
 for(int i=0;i<=10;i++)
 {
	 line(x*i,0,x*i,getmaxy()-90);
	 line(0,y*i,getmaxx()-110,y*i);
 }
 for(i=9;i>=0;i--)
 {
	for(int j=0;j<10;j++)
	 {
		sprintf(s,"%d",k);
		outtextxy(x*j+5,y*i+5,s);
		if(f==0)
			k++;
		else
			k--;
	 }
	if(i%2!=0)
	 {
		 f=1;
		 k+=9 ;
	 }
	if(i%2==0)
	 {
		 f=0;
		 k+=11;
	}
 }
sandl(x,y);
}


void main()
{

 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 int p[10],n,a,z,cpos,f=0;
 int x=getmaxx()/12,y=getmaxy()/12;
 char str[100],str2[100];
 randomize();
 cout<<"\nenter no of players(2-4)=";
 cin>>n;
 for(a=0;a<n;a++)
 {
  p[a]=0;
 }
 a=0;
 cout<<"START!";
 delay(1000);
     while(1)
     {
       clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       if(f==0)
      {
       f=1;
       sprintf(str,"player %d , press a key to roll dice",a+1);
       outtextxy(x,y*10+10,str);
       getch();
      }
       z=dice();
       cpos=p[a];
       if(p[a]+z<=100)
       {        p[a]+=z;


	//ladders
	if(p[a]==1)
	      {
		clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"LADDER!");
       delay(1500);
	       p[a]=38;
	       }
	if(p[a]==4)
	     {
		clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"LADDER!");
       delay(1500);
	      p[a]=14;
		}
	if(p[a]==8)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"LADDER!");
       delay(1500);
	      p[a]=30;
	      }
	if(p[a]==21)
	     {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"LADDER!");
       delay(1500);
	      p[a]=42;

	      }
	if(p[a]==28)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"LADDER!");
       delay(1500);
	      p[a]=76;
	      }
	if(p[a]==50)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"LADDER!");
       delay(1500);
	      p[a]=67;
	      }
	if(p[a]==71)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"LADDER!");
       delay(1500);
	      p[a]=92;
	      }
	if(p[a]==80)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"LADDER!");
       delay(1500);
	      p[a]=99;
	     }

	//snakes
	if(p[a]==97)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"OOPS!! SNAKE");
       delay(1500);
	      p[a]=78;
	      }
	if(p[a]==95)
	      {clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"OOPS! SNAKE");
       delay(1500);
	      p[a]=56;
	      }
	if(p[a]==88)
	      {clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"OOPS! SNAKE");
       delay(1500);
	      p[a]=24;
	      }
	if(p[a]==32)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"OOPS! SNAKE");
       delay(1500);
	      p[a]=10;
	      }
	if(p[a]==62)
	      {clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"OOPS! SNAKE");
       delay(1500);
	      p[a]=18;
	      }
	if(p[a]==48)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"OOPS! SNAKE");
       delay(1500);
	      p[a]=26;
	      }
	if(p[a]==36)
	      {
	      clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       outtextxy(x,y*10+10,"OOPS! SNAKE");
       delay(1500);
	      p[a]=6;
	      }

	clrscr();
	closegraph();
	board();
	posupdate(n,p,x,y);
	playerpos(n,p,x,y);
	sprintf(str,"player %d rolled %d and moved from box-%d to box-%d",a+1,z,cpos,p[a]);
	sprintf(str2,"player %d press any key to roll dice",((a+1)%n)+1);
	outtextxy(x,y*10+10,str);
	outtextxy(x,y*10+20,str2);

	if(p[a]==100)
	      {
	       clrscr();
	       setcolor(BLUE);
	       cleardevice();
	       sprintf(str,"CONGRADULATIONS!!, Player %d is the Winner!! Press any key to exit",a+1);
	       outtextxy(x,y*5+10,str);
	       getch();
	       break;
	      }
       }
     else
     {
       clrscr();
       closegraph();
       board();
       posupdate(n,p,x,y);
       playerpos(n,p,x,y);
       sprintf(str,"Player %d rolled %d,Rolled value exceeds board, TRY AGAIN !",a+1,z);
       outtextxy(x,y*10+10,str);
     }
     getch();
     a=(a+1)%n;
     }
 closegraph();
}