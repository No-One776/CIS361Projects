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
	return -mean * log(rand()/RAND_MAX);
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

void simulation (int numOfTellers){
	Queue waitline;
	initialize(&waitline);
	int x, time, data[100];
	double tellers[numOfTellers];
	readArrivingCustData(data);
	for (time = 1; time < WORK_DAY; time++){
		int a = arrivingCustomers(data);
		updateNumCustServed(a);
		for (a = a; a > 0; a--)
			push(time, &waitline);
		for (x = 0; x < numOfTellers; x++){
			if((tellers[x] -=1) < 0){
				int arTime = pop(&waitline);
				updateCustWaitTime(((double)(time - arTime)) - tellers[x]);
				tellers[x] += expdist(AVG_SERVICE);
			}
		}
		updateWaitLine(waitline.cnt);
	}	
}
 
int main () {
	srand(time(NULL));  // Initialize random seed
	int x;
	for (x = 4; x < 8; x++) 
		simulation(x);
	return EXIT_SUCCESS;                       
}
