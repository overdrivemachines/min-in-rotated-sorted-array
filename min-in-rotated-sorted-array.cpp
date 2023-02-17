#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printv(vector<int> &nums) {
  for (auto n : nums)
    cout << n << " ";
  cout << endl;
}

// Runtime 5 ms Beats 43.8%
// Memory 10 MB Beats 97.91%

int findMin(vector<int>& nums) {
  // printv(nums);

  int nums_size = nums.size();

  // if vector nums is empty
  if (nums_size == 0)
    return 0;

  int left = nums[0];
  int right = nums[nums_size - 1];  

  // if the vector nums is not rotated return the 1st element
  if (left <= right)
    return left;
  if (nums_size == 2)
    return std::min(left, right);

  // left greater than right

  int left_index = 0;
  int right_index = nums_size - 1;
  int mid_index = right_index / 2;
  int min_num = min(nums[left_index], nums[right_index]);

  while(right_index - left_index > 1) {
    mid_index = (right_index - left_index) / 2 + left_index;
    min_num = min(min_num, nums[mid_index]);
    // cout << "Left:[" << left_index << "]:" << nums[left_index] << " Right:[" << right_index << "]:" << nums[right_index] << " Mid:[" << mid_index << "]:" << nums[mid_index] << " Minimum:" << min_num  << endl;

    if (nums[mid_index] <= nums[right_index])
      right_index = mid_index;
    else if (nums[mid_index] > nums[right_index]) {
      left_index = mid_index;
    }
    // return 0;
  }

  return min_num;
}

int main(int argc, char const *argv[]) {
  // vector<int> nums = {3,4,5,1,2};
  // vector<int> nums = {99, 92, 1,5,7,11,19,32,57};
  vector<int> nums = {11,13,15,17};
  cout << findMin(nums) << endl;
  return 0;
}
