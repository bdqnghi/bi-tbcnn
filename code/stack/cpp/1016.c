/**
 * @file Stack.cpp
 */
#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
public:
	explicit Stack(size_t max) : max_(max), count_(0) {};
	virtual ~Stack() {};

	void Push(const T& value) {
		if (Full()) {
			throw std::overflow_error("stack overflow !!");
		}
		++count_;
		stck_.push(value);
	}
	void Pop() {
		if (Empty()) {
			throw std::underflow_error("stack empty !!");
		}
		--count_;
		stck_.pop();
	}
	T Top() const {
		if (Empty()) {
			throw std::underflow_error("stack empty !!");
		}
		return stck_.top();
	}
	bool Full() const {
		return count_ >= max_;
	}
	bool Empty() const {
		return count_ == 0;
	}

private:
	size_t max_;
	size_t count_;
	stack<T> stck_;
};

int main() {
	Stack<int> stck(10);

	try {
		for (int i = 0; i < 20; ++i) {
			stck.Push(i);
		}
	} catch (const std::overflow_error& e) {
		cerr << e.what() << endl;
	}

	while (!stck.Empty()) {
		cout << stck.Top() << ' ';
		stck.Pop();
	}
	cout << endl;

	return 0;
}
