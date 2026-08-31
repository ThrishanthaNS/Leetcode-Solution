/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=prev->next;
        ListNode* next=curr->next;
        vector<int>cpoints;
        int i=1;
        while(next!=nullptr){
            if(curr->val>prev->val && curr->val>next->val){
                cpoints.push_back(i);
            }
            else if(curr->val<prev->val && curr->val<next->val){
                cpoints.push_back(i);
            }
            i++;
            prev=curr;
            curr=next;
            next=next->next;
        }
        if(cpoints.size()<2) return {-1,-1};
        int maxdis=cpoints.back()-cpoints.front();
        int mindis=maxdis;
        for(int i=0;i<cpoints.size()-1;i++){
            mindis=min(mindis,cpoints[i+1]-cpoints[i]);
        }
        return {mindis,maxdis};
        
    }
};