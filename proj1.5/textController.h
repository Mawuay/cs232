/* textController.h declares the textController class
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */
#ifndef TEXTCONTROLLER_H_
#define TEXTCONTROLLER_H_
#include "callTimer.h"
#include <string>

class textController {
public:
	textController();
	void processCalculate(int reps);
	void threadCalculate(int reps);
	void pTCalculate(int reps);
	void receivePID();
	void receiveTID();
	void receiveTXTPID();
	double receiveProcessTime( double processTime);
	virtual ~textController();

private:

	// unsigned repeat;
	bool processTxt;
	bool threadTxt;
	friend class textInterface;
};

#endif /* TEXTCONTROLLER_H_ */
