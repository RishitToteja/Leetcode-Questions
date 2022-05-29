class Solution {
public:
    bool check(string one, string two) {
 	int arr[26] = {0};
 	for (char c : one) arr[c - 'a']++;

 	for (char c : two) {
 		if (arr[c - 'a']) return false;
 	}
 	return true;
 }
    
    int max(int a, int b){
        if(a>b)
            return a;
        return b;
    }
    int maxProduct(vector<string>& words) {
        int m1 = INT_MIN;
        for(int i=0; i<words.size(); i++){
            int m2 = INT_MIN;
            for(int j=i+1; j<words.size(); j++){
                if(check(words[i], words[j])){
                    m2 = max(m2, words[i].size()*words[j].size());
                }
            }
            m1 = max(m1, m2);
        }
        if(m1==INT_MIN){
            return 0;
        }
        
        return m1;
    }
};