/*
 * Michael Puskas
 * Program to read football team data from a text file, store it, then process it based on commands
 * 2/1/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "football.h"
#include "bsort.c"
#include "bfind.c"
#include "orderPackage.c"

#define NO_TEAMS      32 // Number of NFL teams
#define TEAM_NAME_LEN 25 // Maximum team name string length
#define TOP_LEN        6 // Maximum time of possession string length

int numYears = 0; //Global for number of years
int* yearArr; //Global array for specific years to reference

/*
 * Reads a line from stdin
 * Parameters:
 * 	char *linePointer - Points to the beginning of the line that was read
 */
void readLine(char *linePointer)
{
	if (linePointer != NULL)
	{
		int c = EOF;
		unsigned int i = 0;

		while ((c = getchar()) != '\n' && c != EOF)
		{
			linePointer[i++] = (char) c;

		}
		linePointer[i] = '\0';
	}
}
/*
 * Takes a single line and distributes the data to the appropriate places in the struct
 * Parameters:
 *	struct team_stats singleTeamData - Holds a single team's worth of data in a team_stats struct
 *	char* linePointer - Passes through the linePointer to readLine(char *linePointer), then uses it to break apart strings into tokens 	
 * Return:
 * 	Returns a struct filled with 1 line's worth of team data
 */
struct team_stats processTeamInfo(struct team_stats singleTeamData, char* linePointer)
{
	readLine(linePointer);
	char delim[2] = "\t";
	
	strcpy(singleTeamData.team_name, strtok(linePointer,delim));
	singleTeamData.games = atoi(strtok(NULL,delim));
	singleTeamData.pts_per_game = atof(strtok(NULL,delim));;
	singleTeamData.total_points = atoi(strtok(NULL,delim));
	singleTeamData.scrimmage_plays = atoi(strtok(NULL,delim));
	singleTeamData.yds_per_game = atof(strtok(NULL,delim));
	singleTeamData.yds_per_play = atof(strtok(NULL,delim)); 
	singleTeamData.first_per_game = atoi(strtok(NULL,delim));
	singleTeamData.third_md = atoi(strtok(NULL,delim));
	singleTeamData.third_att = atoi(strtok(NULL,delim));
	singleTeamData.third_pct = atoi(strtok(NULL,delim)); 
	singleTeamData.fourth_md = atoi(strtok(NULL,delim));
	singleTeamData.fourth_att = atoi(strtok(NULL,delim));
	singleTeamData.fourth_pct = atoi(strtok(NULL,delim));
	singleTeamData.penalties = atoi(strtok(NULL,delim));
	singleTeamData.pen_yds = atoi(strtok(NULL,delim));
	strcpy(singleTeamData.top_per_game, strtok(NULL,delim));
	singleTeamData.fum = atoi(strtok(NULL,delim));
	singleTeamData.lost = atoi(strtok(NULL,delim));
	singleTeamData.to = atoi(strtok(NULL,delim));

	return singleTeamData;
}

/*
 * Sets up the structures and calls functions to fill them. Also sets globals yearArr and numYears
 * Parameters:
 * 	char* linePointer - Passes it through to the functions that read and process lines 
 * Return:
 * 	Returns a pointer to an annual_stats struct containing all of the team data
 */
struct annual_stats* processData(char* linePointer)
{
	readLine(linePointer);
	numYears = atoi(linePointer); 
	yearArr = malloc(numYears * sizeof(int));

	//Holds all of the years of team data
	struct annual_stats* allYearData = NULL;

