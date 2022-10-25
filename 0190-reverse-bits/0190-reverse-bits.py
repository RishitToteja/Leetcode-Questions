class Solution:
    def reverseBits(self, n: int) -> int:
        t = "{:032b}".format(n)
        return int(t[::-1],2)
        