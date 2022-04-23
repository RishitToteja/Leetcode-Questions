#include <string>
#include <unordered_map>
#include <map>
class Solution {
public:
    map<int, string>pq;
    // Encodes a URL to a shortened URL.
    int a;
    
    Solution(){
        a = 0;
    }
    string encode(string longUrl) {
        pair<int, string>p;
        p.first = a;
        p.second = longUrl;
        this->pq.insert(p);
        
        cout<<pq[a];
    
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