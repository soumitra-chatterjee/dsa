// Implementation of Stack Using Multiple Queues


class MyStack {
    queue<int> container;
    queue<int> temp; 
public:
    MyStack() {}
    
    void push(int x) {
        temp.push(x);
        while( !container.empty() ) {
            temp.push(container.front());
            container.pop();
        }
        swap(temp, container);
    }
    
	// pop the topmost element and return it
    int pop() {
        int top = container.front();
        container.pop();
        return top;
    }
    
	// return the topmost element
    int top() {
        return container.front();
    }
    
    bool empty() {
        return container.empty();
    }
};
