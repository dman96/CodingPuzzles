/*
The following is a working solution to CodeForces Problem - 507B
(https://codeforces.com/problemset/problem/507/B)

The solution consists of finding the length of a line connecting the center of the circle to the goal point. Next, the number of circles of the specified radius that could be fit along the line are computed. If a whole number of circles cannot be found from the computation, this means an extra move is required because the circle cannot be rotated along a tangent to the line connecting the goal and the center of the circle.
*/


#include <iostream>
#include <cmath>

int main()
{

	int r, x, y, x2, y2;
	
	std::cin >> r >> x >> y >> x2 >> y2;
	
	std::cout << ceil(hypot(x-x2,y-y2)/(2*r));
	
	return 0;
}
