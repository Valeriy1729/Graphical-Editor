#ifndef CLIENT_H
#define CLIENT_H

#include "Command/Commands.h"
#include "Command/DrawReciever.h"

class Client {
	StartDrawReciever* StartDrawR;
	DrawReciever* DrawR;
	EndDrawReciever* EndDrawR;
public:
	Client();
	ComplexCommand* getCommand(CommandType ReqType);
	~Client();
};


#endif
