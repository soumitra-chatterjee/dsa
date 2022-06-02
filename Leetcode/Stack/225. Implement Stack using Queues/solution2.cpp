// Implementation of Stack using Single Queue


class MyStack {
	
    queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int q_size = q.size();
        while(q_size > 1) 
        {
            int val = q.front();
            q.pop();
            q.push(val);
            q_size--;
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
