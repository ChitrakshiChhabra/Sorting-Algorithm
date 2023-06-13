#include <iostream>
#include <vector>
using namespace std;
// Time Complexity  O(nlogn) -- Best, Average and Worst Case.
// Space Complexity O(n)
void merge(vector <int> &nums, int low, int mid, int high)
{
	int ptr1 = low, ptr2 = mid + 1;
	vector <int> ds;
	while(ptr1 <= mid && ptr2 <= high)
	{
		if(nums[ptr1] <= nums[ptr2])
		{
			ds.push_back(nums[ptr1]);
			ptr1++;
		}
		else
		{
			ds.push_back(nums[ptr2]);
			ptr2++;
		}
	}
	
	while(ptr1 <= mid)
	{
		ds.push_back(nums[ptr1]);
		ptr1++;
	}
	
	while(ptr2 <= high)
	{
		ds.push_back(nums[ptr2]);
		ptr2++;
	}
	
	for(int i = low; i <= high; i++)
		nums[i] = ds[i - low];
	
}	
void mergeSort(vector <int> &nums, int low, int high)
{
	if(low >= high) return;
	int mid = (low + high)/2;
	mergeSort(nums, low, mid);
	mergeSort(nums, mid + 1, high);
	merge(nums, low, mid, high);
}

int main()
{
	vector <int> nums = {3,1,2,4,15,6,2,4};
	
	cout << "Before sorting.." << endl;
	for(auto a: nums)
		cout << a << " ";
	cout << endl <<"After Sorting.." << endl;
	mergeSort(nums, 0, nums.size() - 1);
	for(auto a: nums)
		cout << a << " ";
	cout << endl;
	return 0;
}