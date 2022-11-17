///////////////////////////////////////////////////////////////////////////////////////////////
// easy IOU
////////////////
// Time Complexity: O(1)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B);
        int s2 = (G - E) * (H - F); 
        // not intersect
        if (A >= G || C <= E || D <= F || B >= H)
            return s1 + s2; 
        // find leftest right side, rightest left side
        // upest down side, downest up side
        return s1 + s2 - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F));
    }
};
