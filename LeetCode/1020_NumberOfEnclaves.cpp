class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();int ans=0;
    
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and vis[i][j]==0){

                    queue<pair<int,int>> q;int temp=0;
                    q.push({i,j});int flag=0;
                    vis[i][j]=1;

                    while(!q.empty()){
                         int row=q.front().first;
                         int col=q.front().second;
                         q.pop();
                         temp++;

                        if(row==0 or row==n-1 or col==0 or col==m-1){
                            flag=1;
                        }

                        int dr[]={0,1,-1,0};
                        int dc[]={1,0,0,-1};

                        for(int index=0;index<4;index++){

                            int newrow=row+dr[index];
                            int newcol=col+dc[index];

                            if(newrow>=0 and newrow<n and newcol>=0 and newcol<m and grid[newrow][newcol]==1 and vis[newrow][newcol]==0){
                                q.push({newrow,newcol});
                                vis[newrow][newcol]=1;
                            }

                        }                

                    }

                    if(flag==0){
                        ans+=temp;
                    }

                }

            }       

        }

        return ans;
    }
};