	printf("\n\n");
	if (numYears > 0)
	{
		int curYear = 0;

		allYearData = malloc(numYears * sizeof(struct annual_stats));
		for(int i = 0; i < numYears; i++)
			allYearData[i].teams = malloc(NO_TEAMS * sizeof(struct team_stats));

		for(int i = 0; i < numYears; i++) 
		{
			readLine(linePointer); //Read the year
			curYear = atoi(linePointer);

			printf("Reading Year: %d\n", curYear);	
			allYearData[i].year = curYear;
			yearArr[i] = curYear;

			for (int k = 0; k < NO_TEAMS; k++)
			{
				allYearData[i].teams[k] = processTeamInfo(allYearData[i].teams[k], linePointer);
			}
		}	
	}
	else
		printf("Please lead the data set with a number of years greater than zero");

	return allYearData;
}

/*
 * Calls an external function to sort the data in dataStruct based on the field passed
 * Parameters:
 * 	int year
 * 	char* field - Declares which field in team_stats to sort by
 * 	char* order - Declares whether to sort in ascending or descending order
 * 	struct annual_stats* dataStruct - Holds the data processed from stdin
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
	if(package[0].type == 'c' || package[0].type == 'n')
	{
		bSortChar(package, order);
	}
	else if(package[0].type == 'i')	
	{
		bSortInt(package, order);
	}
	else if(package[0].type == 'f')
	{
		bSortFloat(package, order);
	}
	else
		printf("field unrecognized");
}

/*
 * Sorts the data set, then finds a value based on given item and field
 * Parameters:
 * 	int year
 *	char* field - What to sort by
 *	char* item - Max, Min, Average, Median
 *	struct annual_stats* dataStruct - Data from stdin
 */
void bFind(int year, char* field, char* item, struct annual_stats* dataStruct) //bFind year
{
	int indexOfYear = -1;

	for(int i = 0; i < numYears; i++)
		if(yearArr[i] == year)
			indexOfYear = i;	
	if(indexOfYear == -1)
	{
		printf("Selected year is not in the data set\n");
		return;
	}

	
	struct team_stats* tempStruct = malloc(32 * sizeof(struct team_stats));	
	memcpy(tempStruct, dataStruct[indexOfYear].teams, (32 * sizeof(struct team_stats)));

	printf("\n##### Finding %d %s %s #####\n", year, item, field);

	if(strcmp(field,"team_name") == 0 || strcmp(field,"top_per_game") == 0)
	{
		bFindChar(tempStruct, field, item);
	}
	else if(strcmp(field,"scrimmage_plays") == 0 || strcmp(field,"total_points") == 0 || strcmp(field,"third_md") == 0 
			|| strcmp(field,"third_att") == 0 ||strcmp(field,"third_pct") == 0 || strcmp(field,"games") == 0 
			||  strcmp(field,"fourth_md") == 0 || strcmp(field,"fourth_att") == 0 || strcmp(field,"fourth_pct") == 0 
			|| strcmp(field,"penalties") == 0 || strcmp(field,"pen_yds") == 0 ||  strcmp(field,"fum") == 0 
			|| strcmp(field,"lost") == 0 || strcmp(field,"to") == 0)
	{
		bFindInt(tempStruct, field, item);
	}
	else if(strcmp(field,"pts_per_game") == 0 || strcmp(field,"yds_per_play") == 0 || strcmp(field,"yds_per_game") == 0 || strcmp(field,"first_per_game") == 0)
	{
		bFindFloat(tempStruct, field, item);
	}
	else
		printf("field unrecognized");

	free(tempStruct);
}
/*
void bSortR(int start, int end, char* field, char* order, struct annual_stats* dataStruct) //bSort range
{
	int dif = end - start;
	int* indexOfYear = malloc(dif * sizeof(int));

	for(int i = 0; i < dif; i++)
	{	
		for(int j = 0; j < numYears; j++)
			if(yearArr[j] == start+i)
				indexOfYear[i] = j;	

		if(indexOfYear[i] == -1)
		{
			printf("Selected year is not in the data set\n");
			return;
		}
	}

	char* ord = "Ascending ";
	if(order[0] == 'd')
	       	ord = "Descending";

	printf("\n#######  %d-%d  Ranking by %s  #######\n", start, end, field);
	printf("#######      %s Order       #######\n",ord);

	struct annual_stats* tempStruct = malloc(dif * 32 * sizeof(struct team_stats));	

	for(int i = 0; i < dif; i++)
	{
		for(int j = 0; j < NO_TEAMS; j++)
		{
			tempStruct[i].teams[j] = dataStruct[indexOfYear[i]].teams[j];
		}
	}

	if(strcmp(field,"team_name") == 0)
	{
		bSortCharRange(tempStruct, field, order, dif);
	}
	else if(strcmp(field,"scrimmage_plays") == 0 || strcmp(field,"total_points") == 0 || strcmp(field,"third_md") == 0 
			|| strcmp(field,"third_att") == 0 ||strcmp(field,"third_pct") == 0 || strcmp(field,"games") == 0 
			||  strcmp(field,"fourth_md") == 0 || strcmp(field,"fourth_att") == 0 || strcmp(field,"fourth_pct") == 0 
			|| strcmp(field,"penalties") == 0 || strcmp(field,"pen_yds") == 0 ||  strcmp(field,"fum") == 0 
			|| strcmp(field,"lost") == 0 || strcmp(field,"to") == 0)
	{
		bSortIntRange(tempStruct, field, order, dif);
	}
	else if(strcmp(field,"pts_per_game") == 0 || strcmp(field,"yds_per_play") == 0 || strcmp(field,"yds_per_game") == 0 || strcmp(field,"first_per_game") == 0)
	{
		bSortFloatRange(tempStruct, field, order, dif);
	}
	else
		printf("field unrecognized");

	free(indexOfYear);
	free(tempStruct);
}
*/

