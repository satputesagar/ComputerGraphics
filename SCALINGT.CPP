#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
void main()
{
int gd=DETECT,gm;
void drawaxis(void);
void polygon(int,int,int);
void dda(int,int,int,int);
void scale(void);
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
scale();
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
for(i=240;i>-240;i-=20)
{
outtextxy(318,237-i,"-");
if(i==0)
continue;
itoa(i,s,10);
outtextxy(286,240 -i,s);
}
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
float x,y,incry,incrx;
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
void scale(void)
{
int ax[15],ay[15],n;
float sx,sy,h[3][2];
int tx[15]={0},ty[15]={0},temp,i,j;
cout<<"Enter the size of polygon => ";
cin>>n;
if(n<3)
{
cout<<"Invalid side error\n";
closegraph();
exit(1);
}
cout<<"Enter the co-ordinate of polygon \n";
for(i=0;i<n;i++)
{
cout<<"Enter for side"<<i+1<<"\n";
cin>>ax[i]>>ay[i];
}
cout<<"Enter the value for sx and sy =>";
cin>>sx>>sy;
cleardevice();
drawaxis();
polygon(ax,ay,n);
for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
{
if(i==j)
h[i][j]=1;
else
h[i][j]=0;
}
}
for(i=0;i<3;i++)
{
h[i][0]=h[i][0]*sx;
h[i][1]=h[i][1]*sy;
}
for(i=0;i<n;i++)
{
temp=ax[i]*h[0][0]+ay[i]*h[1][0]+h[2][0];
ty[i]=(int)(ax[i]*h[0][1]+ay[i]*h[1][1]+h[2][1]);
tx[i]=(int)temp;
}
getch();
cleardevice();
drawaxis();
polygon(tx,ty,n);
}