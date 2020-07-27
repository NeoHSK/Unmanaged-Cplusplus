#include <iostream>

using namespace std;

int main()
{
	constexpr int size = 10;
	int nums[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << nums[2] << endl;

	nums[2] = 0;

	for (int num : nums)
	{
		cout << num<<endl;
	}

	return 0;

}
