/*
 * Michael Puskas
 * Source code file holding definitions of sort functions
 * 2/1/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "football.h"

#define NO_TEAMS      32 // Number of NFL teams
#define TEAM_NAME_LEN 25 // Maximum team name string length
#define TOP_LEN        6 // Maximum time of possession string length

//Bubble sort for characters. 
void bSortChar(struct package* package, int maxIndex)
{
	if(package[0].type == 'n') //Check type 
	{
		char temp[TEAM_NAME_LEN];
		//Bubble sort
		for(int i = 0; i < maxIndex - 1; i++)
			for(int j = i+1; j < maxIndex; j++)
				if(strcmp(package[i].team_name, package[j].team_name) > 0)
				{
					strcpy(temp, package[i].team_name);
				        strcpy(package[i].team_name, package[j].team_name);	
					strcpy(package[j].team_name, temp);
				}
	}	
	else 
	{
		for(int i = 0; i < maxIndex - 1; i++)
			for(int j = i+1; j < maxIndex; j++)
				if(strcmp(package[i].field.c, package[j].field.c) > 0)
				{
					struct package temp = package[i];
					package[i] = package[j];
					package[j] = temp;
				}
	}
}
//Bubble sort for Integers
void bSortInt(struct package* package, int maxIndex)
{
	for(int i = 0; i < maxIndex - 1; i++)
		for(int j = i+1; j < maxIndex; j++)
			if(package[i].field.i < package[j].field.i)
			{
				struct package temp = package[i];
				package[i] = package[j];
				package[j] = temp;
			}
}
//Bubble sort for Floats
void bSortFloat(struct package* package, int maxIndex)
{
	for(int i = 0; i < maxIndex - 1; i++)
		for(int j = i+1; j < maxIndex; j++)
			if(package[i].field.f < package[j].field.f)
			{
				struct package temp = package[i];
				package[i] = package[j];
				package[j] = temp;
			}
}

/*
 * Calls a function to sort the data in dataStruct based on the field passed
 * Parameters:
 * 	struct package* package  - Holds the data relevant to sorting 
 * 	char* field - Declares which field in team_stats to sort by
 * 	char* order - Declares whether to sort in ascending or descending order
 */
void bSortY(struct package* package, char* field, char* order) 
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
		bSortChar(package, NO_TEAMS);
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
		bSortChar(package, NO_TEAMS);
		if(order[0] == 'i')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3s\n", i+1, package[i].team_name, package[i].field.c);
		else if(order[0] == 'd')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3s\n", i+1, package[i].team_name, package[i].field.c);
	}
	else if(package[0].type == 'i') //Int	
	{
		bSortInt(package, NO_TEAMS);
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%d\n", i+1, package[i].team_name, package[i].field.i);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%d\n", i+1, package[i].team_name, package[i].field.i);
	}
	else if(package[0].type == 'f') //Float
	{
		bSortFloat(package, NO_TEAMS);
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, package[i].team_name, package[i].field.f);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, package[i].team_name, package[i].field.f);
	}
	else
		printf("field unrecognized");
}

void bSortR(struct package* package, char* field, char* order, int yearDif) //bSort range
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
		bSortChar(package, maxIndex);
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
		bSortChar(package, maxIndex);
		if(order[0] == 'i')
			for(int i = 0; i < maxIndex; i++)
				printf("%2d.\t%-25s(%d)\t%-3s\n", i+1, package[i].team_name, package[i].year, package[i].field.c);
		else if(order[0] == 'd')
			for(int i = maxIndex-1; i >= 0; i--)
				printf("%2d.\t%-25s(%d)\t%-3s\n", i+1, package[i].team_name, package[i].year, package[i].field.c);
	}
	else if(package[0].type == 'i') //Int	
	{
		bSortInt(package, maxIndex);
		if(order[0] == 'd')
			for(int i = 0; i < maxIndex; i++)
				printf("%2d.\t%-25s(%d)\t%d\n", i+1, package[i].team_name, package[i].year, package[i].field.i);
		else if(order[0] == 'i')
			for(int i = maxIndex-1; i >= 0; i--)
				printf("%2d.\t%-25s(%d)\t%d\n", i+1, package[i].team_name, package[i].year, package[i].field.i);
	}
	else if(package[0].type == 'f') //Float
	{
		bSortFloat(package, maxIndex);
		if(order[0] == 'd')
			for(int i = 0; i < maxIndex; i++)
				printf("%2d.\t%-25s(%d)\t%-3.1f\n", i+1, package[i].team_name, package[i].year, package[i].field.f);
		else if(order[0] == 'i')
			for(int i = maxIndex-1; i >= 0; i--)
				printf("%2d.\t%-25s(%d)\t%-3.1f\n", i+1, package[i].team_name, package[i].year, package[i].field.f);
	}
	else
		printf("field unrecognized");
}
