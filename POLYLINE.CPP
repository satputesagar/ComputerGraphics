#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<conio.h>
void main()
{
int gd=DETECT,gm,i;
float n,x[10],y[10],z[10],midx,midy,x1[10],y1[10],x2[10],y2[10],xinc[10],yinc[10],length[10];
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
midx=getmaxx()/2;
midy=getmaxy()/2;
cout<<"How many line you have draw? ";
cin>>n;
for(i=1;i<=n;i++)
{
cout<<"Enter the value of x1,y1,x2,y2 for line"<<i<<":";
cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
}
clearviewport();
int j;
char s[25];
settextstyle(0,0,0);
line(0,midy,midx+midx,midy);
outtextxy(570,228,"X-AXIS");
settextstyle(0,0,0);
line(midx,0,midx,midy+midy);
outtextxy(332,6,"Y-AXIS");
settextstyle(0,0,0);
for(j=240;j>-240;j-=20)
{
outtextxy(318,237-1,"-");
if(j==0)
continue;
itoa(j,s,10);
outtextxy(286,240-j,s);
}
for(j=-300;j<300;j+=20)
{
outtextxy(j+300+5,236,"-");
if(j==0)
continue;
itoa(j,s,10);
settextstyle(0,1,0);
outtextxy(j+325,245,s);
}
for(i=1;i<=n;i++)
{
if(abs(x2[i]-x1[i])>=abs(y2[i]-y1[i]))
{
length[i]=abs(x2[i]-x1[i]);
}
else
{
length[i]=abs(y2[i]-y1[i]);
}
xinc[i]=(x2[i]-x1[i])/length[i];
yinc[i]=(y2[i]-y1[i])/length[i];
x[i]=x1[i]+0.5;
y[i]=x1[i]+0.5;
int k=1;
while(k<=length[i])
{
putpixel(x[i]+midx,z[i]+midy,GREEN);
x[i]+=xinc[i];
y[i]+=yinc[i];
z[i]=-y[i];
k++;
}
}

getch();
closegraph();
}