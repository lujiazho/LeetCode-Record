///////////////////////////////////////////////////////////////////////////////////////////////
// not hard, just large & small heaps
////////////////
// Time Complexity: O(nlogn), for addNum
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class MedianFinder {
public:
    priority_queue<long> small, large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // we keep small heap number >= large heap number
        if (small.size() == large.size()) {
            large.push(-num);
            small.push(-large.top());
            large.pop();
        } else {
            small.push(num);
            large.push(-small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};