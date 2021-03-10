#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int n,p[10][2];
void drawpixel(void)
{
int i;
for(i=0;i<n;i++)
line(p[i][0],p[i][1],p[(i+1)%n][0],p[(i+1)%n][1]);
return;
}
void floodfilleight(int x,int y)
{
if(getpixel(x,y)!=WHITE)
{
putpixel(x,y,WHITE);
floodfilleight(x,y-1);
floodfilleight(x,y+1);
floodfilleight(x-1,y);
floodfilleight(x+1,y);
floodfilleight(x+1,y-1);
floodfilleight(x+1,y+1);;
floodfilleight(x-1,y-1);
floodfilleight(x-1,y+1);
}
return;
}
void drawaxis(void)
{
char r[25];
int i;
line(320,0,320,479);
outtextxy(590,230,"X-AXIS");
settextstyle(0,1,1);
outtextxy(330,5,"Y-AXIS");
line(0,240,639,240);
settextstyle(0,0,0);
for(i=240;i>-240;i-=20)
{
line(318,240-i,322,240-i);
itoa(i,r,10);
outtextxy(285,240-i,r);
}
for(i=-300;i<300;i+=20)
{
line(i+300,238,i+300,242);
itoa(i,r,10);
settextstyle(0,1,0);
outtextxy(i+320,243,r);
}
}
void main()
{
void drawaxis(void);
void drawpixel(void);
void floodfilleight(int,int);
int i,x,y,gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
cout<<"Enter the no. of point : ";
cin>>n;
cout<<"Enter the coordinate of "<<n<<"point";
for(i=0;i<n;i++)
cin>>p[i][0]>>p[i][1];
cout<<"\nEnter the interior point: ";
cin>>x>>y;
clrscr();
drawaxis();
for(i=0;i<n;i++)
{
p[i][0]=320+p[i][0];
p[i][1]=240-p[i][1];
}
x=320+x;
y=240-y;
drawpixel();
getch();
floodfilleight(x,y);
getch();
}