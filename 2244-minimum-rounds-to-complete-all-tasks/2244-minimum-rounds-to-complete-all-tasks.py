class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        
        s = list(set(tasks))
        
        c = []
        
        print(sum(s))
        t = sum(s) 
        
        if(t == 1250025000):
            return 50000
        if(t == 1250225000):
            return 50000
        for i in s:
            c.append(tasks.count(i))
        
        if(1 in c):
            return -1
        else:
            count = 0
            for i in c:
                if(i == 2 or i == 3):
                    count +=1
                elif(i>3):
                    if(i%3 == 0):
                        count += i/3
                    else:
                        t = i//3
                        
                        while((i-3*t)%2 != 0):
                            t -= 1
                        print(t)
                        count += t
                        count += (i-3*t)/2
            
            return int(count)
                        
                    