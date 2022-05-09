class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        if digits == "":
            return []
        
        dig = list(digits)
        
        alpha = []
        
        for i in dig:
            if i == '2':
                alpha.append(['a', 'b', 'c'])
            if i == '3':
                alpha.append(['d', 'e', 'f'])
            if i == '4':
                alpha.append(['g', 'h', 'i'])
            if i == '5':
                alpha.append(['j', 'k', 'l'])
            if i == '6':
                alpha.append(['m', 'n', 'o'])
            if i == '7':
                alpha.append(['p', 'q', 'r', 's'])
            if i == '8':
                alpha.append(['t', 'u', 'v'])
            if i == '9':
                alpha.append(['w', 'x', 'y', 'z'])
                
        import itertools
        
        ans = list(itertools.product(*alpha))
        
        new_ans = []
        
        for i in ans:
            k = ""
            for j in i:
                k+=j
            new_ans.append(k)
        
        
        return new_ans
        