class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        
        else{
            int j = 0;
            
            for(int i=0; i<haystack.size(); i++){
                if(haystack[i] == needle[j]){
                    bool bol = true;
                    int itr = i;
                    for(int k = j; k<needle.size(); k++, itr++){
                        bol = bol && (haystack[itr] == needle[k]);
                    }
                    if(bol){
                        return i;
                    }
                }
            }
            
            return -1;
        }
    }
};