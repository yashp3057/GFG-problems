class Disjointset{
public:

    vector<int> parents, size;

    Disjointset(int n){

        parents.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++)
            parents[i]=i;
    }

    int findparent(int node){

        if(node==parents[node])
            return node;

        return parents[node]=findparent(parents[node]);
    }

    void unionbysize(int u,int v){

        int up=findparent(u);
        int vp=findparent(v);

        if(up==vp)
            return;

        if(size[up]<size[vp]){

            parents[up]=vp;
            size[vp]+=size[up];
        }
        else{

            parents[vp]=up;
            size[up]+=size[vp];
        }
    }
};

class Solution {
public:

    int Solve(int n, vector<vector<int>>& edge) {

        Disjointset ds(n);

        int countextra=0;

        for(auto it:edge){

            int u=it[0];
            int v=it[1];

            if(ds.findparent(u)==ds.findparent(v))
                countextra++;
            else
                ds.unionbysize(u,v);
        }

        int components=0;

        for(int i=0;i<n;i++){

            if(ds.parents[i]==i)
                components++;
        }

        int ans=components-1;

        if(countextra>=ans)
            return ans;

        return -1;
    }
};