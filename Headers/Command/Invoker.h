#ifndef INVOKER_H
#define INVOKER_H

#include "Command/Commands.h"
#include <iostream>
#include <deque>

using std::deque;

enum class Invoker_Consts { MAX_HIST_LEN = 10 };

class Invoker {
	deque<Command*> History;
	int currHistIndex;
public:
	Invoker();
	void clearHistFuture();
	void execute(CanvasCommand* command);
	void undo();
	void redo();
	~Invoker();
};


#endif
