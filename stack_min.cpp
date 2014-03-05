/***************************************************************************
 * 
 * Design a stack which returns the smallest element in O(1) time. 
 * Space constraint also has to be considered if you use extra space
 * 
 **************************************************************************/

#include <stack>
#include <iostream>
using namespace std;

class stack_min
{
    public:
        void pop();
       	void push(int value);
        int top()
        {
           return value_stack.top(); 
        }        
	int min()
	{
		return min_stack.top();
	}
    private:
        stack<int> value_stack; ///the stack for values
        stack<int> min_stack;   ///save minimum values in the current value_stack
};

/**
 * 1.pop the value_stack
 * 2.if the top value is minimum in the current value_stack, pop the min_stack
 */
void stack_min::pop()
{
    if (value_stack.empty())
    {
        return;
    }
    int top = value_stack.top();
    if (top == min_stack.top())
    {
        min_stack.pop();
    }
    value_stack.pop();
}

/**
 * push the value to value_stack;
 * if the value is less than or equal to the minimum value in the value_stack,
 * push the value to min_stack
 */
void stack_min::push(int value)
{
	value_stack.push(value);
	if (min_stack.empty())
	{
		min_stack.push(value);
		return;
	}

	int min = min_stack.top();
	if (value <= min)
	{
		min_stack.push(value);
	}
}

int main()
{
	stack_min my_stack;
	my_stack.push(5);
	cout << "min:" << my_stack.min() << endl;
	my_stack.push(4); 
	cout << "min:" << my_stack.min() << endl;
	my_stack.push(7);
	cout << "min:" << my_stack.min() << endl;
	my_stack.pop();
	cout << "min:" << my_stack.min() << endl;
	my_stack.pop();
	cout << "min:" << my_stack.min() << endl;
}
