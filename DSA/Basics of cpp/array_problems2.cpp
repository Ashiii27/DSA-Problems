// #include<iostream>
// using namespace std;

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i];
//         if (i < n - 1) cout << " ";
//     }
//     cout << endl;
// }

// void rotateArray(int arr[],int n,int k){
//     do{int temp = arr[0];
//     for (int i = 1; i < n;i++){
//         arr[i - 1] = arr[i];
//     }
//     arr[n - 1] = temp;
//     k--;
//     } while (k > 0);
//     printArray(arr, n);
// }

// int main() {
//     int n;
//     cout << "enter the size of the array : ";
//     cin >> n;
//     int arr[n];
//     cout << "enter the elements of the array :";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int k;
//     cout << "how many time you want to rotate the array : ";
//     cin >> k;
//     rotateArray(arr, n,k);
//     return 0;
// }

//283. Move Zeroes

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int j=0;  // Pointer to place the next non-zero element
//         for(int i=0;i<nums.size();i++){
//             if (nums[i]!=0){
//                 // Swap current element with the element at index j 
//                 swap(nums[i],nums[j]);
            
//                 j++;  // Move j to the next index for placing non-zero
//             }
//         }
//     }
// };