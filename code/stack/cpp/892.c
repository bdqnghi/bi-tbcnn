#include "allInclude.h"

stack::stack()
{
	pos = 0;
	for(int a = 0; a < 16; a++)
		place[a] = 0x00;
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	mainLog.message = "Init stack.\n";
	mainLog.writeMessage();
	#endif
}

void stack::push(unsigned short int pushOn)
{
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	#endif
	if(pos>15)
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "STACK OVERFLOW ZOMG STAWP THAT!\n";
		mainLog.writeMessage();
		#endif
		return;
	}
	place[pos] = pushOn;
	pos++;
}

unsigned short int stack::pop()
{
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	#endif
	if(pos>15)
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "Stack overflow on pop? WAHT?\n";
		mainLog.writeMessage();
		#endif
		return 911;
	}
	pos--;
	if(pos<0)
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "Stack UNDERFLOW :P (too many returns)\n";
		mainLog.writeMessage();
		#endif
		return 911;
	}
	return place[pos];
}

void stack::reset()
{
	for(int x = 0; x < 16; x++)
	{
		place[x] = 0;
	}
	pos = 0;
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	mainLog.message = "Stack reset.\n";
	mainLog.writeMessage();
	#endif
}
