/**
 * Author: Justin Rohr
 *
 * Description: Header file definitions for the ceaser cipher breaker.
 */
void readFreq(float given[], char fname[]);
void calcFreq(float found[], char fname[]);
char rotate(char ch, int num);
int findKey(float given[], float found[]);
void decrypt(int key);
