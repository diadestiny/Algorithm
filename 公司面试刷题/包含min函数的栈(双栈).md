```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st,stm;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(stm.size())
            stm.push(min(x,stm.top()));
        else stm.push(x);
    }
    
    void pop() {
        stm.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stm.top();
    }
};

```

