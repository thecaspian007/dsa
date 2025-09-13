class MinStack {
public:
    MinStack() {
        mini = LLONG_MAX;  
    }
    
    stack<long long> st;  
    long long mini;  

    void push(int val) {
        if (st.empty()) {
            mini = val;  
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val); 
            } else {
                long long x = (2LL * val) - mini;  
                st.push(x);  
                mini = val;  
            }
        }
    }
    
    void pop() {
        if (st.empty()) {
            return;
        }

        long long topValue = st.top();
        st.pop();

        if (topValue < mini) {
            mini = (2LL * mini) - topValue;  
        }
    }
    
    int top() {
        if (st.empty()) {
            return -1;  
        }

        long long topValue = st.top();
        if (topValue < mini) {
            return mini;  
        } else {
            return topValue;  
        }
    }
    
    int getMin() {
        if (st.empty()) {
            return -1;  
        }

        return mini;  
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