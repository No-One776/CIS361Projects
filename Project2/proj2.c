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
	return -mean * log(r/RAND_MAX);
}

int arrivingCustomers(int data[]){
	return data[rand() % 100]; 
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
	} 
}

void printStats(){
	printf("\tTotal Number of Customers Served: %d\n", getTotalCustServed());
	printf("\tWait Time => \t\tAverage: %.3f\tMax: %.3f\n", getAvgWaitTime(), getMaxWaitTime());
	printf("\tWait Line Length => \tAverage: %.3f\tMax: %d\n", getAverageWaitLineLength(), getMaxWaitLineLength());
}

void simulation (int numOfTellers){
	printf("\nSimulation started with %d tellers:\n", numOfTellers);
	Queue waitline;
	initialize(&waitline);
	initializeStats();
	int x, time, data[100];
	double tellers[numOfTellers];
	readArrivingCustData(data);
	
	// Main simulation loop that iterates through a day by the minute
	for (time = 1; time < WORK_DAY; time++){
		//Add arriving customers
		int a = arrivingCustomers(data);
		updateNumCustServed(a);
		for (a = a; a > 0; a--)
			push(time, &waitline);
		// Loop through the tellers and update wait and assign customers
		for (x = 0; x < numOfTellers; x++)
			// If a teller is not busy and there are people waiting, service them
			if((tellers[x] < 0 || (tellers[x] -=1.0) < 0) && !empty(&waitline)){ 
				int arTime = pop(&waitline);
				updateCustWaitTime(((double)(time-arTime))-tellers[x]);
				tellers[x] += expdist(AVG_SERVICE);
			}
		updateWaitLine(waitline.cnt);
	}	
	// Simulation is done, print the statistics for the session
	printStats();
}
 
int main () {
	srand(time(NULL));  // Initialize random seed
	int x;
	for (x = 4; x < 8; x++) 
		simulation(x);
	return EXIT_SUCCESS;                       
}
