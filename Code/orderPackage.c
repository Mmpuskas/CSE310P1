#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "football.h"

#define NO_TEAMS      32 // Number of NFL teams
#define TEAM_NAME_LEN 25 // Maximum team name string length
#define TOP_LEN        6 // Maximum time of possession string length

struct package* orderPackage(int startYear, int endYear, char* field, struct annual_stats* dataStruct)
{
	int yearRange = endYear - startYear + 1;

	//Find where the first year to be read is in the array
	int yearIndex = 0;
	int yearFound = 0;
	struct annual_stats* yearPointer = &dataStruct[yearIndex];
	while(yearPointer && yearFound == 0)
	{
		if(yearPointer->year == startYear)
			yearFound = 1;
		else
		{
			yearIndex++;
			yearPointer = &dataStruct[yearIndex];
		}
	}

	for(int i = 0; i < NO_TEAMS; i++)
		printf("From oP1: %s\n", dataStruct[0].teams[i].team_name);

	struct package* packPointer = malloc(yearRange * 32 * sizeof(struct package));

	for(int i = 0; i < NO_TEAMS; i++)
		printf("From oP2: %s\n", dataStruct[0].teams[i].team_name);

	//For each if, you need to end up with a package pointer that has n amount of 
	//packages full of data
	if(strcmp(field,"team_name") == 0) //Check field
	{
		for(int i = 0; i < yearRange; i++)
		{
			for(int j = 0; j < NO_TEAMS; j++)
			{
				strcpy(packPointer[j].team_name, dataStruct[yearIndex + i].teams[j].team_name);
			}
		}
	}
	else if(strcmp(field,"games") == 0)
	{
	}
	else if(strcmp(field,"pts_per_game") == 0)
	{
	}
	else if(strcmp(field,"total_points") == 0)
	{
	}
	else if(strcmp(field,"scrimmage_plays") == 0)
	{
	}
	else if(strcmp(field,"yds_per_game") == 0)
	{
	}
	else if(strcmp(field,"yds_per_play") == 0)
	{
	}
	else if(strcmp(field,"first_per_game") == 0)
	{
	}
	else if(strcmp(field,"third_md") == 0)
	{
	}
	else if(strcmp(field,"third_att") == 0)
	{
	}
	else if(strcmp(field,"third_pct") == 0)
	{
	}
	else if(strcmp(field,"fourth_md") == 0)
	{
	}
	else if(strcmp(field,"fourth_att") == 0)
	{
	}
	else if(strcmp(field,"fourth_pct") == 0)
	{
	}
	else if(strcmp(field,"penalties") == 0)
	{
	}
	else if(strcmp(field,"pen_yds") == 0)
	{
	}
	else if(strcmp(field,"top_per_game") == 0)
	{
	}
	else if(strcmp(field,"fum") == 0)
	{
	}
	else if(strcmp(field,"lost") == 0)
	{
	}
	else if(strcmp(field,"to") == 0)
	{
	}

	return packPointer;
}
