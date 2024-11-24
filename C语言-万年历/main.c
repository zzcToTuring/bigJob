#include <stdio.h>
char *NameOfMonth[12]={"一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月"};
char *WeekDay[7]={"星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
int Runnian (int year)/*平年闰年判断的函数*/
{
 if(year%4==0&&year%100!=0||year%400==0)
 {
  return 1;/*闰年返回1*/
 }else
 {
  return 0;/*平年返回0*/
 }
}
int DateCheck(int uYear,int uMonth,int uDay)/*合法返回true，非法或超出范围返回false*/
/*日期判断的函数*/
{
 if (uYear<1901||uYear>9999||uMonth<1||uMonth>12||uDay<1||uDay>31)
 {
  return 0;
 }
 if (uMonth==4||uMonth==6||uMonth==9||uMonth==11)
 {
  if (uDay>30)
  {
   return 0;
  }
 }else if (uMonth==2)
 {
  if (Runnian(uYear))
  {
   if (uDay>29)
   {
    return 0;
   }
  }else
  {
   if (uDay>28)
   {
    return 0;
   }                                             
  }
 }
 return 1;
}
int GetDays (int year,int month,int day)
{
 int sum=0;
 if (DateCheck(year,month,day)==0)
 {
  return -1;/*日期有误*/
 }
 if(year>=1901)
 {
  int X=(int)(year/100);/*世纪数*/
  int Y=X-(int)(X/4);/*如果按4年一闰来算，Y指的是比实际上多算的天数，在下面需要减去*/
  if (month<=2&&month>0)
  {
   year--;/*把1月、2月视为上一年的13月、14月（纯粹为了计算需要）*/
   month+=12;
  }
  sum=(int)(365.25*(year-1900))+(int)(30.6*(month+1))+day-Y-49;//以365.25（本来实际太阳年是365.2425天）来计算是为了计算按4年一闰的整数年总天数,加上月份天数再加上余下天数，减掉多闰天数，再减掉一个偏差值（多加的）
  //月份以30.6天的平均值计算。最后减去的49，是多加的一个月以及其余相差天数的和，可得到1900年1月1日的积日为0
 }
 return sum;/*返回距离1900年1月1日的总天数（积日）*/
}
int GetMonthday(int month,int year) 
{
 int tmp_days=GetDays(year,month,1);/*本月积日*/
 int Monthday=0;
 month++;/*下个月*/
 if (month>12)
 {
  month=1;/*遇到月份为12月的情况，月份为1，年份加1*/
  year++;
 }
 Monthday=GetDays(year,month,1);/*下个月的积日*/
 Monthday-=tmp_days;/*下月1日的总天数（距离1900年1月1日的积日）减去当前1日的总天数*/
 return Monthday;/*返回当前月总天数*/
}
int Showday(int year,int month,int day)
{
 int i,j,count;
 int jiri=0;/*积日*/
 int dayofweek=0;/*星期*/
 if (DateCheck(year,month,day)==0)
 {
  printf("输入日期有误!\r\n");/*日期不合法或超出范围，年历从1901年开始*/
/*万年历从1901年开始编排*/
  return 0;
 }
 printf("\t    %d      %s\r\n",year,NameOfMonth[month-1]);
 printf("                                    \r\n");
 printf("   日   一   二   三   四   五   六\r\n");
 printf("                                      \r\n");
 jiri=GetDays(year,month,1);/*获取距离1900年1月1日的总天数*/
 dayofweek=(1+jiri)%7;/*月首星期，因为1900年1月1日星期一*/
 count=GetMonthday(month,year);
 for(i=0;i<dayofweek;i++)
 {
  printf("     ");/*填充前面空格*/
 }
 for(i=1,j=dayofweek;i<=count;i++,j++)
 {
  if (i<10)
  {
   printf("    %d",i);
  }else
  {
   printf("   %d",i);
  }
  if((j+1)%7==0)
  {
   if (i!=count)
   {
    printf("\r\n");/*满7天，换行*/
   }
  }
 }
 printf("\r\n\r\n\r\n");
 return 1;
}
int main()
{
 int year,month,day,Choise=0;
 int totaldays=0;
 while (1)/*主循环*/
/*程序一直重复着这个循环*/
 {
  printf("     欢迎使用万年历  \n");
  printf("     1.闰年判断      \n");
  printf("     2.星期计算      \n");
  printf("     3.月历查询      \n");
  printf("     4.打印整年日历   \n");
  printf("输入对应的序号进行相关操作：\n");
/*制作菜单*/
  scanf("%d",&Choise);
  switch (Choise)
/*Switch 及case 语句进行前面所列出的函数的调用*/
  {
  case 1:/*闰年的判断*/
   printf("请输入要判断的年份：\n");
   scanf("%d",&year);
   if (Runnian(year)==1)
   {
    printf("%d年是闰年！\r\n\r\n",year);
   }else
   {
    printf("%d年是平年！\r\n\r\n",year);
   }
   break;
  case 2:/*星期的计算*/
   printf("请输入要判断的日期：\n");
   scanf("%d %d %d",&year,&month,&day);
   totaldays=GetDays(year,month,day);
   printf("%d年%d月%d日是%s\r\n\r\n",year,month,day,WeekDay[(totaldays+1)%7]);
   break;
  case 3:/*月历查询*/
   printf("请输入要显示的月份\n：");
   scanf("%d %d",&year,&month);
   Showday(year,month,1);
   break;
  case 4:/*打印整年的日历*/
   printf("请输入要打印日期的年份：\n");
   scanf("%d",&year);
   for (month=1;month<=12;month++)
   {
    Showday(year,month,1);
   }
   break;
  default:
   printf("输入错误，请重新输入！\r\n");
   break;
  }

 }
 return 0;/*直接调用所定义的函数，运用case语句使得其简洁明了*/
}

/*程序结束*/
