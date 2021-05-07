#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &stack, int element) {
    if (stack.size() == 0) {
        stack.push(element);
        return;
    }
    
    int top = stack.top();
    stack.pop();
    insert(stack, element);
    stack.push(top);
}

void reverse(stack<int> &stack) {
    if (stack.size() == 0) 
        return;    

    int top = stack.top();
    stack.pop();
    reverse(stack);
    insert(stack, top);
}

int main() {
    stack<int> stack;
    stack.push(2);
    stack.push(5);
    stack.push(1);
    stack.push(3);
    stack.push(0);

    reverse(stack);

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    
    return 0;
}