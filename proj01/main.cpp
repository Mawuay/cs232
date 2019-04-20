/* Name: Daniel Ackuaku
 * Date: 7th February 2019.
 * Class: CS 232
 * Project 1: System Calls and Utilities
 *
 *
 *
 */

#include <iostream>
#include <stdlib.h>
#include <string>       	// string to int
#include <stdio.h>
#include <unistd.h>     	// to include fork(), getpid()
#include <sstream>			// stringstream
#include "NanoTimer.h"		// NanaTimer.h
#include <pthread.h>		// pthread
#include <sys/wait.h>		// wait()
using namespace std;

/* *threadHello
 * @param: void *threadid
 * Precondition: None
 * Postcondition: it points to the location of the thread, and prints out the thread ID
 * return: NULL
 */



void *threadHello(void *threadid) {
	cout << "Hello from the child thread ( TID = " << pthread_self() << "  ) "
			<< endl << flush;
	return 0;
}

/* main
 * @param: int argc,
 char* argv[]
 * Precondition: requires commad line input.
 * Postcondition: it runs the program.
 * return: 0
 */
int main(int argc, char* argv[]) {
	bool process = false;
	bool thread = false;
	int repeat = 1;
	string numParse;
	double processAverageTime = 0;
	double threadAverageTime = 0;

	cout
			<< "========================================================================================"
			<< endl;
	cout
			<< "\n++++++++++++++++++++++++++++++++++++++++   START   +++++++++++++++++++++++++++++++++++++++ \n"
			<< endl;

	/* Swtitch controll
	 * @param: None
	 * Precondition:
	 * Postcondition: it evaluates the user input and triggers the bool swtiches to create processes and threads.
	 * return: None
	 */
	for (int i = 1; i < argc; ++i) {

		if (string(argv[i]).substr(0, 2) == "-r") { // The values in the adresses contained in argv[] are converted into strings and compared against the command line switches.
			string holder = string(argv[i]).substr(2, string(argv[i]).length()); // converts the argv[i] into int
			stringstream test(holder);
			test >> repeat;
			if (repeat < 1) {
				repeat = 1;
			}

			cout << "You requested for the computation to be repeated "
					<< repeat << " times." << endl;
		} else if (string(argv[i]) == "-p" || string(argv[i]) == "-process") {
			process = true;
			cout << "You have requested the time needed to create a process."
					<< endl;
		} else if (string(argv[i]) == "-t" || string(argv[i]) == "-thread") {
			thread = true;
			cout << "You have requested the time needed to create a thread."
					<< endl;
		} else {
			cerr << "You have entered an invalid command " << endl;
		}
	}

	/* creating processes
	 * @param: None
	 * Precondition: bool
	 * Postcondition: it evaluates the user input and triggers the bool switches to create processes and threads.
	 * Function: it creates child processes based of of a parent process and evaluates the time needed to do so.
	 * return: 0
	 */
	if (process) {
		NanoTimer timer;
		cout << "The parent PID  = " << getpid() << endl << flush;
		for (int i = 1; i < repeat + 1; i++) {
			timer.start();
			pid_t pid = fork();               //Performs the fork.
			timer.stop();
			processAverageTime += timer.getTotalTime();
			timer.reset();

			if (pid == 0) {
				cout << "Hello from the child process (PID = " << getpid()
						<< " ) " << endl;
				exit(0);
			}

		}
		sleep(1);        // Don't let a parent ending first end the tree below.
		process = false;
		cout << "\nAverage time taken for a process to be created  =  "
				<< (processAverageTime / repeat) << "s \n" << endl;

	}

	/* creating threads
	 * @param: None
	 * Precondition: bool
	 * Postcondition: it evaluates the user input and triggers the bool switches to create processes and threads.
	 * Function: it uses threadHello() method to create child threads based of a parent thread and evaluates the time needed to do so.
	 * return: 0
	 */
	if (thread) {
		NanoTimer timerT;
		pthread_t my_threads;
		for (int i = 0; i < repeat; i++) {
			timerT.start();
			pthread_create(&my_threads, NULL, &threadHello, (void*)my_threads);
			timerT.stop();
			pthread_join(my_threads, NULL); // A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.
			threadAverageTime += timerT.getTotalTime();
			timerT.reset();

		}

		cout << "\nAverage time taken for a thread to be created  =  "
				<< (threadAverageTime / repeat) << "s \n" << endl << flush;
		cout
				<< "\n++++++++++++++++++++++++++++++++++++++++   END   +++++++++++++++++++++++++++++++++++++++ \n"
				<< endl;
		return 0;
	}

}
