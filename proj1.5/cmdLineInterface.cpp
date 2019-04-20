/* cmdLineInterface.cpp receives and sends I/O to the user.
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */
#include "cmdLineInterface.h"


/* constructor
 * @param: void
 * function: instantiates the repeat variable
 * return: NULL
 */
cmdLineInterface::cmdLineInterface() { // @suppress("Class members should be properly initialized")
	repeat = 1;

}

/* processInput()
 * @param: int argc, 
 * 		   char* argv[]
 * Function: Evalutes the command line and triggers the appropirate switches.
 * return: none
 */
void cmdLineInterface::processInput(int argc, char* argv[]) {

	for (int i = 2; i < argc; ++i) {

		if (string(argv[i]).substr(0, 2) == "-r") { // The values in the adresses contained in argv[] are converted into strings and compared against the command line switches.
			string holder = string(argv[i]).substr(2, string(argv[i]).length()); // converts the argv[i] into int
			stringstream test(holder);
			test >> repeat;
			if (repeat < 1) {
				repeat = 1;
			}

			cout << "You requested for the computation(s) to be repeated "
					<< repeat << " times." << endl;
		}

		else if (string(argv[i]) == "-p" || string(argv[i]) == "-process") {
			process = true;
			cout << "You have requested the average time needed to create a process."
					<< endl;
		} else if (string(argv[i]) == "-t" || string(argv[i]) == "-thread") {
			thread = true;
			cout << "You have requested the average time needed to create a thread."
					<< endl;
		} else {
			cerr << string(argv[i]) << "  You have entered an invalid command "
					<< endl;
		}
	}

	cout << "\n" << endl;

}


/* displayProcessResults()
 * @param: none
 * Function: Displays the process id 
 * return: none
 */
void cmdLineInterface::displayProcessResults() {
	// cout << "\a" << endl;
	cout << "Hello from the child process (PID = " << getpid() << " ) " << endl;

}

/* displayThreadResults()
 * @param: none
 * Function: Displays the thread id 
 * return: none
 */
void cmdLineInterface::displayThreadResults(){
	cout << "Hello from the child thread ( TID = " << pthread_self() << " ) "
			<< endl << flush;
}

/* displayProcessTime()
 * @param:  double processTime
 * Function: Displays the average time to create n processes 
 * return: none
 */
void cmdLineInterface::displayProcessTime( double processTime) {

	cout << "\nAverage time taken for a process to be created  =  " << processTime << "s \n" << endl;

}

/* displayThreadTime()
 * @param:  double threadTime
 * Function: Displays the average time to create n threads 
 * return: none
 */
void cmdLineInterface::displayThreadTime( double threadTime) {
	cout << "\nAverage time taken for a thread to be created  =  " << threadTime << "s \n" << endl;
}


/* destructor
 * @param: void
 * return: NULL
 */
cmdLineInterface::~cmdLineInterface() {
	// TODO Auto-generated destructor stub
}

