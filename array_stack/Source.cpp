#include <iostream>
using namespace std;

template <typename T>
class ArrayStack {
	enum {Def_capacity=100};
public:
	ArrayStack(int cap = Def_capacity);
	int size_s() const;
	bool empty() const;
	const T& top();
	void pop();
	void push(const T& data);
	~ArrayStack();
private:
	T* array_stack;
	int capacity;
	int top_element_index;
};


template<typename T>
ArrayStack<T>::ArrayStack(int cap)
{
	array_stack = new T[cap];
	capacity = cap;
	top_element_index = -1;
}

template<typename T>
int ArrayStack<T>::size_s() const
{
	return (top_element_index+1);
}

template<typename T>
bool ArrayStack<T>::empty() const
{
	return (top_element_index<0);
}

template<typename T>
const T& ArrayStack<T>::top()
{
	if (empty())
		throw ("Stack is full");

	return array_stack[top_element_index];
}

template<typename T>
void ArrayStack<T>::pop()
{
	if (empty())
		throw ("Stack is empty");

	--top_element_index;
}

template<typename T>
void ArrayStack<T>::push(const T& data)
{
	if (size_s() == capacity)
		throw ("Stack is full. Cannot push.");
	array_stack[++top_element_index] = data;
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
}


int main() {
	ArrayStack<char> B;
	B.push('N');
	B.push('M');
	B.push('0');
	cout << B.top() << endl;
	B.pop();
	cout << B.top() << endl;
	cout<<"Stack is empty: " << B.empty() << ". Size of the stack: " << B.size_s();


	return 0;
}