#include <iostream>
#include <string>

/*
This is a solution to Leetcode Problem Number 423 (https://leetcode.com/problems/reconstruct-original-digits-from-english/)s
*/


int main()
{
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int *count = new int[26];
	int *num = new int[10];
	
	std::string input;
	
	
	std::cout << "Enter input String\n" << std::endl;
	std::cin >> input;
	
	for (auto &i : input)
	{
		for (int j = 0; j < 26; j++)
		{
			if (i == alphabet[j])
			{
				count[j]++;
			}
		}
	}
	
	//Count number of zeros, twos, fours, sixes and eights (Based on Unique Characters)
	num[0] = count[25];
	num[2] = count[22];
	num[4] = count[20];
	num[6] = count[23];
	num[8] = count[6];
	
	//Count number of ones, threes, fives, sevens, nines (Based on Non-Unique Characters)
	num[1] = count[14] - num[2] - num[4] - num[0];
	num[3] = count[7] - num[8];
	num[5] = count[5] - num[4];
	num[7] = count[18] - num[6];
	num[9] = count[8] - num[6] - num[8] - num[5];
	
	for (int i = 0; i <= 5; i++)
	{
		if (i <= 5 && num[i] > 0)
		{
			for (int j = 0 ; j < num[i]; j++)
			{
				std::cout << i;
			}
		}
	}
	
	for (int i = 9; i > 5; i--)
	{
		if (num[i] > 0)
		{
			for (int j = 0; j < num[i]; j++)
			{
				std::cout << i;
			}
		}
	}

	std::cout << "\n";
	return 0;
}
