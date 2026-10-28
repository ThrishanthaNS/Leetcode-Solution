class Solution(object):
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        pq=[]
        for p in points:
            distance=sqrt(p[0]*p[0]+p[1]*p[1])
            heapq.heappush(pq,(distance,[p[0],p[1]]))
        res=[]
        while pq and k>0:
            distance,point=heapq.heappop(pq)
            res.append(point)
            k-=1
        return res
        