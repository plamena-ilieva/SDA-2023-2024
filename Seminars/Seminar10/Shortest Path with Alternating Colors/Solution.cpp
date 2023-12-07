class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
         
     unordered_map<int,vector<int>> rgraph;
     unordered_map<int,vector<int>> bgraph;
     int steps=0;

     for(int i=0;i<redEdges.size();++i){
        rgraph[redEdges[i][0]].push_back(redEdges[i][1]);
     }

      for(int i=0;i<blueEdges.size();++i){
        bgraph[blueEdges[i][0]].push_back(blueEdges[i][1]);
     }

     vector<bool> vred(n,false);   // red visited
     vector<bool> vblue(n,false);  // blue visited

     vector<int> res(n,INT_MAX);
    
     queue<pair<int,char>> q; //node and previous edge color
      
     q.push({0,'#'});
     
      while(!q.empty()){
          
        int size=q.size();

        for(int s=0;s<size;++s){

          int u=q.front().first;
          char prev_edge=q.front().second; q.pop();
          
          if(steps<res[u]) res[u]=steps;

          if(prev_edge=='#'){ // if it is root node then we can visit both red and blue edge
            
            for(int j=0;j<rgraph[u].size();++j){

                int v=rgraph[u][j];
                if(!vred[v]){
                  vred[v]=true;
                  q.push({v,'r'});
                }
            }

            for(int j=0;j<bgraph[u].size();++j){

                int v=bgraph[u][j];
                 if(!vblue[v]){
                  vblue[v]=true;
                  q.push({v,'b'});
                 }
            }
            
          }
          else if (prev_edge=='r'){
           
            for(int j=0;j<bgraph[u].size();++j){

                int v=bgraph[u][j];
                  if(!vblue[v]){
                    vblue[v]=true;
                    q.push({v,'b'});
                  }
            }
          }
          else if (prev_edge=='b'){
             
            for(int j=0;j<rgraph[u].size();++j){

                int v=rgraph[u][j];
                  if(!vred[v]){
                  vred[v]=true;
                  q.push({v,'r'});
                 }
            }
          }
        }

       steps++;

     }

     for(int i=0;i<n;++i){
       if(res[i]==INT_MAX) 
        res[i]=-1;
     }
     
     return res;

    }
};