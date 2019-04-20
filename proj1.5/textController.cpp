/* textController.cpp evaluates the text menu option,
 *  calls the model class to excecute them, and calls the textInterface class to dispaly them..
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */

#include "textController.h"
#include "callTimer.h"

model run2;
textInterface view2;

/* constructor
 * @param: void
 * function: instantiates the bools processTxt and threadTxt.
 * return: NULL
 */
textController::textController() {
	processTxt = false;
	threadTxt = false;
}

/* processCalculate()
 * @param: int reps
 * Function: Calls the model class for processCalculate() to be executed.
 * return: none
 * for some reason my textinterface process calculate only performs the function once.
 */
void textController::processCalculate(int reps) {
    model test;
	textInterface input;
	if (input.gettxtProcess()) {

	pid_t pid = test.processCalculate(input.getRepeat());
		if (pid == 0) {
			processTxt = false;
			return ;
		}

	}
	

}

/* threadCalculate()
 * @param: int reps
 * Function: Calls the model class for threadCalculate() to be executed.
 * return: none
 * for some reason my textinterface process calculate only performs the function once.
 */
void textController::threadCalculate(int reps) {
	
	run2.threadCalculate(reps);
	threadTxt = false;
}

/* pTCalculate()
 * @param: int reps
 * Function: Calls the model class for processCalculate() and threadCalculate() to be executed.
 * return: none
 * for some reason my textinterface process calculate only performs the function once.
 */
void textController::pTCalculate(int reps) {

run2.threadCalculate(reps);
	pid_t pid = run2.processCalculate(reps);
		if (pid == 0) {
			processTxt = false;
			// return;
		}

}


/* receivePID()
 * @param: none
 * Function: Receives the process id from the model class 
 * return: none
 */
void textController::receivePID(){

	view2.displayProcessResults();

}


/* receiveProcessTime()
 * @param: double processTime
 * Function: Receives the average time taken for n processes to be creaated. 
 * return: processTime
 */
double textController::receiveProcessTime( double processTime){

	view2.displayProcessTime(processTime);

	return processTime;
}

/* destructor
 * @param: void
 * return: NULL
 */
textController::~textController() {
	
}

