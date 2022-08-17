class Solution {
public:
    int index;
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string>morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        vector<char>alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        

        
        vector<string>code;
        
        for(string i: words){
            string temp;
            
            for(int j = 0; j<i.size(); j++){
                auto it = find(alpha.begin(), alpha.end(), i[j]);
                if (it != alpha.end()){
                    index = it - alpha.begin();
                    }
                
                temp += morse[index];
        }
            code.push_back(temp);
    }
        
        vector<string>set;
        
        for(string i: code){
            bool bol = true;
            for(string j: set){                
                if(i==j){
                    bol = false;
                }
            }
            if(bol){
                set.push_back(i);
            }
        }
        
              
        return set.size();;
    

        
    }
};