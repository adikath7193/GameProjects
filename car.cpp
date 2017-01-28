#include <graphics.h>

using namespace std;

int maxx,maxy,x1,x2,x3,x4,x1a,x2a,x3a,x4a,lane,gap,div_len,lane_dis,up_mar,menu_len,side_road,l_wid;
void Initialize()
{
 initwindow(1780,780,"car_game",0,0,false);
}
void car()
{
    if(lane==1)readimagefile("carr.jpeg",up_mar,135,282,235);
    else if(lane==2)readimagefile("carr.jpeg",up_mar,365,282,465);
    else readimagefile("carr.jpeg",up_mar,595,282,695);
}
void display(int x,int y, char text[],int size=1,int box=BLUE,int txt=WHITE)
{
    setbkcolor(box);
    setcolor(txt);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,size);
    outtextxy(x,y,text);
    setbkcolor(BLACK);
}
void upper_boundary()
{
    setfillstyle(SOLID_FILL, BLUE);
    bar(0, 0, getmaxx(), 50);
}
void menu()
{
    display(5,5,"Score : ");
    display(170,5,"Pause : P");
    display(340,5,"Restart : R");
    display(510,5,"Quit : Q");
}
void road_bound()
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,50,getmaxx(),up_mar);
    bar(0,getmaxy()-30,getmaxx(),getmaxy());
}
void remove_car()
{
    setfillstyle(SOLID_FILL,BLACK);
    if(lane==1)bar(79,134,283,236);
    else if(lane==2)bar(79,364,283,466);
    else bar(79,594,283,696);
}

void init_div()
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(x1,lane_dis+up_mar,x1a,lane_dis+l_wid+81);  bar(x1,lane_dis+up_mar+lane_dis+l_wid,x1a,lane_dis+l_wid+81+lane_dis+l_wid);
    bar(x2,lane_dis+up_mar,x2a,lane_dis+l_wid+81);  bar(x2,lane_dis+up_mar+lane_dis+l_wid,x2a,lane_dis+l_wid+81+lane_dis+l_wid);
    bar(x3,lane_dis+up_mar,x3a,lane_dis+l_wid+81);  bar(x3,lane_dis+up_mar+lane_dis+l_wid,x3a,lane_dis+l_wid+81+lane_dis+l_wid);
    bar(x4,lane_dis+up_mar,x4a,lane_dis+l_wid+81);  bar(x4,lane_dis+up_mar+lane_dis+l_wid,x4a,lane_dis+l_wid+81+lane_dis+l_wid);

}
void divider()
{
    setcolor(BLACK);

    line(x1a,lane_dis+up_mar,x1a,lane_dis+l_wid+up_mar);    line(x1a,lane_dis+up_mar+lane_dis+l_wid,x1a,lane_dis+l_wid+up_mar+lane_dis+l_wid);
    line(x2a,lane_dis+up_mar,x2a,lane_dis+l_wid+up_mar);    line(x2a,lane_dis+up_mar+lane_dis+l_wid,x2a,lane_dis+l_wid+up_mar+lane_dis+l_wid);
    line(x3a,lane_dis+up_mar,x3a,lane_dis+l_wid+up_mar);    line(x3a,lane_dis+up_mar+lane_dis+l_wid,x3a,lane_dis+l_wid+up_mar+lane_dis+l_wid);
    line(x4a,lane_dis+up_mar,x4a,lane_dis+l_wid+up_mar);    line(x4a,lane_dis+up_mar+lane_dis+l_wid,x4a,lane_dis+l_wid+up_mar+lane_dis+l_wid);

    x1--,x2--,x3--,x4--,x1a--,x2a--,x3a--,x4a--;

    setcolor(WHITE);
    line(x1,lane_dis+up_mar,x1,lane_dis+l_wid+up_mar);  line(x1,lane_dis+up_mar+lane_dis+l_wid,x1,lane_dis+l_wid+up_mar+lane_dis+l_wid);
    line(x2,lane_dis+up_mar,x2,lane_dis+l_wid+up_mar);  line(x2,lane_dis+up_mar+lane_dis+l_wid,x2,lane_dis+l_wid+up_mar+lane_dis+l_wid);
    line(x3,lane_dis+up_mar,x3,lane_dis+l_wid+up_mar);  line(x3,lane_dis+up_mar+lane_dis+l_wid,x3,lane_dis+l_wid+up_mar+lane_dis+l_wid);
    line(x4,lane_dis+up_mar,x4,lane_dis+l_wid+up_mar);  line(x4,lane_dis+up_mar+lane_dis+l_wid,x4,lane_dis+l_wid+up_mar+lane_dis+l_wid);

    delay(1);

    if(x1<0)x1=getmaxx();if(x1a<0)x1a=getmaxx();
    if(x2<0)x2=getmaxx();if(x2a<0)x2a=getmaxx();
    if(x3<0)x3=getmaxx();if(x3a<0)x3a=getmaxx();
    if(x4<0)x4=getmaxx();if(x4a<0)x4a=getmaxx();

}
void initial_values()
{
   maxx=getmaxx(),maxy=getmaxy(),lane=2,menu_len=50,side_road=30,up_mar=menu_len+side_road;
   gap=195,div_len=250,lane_dis=210,l_wid=20;
   x1=gap,x1a=x1+div_len,x2=x1a+gap,x2a=x2+div_len,x3=x2a+gap,x3a=x3+div_len,x4=x3a+gap,x4a=x4+div_len;
}

int main()
{

   Initialize();
   initial_values();
   upper_boundary();
   menu();
   car();
   road_bound();
   init_div();

   while(1)
   {
       divider();
       if(kbhit())
       {
           char ch=getch();
           if(ch=='w')
           {
               if(lane==1)lane=1;
               else
                {
                   remove_car();
                   lane--;
                }
               car();
           }
           else if(ch=='s')
           {
               if(lane==3)lane=3;
               else
               {
                   remove_car();
                   lane++;
               }
               car();
           }
       }
   }
   getch();
}
