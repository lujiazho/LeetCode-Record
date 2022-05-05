///////////////////////////////////////////////////////////////////////////////////////////////
// efficiency is not good
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class MyStack {
public:
    queue<int> q;
    queue<int> helper;
    MyStack() {
        
    }
    
    void push(int x) {
        // store q to helper in original order
        while(!q.empty()){
            int top=q.front();
            q.pop();
            helper.push(top);
        }
        q.push(x); // add to front (top)
        // get back from helper
        while(!helper.empty()){
            int top=helper.front();
            helper.pop();
            q.push(top);
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop(); // pop front
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0?true:false;
    }
};