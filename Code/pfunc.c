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

int pMaxChar(struct package* package, int l, int r)
{
	int m1 = 0, m2 = 0;
	if((r - l + 1) == 1)
		return l;
	if((r - l + 1) == 2)
		return (strcmp(package[l].field.c, package[l+1].field.c) < 0) ? l : l+1;
	int mid = (r + l) / 2;
	
	#pragma omp task shared(m1)
	m1 = pMaxChar(package, l, mid);
	#pragma omp task shared(m2)
	m2 = pMaxChar(package, mid + 1, r);
	#pragma omp taskwait
	return (strcmp(package[m1].field.c, package[m2].field.c) < 0) ? m1 : m2;
}
int pMaxInt(struct package* package, int l, int r)
{
	int m1 = 0, m2 = 0;
	if((r - l + 1) == 1)
		return l;
	if((r - l + 1) == 2)
		return (package[l].field.i > package[l+1].field.i) ? l : l+1;
	int mid = (r + l) / 2;

	#pragma omp task shared(m1)
	m1 = pMaxInt(package, l, mid);
	#pragma omp task shared(m2)
	m2 = pMaxInt(package, mid + 1, r);
	#pragma omp taskwait
	return (package[m1].field.i > package[m2].field.i) ? m1 : m2;
}
int pMaxFloat(struct package* package, int l, int r)
{
	int m1 = 0, m2 = 0;
	if((r - l + 1) == 1)
		return l;
	if((r - l + 1) == 2)
		return (package[l].field.f > package[l+1].field.f) ? l : l+1;
	int mid = (r + l) / 2;

	#pragma omp task shared(m1)
	m1 = pMaxInt(package, l, mid);
	#pragma omp task shared(m2)
	m2 = pMaxInt(package, mid + 1, r);
	#pragma omp taskwait
	return (package[m1].field.f > package[m2].field.f) ? m1 : m2;
}
void pMax(struct package* package, char* field)
{
	printf("\n##### Finding %d %s %s #####\n", package[0].year, "max", field);

	if(package[0].type == 'n') //Specific name condition because the formatting is different on the print
	{
		int maxInd = pMaxChar(package, 0, NO_TEAMS - 1);
		printf("##### Max Found for %s #####\nMax Value for %s: %s\n", field, field, package[maxInd].team_name);
	}
	else if(package[0].type == 'c') //Char
	{
		int maxInd = pMaxChar(package, 0, NO_TEAMS - 1);
		printf("##### Max Found for %s #####\nMax Value for %s: %s\n", field, field, package[maxInd].field.c);
	}
	else if(package[0].type == 'i') //Int	
	{
		int maxInd = pMaxInt(package, 0, NO_TEAMS - 1);
		printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, package[maxInd].team_name, package[maxInd].field.i);
	}
	else if(package[0].type == 'f') //Float
	{
		int maxInd = pMaxFloat(package, 0, NO_TEAMS - 1);
		printf("##### Max Found for %s #####\n%2d.\t%-25s\t%-3.1f\n", field, 1, package[maxInd].team_name, package[maxInd].field.f);
	}
	else
		printf("field unrecognized");
}
int pMinChar(struct package* package, int l, int r)
{
	int m1 = 0, m2 = 0;
	if((r - l + 1) == 1)
		return l;
	if((r - l + 1) == 2)
		return (strcmp(package[l].field.c, package[l+1].field.c) > 0) ? l : l+1;
	int mid = (r + l) / 2;
	
	#pragma omp task shared(m1)
	m1 = pMinChar(package, l, mid);
	#pragma omp task shared(m2)
	m2 = pMinChar(package, mid + 1, r);
	#pragma omp taskwait
	return (strcmp(package[m1].field.c, package[m2].field.c) > 0) ? m1 : m2;
}
int pMinInt(struct package* package, int l, int r)
{
	int m1 = 0, m2 = 0;
	if((r - l + 1) == 1)
		return l;
	if((r - l + 1) == 2)
		return (package[l].field.i < package[l+1].field.i) ? l : l+1;
	int mid = (r + l) / 2;

	#pragma omp task shared(m1)
	m1 = pMinInt(package, l, mid);
	#pragma omp task shared(m2)
	m2 = pMinInt(package, mid + 1, r);
	#pragma omp taskwait
	return (package[m1].field.i < package[m2].field.i) ? m1 : m2;
}
int pMinFloat(struct package* package, int l, int r)
{
	int m1 = 0, m2 = 0;
	if((r - l + 1) == 1)
		return l;
	if((r - l + 1) == 2)
		return (package[l].field.f < package[l+1].field.f) ? l : l+1;
	int mid = (r + l) / 2;

	#pragma omp task shared(m1)
	m1 = pMinInt(package, l, mid);
	#pragma omp task shared(m2)
	m2 = pMinInt(package, mid + 1, r);
	#pragma omp taskwait
	return (package[m1].field.f < package[m2].field.f) ? m1 : m2;
}
void pMin(struct package* package, char* field)
{
	printf("\n##### Finding %d %s %s #####\n", package[0].year, "min", field);

	if(package[0].type == 'n') //Specific name condition because the formatting is different on the print
	{
		int maxInd = pMinChar(package, 0, NO_TEAMS - 1);
		printf("##### Min Found for %s #####\nMin Value for %s: %s\n", field, field, package[maxInd].team_name);
	}
	else if(package[0].type == 'c') //Char
	{
		int maxInd = pMinChar(package, 0, NO_TEAMS - 1);
		printf("##### Min Found for %s #####\nMin Value for %s: %s\n", field, field, package[maxInd].field.c);
	}
	else if(package[0].type == 'i') //Int	
	{
		int maxInd = pMinInt(package, 0, NO_TEAMS - 1);
		printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3d\n", field, 1, package[maxInd].team_name, package[maxInd].field.i);
	}
	else if(package[0].type == 'f') //Float
	{
		int maxInd = pMinFloat(package, 0, NO_TEAMS - 1);
		printf("##### Min Found for %s #####\n%2d.\t%-25s\t%-3.1f\n", field, 1, package[maxInd].team_name, package[maxInd].field.f);
	}
	else
		printf("field unrecognized");
}
