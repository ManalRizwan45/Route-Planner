#include<iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<sstream>  
using namespace std;
struct node {
	int px;
	int py;
	int x;
	int y;
	float h;
	float f;
	string str;	
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
				t.f = arr[j].f;
				t.str = arr[j].str;
				t.px = arr[j].px;
				t.py = arr[j].py;
				t.h = arr[j].h;

				arr[j].x = arr[j / 2].x;
				arr[j].y = arr[j / 2].y;
				arr[j].f = arr[j / 2].f;
				arr[j].str = arr[j / 2].str;
				arr[j].px = arr[j / 2].px;
				arr[j].py = arr[j / 2].py;
				arr[j].h = arr[j / 2].h;

				arr[j / 2].x = t.x;
				arr[j / 2].y = t.y;
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
			t.f = arr[i].f;
			t.str = arr[i].str;
			t.px = arr[i].px;
			t.py = arr[i].py;
			t.h = arr[i].h;

			arr[i].x = arr[smallest].x;
			arr[i].y = arr[smallest].y;
			arr[i].f = arr[smallest].f;
			arr[i].str = arr[smallest].str;
			arr[i].px = arr[smallest].px;
			arr[i].py = arr[smallest].py;
			arr[i].h = arr[smallest].h;

			arr[smallest].x = t.x;
			arr[smallest].y = t.y;
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

