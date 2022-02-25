///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (true){
            int num1 = 0;
            while (i < version1.length() && version1[i] != '.'){
                num1 = 10*num1 + int(version1[i])-48;
                i += 1;
            }
            i += 1;
            int num2 = 0;
            while (j < version2.length() && version2[j] != '.'){
                num2 = 10*num2 + int(version2[j])-48;
                j += 1;
            }
            j += 1;
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
            if (i > version1.length() || j > version2.length()) break;
        }
        while (i < version1.length()){
            if (version1[i] != '.' && version1[i] > 48) return 1;
            i += 1;
        }
        while (j < version2.length()){
            if (version2[j] != '.' && version2[j] > 48) return -1;
            j += 1;
        }
        return 0;
    }
};