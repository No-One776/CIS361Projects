/** 
 * Author: Justin Rohr
 *
 * Description: Variables and functions for data collection.
 */
#include <stdlib.h>
#include "stats.h"
Stats custStats;
//struct customerStats {
//	int totalNumCustServed = 0;
//	double totalCustWaitTime = 0;
//	double maxCustWaitTime = 0;
//	double avgWaitLineLength = 0;
//	int maxWaitLineLength = 0;
//} custStats;

// Need to hold:
// Total Number of Customers Served, 
// Average length of time waiting in line
// Maximum length of time a customer spent in line 

// Average waiting line length 
// Maximum length of waiting line

// Updates the average waiting line length and the max weight line length as necessary.
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