			cout << arr[i].x << " " << arr[i].y << " " << arr[i].f << endl;
		}
	}

	bool deletemin(node& temp)
	{
		if (!isempty())
		{
			temp.x = arr[1].x;
			temp.y = arr[1].y;
			temp.f = arr[1].f;
			temp.h = arr[1].h;
			temp.str = arr[1].str;
			temp.px = arr[1].px;
			temp.py = arr[1].py;

			arr[1].x = arr[totalitems].x;
			arr[1].y = arr[totalitems].y;
			arr[1].f = arr[totalitems].f;
			arr[1].str = arr[totalitems].str;
			arr[1].px = arr[totalitems].px;
			arr[1].py = arr[totalitems].py;
			arr[1].h = arr[totalitems].h;

			totalitems--;
			heapify(1);
			return true;
		}
		else
		{
			return false;
		}
	}

};
// function for printing the grid
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
			else if (j <= 9)
			{

			if (i == 0 && j == 0)
			{
				cout << "Initial State" << endl;
				cout << "(" << grid[i][j].x << "," << grid[i][j].y << ")" << " ";
			}
			else
			{
				cout << "(" << grid[i][j].x << "," << grid[i][j].y << ")" << " ";
			}
			}
			else
			{
		      if (i == 19 && j == 19)
			{
			cout << "(" << grid[i][j].x << "," << grid[i][j].y << ")" <<"  ";
			cout << "Goal State ";
			}
			else
			{
			cout << "(" << grid[i][j].x << "," << grid[i][j].y << ")" << "  ";
			}
			}
			
		}
		cout << endl;
	}
}
//function to calculate the heuristic values using euclidean distance
void calculateED(node arr[][20], node n)
{
	float a;
	float b;
	float c;
	            //cout << "Heuristic Value:" << endl;

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
							a = pow((n.x - arr[i][j].x), 2);
							b = pow((n.y - arr[i][j].y), 2);
							c = a + b;
							arr[i][j].h = sqrt(c);
							//cout << "(" << i << "," << j << ")" << ":" << arr[i][j].h << endl;

						}
					}
				}
}
// function for running the A* Algorithm
int Astar(node grid[][20],node source,node des)
{
	bool check[20][20];

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			check[i][j] = false;
		}
	}

	// calculating the heuristic values
	calculateED(grid,des);

	// intializing the min heap
	minheap list(200);

	// setting initial node's parent coordinates
	source.px = -1;
	source.py = -1;

	// Running the A* Algorithm
	int count = 1;
	int i = source.x;
	int j = source.y;

	while (1)
	{

		if (grid[i + 1][j].str != "obstacle" && ((i + 1) >= 0 && (i + 1) <= 19)
			&& (grid[i + 1][j].x != grid[i][j].px || grid[i + 1][j].y != grid[i][j].py)
			&& check[i + 1][j] == false)

		{

			grid[i + 1][j].px = grid[i][j].x;
			grid[i + 1][j].py = grid[i][j].y;
			grid[i + 1][j].f = grid[i + 1][j].h + count;
			list.insert(grid[i + 1][j]);
			check[i + 1][j] = true;

		}
		if (grid[i - 1][j].str != "obstacle" && ((i - 1) >= 0 && (i - 1) <= 19)
			&& (grid[i - 1][j].x != grid[i][j].px || grid[i - 1][j].y != grid[i][j].py)
			&& check[i - 1][j] == false)

		{
			grid[i - 1][j].px = grid[i][j].x;
			grid[i - 1][j].py = grid[i][j].y;
			grid[i - 1][j].f = grid[i - 1][j].h + count;
			list.insert(grid[i - 1][j]);
			check[i - 1][j] = true;

		}
		if (grid[i][j + 1].str != "obstacle" && ((j + 1) >= 0 && (j + 1) <= 19)
			&& (grid[i][j + 1].x != grid[i][j].px || grid[i][j + 1].y != grid[i][j].py)
			&& check[i][j + 1] == false)

		{

			grid[i][j + 1].px = grid[i][j].x;
			grid[i][j + 1].py = grid[i][j].y;
			grid[i][j + 1].f = grid[i][j + 1].h + count;
			list.insert(grid[i][j + 1]);
			check[i][j + 1] = true;

		}
		if (grid[i][j - 1].str != "obstacle" && ((j - 1) >= 0 && (j - 1) <= 19)
			&& (grid[i][j - 1].x != grid[i][j].px || grid[i][j - 1].y != grid[i][j].py)
			&& check[i][j - 1] == false)

		{
			grid[i][j - 1].px = grid[i][j].x;
			grid[i][j - 1].py = grid[i][j].y;
			grid[i][j - 1].f = grid[i][j - 1].h + count;
			list.insert(grid[i][j - 1]);
			check[i][j - 1] = true;

		}
		node temp;
		 // extracting the min node from heap
		
		if (list.deletemin(temp) == true)
		{
			// when goal node is discovered
			if (temp.x == des.x && temp.y == des.y)
			{

				//cout << "Cost: " << temp.f << endl;
				return temp.f;
			}
			else
			{
				i = temp.x;
				j = temp.y;
				count++;

			}
		}
		else
		{
			return 400;
		}
		

	}

}
// function for generating the chromosomes
void chromosome_gen(node* solutions,node grid[][20])
{
	bool check[20][20];
	int row = 0;
	int col = 0;
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			check[i][j] = false;
		}
	}

	solutions[0].x = 0;
	solutions[0].y = 0;
	solutions[0].str = grid[0][0].str;
	solutions[9].x = 19;
	solutions[9].y = 19;
	solutions[9].str= grid[19][19].str;
	check[0][0] = true;
	check[19][19] = true;


	for (int i = 1; i < 9 ;i++)
	{
		while (1)
		{   
			row = rand() % 19;
			col = rand() % 19;
			if ( check[row][col] == false )
			{
				solutions[i].x = row;
				solutions[i].y = col;
				solutions[i].str = grid[row][col].str;
				check[row][col] = true;
				break;
			}
			
		}
	}


}
// function for calculating the fitness of the chromosome
void fitness_fun(int* fitness,node* solutions,node grid[][20],int index)
{
	fitness[index] = 0;
	for (int i = 0; i < 10; i++)
	{   
		if (i < 9)
		{
			/*cout << solutions[i].str << endl;
			cout << solutions[i+1].str << endl;*/

			if (solutions[i].str!="obstacle" && solutions[i + 1].str != "obstacle")
			{
				fitness[index] = fitness[index] + (Astar(grid, solutions[i], solutions[i + 1]));
			}
			else
			{
				fitness[index] = fitness[index] + 400;
			}
		}
		else
		{
			continue;
		}
	}
	
	//cout << "fitness: " << fitness[index] << endl;
}

