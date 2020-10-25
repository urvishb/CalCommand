// These changes are from collaborator's side
// the second time i am changing something as a contributor 24th oct, Part 1 implemented (Linux calCommand)
// Third Update; Part 2 implemented, calendar navigation possible now (25th oct)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

int getkey();
int is_leap (int yr);
void printCal (char *, int);
void printMenu();

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

    for (int i = 0 ; i < 12 ; i++)
    {
        if (strcmpi(month, allMonths[i]) == 0)
        {
            currm = i;
            break;
        }
    }

    printCal(month, year);
    printMenu();

    int endFlag = 0, key;

    while(endFlag == 0)
    {
        key = getkey();

        if (key == 27)
        {
            endFlag = 1;
            printf("\n\n\t>>> Closing Calendar <<<\n\n");
            break;
        }

        if (key == 72)
        {
            // up arrow key
            system("cls");
            year ++;
            printCal(allMonths[currm], year);
            printMenu();
        }

        else if (key == 80)
        {
            // down arrow key
            system("cls");
            year --;

            printCal(allMonths[currm], year);
            printMenu();
        }

        else if (key == 75)
        {
            // left arrow key
            system("cls");

            currm --;
            if (currm < 0)
            {
                currm = 11;
                year--;
                printCal (allMonths[currm], year);
                printMenu();
            }
            else
            {
                printCal(allMonths[currm], year);
                printMenu();
            }
        }

        else if (key == 77)
        {
            // right arrow key
            system("cls");

            currm ++;
            if (currm > 11)
            {
                currm = 0;
                year++;
                printCal (allMonths[currm], year);
                printMenu();
            }

            else
            {
                printCal(allMonths[currm], year);
                printMenu();
            }
        }
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

void printCal (char * mah, int sal)
{
    int currm;
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

	int total_year = abs(sal - 1900);
    int leap_count = 0;

    if(sal > 1900)
    {
        for (int i = 1900 ; i < sal ; i++)
        {
            if(is_leap(i) == 1)
            {
                leap_count++;
            }
        }
    }

    else
    {
        for (int j = sal ; j <= 1900 ; j++)
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

    if(sal >= 1900)
    {
        while(strcmpi(allMonths[yrpoint], mah) != 0)
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
                if (is_leap(sal) == 1)
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
        while(strcmpi(allMonths[yrpoint], mah) != 0)
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
                if (is_leap(sal) == 1)
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

    if(sal == 1900 && (strcmpi(allMonths[0], mah) == 0))
    {
        week_day = 0;
    } 
    
    else
    {
        week_day = total_days % 7 ;
    }
    

    if(sal >= 1900)
    {
        week_day = week_day + 0;
    }

    else if (sal < 1900)
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
        if (strcmpi(mah, allMonths[currm]) == 0)
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
                if (is_leap(sal) == 1)
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

    printf("\n\t\t  %s %d\n\n", mah, sal);


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


}

int getkey ()
{
    int ch;
    ch = getch();
    if (ch == 0)
    {
        ch = getch();
        return ch;
    }

    return ch;
}


void printMenu()
{
    printf("\n\n\n\nPress %c (Up arrow key) : For Next Year\n", 30);
    printf("\nPress %c (Down arrow key) : For Previous Year\n", 31);
    printf("\nPress %c (Right arrow key) : For Next Month\n", 16);
    printf("\nPress %c (Left arrow key) : For Previous Month\n", 17);
    printf("\n\tPress Esc key to Quit");
}