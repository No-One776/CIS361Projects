/**
 * Author: Justin Rohr
 *
 * Description: Bank teller simulation program that reads a data file giving customer frequency and reports statistics on wait for a varying number of tellers.
 */

#include <stdlib.h>
#include <math.h>
#define AVG_SERVICE 2.0

Rand double expdist (double mean) {
	double r = rand();
	r /= RAND_MAX;
	return -mean * log(r);
}
 
int main () {
	double t;                                     
	t = expdist (AVG_SERVICE); 
                       
}
