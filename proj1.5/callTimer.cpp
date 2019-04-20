/* callTimer.cpp evaluates the command-line and launches the reqiutred controller class.
 * author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */

#include "callTimer.h"

callTimer::callTimer() {
	// TODO Auto-generated constructor stub

}


/* getInput()
 * @param: int argc, 
 * 		   char* argv[]
 * Function: Evalutes the command line and launches the appropirate controller class.
 * return: none
 */

void callTimer::getInput(int argc, char* argv[]) {
	for (int i = 1; i < argc; ++i) {

		if (string(argv[1]).substr(0, 3) == "-cl") {
			cout << "You have requested the command Line interface." << endl;
			cmdLineController control;
			control.manipulate(argc, argv);
			break;

		} else {
			cerr << "You have requested the text Menu interface. " << endl;

			textInterface receiver;
			receiver.processInput() ;
		}
	}

}

callTimer::~callTimer() {

}

