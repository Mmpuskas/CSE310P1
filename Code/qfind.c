/*
 * Michael Puskas
 * Source code file for bubble sort-based find function
 * 2/20/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "football.h"

#define NO_TEAMS      32 // Number of NFL teams
#define TEAM_NAME_LEN 25 // Maximum team name string length
#define TOP_LEN        6 // Maximum time of possession string length

/*
 * Sorts the data set, then finds a value based on given item and field
 * Parameters:
 * 	struct package* package  - Holds the data relevant to sorting 
 * 	char* field - Declares which field in team_stats to sort by
 * 	char* order - Declares whether to sort in ascending or descending order
 */
void qFind(struct package* package, char* field, char* item) 
{
	printf("\n##### Finding %d %s %s #####\n", package[0].year, item, field);

	if(package[0].type == 'n') //Specific name condition because the formatting is different on the print
	{
		qSortChar(package, 0, NO_TEAMS - 1);
		//Output based on item
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\nMax Value for %s: %s\n", field, field, package[0].team_name);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\nMin Value for %s: %s\n", field, field, package[NO_TEAMS - 1].team_name);
		else if(strcmp(item, "average") == 0)
			printf("Average is undefined for team names.");
		else if(strcmp(item, "median") == 0)
			printf("median is undefined for team names.");
	}
	else if(package[0].type == 'c') //Char
	{
		qSortChar(package, 0, NO_TEAMS - 1);
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\nMax Value for %s: %s\n", field, field, package[0].field.c);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\nMin Value for %s: %s\n", field, field, package[NO_TEAMS - 1].field.c);
		else if(strcmp(item, "average") == 0)
		{
			for(int i = 0; i < NO_TEAMS; i++)
			{
				package[i].field.c[0] = ' ';
				package[i].field.c[3] = '.';
			}
			float av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += atof(package[i].field.c);
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
			printf("##### Median Found for %s #####\n\t\t%s\n", field, package[NO_TEAMS / 2].field.c);
	}
	else if(package[0].type == 'i') //Int	
	{
		qSortInt(package, 0, NO_TEAMS - 1);
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, package[NO_TEAMS-1].team_name, package[NO_TEAMS-1].field.i);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, package[0].team_name, package[0].field.i);
		else if(strcmp(item, "average") == 0)
		{
			float av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += package[i].field.i;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.2f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, package[NO_TEAMS / 2].field.i);
	}
	else if(package[0].type == 'f') //Float
	{
		qSortFloat(package, 0, NO_TEAMS - 1);
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3.1f\n", field, 1, package[NO_TEAMS-1].team_name, package[NO_TEAMS-1].field.f);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3.1f\n", field, 1, package[0].team_name, package[0].field.f);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += package[i].field.f;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
			printf("##### Median Found for %s #####\n\t\t%-3.2f\n", field, package[NO_TEAMS / 2].field.f);
	}
	else
		printf("field unrecognized");
}
