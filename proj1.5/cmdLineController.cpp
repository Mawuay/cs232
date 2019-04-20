/* cmdLineController.cpp evaluates the command-line instructions,
 * calls the model class to excecute them, calls the cmdInterface class to dispaly them..
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */

#include "cmdLineController.h"
#include "callTimer.h"




model run;
cmdLineInterface view;

/* constructor
 * @param: void
 * function: instantiates the bools process and thread.
 * return: NULL
 */
cmdLineController::cmdLineController() {
	process = false;
	thread = false;

}


/* manipulate()
 * @param: int argc, 
 * 		   char* argv[]
 * Function: Evalutes the command line with the help of the bool switches and calls 
 * the model class to perform the computations. 
 * return: none
 */
void cmdLineController::manipulate(int argc, char* argv[]) {
	cmdLineInterface input;
	input.processInput(argc, argv);
	if (input.getProcess()) {


		pid_t pid = run.processCalculate(input.getRepeat());
		if (pid == 0) {
			process = false;
			return;
		}

	}

	if (input.getThread()) {

			run.threadCalculate(input.getRepeat());

			thread = false;
		}

}


/* receivePID()
 * @param: none
 * Function: Receives the process id from the model class 
 * return: none
 */
void cmdLineController::receivePID(){

	view.displayProcessResults();

}


/* receiveTID()
 * @param: none
 * Function: Receives the thread id from the model class 
 * return: none
 */
void cmdLineController::receiveTID(){
	
	view.displayThreadResults();

}

/* receiveProcessTime()
 * @param: double processTime
 * Function: Receives the average time taken for n processes to be creaated. 
 * return: processTime
 */
double cmdLineController::receiveProcessTime( double processTime){
	view.displayProcessTime(processTime);
	return processTime;
	

}


/* receiveThreadTime()
 * @param: double threadTime
 * Function: Receives the average time taken for n threads to be creaated. 
 * return: threadTime
 */
double cmdLineController::receiveThreadTime( double threadTime){
	view.displayThreadTime(threadTime);
	return threadTime;
}

/* destructor
 * @param: void
 * return: NULL
 */
cmdLineController::~cmdLineController() {

}

