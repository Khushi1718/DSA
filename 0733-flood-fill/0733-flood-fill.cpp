class Solution {
public:
    void dfs (int r , int c , vector<vector<int>>& image,int v,int color){
        if( image[r][c]==color) return;
        image[r][c]=color;
        // up 
        if(r-1 >=0 && image[r-1][c]==v){
            dfs(r-1,c,image,v,color);
        }
        // down 
        if(r+1<image.size() &&image[r+1][c]==v ){
            dfs(r+1,c,image,v,color);
        }
        // right
        if(c+1<image[0].size() && image[r][c+1]==v ){
           dfs(r,c+1,image,v,color);
        }
        //left 
        if(c-1>=0 && image[r][c-1]==v){
            dfs(r,c-1,image,v,color);
        }
    }

        
        
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
        int val = image[sr][sc];
        
         dfs (sr,sc , image ,val,color);
         return image;

    }
};