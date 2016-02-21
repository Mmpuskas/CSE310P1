/*
 * Michael Puskas
 * Source code file holding definitions of sort functions
 * 2/20/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "football.h"

#define NO_TEAMS      32 // Number of NFL teams
#define TEAM_NAME_LEN 25 // Maximum team name string length
#define TOP_LEN        6 // Maximum time of possession string length

void swap(struct package* package, int l, int r)
{
	struct package temp = package[l];
	package[l] = package[r];
	package[r] = temp;
}
//Partition for characters
int partChar(struct package* package, int l, int r)
{
	int i, j;
	char pivot[25];
	strcpy(pivot, package[l].field.c);
	i = l; j = r+1;

	while(1)
	{
		do ++i; while(strcmp(package[i].field.c, pivot) <= 0 && i <= r);
		do --j; while(strcmp(package[j].field.c, pivot) > 0);
		if(i >= j) break;
		swap(package, i, j);
	}
	swap(package, l, j);
	return j;
}
//Quick sort for characters. 
void qSortChar(struct package* package, int l, int r)
{
	int j;	
	if( l < r )
	{
		j = partChar(package, l, r);
		qSortChar(package, l, j-1);
		qSortChar(package, j+1, r);
	}
}
//Partition for Ints
int partInt(struct package* package, int l, int r)
{
	int pivot, i, j;
	pivot = package[l].field.i;
	i = l; j = r+1;

	while(1)
	{
		do ++i; while(package[i].field.i <= pivot && i <= r);
		do --j; while(package[j].field.i > pivot);
		if(i >= j) break;
		swap(package, i, j);
	}
	swap(package, l, j);
	return j;
}
//Quick sort for Integers
void qSortInt(struct package* package, int l, int r)
{
	int j;	
	if( l < r )
	{
		j = partInt(package, l, r);
		qSortInt(package, l, j-1);
		qSortInt(package, j+1, r);
	}
}
//Partition for Floats
float partFloat(struct package* package, int l, int r)
{
	int i, j;
	float pivot;
	pivot = package[l].field.f;
	i = l; j = r+1;

	while(1)
	{
		do ++i; while(package[i].field.f <= pivot && i <= r);
		do --j; while(package[j].field.f > pivot);
		if(i >= j) break;
		swap(package, i, j);
	}
	swap(package, l, j);
	return j;

}
//Quick sort for Floats
void qSortFloat(struct package* package, int l, int r)
{
	int j;	
	if( l < r )
	{
		j = partFloat(package, l, r);
		qSortFloat(package, l, j-1);
		qSortFloat(package, j+1, r);
	}
}

/*
 * Calls a function to sort the data in dataStruct based on the field passed
 * Parameters:
 * 	struct package* package  - Holds the data relevant to sorting 
 * 	char* field - Declares which field in team_stats to sort by
 * 	char* order - Declares whether to sort in ascending or descending order
 */
void qSortY(struct package* package, char* field, char* order) 
{
	//Set a string to be used in the output
	char* ord = "Ascending ";
	if(order[0] == 'd')
	       	ord = "Descending";

	printf("\n#######  %d Ranking by %s  #######\n", package[0].year, field);
	printf("#######      %s Order       #######\n", ord);

	//Split fields based on data type, call appropraite function
	if(package[0].type == 'n') //Specific name condition because the formatting is different on the print
	{
		qSortChar(package, 0, NO_TEAMS - 1);
		//Output sorted data based on order
		if(order[0] == 'i')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t\n", i+1, package[i].team_name);
		else if(order[0] == 'd')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t\n", i+1, package[i].team_name);
	}
	else if(package[0].type == 'c') //Char
	{
		qSortChar(package, 0, NO_TEAMS - 1);
		if(order[0] == 'i')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3s\n", i+1, package[i].team_name, package[i].field.c);
		else if(order[0] == 'd')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3s\n", i+1, package[i].team_name, package[i].field.c);
	}
	else if(package[0].type == 'i') //Int	
	{
		qSortInt(package, 0, NO_TEAMS - 1);
		if(order[0] == 'i')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%d\n", i+1, package[i].team_name, package[i].field.i);
		else if(order[0] == 'd')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%d\n", i+1, package[i].team_name, package[i].field.i);
	}
	else if(package[0].type == 'f') //Float
	{
		qSortFloat(package, 0, NO_TEAMS - 1);
		if(order[0] == 'i')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, package[i].team_name, package[i].field.f);
		else if(order[0] == 'd')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, package[i].team_name, package[i].field.f);
	}
	else
		printf("field unrecognized");
}
void qSortR(struct package* package, char* field, char* order, int yearDif) //bSort range
{
	char* ord = "Ascending ";
	if(order[0] == 'd')
	       	ord = "Descending";

	printf("\n#######  %d-%d  Ranking by %s  #######\n", package[0].year, package[0].year + yearDif, field);
	printf("#######      %s Order       #######\n",ord);

	int maxIndex = NO_TEAMS + (NO_TEAMS * yearDif); //Highest index we can reach

	//Split fields based on data type, call appropraite function
	if(package[0].type == 'n') //Specific name condition because the formatting is different on the print
	{
		qSortChar(package, 0, maxIndex - 1);
		//Output sorted data based on order
		if(order[0] == 'i')
			for(int i = 0; i < maxIndex; i++)
				printf("%2d.\t%-25s(%d)\t\n", i+1, package[i].team_name, package[i].year);
		else if(order[0] == 'd')
			for(int i = maxIndex-1; i >= 0; i--)
				printf("%2d.\t%-25s(%d)\t\n", i+1, package[i].team_name, package[i].year);
	}
	else if(package[0].type == 'c') //Char
	{
		qSortChar(package, 0,  maxIndex - 1);
		if(order[0] == 'i')
			for(int i = 0; i < maxIndex; i++)
				printf("%2d.\t%-25s(%d)\t%-3s\n", i+1, package[i].team_name, package[i].year, package[i].field.c);
		else if(order[0] == 'd')
			for(int i = maxIndex-1; i >= 0; i--)
				printf("%2d.\t%-25s(%d)\t%-3s\n", i+1, package[i].team_name, package[i].year, package[i].field.c);
	}
	else if(package[0].type == 'i') //Int	
	{
		qSortInt(package, 0, maxIndex - 1);
		if(order[0] == 'i')
			for(int i = 0; i < maxIndex; i++)
				printf("%2d.\t%-25s(%d)\t%d\n", i+1, package[i].team_name, package[i].year, package[i].field.i);
		else if(order[0] == 'd')
			for(int i = maxIndex-1; i >= 0; i--)
				printf("%2d.\t%-25s(%d)\t%d\n", i+1, package[i].team_name, package[i].year, package[i].field.i);
	}
	else if(package[0].type == 'f') //Float
	{
		qSortFloat(package, 0, maxIndex - 1);
		if(order[0] == 'i')
			for(int i = 0; i < maxIndex; i++)
				printf("%2d.\t%-25s(%d)\t%-3.1f\n", i+1, package[i].team_name, package[i].year, package[i].field.f);
		else if(order[0] == 'd')
			for(int i = maxIndex-1; i >= 0; i--)
				printf("%2d.\t%-25s(%d)\t%-3.1f\n", i+1, package[i].team_name, package[i].year, package[i].field.f);
	}
	else
		printf("field unrecognized");
}
