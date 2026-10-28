class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n=len(nums)
        bucket=[[] for _ in range(n+1)]
        freq=Counter(nums)
        for num,count in freq.items():
            bucket[count].append(num)
        res=[]
        for i in range(n,0,-1):
            for num in bucket[i]:
                res.append(num)
                k-=1
                if k==0:
                    return res
        return res
        