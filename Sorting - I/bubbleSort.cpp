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
void bubbleSort(vector <int> &nums)
{
	for(int i = nums.size() - 1; i > 0; i--)
	{
		int countSwaps = 0;
		for(int j = 0; j < i; j++)
		{
			if(nums[j] > nums[j + 1])
			{
				swap(&nums[j], &nums[j + 1]);
				countSwaps++;
			}
				
		}
		if(countSwaps == 0) break;
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
	
	bubbleSort(nums);
	
	for(auto a: nums)
		cout << a << " ";
	cout << endl;
	
	return 0;
}