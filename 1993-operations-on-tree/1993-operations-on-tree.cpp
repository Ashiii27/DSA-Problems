class LockingTree {
private:
bool dfs_check(int node)
{
    bool found= false;
    if(locked_by[node]!=-1)
    {
        locked_by[node]=-1;
        found=true;
    }

    //check the child

    for(auto child :children[node])
    {
        found |=dfs_check(child);
    }
    return found;
}
public:
    // define the parent , children , locked by vector
    vector<int>parent;
    vector<vector<int>>children;
    vector<int>locked_by;

    LockingTree(vector<int>& parent) {
        this->parent = parent;
        // first let's assign children
        // we know the nodes are from the 0 to n-1 
        // if the size is 5 then the nodes in the tree will be 
        // from 0 to 4 
        // to know about the parent who can be it can be all nodes 
        // or if we use the hash system n/2 will be becomes the parent of the children
        int n = parent.size();
        children.resize(n);

        // cause the 0 itself is the node of the tree so
        // i can say it is  big grand_dad from boondocks

        for(int i = 1;i<n;i++)    
        {
            children[parent[i]].emplace_back(i);
        }
        locked_by.resize(n, -1);
    }
    
    bool lock(int num, int user) {
        
        // check is the lock is false then it is not aqquired by not someone .
        if(locked_by[num]!=-1)
        {
            return false;
        }
        locked_by[num]=user;

        return true;
    }
    
    bool unlock(int num, int user) {
        // if the lock is not aqquired then it is worthless of doing that instruction
        if(locked_by[num]!=user)
        {
            return false;
        }
        // it tranform from true to false

        locked_by[num]= -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(locked_by[num]!=-1)
        {
            return false;

        }
        int p = parent[num];
        // this is to check the ancestors of the node 
        // perticular node which is not locked
        while(p!=-1)
        {
            if(locked_by[p]!=-1)
            {
                return false;
            }
            p = parent[p];
 
        }
        bool found=false;
        for(auto child :children[num])
        {
            found |=dfs_check(child);
        }

        if(found==false){ return false;}

        locked_by[num]=user;
        return true;

    }
};

