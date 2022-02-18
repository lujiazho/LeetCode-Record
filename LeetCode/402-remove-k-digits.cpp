///////////////////////////////////////////////////////////////////////////////////////////////
// this problem is a bit hard to think of using monotonic stack
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string removeKdigits(string num, int k) {
        string monoStack = "";
        for (int i=0 ; i<num.length() ; i++){
            while (monoStack.length() && k && monoStack[monoStack.length()-1] > num[i]){
                monoStack.pop_back();
                k -= 1;
            }
            if (monoStack.size() || num[i] != '0') monoStack += num[i];
        }
        while (k-- && monoStack.length()) monoStack.pop_back();
        return monoStack.length()?monoStack:"0";
    }
};