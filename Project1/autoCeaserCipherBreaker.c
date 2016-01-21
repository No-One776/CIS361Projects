/**
 * Author: Justin Rohr
 *
 * Description: The program is an automatic Ceaser cipher breaker that uses a Letter Frequency file to then crack the code for Ceaser ciphers. Input is a encrypted file to be cracked and to display the decoded text once done.
 */
include <stdio.h>
include <stdlib.h>
include <ctype.h>
include <autoCeaserCipherBreaker.h>

int main (){

	return EXIT_SUCCESS;
}

// Load array given with the letter frequencies for English from file LetFreq.txt
void readFreq(float given[], char fname[]){

}

// Read the encoded text from an input file and accumulate the letter frequency
// data for the encoded text. Store the frequency data in array found.
void calcFreq(float found[], char fname[]){

}

// Rotate the character in parameter ch down the alphabet for the number of
// positions as given in parameter num and return the resulting character.
char rotate(char ch, int num){

}

// Compare the data in array found with the frequency data in array given, looking
// for a key that will give you the best match. To do this, try each of the 26 rotations,
// and remember which gives the smallest difference between the frequencies you
// observed and the frequencies given. Return the key.
int findKey(float given[], float found[]){

}

// Decrypt the encoded text in the input file using the key and display the decoded text
void decrypt(int key){

}

