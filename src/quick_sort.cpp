#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> & array,int first,int last)
{
	if(first >= last) return;

	int left = first, right = last;
	int& key = array[right];
	//int& key = array[left]; // 为什么用第一个元素不行？
	while(left < right)
	{
		while(left < right && array[left] >= key)
		{
			++left;
		}
		while(left < right && array[right] <= key)
		{
			--right;
		}
		swap(array[left],array[right]);
	}
	swap(array[left],key);

	quick_sort(array,first,left - 1);
	quick_sort(array,left + 1,last);
}

int main(int argc, char *argv[])
{
	vector<int> nums;
	int k = 0;
	for(int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		nums.push_back(num);
	}

	cout << "qsort: " << endl;
	quick_sort(nums, 0, nums.size() - 1);
	for(int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}
