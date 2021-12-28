#include <iostream>
#include <stack>
#include <string>

/* 
This file contains the solution to problem 821C from CodeForces (https://codeforces.com/problemset/problem/821/C).
The algorithm uses a stack that holds box numbers. Whenever a box is commanded to be added, the box is pushed to the top of the stack. If a box is required to be removed, the algorithm matches the top of the stack with the "counter" variable. If the "counter" variable and the number at the top of the stack match, then the top of the stack is popped. Otherwise, if "counter" and the number at the top of the stack don't match, the stack is dumped. Finally, the "answer" variable is incremented by 1 because this indicates the boxes need to be reordered at this point.
*/

int main()
{
	//Variables and Storage
	std::stack<int> st; //Main Stack
	unsigned int counter = 1; //Box Removal Counter
	unsigned int answer = 0; //Answer Counter
	unsigned int moves; //Move Counter
	std::string command; //Action
	unsigned int box_no; //Box Number
	
	//Read number of moves
	std::cin >> moves;
	
	for (int i = 1; i <= 2*moves; i++)
	{
		std::cin >> command;
		
		if (command[0] == 'a')
		{
			std::cin >> box_no;
			st.push(box_no);
		}
		
		else if (command[0] == 'r')
		{
			if (!st.empty())
			{
				if (st.top() == counter)
				{
					st.pop();
				}
				
				else
				{
					while (!st.empty())
					{
						st.pop();
					}
					
					answer++;
				}
			}
			
			counter++;
		}
	}
	
	std::cout << answer << std::endl;
	
	return 0;
}
					
	 
	
