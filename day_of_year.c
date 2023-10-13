#include<stdio.h>

static char *daytab[13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int day_of_year(int,int,int);

int main(int argc, char *argv[]){
	if(argc >= 4){
		int year,month,day,day_year;

		year = (int) argv[3]-'0';
		month = (int) argv[2]-'0';
		day = (int) argv[1]-'0';
		day_year = day_of_year(year,month,day);
		printf("Day is %4dth day of the year\n",day_year);
	}
}

int day_of_year(int year,int month, int day){
	int leap,i;
	leap = year%4==0 && year%100 != 0 || year%400 == 0;
	for(i=1;i<month;i++)
		day += daytab[leap][i];
	return day;
}
