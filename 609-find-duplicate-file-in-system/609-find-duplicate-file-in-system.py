class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        import re
        d = {}
        for i in paths:
            l = i.split(" ")
            root = l[0]+'/'
            for j in range(1, len(l)):
                s = l[j]
                t = re.search("\(.*\)", s)
                file = s[0: t.start()]
                key = s[t.start(): len(s)]
                if(key in d):
                    d[key].append(root+file)
                else:
                    d[key] = [root+file]
        
        ans = []
        for i in d.keys():
            if(len(d[i])>1):
                ans.append(d[i])
            # print("{}: ".format(i), end = "")
            # print(*d[i], end = "\n")
        return ans;
            
                
            