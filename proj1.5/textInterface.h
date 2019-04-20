/* textInterface.h declares the cmdInterface class
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */

#ifndef TEXTINTERFACE_H_
#define TEXTINTERFACE_H_
#include "callTimer.h"

class textInterface {
public:
	textInterface();
	void processInput();
	virtual ~textInterface();
	void displayProcessResults();
	bool gettxtProcess() { return processTxt; };
	void displayProcessTime( double processTime);
	bool gettxtThread(){ return threadTxt; };
	int getRepeat(){  return reps;	};
	
	private:
	friend class textController;
	int reps;
	bool processTxt;
	bool threadTxt;
	bool processAndThread;

};

#endif /* TEXTINTERFACE_H_ */
