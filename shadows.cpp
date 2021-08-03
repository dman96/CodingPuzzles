#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* 
This is the solution to the Shadows of the Knight (Episode 1) problem on Codinggame (https://www.codingame.com/training/medium/shadows-of-the-knight-episode-1). 
The approach taken was to make Batman jump to the midpoints of a search window.
As the game progresses, the search window is gradually restricted making Batman converge to the location of the bomb.
Note that the direction convention is as follows:
	-Positive X is to the right
	-Positive Y is down

*/

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0; //Batman's Initial X-Position
    int Y0; //Batman's Initial Y-Position
    cin >> X0 >> Y0; cin.ignore();

    //Current Positions and Updated Positions
    int currentx = X0;
    int currenty = Y0;
    int newx;
    int newy;
    
    //Search Limits
    float max_x = W;
    float max_y = H;
    float min_x = 0;
    float min_y = 0;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

	//Up
       if (bombDir == "U")
       {
           max_y = currenty;
           newx = currentx;
           newy = currenty - ceil((max_y - min_y)/2);

       }

	//Right
        if (bombDir == "R")
        {
            min_x = currentx;
            newx = currentx + ceil((max_x - min_x)/2);
            newy = currenty;

            
        }

	//Down
        if (bombDir == "D")
        {
            min_y = currenty;
            newx = currentx;
            newy = currenty + ceil((max_y - min_y)/2);

            
        }

        //Left
        if (bombDir == "L")
        {
            max_x = currentx;
            newx = currentx - ceil((max_x - min_x)/2);
            newy = currenty;

        }

	//Upper Right
        if (bombDir == "UR")
        {
            min_x = currentx;
            max_y = currenty;

            newx = currentx + ceil((max_x - min_x)/2);
            newy = currenty - ceil((max_y - min_y)/2);

            
        }

	//Bottom Right
        if (bombDir == "DR")
        {
            min_x = currentx;
            min_y = currenty;

            newx = currentx + ceil((max_x - min_x)/2);
            newy = currenty + ceil((max_y - min_y)/2);
            
        }
	
	//Bottom Left
        if (bombDir == "DL")
        {
            max_x = currentx;
            min_y = currenty;

            newx = currentx - ceil((max_x - min_x)/2);
            newy = currenty + ceil((max_y - min_y)/2);

            
        }
        
	//Upper Left
        if (bombDir == "UL")
        {
            max_x = currentx;
            max_y = currenty;

            newx = currentx - ceil((max_x - min_x)/2);
            newy = currenty - ceil((max_y - min_y)/2);

        }

        // the location of the next window Batman should jump to.
        cout << newx << " " << newy << endl;

        //Update Batman's Location
        currentx = newx;
        currenty = newy;
    }
}
