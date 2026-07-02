class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>> >, greater<pair<int,pair<int,int>>>> pq;


        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=0;

        pq.push({0,{0,0}});

        int delrow[]={0,-1,0,1};
        int delcol[]={-1,0,1,0};

        while(!pq.empty()){

            auto it=pq.top();
            pq.pop();

            
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int neffort=max(abs(heights[row][col]-heights[nrow][ncol]), diff);

                    if(neffort < dis[nrow][ncol]){
                        dis[nrow][ncol]=neffort;
                        pq.push({neffort,{nrow,ncol}});
                    }
                }
            }

           


            


        }
         return dis[n-1][m-1];
        
    }
};