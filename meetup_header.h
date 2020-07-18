#ifndef MEETUP_HEADER_H_INCLUDED
#define MEETUP_HEADER_H_INCLUDED

//Header files
#include<stdio.h>
#include<string.h>
#include<math.h>

//Global variables
extern int flag;
extern int cnt;

//Function declaration
void find_day_month_year(char describe[],char *day, int *month, int *year);

void find_year_month_cent_codes(int month,int year,int *yy,int *mcode,int *ccode);

const char* find_date(int date,int leap,int mcode,int yy,int ccode);

#endif // MEETUP_HEADER_H_INCLUDED
