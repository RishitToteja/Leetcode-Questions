#include <string>
#include <unordered_map>
#include <map>
class Solution {
public:
    unordered_map<int, string>pq;
    // Encodes a URL to a shortened URL.
    int a;
    
    Solution(){
        a = 0;
    }
    string encode(string longUrl) {
        
        pq[a] = longUrl;
        return to_string(a++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return pq[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));