/*
 * Michael Puskas
 * Header file for CSE310 Project 1
 * 2/1/2016
 */

#ifndef FOOTBALL_H 
#define FOOTBALL_H

#define NO_TEAMS      32 // Number of NFL teams
#define TEAM_NAME_LEN 25 // Maximum team name string length
#define TOP_LEN        6 // Maximum time of possession string length

//Struct to hold data after being read from stdin
struct team_stats {
	char team_name[TEAM_NAME_LEN]; // Name of NFL team
	int games; // Number of games played in the season
	float pts_per_game; // Points per game
	int total_points; // Total points
	int scrimmage_plays; // Scrimmage plays
	float yds_per_game; // Yards per game
	float yds_per_play; // Yards per play
	float first_per_game; // First downs per game
	int third_md; // Third down conversions
	int third_att; // Third down attempts
	int third_pct; // Third down percentage
	int fourth_md; // Fourth down conversions
	int fourth_att; // Fourth down attempts
	int fourth_pct; // Fourth down percentage
	int penalties; // Number of penalties
	int pen_yds; // Penalty yards
	char top_per_game[TOP_LEN]; // Time of possession per game
	int fum; // Number of fumbles
	int lost; // Fumbles lost
	int to; // Turnover ratio
};
//Struct to hold multiple years worth of data
struct annual_stats {
	int year;
	struct team_stats* teams;
};
//Interstitial struct to hold the single relevant field of data based on the command given.
struct package {
	char team_name[TEAM_NAME_LEN];
	union Field{
		int i;
		float f;
		char c[TEAM_NAME_LEN];
	}field;
	int year;
	char type;
};

//Below are bubble sort implementations to sort various data types, sort then find, and sort larger ranges of data
void bSortChar(struct package* package, int maxIndex);
void bSortInt(struct package* package, int maxIndex);
void bSortFloat(struct package* package, int maxIndex);
void bSortY(struct package* package, char* field, char* order);
void bFind(struct package* package, char* field, char* item);
void bSortCharRange(struct annual_stats* teamStruct, char* field, char* order, int length);
void bSortIntRange(struct annual_stats* teamStruct, char* field, char* order, int length);
void bSortFloatRange(struct annual_stats* teamStruct, char* field, char* order, int length);


#endif /* FOOTBALL_H */
