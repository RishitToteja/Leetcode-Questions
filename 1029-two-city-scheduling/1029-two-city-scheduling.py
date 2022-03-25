class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        new_l = []
        
        
        for i in costs:
            temp = (i[0], i[1])
            new_l.append(temp)
        
        new_l.sort(key=lambda i:i[0]-i[1])
        
        count1 = 0
        
        
        half = int(len(new_l)/2)
        
        for i in range(half):
            count1 += new_l[i][0]
        
        for i in range(half, len(new_l)):
            count1 += new_l[i][1]
        
        print(new_l)
        
        
        
        
        return count1;
        
        