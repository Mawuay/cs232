/* model.cpp forks the process and spwans the threads and times how 
 * long these events take.
 * author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */

#include "model.h"
#include "callTimer.h"


/* constructor
 * @param: void
 * function: instantiates the processAverageTime &  threadAverageTime variables.
 * return: NULL
 */
model::model() {
	processAverageTime = 0;
	threadAverageTime = 0;

}

/* processCalculate()
 * @param: unsigned repeat
 * Function: Creates a process, forks the process "repeat" times and returns the process id.
 * return: pid
 */
pid_t model::processCalculate(unsigned repeat) {

	NanoTimer timer;
	
	pid_t pid;
	cmdLineController processID;
	textController textProcessID;
	for (unsigned i = 1; i < (repeat + 1); i++) {
		timer.start();
		pid = fork();               //Performs the fork.
		timer.stop();

		if (pid == 0) {
			
			processID.receivePID();
			return pid;
		}
		wait(NULL);
	}
	processAverageTime = timer.getTotalTime() / repeat;
	timer.reset();
	processID.receiveProcessTime(getProcessTime());


	return pid;
}



/* threadHello()
 * @param: void *threadid
 * Function: thread pointer
 * return: none
 */
void *threadHello(void *threadid) {
	return 0;
}


/* threadCalculate()
 * @param: unsigned repeat
 * Function: Creates a thread, spawns the thread "repeat" times and returns the thread id.
 * return: none
 */
void model::threadCalculate(unsigned repeat) {

	NanoTimer timerT;

	pthread_t my_threads;
	cmdLineController threadID;
	for (unsigned i = 0; i < repeat; i++) {
		timerT.start();
		pthread_create(&my_threads, NULL, &threadHello, (void*) my_threads);
		timerT.stop();
		
		threadID.receiveTID();
		pthread_join(my_threads, NULL); // A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.
		threadAverageTime = timerT.getTotalTime();
		timerT.reset();

		

	}
threadID.receiveThreadTime(getThreadTime());

	return;

}


/* destructor
 * @param: void
 * return: NULL
 */
model::~model() {

}

