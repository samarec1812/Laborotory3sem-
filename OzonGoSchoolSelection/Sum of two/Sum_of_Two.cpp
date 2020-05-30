#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int target;
	vector<int> nums;
	ifstream inputFile;

	inputFile.open("input.txt");
	if (!inputFile)
	{
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	int x;
	int i = 0;
	while (inputFile >> x)
	{
		if (i == 0)
		{
			target = x;
			i++;
			continue;
		}

		if (x >= target || x < 0 || x > 999999999)
		{
			continue;
		}

		nums.push_back(x);
	}
	inputFile.close();

	sort(nums.begin(), nums.end());

	int result = 0;
	int left = 0;
	int right = nums.size() - 1;

	while (left < right)
	{
		int cur = nums[left] + nums[right];

		if (cur == target)
		{
			result = 1;
			break;
		}
		else
		{
			if (cur < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}

	ofstream outputFile;
	outputFile.open("output.txt");
	outputFile << result;
	outputFile.close();

	return 0;
}