class Solution:
    def frequencySort(self, s: str) -> str:
        d= {}
        
        for i in s:
            d[i] = 0;
        for i in s:
            d[i] += 1;
        print(d);
        
        s = ""
        
        f = dict(sorted(d.items(), key=lambda item: item[1]))
        temp = list(f.keys())
        rev = [temp[len(temp)-i-1] for i in range(len(temp))]
        
        for i in rev:
            for j in range(f[i]):
                s += i
            
        return s;
    
    