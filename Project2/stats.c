/** 
 * Author: Justin Rohr
 *
 * Description: Variables and functions for data collection.
 */
#include <stdlib.h>
#include "stats.h"
i
struct custStats {
	int totalNumCustServed = 0;
	double totalCustWaitTime = 0;
	double maxCustWaitTime = 0;
	double avgWaitLineLength = 0;
	int maxWaitLineLength = 0;
}
// Need to hold:
// Total Number of Customers Served, 
// Average length of time waiting in line
// Maximum length of time a customer spent in line 

// Average waiting line length 
// Maximum length of waiting line

// Updates the average waiting line length and the max weight line length as necessary.
void updateWaitLine(int length) {
	avgWaitLineLength = (avgWaitLineLength + length) / 2.0;
	if (length > maxWaitLineLength)
		maxWaitLineLength = length;
}

double getAverageWaitLineLength() {
	return avgWaitLineLength;
}

int getMaxWaitLineLength() {
	return maxWaitLineLength;
}
