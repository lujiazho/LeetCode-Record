///////////////////////////////////////////////////////////////////////////////////////////////
// new things learnt, which is c++ class inheritance and how to use parent class method
////////////////
// Time Complexity: O(1)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class PeekingIterator : public Iterator {
public:
    int nxt;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        if (Iterator::hasNext())
            nxt = Iterator::next();
        else
            nxt = -1;
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return nxt;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int res = nxt;
        if (Iterator::hasNext())
            nxt = Iterator::next();
        else
            nxt = -1;
        return res;
    }
    
    bool hasNext() const {
        return nxt!=-1;
    }
};