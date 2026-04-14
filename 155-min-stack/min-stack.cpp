class MinStack {
public:
// This was the min stack 
   stack <int> st;
   stack<int> gt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(gt.size()==0 || val<gt.top()){
            gt.push(val);
        }
        else{
            gt.push(gt.top());
        }
    }
    
    void pop() {
        st.pop();
        gt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return gt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */