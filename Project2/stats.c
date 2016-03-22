/** 
 * Author: Justin Rohr
 *
 * Description: Variables and functions for data collection.
 */
#include <stdlib.h>
#include "stats.h"
Stats custStats;

void initializeStats(){
	custStats.totalNumCustServed = 0;
	custStats.totalCustWaitTime = 0;
	custStats.maxCustWaitTime = 0;
	custStats.avgWaitLineLength = 0;
	custStats.maxWaitLineLength = 0;
}

double getAvgWaitTime(){
	return custStats.totalCustWaitTime / custStats.totalNumCustServed;
}

double getMaxWaitTime(){
	return custStats.maxCustWaitTime;
}	

void updateCustWaitTime(double time){
	custStats.totalCustWaitTime += time;
	if (time > custStats.maxCustWaitTime)
		custStats.maxCustWaitTime = time;
}

// Updates the average waiting line length and the max wait line length
void updateWaitLine(int length) {
	custStats.avgWaitLineLength = (custStats.avgWaitLineLength + length) / 2.0;
	if (length > custStats.maxWaitLineLength)
		custStats.maxWaitLineLength = length;
}

double getAverageWaitLineLength() {
	return custStats.avgWaitLineLength;
}

int getMaxWaitLineLength() {
	return custStats.maxWaitLineLength;
}

void updateNumCustServed(int number){
	custStats.totalNumCustServed += number;
}

int getTotalCustServed(){
	return custStats.totalNumCustServed;
}
