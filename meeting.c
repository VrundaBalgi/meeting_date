#include "meetup_header.h"
int flag = 0;
int cnt = 0;
int main()
{
    char describe[100];
    char day[10];
    int date = 0,month,year;
    int yy=0,mcode=0,ccode=0;
    int k,leap;

    printf("\nEnter the description of meetup date as per below examples(case sensitive):\nEx1: The monteenth of January 2017\nEx2: The first Sunday of May 2012\nEx3: The last Friday of August 2013:\n");
    scanf(" %[^\n]",describe);

    find_day_month_year(describe,day,&month,&year);

    find_year_month_cent_codes(month,year,&yy,&mcode,&ccode);

    if((month==1 || month==2) && ((year%400==0 && year%100!=0)||(year%4==0)))
        leap = 1;

    if(flag == 0)
    {
        k = 13;
        while(k!=20)
        {
            if(strcmp(day,find_date(k,leap,mcode,yy,ccode))==0)
            {
                date = k;
                break;
            }
            k++;
        }
    }
    else if(flag == 1)
    {
        int counter = 0,l = 0;
        if(month == 1 ||  month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            l = 32;
        else if(month == 4 || month == 6 || month == 9 || month == 11)
            l = 31;
        else if(leap == 1 && month == 2)
            l = 30;
        else if(leap == 0 && month == 2)
            l = 29;

        k = 1;
        while(k!=l)
        {
            if(strcmp(day,find_date(k,leap,mcode,yy,ccode))==0)
            {
                counter++;
            }
            if(counter == cnt)
            {
                date = k;
                break;
            }
            k++;
        }
    }
    else if(flag == 2)
    {
        if(month == 1 ||  month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            k = 31;
        else if(month == 4 || month == 6 || month == 9 || month == 11)
            k = 30;
        else if(leap == 1 && month == 2)
            k = 29;
        else if(leap == 0 && month == 2)
            k = 28;

        while(k!=0)
        {
            if(strcmp(day,find_date(k,leap,mcode,yy,ccode))==0)
            {
                date = k;
                break;
            }
            k--;
        }
    }
    printf("\nMeetup date = %d/%d/%d",year,month,date);

}
