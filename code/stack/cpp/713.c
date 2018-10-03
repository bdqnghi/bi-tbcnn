#include <iostream> 
#include <stack>

using namespace std;

/** Test basic operations of stack.
 *
 * From http://www.cplusplus.com/reference/stack/stack/
 *		Stacks are a type of container adaptor, specifically designed to operate
 *		in a LIFO context (last-in first-out), where elements are inserted and extracted 
 *		only from the end of the container.
 *
 *		stacks are implemented as containers adaptors, which are classes that use an
 *		encapsulated object of a specific container class as its underlying container,
 *		providing a specific set of member functions to access its elements. Elements are
 *		pushed/popped from the "back" of the specific container, which is known as the
 *		top of the stack.
 *
 * Tested functions:
 * http://www.cplusplus.com/reference/stack/stack/empty/
 * empty: bool empty ( ) const;
 *		Returns whether the stack is empty, i.e. whether its size is 0.
 *
 * http://www.cplusplus.com/reference/stack/stack/size/
 * size: size_type size ( ) const;
 *		Returns the number of elements in the stack.
 *
 * http://www.cplusplus.com/reference/stack/stack/push/
 * push: void push ( const T& x );
 *		Adds a new element at the top of the stack, above its current top element.
 *		The content of this new element is initialized to a copy of x.
 *
 *
 * http://www.cplusplus.com/reference/stack/stack/pop/
 * pop: void pop ( );
 *		Removes the element on top of the stack, effectively reducing its size by one.
 *		The value of this element can be retrieved before being popped by calling member stack::top.
 *
 *		NOTE: pop probably cause runtime error if stack is empty
 *
 * http://www.cplusplus.com/reference/stack/stack/top/
 * top: value_type& top ( ); or const value_type& top ( ) const;
 *		Returns a reference to the next element in the stack. Since stacks are last-in first-out
 *		containers this is also the last element pushed into the stack.
 *
 *		NOTE: top probably cause runtime error if stack is empty
 *
 */

stack<int> testEmptySizePush (stack<int> intStack);
stack<int> testTop (stack<int> intStack);
stack<int> testPop (stack<int> intStack);

int main() {
	stack<int> intStack;
	intStack = testEmptySizePush (intStack);
	intStack = testTop (intStack);
	intStack = testPop (intStack);

	system("PAUSE");
	return 0;
}
stack<int> testEmptySizePush (stack<int> intStack) {
	cout << "function testEmptySizePush" << endl;
	// test empty and size
	cout << "is intStack empty? " << (intStack.empty()? "true" : "false") << endl;
	cout << "size of intStack is: " << intStack.size() << endl;
	cout << "push 3 then 5 into intStack" << endl;
	// test push
	intStack.push(3);
	intStack.push(5);
	// test empty and size again
	cout << "is intStack empty? " << (intStack.empty()? "true" : "false") << endl;
	cout << "size of intStack is: " << intStack.size() << endl << endl;
	return intStack;
}
stack<int> testTop (stack<int> intStack) {
	cout << "function testTop" << endl;
	if (!intStack.empty()) {
		// test top
		cout << "current top value is: " << intStack.top() << endl;
		cout << "add 5 to top value" << endl;
		intStack.top() += 5;
		cout << "modified top value is: " << intStack.top() << endl << endl;
	}
	return intStack;
}
stack<int> testPop (stack<int> intStack) {
	cout << "function testPop" << endl;
	if (!intStack.empty()) {
		// test pop
		cout << "top value before pop is: " << intStack.top() << endl;
		cout << "pop top value" << endl;
		intStack.pop();
		cout << "top value after pop is: " << intStack.top() << endl << endl;
	}
	return intStack;
}
