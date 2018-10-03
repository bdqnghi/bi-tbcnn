#include <iostream>
#include <cstring>
#include <cmath>
#define MAXSIZE 100

using namespace std;

template<class T>
class stack
{
	T a[MAXSIZE];
	int tos;
	
	public:
	stack() {
		tos=-1;
	}

	bool push(T c) {
		if(tos==MAXSIZE) {
			cout<<"Stack Overflow"<<endl;
			return false;
		}
		else {
			a[++tos]=c;
			return true;
		}
	}

	T pop() {
		if(tos==-1) {
			cout<<"Stack Underflow"<<endl;
			return 0;
		}
		else {
			return a[tos--];
		}
	}

	T showtos() {
		if(tos==-1) {
			return 0;
		}
		else return a[tos];
	}

	bool empty() {
		return (tos==-1)?true:false;

	}
};

class postfix
{
	char exp[50];
	stack <char> s;

	int pres(char c) {
		switch(c) {
			case '^': return 2;
			case '*': case '/': return 1;
			case '+': case '-': return 0;
		}
		return -1;
	}

	float calc(char o,float a,float b) {
		switch(o) {
			case '+': return a+b;
			case '-': return a-b;
			case '*': return a*b;
			case '/': return a/b;
			case '^': return pow(a,b);
		}
	}

	public:
	postfix(char*);
	float eval();
	char* show() {
		return exp;
	}
};

postfix::postfix(char *infix) {
	int exppos=0;
	for(int i=0;i<strlen(infix);i++) {
		char c=infix[i];
		if((c>96&&c<123)||(c>64&&c<91)) {
			exp[exppos++]=c;
		}
		else if(c=='('||s.showtos()=='('||pres(c)>pres(s.showtos())) {
			s.push(c);
		}
		else if(c==')') {
			char ch;
			while(s.showtos()!='(') {
				ch=s.pop();
				exp[exppos++]=ch;
			}
			s.pop();
		}
		else if(pres(c)<=pres(s.showtos())) {
			char ch;
			//while(s.showtos()!=0) {
			while(pres(s.showtos())>=pres(c)) {
				ch=s.pop();
				exp[exppos++]=ch;
			}
			s.push(c);
		}
	}
	while(s.showtos()!=0) {
		exp[exppos++]=s.pop();
	}
}

float postfix::eval() {
	stack <float> e;

	for(int i=0;i<strlen(exp);i++) {
		char c=exp[i];
		if((c>96&&c<123)||(c>64&&c<91)) {
			cout<<c<<"?: ";
			float f;
			cin>>f;
			e.push(f);
		}
		else {
			float a,b;
			b=e.pop();
			a=e.pop();
			e.push(calc(c,a,b));
		}
	}
	return e.showtos();
}

int main()
{
	char e[50];
	cout<<"Enter an exp: ";
	cin>>e;
	postfix p(e);
	cout<<p.show()<<endl;
	cout<<p.eval()<<endl;

	return 0;
}
