/* cmdLineController.h declares the cmdLineController class
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */

#ifndef CMDLINECONTROLLER_H_
#define CMDLINECONTROLLER_H_

class cmdLineController {
public:
	cmdLineController();
	void manipulate(int argc, char* argv[]);
	void receivePID();
	double receiveProcessTime( double processTime);
	double receiveThreadTime( double threadTime);
	void receiveTID();
	virtual ~cmdLineController();

private:

	bool process;
	bool thread;
	friend class model;
	friend class cmdLineInterface;
};

#endif /* CMDLINECONTROLLER_H_ */
