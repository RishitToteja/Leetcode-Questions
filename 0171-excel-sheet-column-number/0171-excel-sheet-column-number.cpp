class Solution {
public:
    unordered_map<char, int>mp;
    int titleToNumber(string c) {
        mp.insert({'A', 1});
        mp.insert({'B', 2});
        mp.insert({'C', 3});
        mp.insert({'D', 4});
        mp.insert({'E', 5});
        mp.insert({'F', 6});
        mp.insert({'G', 7});
        mp.insert({'H', 8});
        mp.insert({'I', 9});
        mp.insert({'J', 10});
        mp.insert({'K', 11});
        mp.insert({'L', 12});
        mp.insert({'M', 13});
        mp.insert({'N', 14});
        mp.insert({'O', 15});
        mp.insert({'P', 16});
        mp.insert({'Q', 17});
        mp.insert({'R', 18});
        mp.insert({'S', 19});
        mp.insert({'T', 20});
        mp.insert({'U', 21});
        mp.insert({'V', 22});
        mp.insert({'W', 23});
        mp.insert({'X', 24});
        mp.insert({'Y', 25});
        mp.insert({'Z', 26});

        int s = c.size();
        
        int ans = 0;
        int j=1;
        for(int i=0; i<c.size(); i++){
            ans += pow(26, s-j)*mp[c[i]];
            j++;
        }
        return ans;
        
    }
};