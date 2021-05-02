#include <iostream>
#include <stack>

using namespace std;

void deleteMiddle(stack<int> &stack, int k) {
    if (stack.size() == 0 || k == 1) {
        stack.pop();
        return;
    }

    int top = stack.top();
    stack.pop();
    deleteMiddle(stack, k - 1);
    stack.push(top);
}

int main() {
    stack<int> stack;
    stack.push(2);
    stack.push(5);
    stack.push(1);
    stack.push(3);
    stack.push(0);

    int k = stack.size() % 2 == 0 ? (stack.size() / 2) : (stack.size() / 2 + 1);
    deleteMiddle(stack, k);

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    
    return 0;
}