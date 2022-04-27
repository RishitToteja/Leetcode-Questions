class Solution {
public:
    int romanToInt(string s) {
        int a = 0;
        
        for(int i=0; i<s.size(); i++){

            if(s[i] == 'I'){
                bool bol = true;
                if(s[i+1] == 'V' && i+1<s.size()){
                    bol = false;
                    i++;
                    a += 4;
                    continue;
                }
                else if(s[i+1] != 'X' && i+1<s.size()){
                    bol = false;
                    a += 1;
                    continue;
                }
                if(s[i+1] == 'X' && i+1<s.size()){
                    i++;
                    a += 9;
                    continue;
                }
                else if(bol){
                    a += 1;
                    continue;
                }
            }
            
            else if(s[i] == 'X'){
                bool bol = true;
                if(s[i+1] == 'L' && i+1<s.size()){
                    bol = false;
                    i++;
                    a += 40;
                    continue;
                }
                else if(s[i+1] != 'C' && i+1<s.size()){
                    bol = false;
                    a += 10;
                    continue;
                }
                if(s[i+1] == 'C' && i+1<s.size()){
                    i++;
                    a += 90;
                    continue;
                }
                else if(bol){
                    a += 10;
                    continue;
                }
            }
            
            else if(s[i] == 'C'){
                bool bol = true;
                if(s[i+1] == 'D' && i+1<s.size()){
                    bol = false;
                    i++;
                    a += 400;
                    continue;
                }
                else if(s[i+1] != 'M' && i+1<s.size()){
                    bol = false;
                    a += 100;
                    continue;
                }
                if(s[i+1] == 'M' && i+1<s.size()){
                    i++;
                    a += 900;
                    continue;
                }
                
                else if(bol){
                    a += 100;
                    continue;
                }
            }
            
            else if(s[i] == 'V'){
                a += 5;
                continue;
            }
            else if(s[i] == 'L'){
                a += 50;
                continue;
            }
            else if(s[i] == 'D'){
                a += 500;
                continue;
            }
            else if(s[i] == 'M'){
                a += 1000;
                continue;
            }
            
            
            
        }
        
        return a;
    }
};