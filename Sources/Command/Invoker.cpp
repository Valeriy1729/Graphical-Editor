#include "Command/Invoker.h"

Invoker::Invoker() : History({})
{ }

void Invoker::execute(CanvasCommand* command)
{
	command->execute();
	if(command->getHistoryFlag() == true) {
		std::cout << "added in history" << std::endl;
		History.push_back(command);
	} else
		delete command;
}

void Invoker::undo()
{
	if(History.size() == 0) return;
	std::cout << "removed from history" << std::endl;
	Command* last_command {History.back()};
	last_command->undo();
	History.pop_back();
	delete last_command;
}

void Invoker::redo()
{
	return;
}

Invoker::~Invoker()
{
	Command* command;
	while(History.size() > 0) {
		command = History.back();
		History.pop_back();
		delete command;
	}
}

