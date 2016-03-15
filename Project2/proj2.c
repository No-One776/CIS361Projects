/**
 * Author: Justin Rohr
 *
 * Description: Bank teller simulation program that reads a data file giving customer frequency and reports statistics on wait for a varying number of tellers.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stats.h"
#include "queue.h"
#define AVG_SERVICE 2.0
#define WORK_DAY 480 // Minutes in a work day

double expdist (double mean) {
	double r = rand();
	r /= RAND_MAX;
	return -mean * log(r);
}

int arrivingCustomers(){
	// Use the data input & a rand to get how many customers arrive now
	int r = rand() % 100;
	return r;
}

void simulation (int numOfTellers){
	int time;
	for (time = 1; time < WORK_DAY; time++){
		// Add a new round of arrivingCustomers to queue and assign as possible
		// Check all the busy tellers & add non-busy to queue, decrement time for service
	}	
}
 
int main () {
	double t;                                     
	t = expdist (AVG_SERVICE);
	int arrCust = arrivingCustomers(); 
	printf("%f\t%d\n", t, arrCust);
	return EXIT_SUCCESS;                       
}
