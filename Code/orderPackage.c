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

	struct package* packPointer = malloc(yearRange * 32 * sizeof(struct package));

	//Give each team a name
	for(int i = 0; i < yearRange; i++)
		for(int j = 0; j < NO_TEAMS; j++)
			strcpy(packPointer[j].team_name, dataStruct[yearIndex + i].teams[j].team_name);
	
	//Fill in the field to be sorted by
	if(strcmp(field,"team_name") == 0) //Check field
	{
		//Do nothing, each sort will need to handle names differently anyway because of output
	}
	else if(strcmp(field,"games") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].games;
	}
	else if(strcmp(field,"pts_per_game") == 0)
	{
		packPointer[0].type = 'f';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.f = dataStruct[yearIndex + i].teams[j].pts_per_game;
	}
	else if(strcmp(field,"total_points") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].total_points;
	}
	else if(strcmp(field,"scrimmage_plays") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].scrimmage_plays;
	}
	else if(strcmp(field,"yds_per_game") == 0)
	{
		packPointer[0].type = 'f';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.f = dataStruct[yearIndex + i].teams[j].yds_per_game;
	}
	else if(strcmp(field,"yds_per_play") == 0)
	{
		packPointer[0].type = 'f';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.f = dataStruct[yearIndex + i].teams[j].yds_per_play;
	}
	else if(strcmp(field,"first_per_game") == 0)
	{
		packPointer[0].type = 'f';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.f = dataStruct[yearIndex + i].teams[j].first_per_game;
	}
	else if(strcmp(field,"third_md") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].third_md;
	}
	else if(strcmp(field,"third_att") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].third_att;
	}
	else if(strcmp(field,"third_pct") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].third_pct;
	}
	else if(strcmp(field,"fourth_md") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].fourth_md;
	}
	else if(strcmp(field,"fourth_att") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].fourth_att;
	}
	else if(strcmp(field,"fourth_pct") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].fourth_pct;
	}
	else if(strcmp(field,"penalties") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].penalties;
	}
	else if(strcmp(field,"pen_yds") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].pen_yds;
	}
	else if(strcmp(field,"top_per_game") == 0)
	{
		packPointer[0].type = 's';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				strcpy(packPointer[j].field.c, dataStruct[yearIndex + i].teams[j].top_per_game);
	}
	else if(strcmp(field,"fum") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].fum;
	}
	else if(strcmp(field,"lost") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].lost;
	}
	else if(strcmp(field,"to") == 0)
	{
		packPointer[0].type = 'i';
		for(int i = 0; i < yearRange; i++)
			for(int j = 0; j < NO_TEAMS; j++)
				packPointer[j].field.i = dataStruct[yearIndex + i].teams[j].to;
	}

	return packPointer;
}
