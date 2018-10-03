/***************************************
 Author : jt
 Mail : zhuiyitaosheng@gmail.com
***************************************/

#include <iostream>
//#include <string>
//#include <vector>
//#include <cstddef>
//#include <exception>
//#include <stdexcept>
//#include <new>
//#include <type_info>

#define MAX_SIZE 50
#define INCREMENT_SIZE 10

using namespace::std;
using Elemtype = char;

typedef struct SqStack {
	Elemtype *data;
	int top;
	int max_size;
}SqStack;

void InitStack(SqStack &St);
bool IsEmpty(const SqStack &St);
bool Pop(SqStack &St, Elemtype &e);
bool Push(SqStack &St, Elemtype e);
bool IsOverflow(const SqStack &St);

bool BracketsCheck(char *s);

int main()
{
	char test[] = "([{}])";

	if (BracketsCheck(test)) {
		cout << "Right" << endl;
	} else {
		cout << "Wrong" << endl;
	}

	return 0;
}

void InitStack(SqStack &St)
{
	St.data = (Elemtype *) malloc (sizeof (Elemtype) * MAX_SIZE);
	if (St.data) {
		St.max_size = MAX_SIZE;
		St.top = -1;
	} else {
		cout << "Wrong" << endl;
		exit(-1);
	}
}

bool IsEmpty(const SqStack &St)
{
	return St.top < 0 ? true : false;
}

bool Pop(SqStack &St, Elemtype &e)
{
	if (!IsEmpty(St)) {
		e = St.data[St.top--];
		return true;
	} else {
		return false;
	}
}

bool Push(SqStack &St, Elemtype e)
{
	if (IsOverflow(St)) {
		St.data = (Elemtype *) realloc (St.data, sizeof(Elemtype) * (INCREMENT_SIZE + St.max_size));
		St.max_size += INCREMENT_SIZE;
	}
	St.data[++St.top] = e;

	return true;
}

bool IsOverflow(const SqStack &St)
{
	if (St.top == St.max_size - 1) {
		return true;
	} else {
		return false;
	}
}

bool BracketsCheck(char *s)
{
	SqStack St;
	InitStack(St);
	Elemtype e;
	size_t index = 0;
	char ch;

	while ((ch = s[index]) != '\0') {
		switch (ch) {
			case '(': case '[': case '{':
				Push(St, ch);
				break;
			case ')':
				if (!Pop(St, e) || e != '(') {
					cout << e << endl;
					return false;
				}
				break;
			case ']':
				if (!Pop(St, e) || e != '[') {
					cout << e << endl;
					return false;
				}
				break;
			case '}':
				if (!Pop(St, e) || e != '{') {
					cout << e << endl;
					return false;
				}
				break;
		}
		++index;
	}

	if (IsEmpty(St)) {
		return true;
	} else {
		return false;
	}
}