// Function to calculate the cumulative fitness
void cumulative_frequency(int* fitness, int* cfitness)
{
	cfitness[0] = fitness[0];
	cfitness[1] = fitness[1] + fitness[0];
	cfitness[2] = fitness[2] + fitness[1] + fitness[0];
	cfitness[3] = fitness[3] + fitness[2] + fitness[1] + fitness[0];
	cfitness[4] = fitness[4] + fitness[3] + fitness[2] + fitness[1] + fitness[0];
	cfitness[5] = fitness[5] + fitness[4] + fitness[3] + fitness[2] + fitness[1] + fitness[0];
	cfitness[6] = fitness[6] + fitness[5] + fitness[4] + fitness[3] + fitness[2] + fitness[1] + fitness[0];
	cfitness[7] = fitness[7] + fitness[6] + fitness[5] + fitness[4] + fitness[3] + fitness[2] + fitness[1] + fitness[0];
	cfitness[8] = fitness[8] + fitness[7] + fitness[6] + fitness[5] + fitness[4] + fitness[3] + fitness[2] + fitness[1] + fitness[0];
	cfitness[9] = fitness[9] + fitness[8] + fitness[7] + fitness[6] + fitness[5] + fitness[4] + fitness[3] + fitness[2] + fitness[1] + fitness[0];
}
// function to find the least fit chromosomes
void find_least_fit(int* fitness, int& index1, int& index2)
{
	int m1 = -1;

	for (int i = 0; i < 10; i++)
	{
		if (m1 < fitness[i])
		{
			m1 = fitness[i];
			index1 = i;
		}
	}

	int m2 = -1;


	for (int i = 0; i < 10; i++)
	{
		if (m2 < fitness[i] && i != index1)
		{
			m2 = fitness[i];
			index2 = i;
		}
	}

}
// function for doing two point crossover
void two_point_crossover(int* fitness, node** solutions, int* cfitness)
{
	int range = cfitness[9] + 1;
	int candidate1;
	int candidate2;
	int p1;
	int p2;
	int x;
	int y;
	int index1;
	int index2;
	node c1[10];
	node c2[10];

	// selecting the parents
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			candidate1 = rand() % range;

			for (int j = 0; j < 10; j++)
			{
				if (candidate1 <= cfitness[j])
				{
					p1 = j;
					break;
				}
			}
		}
		else
		{
			while (1)
			{
				candidate2 = rand() % range;
				if (candidate2 != candidate1)
				{
					break;
				}
			}

			for (int j = 0; j < 10; j++)
			{

				if (candidate2 <= cfitness[j])
				{

					p2 = j;
					break;
				}
			}

		}

	}

	x = rand() % 10;
	y = rand() % 10;
    
	// performing the two point crossover
	for (int i = 0; i < 10; i++)
	{
		if (x < y)
		{
			if (i >= x && i <= y)
			{
				c1[i].x = solutions[p2][i].x;
				c1[i].y = solutions[p2][i].y;
				c1[i].str = solutions[p2][i].str;
				c2[i].x = solutions[p1][i].x;
				c2[i].y = solutions[p1][i].y;
				c2[i].str= solutions[p1][i].str;
			}
			else
			{
				c1[i].x = solutions[p1][i].x;
				c1[i].y = solutions[p1][i].y;
				c1[i].str = solutions[p1][i].str;
				c2[i].x = solutions[p2][i].x;
				c2[i].y = solutions[p2][i].y;
				c2[i].str = solutions[p2][i].str;
			}
		}
		else if (x > y)
		{
			if (i >= y && i <= x)
			{
				c1[i].x = solutions[p2][i].x;
				c1[i].y = solutions[p2][i].y;
				c1[i].str = solutions[p2][i].str;
				c2[i].x = solutions[p1][i].x;
				c2[i].y = solutions[p1][i].y;
				c2[i].str = solutions[p1][i].str;
			}
			else
			{
				c1[i].x = solutions[p1][i].x;
				c1[i].y = solutions[p1][i].y;
				c1[i].str = solutions[p1][i].str;
				c2[i].x = solutions[p2][i].x;
				c2[i].y = solutions[p2][i].y;
				c2[i].str = solutions[p2][i].str;
			}
		}
		else
		{
			if (i >= x)
			{
				c1[i].x = solutions[p2][i].x;
				c1[i].y = solutions[p2][i].y;
				c1[i].str = solutions[p2][i].str;
				c2[i].x = solutions[p1][i].x;
				c2[i].y = solutions[p1][i].y;
				c2[i].str= solutions[p1][i].str;
			}
			else
			{
				c1[i].x = solutions[p1][i].x;
				c1[i].y = solutions[p1][i].y;
				c1[i].str = solutions[p1][i].str;
				c2[i].x = solutions[p2][i].x;
				c2[i].y = solutions[p2][i].y;
				c2[i].str = solutions[p2][i].str;
			}
		}
	}

	/*cout << p1 + 1 << " " << p2 + 1 << endl;*/

	// finding the least fit chromosomes and replacing them with the children
	find_least_fit(fitness, index1, index2);

	for (int i = 0; i < 10; i++)
	{
		solutions[index1][i].x = c1[i].x;
		solutions[index1][i].y = c1[i].y;
		solutions[index2][i].x = c2[i].x;
		solutions[index2][i].y = c2[i].y;
	}

	
}
// function to see if the diversity between the chromosomes is finished
bool check_fitness(int* fitness)
{
 int x = fitness[0];
 

	for (int i = 1; i < 10; i++)
	{
		if (x != fitness[i])
		{
			return false;
	    }
	}
	
	return true;
}
// function for printing the chromosome
void print_chromosome(node** solutions)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Chromosome: " << i + 1 << endl;
		for (int j = 0; j < 10; j++)
		{
			cout << "(" << solutions[i][j].x << "," << solutions[i][j].y << ")" << " ";
		}
		cout << endl;

	}
}
// function to find the chromosome with the best fitness
int find_best_solution(int* fitness)
{
	int min = 999999;
	int index = -1;
	
	for (int i = 0; i < 10; i++)
	{
		if (min > fitness[i])
		{
			min = fitness[i];
			index = i;
		}
	}
	return index;
}
int main()
{
	node grid[20][20];
	node** solutions = new node* [10];
	int* fitness = new int[10];
	int* cfitness = new int[10];
	int r;
	int c;
	int count = 1;
	int index;

	for (int i = 0; i < 10; i++)
	{
		solutions[i] = new node[10];
	}
	

	// assigning the nodes the x and y coordinates
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			grid[i][j].x = i;
			grid[i][j].y = j;
			grid[i][j].str = ".";
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
	  cout << endl;

	
		// generating chromosomes
		for (int i = 0; i < 10; i++)
		{
			chromosome_gen(solutions[i],grid);
			
		}
		

			while (1)
			{

				// calculating the fitness
				for (int i = 0; i < 10; i++)
				{
					fitness_fun(fitness, solutions[i], grid, i);
					
				}

				
				if (count==100)
				{
					index=find_best_solution(fitness);
					cout << "Best Solution Generated By GA:" << endl;
					cout << "Generation:" << count << endl;
					cout << "Chromosome:" << 1 << endl;
					for (int j = 0; j < 10; j++)
					{
						cout << "(" << solutions[index][j].x << "," << solutions[index][j].y << ")" << " ";

					}
					cout << endl;
					cout << "Cost: " << fitness[index] << endl;
					break;
				}

				//calculating cumulative fitness
				cumulative_frequency(fitness, cfitness);

				
				//two-point crossover
				two_point_crossover(fitness, solutions, cfitness);

				
				
				
				count++;
			}
		
		
			cout << endl;
			cout << "Comparison of GA with A* Algorithm:" << endl;
			cout << "Cost of Path Generated by GA: " << fitness[index] << endl;
			cout << "Cost of Path Generated by A * Algorithm: " << Astar(grid, grid[0][0], grid[19][19]) << endl;

		
	

	

	system("pause");
	return 0;
}