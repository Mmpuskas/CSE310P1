/*
 * Michael Puskas
 * Source code file for bubble sort-based find function
 * 2/1/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "football.h"

#define NO_TEAMS      32 // Number of NFL teams
#define TEAM_NAME_LEN 25 // Maximum team name string length
#define TOP_LEN        6 // Maximum time of possession string length

//Sorts structure using bubble sort, then chooses entry based on item
void bFindChar(struct team_stats* teamStruct, char* field, char* item)
{
	if(strcmp(field,"team_name") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)
			{
				if(strcmp(teamStruct[i].team_name,teamStruct[j].team_name) > 0)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];	
					teamStruct[j] = temp;
				}
			}
		}

		if(strcmp(item, "max") == 0)
			printf("Max Found.\nMax Value for %s: %s\n", field, teamStruct[0].team_name);
		else if(strcmp(item, "min") == 0)
			printf("Min Found.\nMin Value for %s: %s\n", field, teamStruct[NO_TEAMS - 1].team_name);
		else if(strcmp(item, "average") == 0)
			printf("Average is undefined for team names.");
		else if(strcmp(item, "median") == 0)
			printf("median is undefined for team names.");
	}	
	else if(strcmp(field,"top_per_game") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)
			{
				if(strcmp(teamStruct[i].top_per_game,teamStruct[j].top_per_game) > 0)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];	
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("Max Found.\nMax Value for %s: %s\n", field, teamStruct[0].top_per_game);
		else if(strcmp(item, "min") == 0)
			printf("Min Found.\nMin Value for %s: %s\n", field, teamStruct[NO_TEAMS - 1].top_per_game);
		else if(strcmp(item, "average") == 0)
		{
			for(int i = 0; i < NO_TEAMS; i++)
			{
				teamStruct[i].top_per_game[0] = ' ';
				teamStruct[i].top_per_game[3] = '.';
			}
			float av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += atof(teamStruct[i].top_per_game);
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%s\n", field, teamStruct[NO_TEAMS / 2].top_per_game);
		}
	}

}

//Sorts structure using bubble sort, then chooses entry based on item
void bFindInt(struct team_stats* teamStruct, char* field, char* item)
{
	if(strcmp(field,"games") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].games < teamStruct[j].games)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].games);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].games);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].games;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].games);
		}
	}
	
	else if(strcmp(field,"total_points") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].total_points < teamStruct[j].total_points)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].total_points);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].total_points);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].total_points;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].total_points);
		}
	}
	else if(strcmp(field,"scrimmage_plays") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].scrimmage_plays < teamStruct[j].scrimmage_plays)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].scrimmage_plays);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].scrimmage_plays);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].scrimmage_plays;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].scrimmage_plays);
		}
	}
	else if(strcmp(field,"third_md") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].third_md < teamStruct[j].third_md)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].third_md);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].third_md);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].third_md;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].third_md);
		}
	}
	else if(strcmp(field,"third_att") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].third_att < teamStruct[j].third_att)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].third_att);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].third_att);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].third_att;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].third_att);
		}
	}
	else if(strcmp(field,"third_pct") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].third_pct < teamStruct[j].third_pct)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].third_pct);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].third_pct);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].third_pct;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].third_pct);
		}
	}
	else if(strcmp(field,"fourth_md") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].fourth_md < teamStruct[j].fourth_md)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].fourth_md);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].fourth_md);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].fourth_md;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].fourth_md);
		}
	}
	else if(strcmp(field,"fourth_att") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].fourth_att < teamStruct[j].fourth_att)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].fourth_att);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].fourth_att);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].fourth_att;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].fourth_att);
		}
	}
	else if(strcmp(field,"fourth_pct") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].fourth_pct < teamStruct[j].fourth_pct)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].fourth_pct);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].fourth_pct);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].fourth_pct;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].fourth_pct);
		}
	}
	else if(strcmp(field,"penalties") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].penalties < teamStruct[j].penalties)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].penalties);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].penalties);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].penalties;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n.\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].penalties);
		}
	}
	else if(strcmp(field,"pen_yds") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].pen_yds < teamStruct[j].pen_yds)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].pen_yds);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].pen_yds);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].pen_yds;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].pen_yds);
		}
	}
	else if(strcmp(field,"fum") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].fum < teamStruct[j].fum)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].fum);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].fum);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].fum;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].fum);
		}
	}
	else if(strcmp(field,"lost") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].lost < teamStruct[j].penalties)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].lost);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].lost);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].lost;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].lost);
		}
	}
	else if(strcmp(field,"to") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].to < teamStruct[j].to)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
				
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[0].team_name, teamStruct[0].to);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].to);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].to;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3d\n", field, teamStruct[NO_TEAMS / 2].to);
		}
	}
	
}

void bFindFloat(struct team_stats* teamStruct, char* field, char* item)
{
	if(strcmp(field,"pts_per_game") == 0) 
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].pts_per_game < teamStruct[j].pts_per_game)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3.2ff\n", field, 1, teamStruct[0].team_name, teamStruct[0].pts_per_game);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3.2f\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].pts_per_game);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].pts_per_game;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3.2f\n", field, teamStruct[NO_TEAMS / 2].pts_per_game);
		}
	}
	else if (strcmp(field,"yds_per_game") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].yds_per_game < teamStruct[j].yds_per_game)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3.2f\n", field, 1, teamStruct[0].team_name, teamStruct[0].yds_per_game);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n.\t\t%-3.2f\n", field, teamStruct[NO_TEAMS-1].yds_per_game);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].yds_per_game;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3.2f\n", field, teamStruct[NO_TEAMS / 2].yds_per_game);
		}
	}
       	else if(strcmp(field,"yds_per_play") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].yds_per_play < teamStruct[j].yds_per_play)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3.2f\n", field, 1, teamStruct[0].team_name, teamStruct[0].yds_per_play);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3.2f\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].yds_per_play);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].yds_per_play;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3.2f\n", field, teamStruct[NO_TEAMS / 2].yds_per_play);
		}
	}
       	else if(strcmp(field,"first_per_game") == 0)
	{
		for(int i = 0; i < NO_TEAMS - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS; j++)	
			{
				if(teamStruct[i].first_per_game < teamStruct[j].first_per_game)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(strcmp(item, "max") == 0)
			printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3.2f\n", field, 1, teamStruct[0].team_name, teamStruct[0].first_per_game);
		else if(strcmp(item, "min") == 0)
			printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3.2f\n", field, 1, teamStruct[NO_TEAMS-1].team_name, teamStruct[NO_TEAMS-1].first_per_game);
		else if(strcmp(item, "average") == 0)
		{
			int av = 0;
			for(int i = 0; i < NO_TEAMS; i++)
				av += teamStruct[i].first_per_game;
			float avF = av / NO_TEAMS;
			printf("##### Average Found for %s #####\n\t\t%3.1f\n", field, avF);
		}
		else if(strcmp(item, "median") == 0)
		{
			printf("##### Median Found for %s #####\n\t\t%-3.2f\n", field, teamStruct[NO_TEAMS / 2].first_per_game);
		}
	}
}
