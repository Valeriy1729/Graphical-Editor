#ifndef INVOKER_H
#define INVOKER_H

#include "Command/Commands.h"
#include <iostream>
#include <deque>

using std::deque;

enum class Consts { MAX_HIST_LEN = 10 };

class Invoker {
	deque<Command*> History;
public:
	Invoker();
	~Invoker();
	void execute(Command* command);
	void undo();
};


#endif
