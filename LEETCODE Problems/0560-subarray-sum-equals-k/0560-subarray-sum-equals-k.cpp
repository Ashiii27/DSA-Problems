class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> prefixCount;

        // Base case: A prefix sum of 0 has occurred once (before starting the array)
        prefixCount[0] = 1;    

        int prefixSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int required = prefixSum - k;

            // Check if (prefixSum - k) occurred previously
            if(prefixCount.find(required) != prefixCount.end()) {
                count += prefixCount[required];
            }

            // Record the current prefix sum count
            prefixCount[prefixSum]++;
        }
        return count;
    }
};


/*    ***********   Brute Force    **********

      int possibleSubArray = 0;
        
      for(int i = 0; i < nums.size(); i++) {     
        int sum = 0;
        for(int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if(sum == k) {
                possibleSubArray++;
            }
        }
      }
      return possibleSubArray;

      //Time Complexity = O(n2) , Space Complexity = O(n)

    */