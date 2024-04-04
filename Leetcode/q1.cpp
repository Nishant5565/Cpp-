#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int index1, index2;
        index1 = -1;
        index2 = -1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n ; j++){
                if((nums[i] + nums[j]) == target){
                    index1 = i;
                    index2 = j;
                    break;
                }
            }
        }
        return {index1, index2};
}

int main(){
     vector<int> nums;
     nums = {3 , 2 , 4};
     int target;
     cout << "Enter the target element: ";
     cin >> target;
     vector<int> result = twoSum(nums, target);
     cout << result[0] << " " << result[1];
     return 0;
}