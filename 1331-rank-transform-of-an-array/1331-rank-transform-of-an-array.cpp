class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Create a copy of the array
        vector<int> copy;
        unordered_map<int,int> mpp;

        for(int i = 0; i < n; i++) {
            copy.push_back(arr[i]);
        }
        
        // Step 2: Sort the copy
        sort(copy.begin(), copy.end());
        
        // Step 3: Build rank mapping
        int temp = 1;
        for(int i = 0; i < n; i++) {
            if(mpp[copy[i]] == 0) {
                mpp[copy[i]] = temp;  // Assign rank to new unique value
                temp++;               // Increment for next unique value
            }
            // Duplicates automatically get skipped (already in map)
        }
        
        // Step 4: Map original array to ranks
        for(int i = 0; i < n; i++) {
            arr[i] = mpp[arr[i]];
        }
        
        // Step 5: Return result
        return arr;
    }
};