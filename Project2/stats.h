struct Stats {
	int totalNumCustServed;
	double totalCustWaitTime;
	double maxCustWaitTime;
	double avgWaitLineLength;
	int maxWaitLineLength;
};

typedef struct Stats 	Stats;

void updateWaitLine(int length);
double getAverageWaitLineLength();
int getMaxWaitLineLength();
