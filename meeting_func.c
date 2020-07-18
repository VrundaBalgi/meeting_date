#include "meetup_header.h"

void find_day_month_year(char describe[],char *day, int *month, int *year)
{
    char store[25];
    int len = 0;
    int i=4,j=0;

    while(describe[i]!=' ')
    {
        store[j] = describe[i];
        i++;
        j++;
    }
    store[j] = '\0';
    len = strlen(store);

    if(strcmp(store+(len-6),"teenth")==0)
    {
        if(strcmp(store,"monteenth") == 0)
        {
            strcpy(day,"Monday");
        }
        else if(strcmp(store,"tuesteenth") == 0)
        {
            strcpy(day,"Tuesday");
        }
        else if(strcmp(store,"wednesteenth") == 0)
        {
            strcpy(day,"Wednesday");
        }
        else if(strcmp(store,"thursteenth") == 0)
        {
            strcpy(day,"Thursday");
        }
        else if(strcmp(store,"friteenth") == 0)
        {
            strcpy(day,"Friday");
        }
        else if(strcmp(store,"saturteenth") == 0)
        {
            strcpy(day,"Saturday");
        }
        else if(strcmp(store,"sunteenth") == 0)
        {
            strcpy(day,"Sunday");
        }
    }
    else
    {
        flag = 1;
        if(strcmp(store,"first")==0)
            cnt = 1;
        else if(strcmp(store,"second")==0)
            cnt = 2;
        else if(strcmp(store,"third")==0)
            cnt = 3;
        else if(strcmp(store,"fourth")==0)
            cnt = 4;
        else if(strcmp(store,"fifth")==0)
            cnt = 5;
        else if(strcmp(store,"last")==0)
        {
            cnt = 6;
            flag = 2;
        }
        i++;
        j=0;

        while(describe[i]!=' ')
        {
            store[j] = describe[i];
            i++;
            j++;
        }
        store[j] = '\0';
        strcpy(day,store);
    }

    i = i+4;
    j = 0;
    while(describe[i]!=' ')
    {
        store[j] = describe[i];
        i++;
        j++;
    }
    store[j] = '\0';
    i++;
    j=0;

    if(strcmp(store,"January") == 0)
    {
        *month = 1;
    }
    else if(strcmp(store,"February") == 0)
    {
        *month = 2;
    }
    else if(strcmp(store,"March") == 0)
    {
        *month = 3;
    }
    else if(strcmp(store,"April") == 0)
    {
        *month = 4;
    }
    else if(strcmp(store,"May") == 0)
    {
        *month = 5;
    }
    else if(strcmp(store,"June") == 0)
    {
        *month = 6;
    }
    else if(strcmp(store,"July") == 0)
    {
        *month = 7;
    }
    else if(strcmp(store,"August") == 0)
    {
        *month = 8;
    }
    else if(strcmp(store,"September") == 0)
    {
        *month = 9;
    }
    else if(strcmp(store,"October") == 0)
    {
        *month = 10;
    }
    else if(strcmp(store,"November") == 0)
    {
        *month = 11;
    }
    else if(strcmp(store,"December") == 0)
    {
        *month = 12;
    }

    while(describe[i]!='\0')
    {
        store[j] = describe[i];
        i++;
        j++;
    }
    store[j] = '\0';

    *year = atoi(store);
}

void find_year_month_cent_codes(int month,int year,int *yy,int *mcode,int *ccode)
{
    int cc;
    for(int i=0;i<4;i++)
    {
        switch(i)
        {
            case 0: *yy = *yy+(year%10);break;
            case 1: *yy = *yy+((year%10)*10);break;
            case 2: cc = cc+(year%10); break;
            case 3: cc = cc+((year%10)*10); break;
        }
        year = year/10;
    }
    cc = cc*100;

    switch(month)
    {
        case 1: *mcode = 1; break;
        case 2: *mcode = 4; break;
        case 3: *mcode = 4; break;
        case 4: *mcode = 0; break;
        case 5: *mcode = 2; break;
        case 6: *mcode = 5; break;
        case 7: *mcode = 0; break;
        case 8: *mcode = 3; break;
        case 9: *mcode = 6; break;
        case 10: *mcode = 1; break;
        case 11: *mcode = 4; break;
        case 12: *mcode = 6; break;
    }

    switch(cc)
    {
        case 1600: *ccode = 6; break;
        case 1700: *ccode = 4; break;
        case 1800: *ccode = 2; break;
        case 1900: *ccode = 0; break;
        case 2000: *ccode = 6; break;
    }

}

const char* find_date(int date,int leap,int mcode,int yy,int ccode)
{
    int day_code;
    day_code = date+mcode+yy+(yy/4)+ccode;
    if(leap == 1)
        day_code-=1;
    day_code = day_code%7;
    switch(day_code)
    {
        case 1: return "Sunday"; break;
        case 2: return "Monday"; break;
        case 3: return "Tuesday"; break;
        case 4: return "Wednesday"; break;
        case 5: return "Thursday"; break;
        case 6: return "Friday"; break;
        case 0: return "Saturday"; break;
    }
}
