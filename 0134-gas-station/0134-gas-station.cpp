class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentgas=0,requiredgas=0,beg=-1,n=gas.size();
        // vector<int>vis(n,0);
        int totalgas=0,totalcost=0;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalgas<totalcost) {
            return -1;
        }
        for(int i=0;i<n;i=(i+1)%n){
            currentgas+=gas[i];
            requiredgas=cost[i];
            if(currentgas<requiredgas){
                currentgas=0;
                beg=-1;
            }
            else{
            if(beg==-1){
                beg=i;
            }
            else if(i==beg) return beg;
            currentgas-=requiredgas;
            }
        }
        return beg; 
    }
};