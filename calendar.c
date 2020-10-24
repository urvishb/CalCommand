// These changes are from collaborator's side
//the second time i am changing something as a contributor 24th oct

#include <stdio.h>
#include <math.h>
#include <string.h>

int is_leap(int yr);

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
            if(is_leap(i) == 1)
            {
                leap_count++;
            }
        }
    }

    else
    {
        for (int j = year ; j <= 1900 ; j++)
        { 
            if(is_leap(j) == 1)
            {
                leap_count++;
            }
        }
    }

    int Normal_years = total_year - leap_count ; 

    int total_days = ((leap_count * 366) + (Normal_years) * 365 );

    int yrpoint = 0;

    if(year >= 1900)
    {
        while(strcmpi(allMonths[yrpoint], month) != 0)
        {
            if(yrpoint == 0 || yrpoint == 2 || yrpoint == 4 || yrpoint == 6 || yrpoint == 7 || yrpoint == 9 || yrpoint == 11)
            {
                    //printf("\n\nThis month had/has/will have 31 days\n\n");
                    total_days += 31;
            }

            else if (yrpoint == 3 || yrpoint == 5 || yrpoint == 8 || yrpoint == 10)
            {
                //printf("\n\nThis month had/has/will have 30 days\n\n");
                total_days += 30;
            }

            else
            {
                if (is_leap(year) == 1)
                {
                    //printf("\nThis month had/has/will have 29 days\n\n");
                    total_days += 29;
                }

                else
                {
                    //printf("\nThis month had/has/will have 28 days\n\n");
                    total_days += 28;
                }
            }
            yrpoint ++;      
        }
    }

    else
    {
        while(strcmpi(allMonths[yrpoint], month) != 0)
        {
            if(yrpoint == 0 || yrpoint == 2 || yrpoint == 4 || yrpoint == 6 || yrpoint == 7 || yrpoint == 9 || yrpoint == 11)
            {
                    //printf("\n\nThis month had/has/will have 31 days\n\n");
                    total_days -= 31;
            }

            else if (yrpoint == 3 || yrpoint == 5 || yrpoint == 8 || yrpoint == 10)
            {
                //printf("\n\nThis month had/has/will have 30 days\n\n");
                total_days -= 30;
            }

            else
            {
                if (is_leap(year) == 1)
                {
                    //printf("\nThis month had/has/will have 29 days\n\n");
                    total_days -= 29;
                }

                else
                {
                    //printf("\nThis month had/has/will have 28 days\n\n");
                    total_days -= 28;
                }
            }
            yrpoint ++;      
        }
    }
    

    int week_day;

    if(year == 1900 && (strcmpi(allMonths[0], month) == 0))
    {
        week_day = 0;
    } 
    
    else
    {
        week_day = total_days % 7 ;
    }
    

    if(year >= 1900)
    {
        week_day = week_day + 0;
    }

    else if (year < 1900)
    {
        week_day = 7 - week_day; 
    }

    // else
    // {
    //     week_day = 0;
    // }
    

    char days[7][10] = {"Mon",
                         "Tue",
                         "Wed",
                         "Thu",
                         "Fri" ,
                         "Sat",
                         "Sun"}; 

    // printf ("\n\nThe day at date - 01 / %s / %d was/is/will be %s!\n\n", month, year, days[week_day]);

    int days_in_mnth;

    for(currm = 0 ; currm < 12 ; currm++)
    {
        if (strcmpi(month, allMonths[currm]) == 0)
        {
            if(currm == 0 || currm == 2 || currm == 4 || currm == 6 || currm == 7 || currm == 9 || currm == 11)
            {
                // printf("\n\nThis month had/has/will have 31 days\n\n");
                days_in_mnth = 31;
            }

            else if (currm == 3 || currm == 5 || currm == 8 || currm == 10)
            {
                // printf("\n\nThis month had/has/will have 30 days\n\n");
                days_in_mnth = 30;
            }

            else
            {
                if (is_leap(year) == 1)
                {
                    // printf("\nThis month had/has/will have 29 days\n\n");
                    days_in_mnth = 29;
                }

                else
                {
                    // printf("\nThis month had/has/will have 28 days\n\n");
                    days_in_mnth = 28;
                } 
                
            }
            
        }
    }

    printf("\n\t\t  %s %d\n\n", month, year);


    // print days mon   tue   wed  ...
    for (int d = 0 ; d < 7 ; d++)
    {
        printf("%s\t", days[d]);
    }

    printf("\n");

    int blanks = 0, date = 1;

    while (blanks < week_day)
    {
        printf(" \t");
        blanks ++;
    }

    while (date <= days_in_mnth)
    {
        if(((week_day) % 7) == 0)
        {
            printf("\n\n");
        }

        printf(" %d\t", date);
        week_day++;
        date++;
    }

    return 0;	
}


int is_leap(int yr)
{
    int leap;
    if((yr % 400 == 0) || ((yr % 4 == 0) && (yr % 100 != 0)))
    {
        leap = 1;
        return leap;
    }

    else
    {
        leap = 0;
        return leap;
    }

}