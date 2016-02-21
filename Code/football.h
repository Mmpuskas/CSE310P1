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

//Bubble sort implementation
void bSortY(struct package* package, char* field, char* order);
void bSortR(struct package* package, char* field, char* order, int yearDif);
void bFind(struct package* package, char* field, char* item);
void bSortChar(struct package* package, int maxIndex);
void bSortInt(struct package* package, int maxIndex);
void bSortFloat(struct package* package, int maxIndex);
//Quick sort implementations
void qSortY(struct package* package, char* field, char* order);
void qSortR(struct package* package, char* field, char* order, int yearDif);
void qFind(struct package* package, char* field, char* item);
void qSortChar(struct package* package, int l, int r);
void qSortInt(struct package* package, int l, int r);
void qSortFloat(struct package* package, int l, int r);
//Parallel Functions
void pMax(struct package* package, char* field);
void pMin(struct package* package, char* field);

#endif /* FOOTBALL_H */
