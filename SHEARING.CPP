#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
void main()
{
clrscr();
int gd=DETECT,gm;
void drawaxis(void);
void polygon(int,int,int);
void dda(int,int,int,int);
void yshear(void);
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
yshear();
getch();
closegraph();
}
void drawaxis()
{
int i;
char s[25];
line(320,0,320,480);

outtextxy(5,230,"X-AXIS");
settextstyle(0,1,1);
outtextxy(336,6,"Y-AXIS");
line(0,240,640,240);
settextstyle(0,0,0);
for(i=-300;i<300;i+=20)
{

itoa(i,s,10);
settextstyle(0,1,0);
outtextxy(i+325,245,s);
outtextxy(i+300+5,236,"-");
}
}
void dda(int x1,int y1,int x2,int y2)
{
int k,dx,dy,steps;
float x,y,incrx,incry;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
steps=abs(dx);
else
steps=abs(dy);
incrx=(float)dx/steps;
incry=(float)dy/steps;
x=x1;
y=y1;
putpixel(320+x,240-y,WHITE);
for(k=0;k<steps;k++)
{
x+=incrx;
y+=incry;
putpixel(320+x,240-y,WHITE);
}
}
void polygon(int cx[],int cy[],int n)
{
int i;
for(i=0;i<n-1;i++)
dda(cx[i],cy[i],cx[i+1],cy[i+1]);
dda(cx[n-1],cy[n-1],cx[0],cy[0]);
}
void yshear(void)
{
int ax[15],ay[15],n;
float a,h[2][2];
int tx[15]={0},ty[15]={0},temp,i,j;
cout<<"Enter The Size of Polygon  = ";
cin>>n;
if(n<3)
{
cout<<"Invalid Side Error ";
closegraph();
exit(1);
}
cout<<"Enter the Co-Ordinates of Polygon \n";
for(i=0;i<n;i++)
{
cout<<"Enter for Side "<<i+1<<"\n";
cin>>ax[i]>>ay[i];
}
cout<<"Enter the value for a (yshear ) =";
cin>>a;
cleardevice();
drawaxis();
polygon(ax,ay,n);
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
if(i==j)
h[i][j]=1;
else
h[i][j]=0;
}
}
h[0][1]=h[0][1]+a;
for(i=0;i<n;i++)
{
temp=ax[i]*h[0][0]+ay[i]*h[1][0];
ty[i]=(int)(ax[i]*h[0][1]+ay[i]*h[1][1]);
tx[i]=(int)temp;
}
getch();
cleardevice();
drawaxis();
polygon(tx,ty,n);
}