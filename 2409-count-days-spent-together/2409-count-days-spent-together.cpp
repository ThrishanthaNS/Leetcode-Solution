class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        unordered_map<string,int>mp{
            {"01",0},
            {"02",31},
            {"03",59},
            {"04",90},
            {"05",120},
            {"06",151},
            {"07",181},
            {"08",212},
            {"09",243},
            {"10",273},
            {"11",304},
            {"12",334}
        };
        int as=mp[arriveAlice.substr(0,2)]+stoi(arriveAlice.substr(3));
        int ae=mp[leaveAlice.substr(0,2)]+stoi(leaveAlice.substr(3));
        int bs=mp[arriveBob.substr(0,2)]+stoi(arriveBob.substr(3));
        int be=mp[leaveBob.substr(0,2)]+stoi(leaveBob.substr(3));
        int ans=min(ae,be)-max(as,bs)+1;
        return ans<=0?0:ans;
    }
};