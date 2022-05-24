class Solution:
    def process_input(self, strs):
        self.weights = []
        for s in strs:
            c_s = Counter(s)
            self.weights.append((c_s.get('0', 0), c_s.get('1', 0)))
        
    def run(self,m,n,idx,L):
        if idx < 0 or idx == L or m<0 or n<0:
            return 0
        key = (m,n,idx)
        if key in self.table:
            return self.table[key]
        a,b = self.weights[idx]
        first = 0
        if m-a >= 0 and n-b>=0:
            first = 1 + self.run(m-a, n-b, idx-1,L)
        second = self.run(m,n, idx-1,L)
        
        self.table[key] = max(first, second)
        return self.table[key]
        
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        self.process_input(strs)
        self.table = {}
        ans =  self.run(m, n, len(self.weights)-1, len(self.weights))
        return ans