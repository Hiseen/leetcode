class Stack {
 public:
 
 stack<int> stack1;
     // Push element x onto stack.
     void push(int x) {
         stack1.push(x);
     }
 
     // Removes the element on top of the stack.
     void pop() {
         stack1.pop();
     }
 
     // Get the top element.
     int top() {
         return stack1.top();
     }
 
     // Return whether the stack is empty.
     bool empty() {
         return stack1.empty();
     }
 };