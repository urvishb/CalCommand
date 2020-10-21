#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int year, currm;
    char month[4];
    char allMonths[12][4] = {"jan",
                             "feb",
                             "mar", 
                             "apr", 
                             "may", 
                             "jun", 
                             "jul", 
                             "aug", 
                             "sep", 
                             "oct", 
                             "nov", 
                             "dec"};
            
	printf("Please Enter the first 3 letters of any Month (Ex - Nov for November) : ");
    scanf("%s", month);

    printf ("\nPlease enter the corresponding year = ");
	scanf("%d", &year);

	int total_year = abs(year - 1900);
    int leap_count = 0;

    if(year > 1900)
    {
        for (int i = 1900 ; i < year ; i++)
        {
            if((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
            {
                leap_count++;
            }  
        }
    }

    else
    {
        for (int j = year ; j <= 1900 ; j++)
        { 
            if((j % 400 == 0) || ((j % 4 == 0) && (j % 100 != 0)))
            {
                leap_count++;
            }
        }
    }

    int Normal_years = total_year - leap_count ; 

    int total_days = ((leap_count * 366) + (Normal_years) * 365 );

    int week_day;

    if(year == 1900)
    {
        week_day = 0;
    } 
    
    else
    {
        week_day = total_days % 7 ;
    }
    

    if(year > 1900)
    {
        week_day = week_day + 0;
    }

    else
    {
        week_day = 7 - week_day; 
    }

    char days[7][10] = {"Monday",
                         "Tuesday",
                         "Wednesday",
                         "Thursday",
                         "Friday" ,
                         "Saturday",
                         "Sunday"}; 

    printf ("\n\nThe day at date - 01/ Jan / %d was %s!\n\n", year, days[week_day]);



    for(currm = 0 ; currm < 12 ; currm++)
    {
        if (strcmpi(month, allMonths[currm]) == 0)
        {
            if(currm == 0 || currm == 2 || currm == 4 || currm == 6 || currm == 7 || currm == 9 || currm == 11)
            {
                printf("\n\nThis month had/has/will have 31 days\n\n");
            }

            else if (currm == 3 || currm == 5 || currm == 8 || currm == 10)
            {
                printf("\n\nThis month had/has/will have 30 days\n\n");
            }

            else
            {
                printf("\nThis month had/has/will have 28/29 days\n\n");
            }
            
        }
    }

    return 0;	
}
