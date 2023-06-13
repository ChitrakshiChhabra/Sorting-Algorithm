#include <iostream>
#include <vector>
// Time Complexity  O(nlogn) -- Best, Average and Worst Case.
// Space Complexity O(1)
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int quickSort(vector <int> &nums, int low, int high)
{
	int pivot = low, i = low, j = high;
	while(i < j)
	{
		while(i < high && nums[i] <= nums[pivot]) i++;
		while(j > low && nums[j] > nums[pivot]) j--;
		if(i < j)
			swap(&nums[i], &nums[j]);
	}
	swap(&nums[pivot], &nums[j]);
	return j;
}
void qs(vector <int> &nums, int low, int high)
{
	if(low < high)
	{
		int partitionIndex = quickSort(nums, low, high);
		qs(nums, low, partitionIndex - 1);
		qs(nums, partitionIndex + 1, high);
	}
}
int main()
{
	vector <int> nums = {4,6,2,5,7,9,1,3};
	cout << "Before Sorting..." << endl;
	for(auto a: nums)
		cout << a << " ";
	cout << endl << "After Sorting..." << endl;
	qs(nums, 0, nums.size() - 1);
	for(auto a: nums)
		cout << a << " ";
	cout << endl;
	return 0;
}