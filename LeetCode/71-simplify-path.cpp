///////////////////////////////////////////////////////////////////////////////////////////////
// a little bit lengthy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        int i=0;
        string cur = "";
        while (i<path.length()){
            if (path[i] != '/'){
                cur += path[i];
            }else{
                if (cur == ".") {
                    cur = "";
                }else if (cur == ".."){
                    res = traceback(res);
                }else if (cur.length()){
                    res += "/" + cur;
                }
                cur = "";
            }
            i++;
        }
        if (cur.length()){
            if (cur == ".") {
                cur = "";
            }else if (cur == ".."){
                res = traceback(res);
            }else if (cur.length()){
                res += "/" + cur;
            }
        }
        return res.length()?res:"/";
    }
    string traceback(string res){
        while (res.length() && res[res.length()-1] != '/'){
            res.pop_back();
        }
        if (res.length()) res.pop_back();
        return res;
    }
};