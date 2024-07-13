class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
    
        vector<pair<int, int>>direction={{-1, 0}, {0,1}, {1,0},{0,-1}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++ ){
                int maxEle=mat[i][j];
                for(auto& [dr, dc]:direction){
                    if(i+dr<m && i+dr>=0 && j+dc<n && j+dc>=0){
                         if(mat[i+dr][dc+j]>=mat[i][j]) {
                            maxEle=max(maxEle,mat[i+dr][j+dc]);
                            break;
                         }
                    }
                }
                if(maxEle==mat[i][j]) return {i,j};
            }
        }
        return {0,0};
    }
};
