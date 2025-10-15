/* Task description:
The results of a running competition are shown in the table below.
Index	Name	Birthdate	Rank

0	Am, Erica	1984. 05. 06.	1
1	Abnorm, Al	1982. 09. 30.	3
2	Pri, Mary	1988. 08. 25.	2
3	Duck, Ling	1979. 06. 10.	5
4	Mac, Donald	1992. 04. 05.	4

Find an unfinished program below that contains the appropriate types and the above data in an array. Complete the program, step-by-step, according to the comments.

*/

#include <stdio.h>
#include <ctype.h>

typedef struct Date
{ // Create a stuct definition, not an instance, it is a type. With typedef we give it a new name (struct Date-->Date
    int year, month, day;
} Date;

typedef struct Competitor
{
    char name[31];
    Date birth; // Here we use our fresh type: Date!
    int rank;
} Competitor;

void Date_print(Date d); // Here we declare that there is a function
// that "eats" Date and do not return (poos) anything. You need to write a function at the bottom!

Competitor Competitor_read(); // This function will read data from user store in a stucture
// and return with the new element (to be put into the array later)

void Competitor_print(Competitor c);

int main()
{
    Competitor competitors[6] = {
        // It is an array of Competitor, like array of int!
        // Please note that the individual competitors are not variables,
        // there are no variable name for them, these exists only in the array!
        // 6 competitor to be able to add one more!
        {"Am, Erica", {1984, 5, 6}, 1},
        {"Abnorm, Al", {1982, 9, 30}, 3},
        {"Pri, Mary", {1988, 8, 25}, 2},
        {"Duck, Ling", {1979, 6, 10}, 5},
        {"Mac, Donald", {1992, 4, 5}, 4},
    };
    /* name of competitor 0 - printf %s */ printf("%s\n", (competitors[0].name));
    /* rank of competitor 2 */ printf("%d\n", competitors[2].rank);
    /* birth date of competitor 4, use the given function */ Date_print(competitors[4].birth);
    /* the first letter of the name of competitor 1 (a string is an array of characters) */ printf("%c\n", ((competitors[1].name)[0]));
    /* is competitor 1 among the best three? yes/no, may use ?: operator */ if (competitors[1].rank <= 3)
        printf("Yes\n");
    else
    {
        printf("No\n");
    } /* is competitor 4 faster than competitor 3? */
    /* was competitor 1 born in the same year as competitor 2? */ if ((competitors[1].birth.year == competitors[2].birth.year) && competitors[1].birth.month == competitors[2].birth.month && competitors[1].birth.day == competitors[2].birth.day)
        printf("Yes\n");
    else
    {
        printf("No\n");
    }
    /* complete the Competitor_print() function,
     * then print all data of competitor 1 */
    Competitor_print(competitors[1]);
    /* Check if Abnorm, Al was competeing (using strcmp())*/
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(competitors[i].name, "Abnorm, Al") == 0)
            printf("Yes\n");
    }
    /* Create a function to add a new competitor according to user's input (using scanf)*/
    /*Add a new competitor as 6th element (index 5)*/competitors[5] =Competitor_read();
    /* at last print all data of all competitors. */ Competitor_print(competitors[5]);
    for (int i = 0; i < 6; i++){
        Competitor_print(competitors[i]);
    }

    return 0;
}
void Date_print(Date d)
{
    printf("%d. %d. %d\n", d.year, d.month, d.day); /* print year, month and day */
}

void Competitor_print(Competitor c)
{
    printf("%s\t%d:%d:%d\t%d\n", c.name, c.birth.year, c.birth.month, c.birth.day, c.rank); /* print all data of the competitor */
}

Competitor Competitor_read()
{
    Competitor c;
    
    printf("Add competitor\n");
    scanf("%s", c.name);
    getchar();
    printf("Add birth\n");
    scanf("%d.%d.%d",  &c.birth.year, &c.birth.month, &c.birth.day);
    getchar();
    printf("Add rank\n");
    scanf("%d", &c.rank);
    return c;
    /* prompt the user the give details of a new competitor, create the new competitor and return with that!*/
}
                     