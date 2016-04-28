class MinStack {
public:
    stack<int> s;
    stack<int> min;
    void push(int x) {
        s.push(x);
        if(!min.size()|| x<=min.top())
            min.push(x);
    }

    void pop() {
        if(min.top()==s.top())
            min.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
};