///////////////////////////////////////////////////////////////////////////////////////////////
// good usage of monotonic stack, the span is accumulated 
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class StockSpanner {
public:
    vector< pair<int, int> > stack;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int curSpan = 1;
        
        // monotonic stack
        while( stack.size() && stack.back().first <= price ){
            
            auto [prevPrice, prevSpan] = stack.back();
            
            // it's ok to pop because the prev span is accumulated
            stack.pop_back();
            
            // accumulate span of prev price
            curSpan += prevSpan;
        }
        
        // update latest price quote and price span
        stack.push_back( pair<int, int>{price, curSpan} );
        return curSpan;
    }
};