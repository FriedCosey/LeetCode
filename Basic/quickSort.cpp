#include <iostream>
#include <vector>
using namespace std;

ostream& operator <<(ostream& os, const vector<int>& v){
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return os;
}
/*
void quickSort(vector<int>& nums, int left, int right){
    if(left >= right) 
        return;
    int cur = left; 
    for(int i = cur + 1; i <= right; i++)
        if(nums[i] < nums[left])
            swap(nums[i], nums[++cur]);
    swap(nums[left], nums[cur]);
    quickSort(nums, left, cur - 1);
    quickSort(nums, cur + 1, right);
}*/
void quickSort(vector<int>& nums, int left, int right){
    if(left >= right)
        return;
    int cur = left;
    for(int i = cur + 1; i <= right; i++){
        if(nums[i] < nums[left])
            swap(nums[i], nums[++cur]);
    }
    swap(nums[left], nums[cur]);
    quickSort(nums, left, cur - 1);
    quickSort(nums, cur + 1, right);

}
void swap(int &i, int &j){
	int temp = i;
	i = j;
	j = temp; 
}

int main(){
    //int nums[] = {10, -1, 2, 3, 4, 9, 77, 88, 20, 100};
    int nums[] = {3, 2, 1, 4, 5};
    vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
	quickSort(v, 0, v.size() - 1);
    cout << v;
    return 0;
}


