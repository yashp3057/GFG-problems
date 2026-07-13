class Disjointset{
  public:
  
  vector<int>parents,size;

  Disjointset(int n){
       parents.resize(n);
       size.resize(n,1);
       
       for(int i=0; i<n; i++){
           parents[i]=i;
       }
       
       
       
       
   }
   
   int finduparent(int node){
       
       if(node==parents[node]) return node;
       
       return finduparent(parents[node]);
       
   }
   
   void unionbysize(int u,int v){
       
       int up=finduparent(u);
       int vp=finduparent(v);
       
       if(up==vp) return;
       
       if(size[up]<size[vp]){
           parents[up]=vp;
           size[vp]+=size[up];
       }
       else{
           parents[vp]=up;
           size[up]+=size[up];
           
       }

   } 
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        sort(edges.begin(),edges.end(),
         [](vector<int>&a, vector<int>&b){
             
              return a[2]<b[2];
             
         });
         
         Disjointset ds(V);
         int sum=0;
         for(auto it:edges){
           
           int u=it[0];
           int v=it[1];
           int w=it[2];
           
           if(ds.finduparent(u)!=ds.finduparent(v)){
               sum+=w;
               ds.unionbysize(u,v);
               
           }
           
         }
         return sum;
         
    }
};