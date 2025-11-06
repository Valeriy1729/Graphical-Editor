#include "Command/Invoker.h"

Invoker::Invoker() : History({})
{ }

void Invoker::execute(Command* command)
{
	std::cout << "added in history" << std::endl;
	History.push_back(command);
	command->execute();
}

void Invoker::undo()
{
	std::cout << "removed from history" << std::endl;
	Command* last_command {History.back()};
	last_command->undo();
	History.pop_back();
	delete last_command;
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

