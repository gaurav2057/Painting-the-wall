class Solution {
public:
int dp[501][501];
int rec(int level,int walls,vector<int>& cost,vector<int>& time)
{
    if(walls<=0) return 0;

    if(level==cost.size()) return 1e9;
    

    if(dp[level][walls]!=-1) return dp[level][walls];

    int ans=rec(level+1,walls,cost,time)+0;
        ans=min(ans,rec(level+1,walls-time[level]-1,cost,time)+cost[level]);

    return dp[level][walls]=ans;
}

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int walls=cost.size();
        memset(dp,-1,sizeof(dp));
        int minamnt=rec(0,walls,cost,time);
        return minamnt;
    }
};