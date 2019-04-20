/*
 * callTimer.h
 *
 *  Created on: Feb 23, 2019
 *      Author: dma2
 */

#ifndef CALLTIMER_H_
#define CALLTIMER_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>       	// string to int
#include <stdio.h>
#include <unistd.h>     	// to include fork(), getpid()
#include <sstream>			// stringstream
#include "NanoTimer.h"		// NanaTimer.h
#include <pthread.h>		// pthread
#include <sys/wait.h>		// wait()
#include "cmdLineController.h"
#include "textController.h"
#include "model.h"
#include "cmdLineInterface.h"
#include "textInterface.h"
using namespace std;


class callTimer {
public:
	callTimer();
	void getInput(int argc, char* argv[]);
	virtual ~callTimer();
};

#endif /* CALLTIMER_H_ */
