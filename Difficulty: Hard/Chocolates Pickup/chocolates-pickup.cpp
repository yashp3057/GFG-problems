class Solution {
public:

    int helper(vector<vector<int>>& grid, int c1, int c2, int r, int n,vector<vector<vector<int>>>&dp) {

        int m = grid[0].size();

        if(c1<0 || c1>=m || c2<0 || c2>=m)
            return -1e8;
        
        
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];    

        if(r==n){

            if(c1==c2)
                return grid[r][c1];

            return grid[r][c1]+grid[r][c2];
        }

        int maxi = INT_MIN;

        for(int k=-1;k<=1;k++){

            for(int l=-1;l<=1;l++){

                int value;

                if(c1==c2)
                    value = grid[r][c1];
                else
                    value = grid[r][c1]+grid[r][c2];

                value += helper(grid,c1+k,c2+l,r+1,n,dp);

                maxi=max(maxi,value);
            }
        }

        return dp[r][c1][c2]=maxi;
    }

    int maxChocolate(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(grid,0,m-1,0,n-1,dp);
    }
};