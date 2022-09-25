///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(1)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class MyCircularQueue {
public:
    int* q;
    int s=0, e=-1; // s: start of queue, e: end of queue(including a value)
    int size;
    MyCircularQueue(int k) {
        size = k;
        q = new int[k];
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        e = (e+1) % size;
        q[e] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        if (s == e) s = 0, e = -1; // only has one element, then reset
        else s = (s+1) % size;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[s];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[e];
    }
    
    bool isEmpty() {
        return e == -1;
    }
    
    bool isFull() {
        return !isEmpty() && (e + 1) % size == s;
    }
};