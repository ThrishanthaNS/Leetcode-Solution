class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
         greater<pair<int,pair<int,int>>>
        >minheap;
        int m=nums1.size();
        int n=nums2.size();
        minheap.push({nums1[0]+nums2[0],{0,0}});
        set<pair<int,int>>vis;
        vector<vector<int>>res;
        vis.insert({0,0});
        while(k-- && !minheap.empty()){
            auto top=minheap.top();
            minheap.pop();
            int i=top.second.first;
            int j=top.second.second;
            int sum=top.first;
            res.push_back({nums1[i],nums2[j]});
            if(i+1<m && vis.find({i+1,j})==vis.end()){
                minheap.push({nums1[i+1]+nums2[j],{i+1,j}});
                vis.insert({i+1,j});
            }
            if(j+1<n && vis.find({i,j+1})==vis.end()){
                minheap.push({nums1[i]+nums2[j+1],{i,j+1}});
                vis.insert({i,j+1});
            }
        }
        return res;
        
        
    }
        
};