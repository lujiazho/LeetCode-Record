///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int res = peek();
        output.pop();
        return res;
    }
    
    int peek() {
        // insert
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};