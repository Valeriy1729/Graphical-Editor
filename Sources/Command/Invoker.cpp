#include "Command/Invoker.h"

Invoker::Invoker() : History({}), currHistIndex(-1)
{ }

void Invoker::clearHistFuture()
{
	Command* back_command;
	int histSize {static_cast<int>(History.size())};
	for(int i {++currHistIndex}; i < histSize; ++i) {
		back_command = History.back();
		History.pop_back();
		delete back_command;
	}
}

void Invoker::execute(Command* command)
{
	command->execute();

	if(command->getHistoryFlag() == true) {
		clearHistFuture();
		History.push_back(command);
	} else
		delete command;
}

void Invoker::undo()
{
	if(currHistIndex == -1) return;
	if(currHistIndex == 0) {
		History[0]->undo();
		--currHistIndex;
		return;	
	}
	Command* last_command {History[--currHistIndex]};
	last_command->undo();
}

void Invoker::redo()
{
	int histSize {static_cast<int>(History.size())};
	if(currHistIndex >= histSize - 1) return;
	++currHistIndex;
	Command* redo_command {History[currHistIndex++]};
	--currHistIndex;
	redo_command->redo();
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

