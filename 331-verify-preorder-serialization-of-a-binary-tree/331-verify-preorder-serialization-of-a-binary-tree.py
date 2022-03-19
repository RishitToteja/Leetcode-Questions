class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        l = preorder.split(",")
        
        score = 1
        if(len(l)>1 and l[0] == '#'):
            return False;
        for i in range(len(l)):
            
            if(l[i] == '#'):
                score -= 1
            else:
                score += 1
            if(score <= 0 and i != len(l) - 1):
                return False
            print(score)
        
        if(score == 0):
            return True;
        else:
            return False;
        
 