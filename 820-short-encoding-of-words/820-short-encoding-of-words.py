class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted(words, key = lambda x: len(x))[::-1]
        s = ""
        for i in words:
            if (i+'#') not in s:
                s += (i+'#')
        return len(s);