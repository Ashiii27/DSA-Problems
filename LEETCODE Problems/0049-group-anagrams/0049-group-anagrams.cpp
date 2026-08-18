class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map ;
        vector<vector<string>> ans ; 
        
        for(string s : strs){ 
            string t = s ;  
            sort(t.begin() , t.end()) ;       
            map[t].push_back(s);
        }

        for (auto&[key,value] : map){
            ans.push_back(value) ; 
        }

        return ans ; 
    }
};