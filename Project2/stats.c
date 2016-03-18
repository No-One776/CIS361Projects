/** 
 * Author: Justin Rohr
 *
 * Description: Variables and functions for data collection.
 */
#include <stdlib.h>
#include "stats.h"
Stats custStats;
// Total Number of Customers Served, 
// Average length of time waiting in line
// Maximum length of time a customer spent in line 

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
