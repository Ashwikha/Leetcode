class MyStack {
public:
queue<int>q1;
queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size(); 
        for(int i=0;i<size-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int ele=q1.front();
        q1.pop();
        int size2 = q2.size(); 
        for(int i=0;i<size2;i++){
            q1.push(q2.front());
            q2.pop();
        }
        return ele;
    }
    
    int top() {
        int size = q1.size(); 
         for(int i=0;i<size-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int ele=q1.front();
        q2.push(q1.front());
        q1.pop();
        int size2 = q2.size(); 
        for(int i=0;i<size2;i++){
            q1.push(q2.front());
            q2.pop();
        }
        return ele;
    }
    
    bool empty() {
        return q1.empty();
    }
  
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */