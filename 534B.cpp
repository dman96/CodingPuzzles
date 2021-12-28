#include <iostream>


/*
This is a solution for problem 534B of Codeforces (Covered Path). To determine the maximum distance travelled, we are going to approach each value of t from both the start and the end of the journey
(i.e. time = 0 and time = t). We will try to add d units of speed to each instance of t from both directions. Among the two values, we need to choose the minimum in order to ensure that we can meet our constraints.
*/

int main()
{
    int v1, v2, d, t, sum = 0;

    std::cin >> v1 >> v2;
    std::cin >> t >> d;

    for (int i = 0; i < t; i++)
    {
        sum += std::min(v1+d*i, v2+d*(t-i-1));
    }

    std::cout << sum << std::endl;
    return 0;
}
