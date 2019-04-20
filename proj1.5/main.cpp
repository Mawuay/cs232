/* Name: Daniel Ackuaku
 * Date: 28th February 2019.
 * Class: CS 232
 * Project 1.5 : User Interfaces and Reuseable Code
 */

#include "callTimer.h"

/* main
 * @param: int argc, char* argv[]
 * Precondition: requires commad line input.
 * Postcondition: it runs the program.
 * return: 0
 */
int main(int argc, char* argv[]) {
	cout << "________________________________________________________________________" << endl;
	cout << "\n                               Welcome !                                " << endl;
	cout << "________________________________________________________________________" << endl;
	
// Instantiates the callTimer class to handle the rest of program.
	callTimer program;
	program.getInput(argc, argv);


}

