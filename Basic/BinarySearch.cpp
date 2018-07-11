#include <iostream>
#include <vector>
using namespace std;

class BinarySearch {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while(low <= high){
            mid = (low + high) / 2;
			cout << mid << endl;
            if(nums[mid] > target){
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else
                return mid;
        }
        return target > nums[mid] ? mid + 1 : mid;
    }
};

int main(){
	BinarySearch tester;	
	int num[] = {1, 3, 6, 7};
	vector<int> nums(num, num + 4);
	cout << tester.searchInsert(nums, 8) << endl;
}
