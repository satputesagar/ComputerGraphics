#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
void main()
{
int gd=DETECT,gm;
void drawaxis(void);//funct1
void drawcircle(int,int,int,int,int);//funct2
int x1,y1,r,x,y;
initgraph(&gd,&gm,"C:\TURBOC3\BGI");
cout<<"Enter the  value of Origin : ";
cin>>x>>y;
cout<<"Enter the value of Radius : ";
cin>>r;
cleardevice();
drawaxis();
drawcircle(x1,y1,r,x,y);
getch();
closegraph();
}

void drawaxis()
{
int i;
char s[25];
line(320,0,320,480);
line(0,240,640,240);
outtextxy(5,230,"X-AXIS ");
settextstyle(0,1,1);
outtextxy(336,6,"Y-AXIS");
settextstyle(0,0,1);
for(i=240;i>-240;i-=20)
{
outtextxy(318,237-1,"-");
if(i==0)
continue;
itoa(i,s,10);
outtextxy(286,240-i,s);
}
for(i=-300;i<300;i+=20)
{
itoa(i,s,10);
settextstyle(0,1,0);
outtextxy(i+300+5,236,"-");
outtextxy(i+325,245,s);
}
}
void drawcircle(int x1,int y1,int r,int x,int y)
{
int lim,d1,del,del2,z;
x1=0;
y1=r;
d1=2*(1-r);
lim=0;
while(y1>=lim)
{
putpixel(x1+x+320,240-y1-y,RED);
putpixel(x1+x+320,y1-y+240,RED);
putpixel(320-x1+x,240+y1-y,RED);
putpixel(320-x1+x,240-y1-y,RED);

if(d1<0)
{
del=(2*d1)+(2*y1)-1;
if(del<=0)
{
x1=x1+1;
d1=d1+(2*x1)+1;
}
else
{
x1=x1+1;
y1=y1-1;
d1=d1+(2*x1)-(2*y1)+2;
}
}
else if(d1>0)
{
del2=(2*d1)-(2*x1)-1;
if(del2<=0)
{
x1=x1+1;
y1=y1-1;
d1=d1+(2*x1)-(2*y1)+2;
}
else
{
y1=y1-1;
d1=d1-(2*y1)+1;
}
}
if(d1==0)
{
x1=x1+1;
y1=y1-1;
d1=d1+(2*x1)-(2*y1)+2;
}
}
}