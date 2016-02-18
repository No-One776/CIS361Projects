/** 
 * Author: Justin Rohr
 *
 * Description: Variables and functions for data collection.
 */
#include <stdlib>
struct customer {
	int totalNumCustServed = 0;
	double totalCustWaitTime = 0;
	double maxCustWaitTime = 0;
}
// Need to hold:
// Total Number of Customers Served, 
// Average length of time waiting in line
// Maximum length of time a customer spent in line 

// Average waiting line length 
// Maximum length of waiting line
double avgWaitLineLength = 0;
int maxWaitLineLength = 0;

// Updates the average waiting line length and the max weight line length as necessary.
void updateWaitLine(int length){
	avgWaitLineLength = (avgWaitLineLength + length) / 2;
	if (length > maxWaitLineLength)
		maxWaitLineLength = length;
}

double getAverageWaitLineLength(){
	return avgWaitLineLength;
}
