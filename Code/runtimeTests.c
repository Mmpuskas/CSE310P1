/*
 * Program for testing the runtime of bsort, qsort, and pmax 
 *      as specified in the project 1 part 3 specifications.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bsort.c"
#include "qsort.c"
#include "pfunc.c"
#include "football.h"

/* Tests the runtime of bSort function
 * Parameters: 
 * 	int n - Size of data set to sort. (Will be filled with n random values)
 * Return:
 * 	Returns the time spent sorting (Based on time.h clock function)
 */
double testBSort(int n)
{
	struct package* dataArr = malloc(n * sizeof(struct package));	
	srand( (unsigned) time(NULL) );

	for(int i = 0; i < n; i++)
		dataArr[i].field.i = rand() % 100000;

	int start = clock();
	bSortInt(dataArr, n);
	int end = clock();

	free(dataArr);
	return (double)(end - start) / CLOCKS_PER_SEC;
}

/* Tests the runtime of qSort function
 * Parameters: 
 * 	int n - Size of data set to sort. (Will be filled with n random values)
 * Return:
 * 	Returns the time spent sorting (Based on time.h clock function)
 */
double testQSort(int n)
{
	struct package* dataArr = malloc(n * sizeof(struct package));	
	srand( (unsigned) time(NULL) );

	for(int i = 0; i < n; i++)
		dataArr[i].field.i = rand() % 100000;

	int start = clock();
	qSortInt(dataArr, 0,  n - 1);
	int end = clock();

	free(dataArr);
	return (double)(end - start) / CLOCKS_PER_SEC;
}

/* Tests the runtime of qSort function
 * Parameters: 
 * 	int n - Size of data set to sort. (Will be filled with n random values)
 * Return:
 * 	Returns the time spent sorting (Based on time.h clock function)
 */
double testPMax(int n)
{
	struct package* dataArr = malloc(n * sizeof(struct package));	
	srand( (unsigned) time(NULL) );

	for(int i = 0; i < n; i++)
		dataArr[i].field.i = rand() % 100000;

	int start = clock();
	pMaxInt(dataArr, 0,  n - 1);
	int end = clock();

	free(dataArr);
	return (double)(end - start) / CLOCKS_PER_SEC;
}

int main()
{
	double b10 = testBSort(10);
	double b100 = testBSort(100);
	double b1000 = testBSort(1000);
	double b10000 = testBSort(10000);
	//double b100000 = testBSort(100000);
	//double b1000000 = testBSort(1000000);

	double q10 = testQSort(10);
	double q100 = testQSort(100);
	double q1000 = testQSort(1000);
	double q10000 = testQSort(10000);
	//double q100000 = testQSort(100000);
	//double q1000000 = testQSort(1000000);

	printf("Time spent running Bubble Sort on n = 10: %fs\n", b10);
	printf("Time spent running Bubble Sort on n = 100: %fs\n", b100);
	printf("Time spent running Bubble Sort on n = 1000: %fs\n", b1000);
	printf("Time spent running Bubble Sort on n = 10000: %fs\n", b10000);
	//printf("Time spent running Bubble Sort on n = 100000: %fs\n", b100000);
	//printf("Time spent running Bubble Sort on n = 1000000: %fs\n", b1000000);


	printf("Time spent running Quick Sort on n = 10: %fs\n", q10);
	printf("Time spent running Quick Sort on n = 100: %fs\n", q100);
	printf("Time spent running Quick Sort on n = 1000: %fs\n", q1000);
	printf("Time spent running Quick Sort on n = 10000: %fs\n", q10000);
	//printf("Time spent running Quick Sort on n = 100000: %fs\n", q100000);
	//printf("Time spent running Quick Sort on n = 1000000: %fs\n", q1000000);

	//bFind max and qFind max make a call to bSort and qSort respectively, then make an O(1) print statement to display the max. 
	//Because of this, I will be reusing the time values from the previous bSort and qSort to avoid the unnecessary print statements.
	double p10 = testPMax(10);
	double p100 = testPMax(100);
	double p1000 = testPMax(1000);
	double p10000 = testPMax(10000);
	//double p100000 = testPMax(100000);
	//double p1000000 = testPMax(1000000);
	testPMax(10);
	
	printf("Time spent running Parallel Max on n = 10: %fs\n", p10);
	printf("Time spent running Parallel Max on n = 100: %fs\n", p100);
	printf("Time spent running Parallel Max on n = 1000: %fs\n", p1000);
	printf("Time spent running Parallel Max on n = 10000: %fs\n", p10000);
	//printf("Time spent running Parallel Max on n = 100000: %fs\n", p100000);
	//printf("Time spent running Parallel Max on n = 1000000: %fs\n", p1000000);
	
	return 0;
}
