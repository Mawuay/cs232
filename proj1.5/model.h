/* model.h declares the model class
 * Author Daniel Ackuaku
 * CS 232 Calvin college 2019.
 *  Created on: Feb 23, 2019
 */
typedef int pid_t;
#ifndef MODEL_H_
#define MODEL_H_

class model {
	friend class cmdLineInterface;
public:
	model();
	pid_t processCalculate(unsigned repeat);
	void threadCalculate(unsigned repeat);
	double getProcessTime(){ return processAverageTime; };
	double getThreadTime(){ return threadAverageTime; };
	pid_t textProcessCalculate(unsigned repeat);
	virtual ~model();

private :
	double processAverageTime;
	double threadAverageTime;

};

#endif /* MODEL_H_ */
