#include<iostream>
#include <cmath>
#include <Windows.h>
#include <cstdlib>
#include<stdlib.h>
using namespace std;
// node class
struct node {
	int px;
	int py;
  string str;
	int x;
	int y;
	float h;
	int g;
	float f;
};
// min heap class implementation
class minheap
{
public:
	node* arr;
	int capacity;
	int totalitems;

	minheap()
	{
		arr = nullptr;
	}
	minheap(int cap)
	{
		capacity = cap;
		totalitems = 0;
		arr = new node[capacity];
	}
	bool isempty()
	{
		if (totalitems == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void insert(node d)
	{
		if (totalitems + 1 != capacity)
		{

			totalitems++;
			arr[totalitems].x = d.x;
			arr[totalitems].y = d.y;
			arr[totalitems].f = d.f;
			arr[totalitems].g = d.g;
			arr[totalitems].h = d.h;
			arr[totalitems].str = d.str;
			arr[totalitems].px = d.px;
			arr[totalitems].py = d.py;
			

			int j = totalitems;
			while (j > 1 && arr[j].f < arr[j / 2].f)
			{
				node t;

				t.x = arr[j].x;
				t.y = arr[j].y;
				t.g = arr[j].g;
				t.f = arr[j].f;
				t.str = arr[j].str;
				t.px = arr[j].px;
				t.py = arr[j].py;
				t.h = arr[j].h;

				arr[j].x = arr[j / 2].x;
				arr[j].y = arr[j / 2].y;
				arr[j].g = arr[j / 2].g;
				arr[j].f = arr[j / 2].f;
				arr[j].str = arr[j / 2].str;
				arr[j].px = arr[j / 2].px;
				arr[j].py = arr[j / 2].py;
				arr[j].h = arr[j / 2].h;

				arr[j / 2].x = t.x;
				arr[j / 2].y = t.y;
				arr[j / 2].g = t.g;
				arr[j / 2].f = t.f;
				arr[j / 2].str = t.str;
				arr[j / 2].px = t.px;
				arr[j / 2].py = t.py;
				arr[j / 2].h = t.h;

				j = j / 2;
			}
			
		}
		else
		{

			cout << "Min heap is full" << endl;

		}
		
	}
	void heapify(int i)
	{
		int smallest = i;
		if (2 * i <= totalitems && arr[smallest].f > arr[2 * i].f)
		{
			smallest = 2 * i;
		}
		if (2 * i + 1 <= totalitems && arr[smallest].f > arr[2 * i + 1].f)
		{
			smallest = 2 * i + 1;
		}
		if (smallest != i)
		{
			node t;
			t.x = arr[i].x;
			t.y = arr[i].y;
			t.g = arr[i].g;
			t.f = arr[i].f;
			t.str = arr[i].str;
			t.px = arr[i].px;
			t.py = arr[i].py;
			t.h = arr[i].h;

			arr[i].x = arr[smallest].x;
			arr[i].y = arr[smallest].y;
			arr[i].g = arr[smallest].g;
			arr[i].f = arr[smallest].f;
			arr[i].str = arr[smallest].str;
			arr[i].px = arr[smallest].px;
			arr[i].py = arr[smallest].py;
			arr[i].h = arr[smallest].h;

			arr[smallest].x = t.x;
			arr[smallest].y = t.y;
			arr[smallest].g = t.g;
			arr[smallest].f = t.f;
			arr[smallest].str = t.str;
			arr[smallest].px = t.px;
			arr[smallest].py = t.py;
			arr[smallest].h = t.h;

			heapify(smallest);

		}
	}
	void print()
	{
		cout << "printing list :" << endl;
		for (int i = 1; i <= totalitems; i++)
		{
			
			cout << arr[i].x<<" "<<arr[i].y<<" "<<arr[i].f<< endl;
		}
	}
	
	void deletemin(node & temp)
	{
		if (!isempty())
		{
			temp.x = arr[1].x;
			temp.y = arr[1].y;
			temp.f = arr[1].f;
			temp.g = arr[1].g;
			temp.h = arr[1].h;
			temp.str = arr[1].str;
			temp.px = arr[1].px;
			temp.py = arr[1].py;

			arr[1].x = arr[totalitems].x;
			arr[1].y = arr[totalitems].y;
			arr[1].g = arr[totalitems].g;
			arr[1].f = arr[totalitems].f;
			arr[1].str = arr[totalitems].str;
			arr[1].px = arr[totalitems].px;
			arr[1].py = arr[totalitems].py;
			arr[1].h = arr[totalitems].h;

			totalitems--;
			heapify(1);
		}
	}

};
//function to calculate the heuristic values using euclidean distance
void calculateED(node arr[][20]) 
{
	float a;
	float b;
	float c;
	cout << "heuristic values" << endl;
	for (int i = 0; i < 20; i++) 
	{
		for (int j = 0; j < 20; j++) 
		{
			if (arr[i][j].str == "obstacle")
			{
				continue;
			}
			else
			{
				a = pow((19 - arr[i][j].x), 2); 
				b = pow((19 - arr[i][j].y), 2); 
				c = a + b;
				arr[i][j].h = sqrt(c);
				cout << "(" << i << "," << j << ")" << ":" << arr[i][j].h << endl;
				
			}
		}
	}

}
void printgrid(node grid[][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			   if (grid[i][j].str == "obstacle")
			   {
				cout << grid[i][j].str << " ";
			   }
			
				else if (i == 0 && j == 0)
				{
					cout << "Initial State" << endl;
					cout << "CAR"<<"   ";
				}
				else if (i == 19 && j == 19)
				{
					
					cout << "Goal State ";
				}
				else
			   {
				   cout << "---" << " ";
			   }	
		}
		cout << endl;
	}
}
bool ifexisted(bool arr[][20], int a , int b)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (i == a && b == j && arr[i][j] == true)
			{
				return true;
			}
			else if (i == a && b == j && arr[i][j] == false)
			{
				return false;
			}
		}

	}
	
}

