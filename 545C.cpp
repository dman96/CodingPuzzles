#include <iostream>

int main()
{

	int n;
	std::cout << "Enter the number of trees\n";
	std::cin >> n;


	int tree[n];
	int height[n];	

	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter a tree coordinate and height\n";
		std::cin>> tree[i] >> height[i];
	}


	return 0;
}
