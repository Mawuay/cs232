/* textInterface.cpp receives and sends I/O to the user.
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */
#include "textInterface.h"
//#include <string>


/* constructor
 * @param: void
 * function: instantiates the repeat variable
 * return: NULL
 */
textInterface::textInterface() {
	// TODO Auto-generated constructor stub

}


/* processInput()
 * @param: none
 * Function: Launches a switch case menu that evalutes user input.
 * return: none
 */
void textInterface::processInput() {
	string menuCommand;
	while (menuCommand != "0") {
	 cout << "\nWelcome to the Text Interface Manager! " << endl;
	 cout << "\nPlease enter:" << endl;
	 cout << "   1 - to calculate the average time needed to create a process" << endl;
     cout << "   2 - to calculate the average time needed to create a thread" << endl;
     cout << "   3 - to to calculate the average time needed to create a process and a thread simultaneosly" << endl;
     cout << "   0 - to quit" << endl;
	 cout << "--->  "	<< endl;

	 
	 cin >> menuCommand;
	 cin.ignore();

	 	if (menuCommand == "1") {
			processTxt = true;
			cout << "You have requested the average time needed to create a process: " << flush;
			cout << "How many times would you want this to be repeated: " << flush;
			cin >> reps;
			cin.ignore();
			if (reps < 1 ) {
				cerr << " The number of times you entered is invalid" << endl;
				cout << "How many times would you want this to be repeated: " << flush;
				cin >> reps;
				cin.ignore();
			}
			cout << "You requested for the operation to be repeated " << reps << " times" << endl;

			textController process;
			process.processCalculate(reps);

			processTxt = false;

		}

		else if (menuCommand == "2") {
			threadTxt = true;
			cout << "You have requested the average time needed to create a thread: " << flush;
			cout << "How many times would you want this to be repeated: " << flush;
			cin >> reps;
			cin.ignore();
			if (reps < 1 ) {
				cerr << " The number of times you entered is invalid" << endl;
				cout << "How many times would you want this to be repeated: " << flush;
				cin >> reps;
				cin.ignore();
			}
			cout << "You requested for the operation to be repeated " << reps << " times" << endl;

			textController thread;
			thread.threadCalculate(reps);

			threadTxt = false;

		}

		else if (menuCommand == "3") {
			processAndThread = true;
			cout << "You have requested the average time needed to create a process and a  thread: " << flush;
			cout << "How many times would you want this to be repeated: " << flush;
			cin >> reps;
			cin.ignore();
			if (reps < 1 ) {
				cerr << " The number of times you entered is invalid" << endl;
				cout << "How many times would you want this to be repeated: " << flush;
				cin >> reps;
				cin.ignore();
			}
			cout << "You requested for the operation to be repeated " << reps << " times" << endl;

			textController both;
			both.pTCalculate(reps);

			processAndThread = false;

		}
		else if (menuCommand == "0") {
			processAndThread = true;
			cout << "You have requested to exit the program......" << endl;
			cout << "________________________________________________________________________" << endl;
			cout << "\n                               GoodBye !                              " << endl;
			cout << "________________________________________________________________________" << endl;
			break;

		}
		else {
			cerr << "\nYou've entered an invalid command !! " << endl;
		}



	}
	
}

/* displayProcessTime()
 * @param:  double processTime
 * Function: Displays the average time to create n processes 
 * return: none
 */
void textInterface::displayProcessTime( double processTime) {

	cout << "\nAverage time taken for a process to be created  =  " << processTime << "s \n" << endl;

}

void textInterface::displayProcessResults() {
	// cout << "\a" << endl;
	cout << "Hello from the child process (PID = " << getpid() << " ) " << endl;

}

/* destructor
 * @param: void
 * return: NULL
 */
textInterface::~textInterface() {
	// TODO Auto-generated destructor stub
}




