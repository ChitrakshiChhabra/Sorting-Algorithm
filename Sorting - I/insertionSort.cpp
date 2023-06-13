#include <iostream>
#include <vector>
using namespace std;
// Time Complexity  O(n^2) -- Worst and Average case
//				    O(n) -- Best case (Array already sorted in ascending order.)
// Space Complexity O(1)
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void insertionSort(vector <int> &nums)
{
	for(int i = 1; i < nums.size(); i++)
	{
		int j = i;
		while(j > 0 && nums[j] < nums[j - 1])
		{
			swap(&nums[j], &nums[j - 1]);
			j--;
		}
	}
}
int main()
{
	cout << "Enter the size of the array:";
	int size;
	cin >> size;
	vector <int> nums(size, 0);
	
	for(int i = 0; i < size; i++)
		cin >> nums[i];
	
	insertionSort(nums);
	
	for(auto a: nums)
		cout << a << " ";
	cout << endl;
	return 0;
}