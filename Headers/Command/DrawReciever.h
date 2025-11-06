#ifndef DRAWRECIEVER_H
#define DRAWRECIEVER_H


class Reciever {
public:
	Reciever();
	virtual void execute() = 0;
	virtual void undo() = 0;	
	virtual ~Reciever();
};


class StartDrawReciever : public Reciever {
public:
	StartDrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual ~StartDrawReciever();
};


class DrawReciever : public Reciever {
public:
	DrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual ~DrawReciever();
};


class EndDrawReciever : public Reciever {
public:
	EndDrawReciever();
	virtual void execute() override;
	virtual void undo() override;	
	virtual ~EndDrawReciever();
};


#endif
