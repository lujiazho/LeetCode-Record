///////////////////////////////////////////////////////////////////////////////////////////////
// the location is unique in a vector for any url
////////////////
// Time Complexity: O(1)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:

    vector<string> v;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        v.push_back(longUrl);
        return to_string(v.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return v[stoi(shortUrl)];
    }
};