int main()
{
	node grid[20][20];
	bool check[20][20];
	int r;
	int c;
	// assigning the nodes the x and y coordinates
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			grid[i][j].x = i;
			grid[i][j].y = j;
			grid[i][j].str = ".";
			check[i][j] = false;
			
		}
	}
	// creating obstacles
	for (int i = 0; i < 100; i++) 
	{
		r = rand() % 19; 
		c = rand() % 19; 
		if (r == 0 && c == 0)
		{
			continue;
		}
		if (r == 19 && c == 19)
		{
			continue;
		}
		grid[r][c].str = "obstacle";
	}
	// printing the grid
	printgrid(grid);
	Sleep(2000);
	system("CLS");


	// assigning heuristic values
	calculateED(grid);
	Sleep(2000);
	system("CLS");

	// intializing the min heap
	minheap list(200);

	// setting initial node's parent coordinates
	grid[0][0].px = -1;
	grid[0][0].py = -1;

	// Running the A* Algorithm
	int count = 1;
	int i = 0;
	int j = 0;

	while(1) 
	{
		
		if (grid[i + 1][j].str != "obstacle" && ((i + 1) >= 0 && (i + 1) <= 19) 
			&& (grid[i + 1][j].x != grid[i][j].px || grid[i + 1][j].y != grid[i][j].py) 
			&& check[i + 1][j]==false)
			
		{  
			
			grid[i + 1][j].px = grid[i][j].x;
			grid[i + 1][j].py = grid[i][j].y;
			grid[i + 1][j].f = grid[i + 1][j].h + count;
			list.insert(grid[i + 1][j]);
			check[i + 1][j] = true;
			
		}
		if (grid[i - 1][j].str != "obstacle" && ((i - 1) >= 0 && (i - 1) <= 19)
		&&  (grid[i-1][j].x!=grid[i][j].px || grid[i - 1][j].y != grid[i][j].py)
			&& check[i - 1][j]==false)
			
		{
			grid[i - 1][j].px = grid[i][j].x;
			grid[i - 1][j].py = grid[i][j].y;
			grid[i - 1][j].f = grid[i - 1][j].h + count;
			list.insert(grid[i - 1][j]);
			check[i - 1][j] = true;
			
		}
		if (grid[i][j + 1].str != "obstacle" && ((j + 1) >= 0 && (j + 1) <= 19)
			&& ( grid[i][j+1].x != grid[i][j].px || grid[i][j+1].y != grid[i][j].py)
			&& check[i][j + 1]==false)
			
		{
			
			grid[i][j+1].px = grid[i][j].x;
			grid[i][j+1].py = grid[i][j].y;
			grid[i][j + 1].f = grid[i][j + 1].h + count;
			list.insert(grid[i][j + 1]);
			check[i][j + 1] = true;
			
		}
		if (grid[i][j - 1].str != "obstacle" && ((j - 1) >= 0 && (j - 1) <= 19)
			&& (grid[i][j-1].x != grid[i][j].px || grid[i][j-1].y != grid[i][j].py)
			&& check[i][j - 1]==false)
			
		{
			grid[i][j-1].px = grid[i][j].x;
			grid[i][j-1].py = grid[i][j].y;
			grid[i][j - 1].f = grid[i][j - 1].h + count;
			list.insert(grid[i][j - 1]);
			check[i][j - 1] = true;
			
		}
		node temp;
		list.deletemin(temp); // extracting the min node from heap
		// printing the grid
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (i == temp.x && j == temp.y)
				{
					cout << "CAR" << "   ";
				}
				else if (grid[i][j].str == "obstacle")
				{
					cout << grid[i][j].str<<" ";
				}
				
				else if (i == 0 && j == 0)
					{
						cout << "Initial State  ";
						
					}
					else if (i == 19 && j == 19)
					{
						
						cout << "Goal State  ";
					}

					else
					{
						
						cout << "---" << " ";
					}	
				
			}
			cout << endl;
		}
		Sleep(1000);
		system("CLS");
		// when goal node is discovered
		if (temp.x == 19 && temp.y == 19)
		{
			
			cout <<"Cost: "<<temp.f << endl;
			break;
		}
		else
		{
			i = temp.x;
			j = temp.y;
			count++;
			
		}
		
		
	}
		
	
	
	system("pause");
	return 0;
}