/*
 * Break up commands into data that can be passed into the function
 * Parameters:
 * 	char* linePointer - Chooses which command function to call and passes tokens based on this string
 * 	struct annual_stats* dataStruct - Data from stdin
 */
void processCommands(char* linePointer, struct annual_stats* dataStruct)
{
	readLine(linePointer);
	int numOfCommands = atoi(linePointer);
	char delim[2] = " ";

	for (int i = 0; i < numOfCommands; i++)
	{
		readLine(linePointer);
		char* command = strtok(linePointer, delim);

		if(strcmp(command, "bsort") == 0)
		{
			char* temp = strtok(NULL, delim); //Either 2 for year '20xx' or r for 'range'
			if(temp[0] == '2')
			{
				int year = atoi(temp);
				char* field = strtok(NULL,delim);
				char* order = strtok(NULL,delim);

				struct package* package = orderPackage(year, year, field, dataStruct);

				bSortY(package, field, order);
			}
			else if(temp[0] == 'r')
			{
				int start = atoi(strtok(NULL,delim));
				int end = atoi(strtok(NULL,delim));
				char* field = strtok(NULL,delim);
				char* order = strtok(NULL,delim);

				printf("\n\n Sorry, bSort Range is unsupported in this version. Values passed: %d %d %s %s\n", start, end, field, order);
				//orderPackage(start, end, field, dataStruct);
				//bSortR(start, end, field, order, dataStruct);
			}
			else
				printf("Error in calling sort function.\n");
		}
		else if (strcmp(command, "bfind") == 0)
		{
			int year = atoi(strtok(NULL,delim));;
			char* field = strtok(NULL,delim);
			char* item = strtok(NULL,delim);
			//orderPackage(year, year, field, dataStruct);
			//bFind( field, item, dataStruct);
		}
	}
	
}

int main()
{
	char* linePointer = malloc(150); //A typical long line in the sample is 96 chars, 150 should be safe. 

	struct annual_stats* allYearData = processData(linePointer);

	printf("\nRead Successful\n");
	printf("\nProcessing Commands\n");

	processCommands(linePointer, allYearData);

	free(allYearData);
	free(linePointer);
	allYearData = NULL;
	linePointer = NULL;

	return 0;
}
