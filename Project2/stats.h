struct Stats {
	int totalNumCustServed;
	double totalCustWaitTime;
	double maxCustWaitTime;
	double avgWaitLineLength;
	int maxWaitLineLength;
};

typedef struct Stats 	Stats;

void initializeStats();
double getAvgWaitTime();
double getMaxWaitTime();
void updateCustWaitTime(double time);
void updateWaitLine(int length);
double getAverageWaitLineLength();
int getMaxWaitLineLength();
void updateNumCustServed(int number);
int getTotalCustServed();
