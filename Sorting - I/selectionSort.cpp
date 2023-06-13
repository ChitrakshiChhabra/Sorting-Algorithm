#include <iostream>
#include <vector>
using namespace std;

// Time Complexity  O(n^2) -- Best, Average and Worst.
// Space Complexity O(1)
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectionSort(vector <int> &nums)
{
	for(int i = 0; i < nums.size() - 1; i++)
	{
		int min = i;
		for(int j = i + 1; j < nums.size(); j++)
		{
			if(nums[j] < nums[min])
				min = j;
		}
		swap(&nums[i], &nums[min]);
	}
}
int main()
{
	int size;
	cout << "Enter the size of array:";
	cin >> size;
	vector <int> nums(size, 0);
	for(int i = 0; i < size; i++)
		cin >> nums[i];
	
	selectionSort(nums);
	for(auto a: nums)
		cout << a << " ";
	cout << endl;

	return 0;
}