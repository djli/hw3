#include "stack.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	Stack<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	cout << test.top() << endl;
	cout << test.size() << endl;
	cout << test.empty() << endl;
	test.pop();
	cout << test.top() << endl;
	cout << test.size() << endl;
	cout << test.empty() << endl;
	test.pop();
	cout << test.top() << endl;
	cout << test.size() << endl;
	cout << test.empty() << endl;
	test.pop();
	cout << test.top() << endl;
	cout << test.size() << endl;
	cout << test.empty() << endl;
}