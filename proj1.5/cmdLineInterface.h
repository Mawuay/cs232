/* cmdLineInterface.h declares the cmdInterface class
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */

#ifndef CMDLINEINTERFACE_H_
#define CMDLINEINTERFACE_H_
#include "callTimer.h"

class cmdLineInterface {
	friend class cmdLineController;
public:
	cmdLineInterface();
	void processInput(int argc, char* argv[]);
	virtual ~cmdLineInterface();
	unsigned getRepeat(){return repeat;	};
	bool getProcess(){return process; };
	bool getThread(){return thread; };
	void displayProcessResults();
	void displayProcessTime(double processTime);
	void displayThreadTime( double threadTime);
	void displayThreadResults();


private:
	unsigned repeat;
	bool process;
	bool thread;


};

#endif /* CMDLINEINTERFACE_H_ */
