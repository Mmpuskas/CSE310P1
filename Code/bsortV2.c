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
void bSortChar(struct team_stats* teamStruct, char* field, char* order)
{
	//All conditional statements in this file follow the same format
	if(strcmp(field,"team_name") == 0) //Check field
	{
		//Bubble sort
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
		//Output sorted data based on order
		if(order[0] == 'i')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t\n", i+1, teamStruct[i].team_name);
		else if(order[0] == 'd')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t\n", i+1, teamStruct[i].team_name);
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
		if(order[0] == 'i')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%s\n", i+1, teamStruct[i].team_name, teamStruct[i].top_per_game);
		else if(order[0] == 'd')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%s\n", i+1, teamStruct[i].team_name, teamStruct[i].top_per_game);
	}
}

//Bubble sort for Integers
void bSortInt(struct team_stats* teamStruct, char* field, char* order)
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].games);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].games);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].total_points);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].total_points);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].scrimmage_plays);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].scrimmage_plays);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_md);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_md);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_att);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_att);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_pct);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_pct);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_md);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_md);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_att);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_att);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_pct);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_pct);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].penalties);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].penalties);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].pen_yds);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].pen_yds);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fum);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fum);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].lost);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].lost);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].to);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].to);
	}
}

//Bubble sort for Floats
void bSortFloat(struct team_stats* teamStruct, char* field, char* order)
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].pts_per_game);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].pts_per_game);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].yds_per_game);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].yds_per_game);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].yds_per_play);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].yds_per_play);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].first_per_game);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].first_per_game);
	}
}
//Broken code for sorting Range
/*
void bSortCharRange(struct annual_stats* teamStruct, char* field, char* order)
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
		if(order[0] == 'i')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t\n", i+1, teamStruct[i].team_name);
		else if(order[0] == 'd')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t\n", i+1, teamStruct[i].team_name);
	}	

}


void bSortIntRange(struct annual_stats* teamStruct, char* field, char* order, int length)
{
	if(strcmp(field,"games") == 0)
	{
		for(int i = 0; i < NO_TEAMS * length - 1; i++)
		{
			for(int j = i+1; j < NO_TEAMS * length; j++)	
			{
				if(teamStruct[i].teams.games < teamStruct[j].games)
				{
					struct team_stats temp = teamStruct[i];
					teamStruct[i] = teamStruct[j];
					teamStruct[j] = temp;
				}
			}
		}
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].games);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].games);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].total_points);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].total_points);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].scrimmage_plays);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].scrimmage_plays);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_md);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_md);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_att);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_att);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_pct);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].third_pct);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_md);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_md);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_att);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_att);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_pct);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fourth_pct);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].penalties);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].penalties);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].pen_yds);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].pen_yds);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fum);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].fum);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].lost);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].lost);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].to);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3d\n", i+1, teamStruct[i].team_name, teamStruct[i].to);
	}
	
}

void bSortFloatRange(struct annual_stats* teamStruct, char* field, char* order)
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].pts_per_game);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].pts_per_game);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].yds_per_game);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].yds_per_game);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].yds_per_play);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].yds_per_play);
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
		if(order[0] == 'd')
			for(int i = 0; i < NO_TEAMS; i++)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].first_per_game);
		else if(order[0] == 'i')
			for(int i = NO_TEAMS-1; i >= 0; i--)
				printf("%2d.\t%-25s\t%-3.1f\n", i+1, teamStruct[i].team_name, teamStruct[i].first_per_game);
	}
}
*/
