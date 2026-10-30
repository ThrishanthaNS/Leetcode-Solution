class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        if all(s[i+1]>=s[i] for i in range(len(s)-1)):
            return 0
        if len(s)<=2:
            return -1
        minx=min(s)
        maxx=max(s)
        if s[0]==minx or s[-1]==maxx:
            return 1
        if s[0]==maxx and s[-1]==minx:
            if s.count(minx)>1 or s.count(maxx)>1:
                return 2
            return 3
        return 2
        