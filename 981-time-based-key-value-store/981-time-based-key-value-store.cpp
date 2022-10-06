class TimeMap {
public:
    unordered_map<string, string>mp;
    set<int, greater<int>> s;
    string makeKey(string s1, int t){
        return s1 + " " + to_string(t);
    }
    void set(string key, string value, int timestamp) {
        mp[makeKey(key, timestamp)]=value;
        s.insert(timestamp);
    }
    string get(string key, int timestamp) {
        if(mp.find(makeKey(key, timestamp)) != mp.end())
            return mp[makeKey(key, timestamp)];
        else{
            for (auto itr = s.begin(); itr != s.end(); itr++) {
                if(*itr<=timestamp){
                    if(mp.find(makeKey(key, *itr)) != mp.end())
                        return mp[makeKey(key, *itr)];
                }
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */