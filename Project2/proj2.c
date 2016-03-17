/**
 * Author: Justin Rohr
 *
 * Description: Bank teller simulation program that reads a data file giving customer frequency and reports statistics on wait for a varying number of tellers.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "stats.h"
#include "queue.h"

#define AVG_SERVICE 2.0
#define WORK_DAY 480 // Minutes in a work day

double expdist (double mean) {
	double r = rand();
	r /= RAND_MAX;
	return -mean * log(r);
}

int arrivingCustomers(int data[]){
	int r = rand() % 100; // Random between 0-99
	return data[r];
}

void readArrivingCustData(int data[]) {
	FILE *read;
	read = fopen("proj2.dat", "r");
	if (read == NULL) {
		printf("File could not be opened\n");
		exit(1);
	}
	int x, range = 0, count, arriving = 0;
	while (fscanf(read, "%d %d", &arriving, &count) != EOF){
		for (x = range; x < range + count; x++)
			data[x] = arriving;
		range += count;
		printf("Data %d\n", data[x-1]);
	} 
}

void simulation (int numOfTellers){
	Queue waitline;
	initialize(&waitline);
	int time, data[100];
	readArrivingCustData(data);
	for (time = 1; time < WORK_DAY; time++){
		int a = arrivingCustomers(data);
		for (a = a; a > 0; a--)
			push(a, &waitline);
		//Get arriving customers (add to queue)
		//Check busy tellers (Update statistics with those done & 
		// Check all the busy tellers & add non-busy to queue, decrement time for service
	}	
}
 
int main () {
	int data[100];
	readArrivingCustData(data);	
	srand(time(NULL));  // Initialize random seed
	double t;                                     
	t = expdist (AVG_SERVICE);
	int arrCust = arrivingCustomers(data); 
	printf("%f\t%d\n", t, arrCust);
	return EXIT_SUCCESS;                       
}
