#include<iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<sstream>  
using namespace std;

int compare_time3(char s1[], char s2[])
{
	string sub1;
	string sub2;
	int x;
	int y;
	int l1;
	int l2;

	l1 = strlen(s1);
	l2 = strlen(s2);

	sub1 = s1[0];
	if (s1[1] != ':')
	{
		sub1 = sub1 + s1[1];
	}

	sub2 = s2[0];
	if (s2[1] != ':')
	{
		sub2 = sub2 + s2[1];
	}

	x = stoi(sub1);
	y = stoi(sub2);

	if (x == y)
	{
		string sub3;
		string sub4;


		sub3 = s1[l1 - 2];
		if (sub3 == "0")
		{
			sub3 = s1[l1 - 1];
		}
		else
		{
			sub3 = sub3 + s1[l1 - 1];
		}

		sub4 = s2[l2 - 2];
		if (sub4 == "0")
		{
			sub4 = s2[l2 - 1];
		}
		else
		{
			sub4 = sub4 + s2[l2 - 1];
		}
		x = stoi(sub3);
		y = stoi(sub4);

		if (x == y)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	else
	{
		return 0;
	}

}


int compare_time2(char s1[], char s2[])
{
	string sub1;
	string sub2;
	int x;
	int y;
	int l1;
	int l2;

	l1 = strlen(s1);
	l2 = strlen(s2);

	sub1 = s1[0];
	if (s1[1] != ':')
	{
		sub1 = sub1 + s1[1];
	}

	sub2 = s2[0];
	if (s2[1] != ':')
	{
		sub2 = sub2 + s2[1];
	}

	x = stoi(sub1);
	y = stoi(sub2);

	if (x > y)
	{
		return 1;
	}
	else if (x < y)
	{
		return 0;
	}
	else
	{
		string sub3;
		string sub4;


		sub3 = s1[l1 - 2];
		if (sub3 == "0")
		{
			sub3 = s1[l1 - 1];
		}
		else
		{
			sub3 = sub3 + s1[l1 - 1];
		}

		sub4 = s2[l2 - 2];
		if (sub4 == "0")
		{
			sub4 = s2[l2 - 1];
		}
		else
		{
			sub4 = sub4 + s2[l2 - 1];
		}
		x = stoi(sub3);
		y = stoi(sub4);

		if (x > y)
		{
			return 1;
		}
		else if (x < y)
		{
			return 0;
		}
		else
		{
			return 1;
		}

	}

}
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
int compare_time1(char s1[], string s2)
{
	string sub1;
	string sub2;
	int x;
	int y;
	int l1;
	int l2;

	l1 = strlen(s1);
	l2 = s2.length();

	sub1 = s1[0];
	if (s1[1] != ':')
	{
		sub1 = sub1 + s1[1];
	}

	sub2 = s2[0];
	if (s2[1] != ':')
	{
		sub2 = sub2 + s2[1];
	}

	x = stoi(sub1);
	y = stoi(sub2);

	if (x > y)
	{
		return 1;
	}
	else if (x < y)
	{
		return 0;
	}
	else
	{
		string sub3;
		string sub4;


		sub3 = s1[l1 - 2];
		if (sub3 == "0")
		{
			sub3 = s1[l1 - 1];
		}
		else
		{
			sub3 = sub3 + s1[l1 - 1];
		}

		sub4 = s2[l2 - 2];
		if (sub4 == "0")
		{
			sub4 = s2[l2 - 1];
		}
		else
		{
			sub4 = sub4 + s2[l2 - 1];
		}
		x = stoi(sub3);
		y = stoi(sub4);

		if (x > y)
		{
			return 1;
		}
		else if (x < y)
		{
			return 0;
		}
		else
		{
			return 1;
		}

	}

}
void check_time_range(int* solutions, char arrival[][6], char departure[][6], char open[][6], 
	char close[][6], int & clash,int size[],char time_taken[3][6][3])
{
	for (int m = 0; m < 10; m++)
	{
		string x;
		string y;
		string z;
		string time;
		int x1;
		int y1;
		int sum;
		// extracting the time it will take for the dockyard to load or unload the ship
			 if (size[m] == 10000)
			 {
			 	x = time_taken[solutions[m]][0][0];
			 	x = x + time_taken[solutions[m]][0][1];
			 }
			 else if (size[m] == 15000)
			 {
			 	x = time_taken[solutions[m]][1][0];
			 	x = x + time_taken[solutions[m]][1][1];
			 }
			 else if (size[m] == 20000)
			 {
			 	x = time_taken[solutions[m]][2][0];
			 	x = x + time_taken[solutions[m]][2][1];
			 }
			 else if (size[m] == 30000)
			 {
			 	x = time_taken[solutions[m]][3][0];
			 	x = x + time_taken[solutions[m]][3][1];

			 }
			 else if (size[m] == 50000)
			 {
			 	x = time_taken[solutions[m]][4][0];
			 	x = x + time_taken[solutions[m]][4][1];

			 }
			 else
			 {
			 	x = time_taken[solutions[m]][5][0];
			 	x = x + time_taken[solutions[m]][5][1];
			 }

	    // extracting the minutes from the arrival time
		y = arrival[m];
		int l = y.length();
		z = y[l - 2];
		z = z + y[l - 1];

		if (z == "00")
		{
			y1 = stoi("0");
		}
		else
		{
			y1 = stoi(z);
		}
		x1 = stoi(x);

		// adding the minutes
		sum = x1 + y1;

		// calculating the time it will take for the dockyard to load or unload the ship
		if (sum <= 59)
		{
			string temp;
			stringstream ss;
			ss << sum;
			ss >> temp;


			time = y[0];
			if (y[1] != ':')
			{
				time = time + y[1];
			}
			time = time + ":";
			if (sum < 10)
			{
				time = time + "0";
			}
			time = time + temp;
		}
		else
		{
			string temp1;
			string temp2;
			stringstream ss;
			int x;
			temp1 = y[0];
			if (y[1] != ':')
			{
				temp1 = temp1 + y[1];
			}

			x = stoi(temp1);
			x = x + 1;

			ss << x;
			ss >> temp2;

			time = temp2[0];
			if (temp2[1] != ':')
			{
				time = time + temp2[1];
			}
			time = time + ":";

			if (sum == 60)
			{
				time = time + "00";
			}
			else
			{
				stringstream s;
				string temp3;
				int sum2 = sum - 60;
				s << sum2;
				s >> temp3;

				if (sum2 < 10)
				{
					time = time + "0";
				}
				time = time + temp3;

			}

		}

		if (compare_time2(arrival[m], open[solutions[m]]) != 1)
		{
			clash++;
		}
		else
		{
			if (compare_time1(departure[m], time) != 1 || compare_time1(close[solutions[m]], time) != 1)
			{
				clash++;
			}
		}

	}
}
void fitness_fun(int* solutions, int* fitness, char arrival[][6],char departure[][6],
	char open[][6],char close[][6],int size[],char time_taken[3][6][3], int k)
{
	int clash = 0;
	bool check[10];

	for (int i = 0; i < 10; i++)
	{
		check[i] = false;
	}

	for (int j = 0; j < 10; j++) {

		if (check[j] == false)
		{
			check[j] = true;

			for (int i = j + 1; i < 10; i++)
			{
				if (solutions[j] == solutions[i])
				{

					if (compare_time3(arrival[j], arrival[i]) == 1)
					{
						clash++;
						check[i] = true;
					}
				}
			}
		}

	}

	
	check_time_range(solutions, arrival, departure, open, close, clash, size, time_taken);
	

	if (clash == 0)
	{
		fitness[k] = 100;
	}
	else
	{
		fitness[k] = 100 - clash;
	}


}
void extracting_minutes(char time_taken[3][6][3], int size, int dock)
{
	string x;
	if (size == 10000)
	{
		x = time_taken[dock][0][0];
		x = x + time_taken[dock][0][1];

	}
	else if (size == 15000)
	{
		x = time_taken[dock][1][0];
		x = x + time_taken[dock][1][1];

	}
	else if (size == 20000)
	{
		x = time_taken[dock][2][0];
		x = x + time_taken[dock][2][1];

	}
	else if (size == 30000)
	{
		x = time_taken[dock][3][0];
		x = x + time_taken[dock][3][1];

	}
	else if (size == 50000)
	{
		x = time_taken[dock][4][0];
		x = x + time_taken[dock][4][1];

	}
	else
	{
		x = time_taken[dock][5][0];
		x = x + time_taken[dock][5][1];

	}

	cout << "Time Taken by the Dockyard to Load or Unload the Ship: " << x << " minutes" << endl;


}

void chromosome_gen(int* solutions)
{

	for (int m = 0; m < 10; m++)
	{

		int dockyard;
		dockyard = rand() % 3;
		solutions[m] = dockyard;

	}

}
void print_chromosomes(int** solutions, char ships[][3], char arrival[][6], char departure[][6],
	char open[][6], char close[][6], int size[], char time_taken[3][6][3], char dockyards[][3])
{
	for (int j = 0; j < 10; j++)
	{
		cout << "Chromosome: " << j << endl;
		for (int i = 0; i < 10; i++)
		{

			cout << "Ship: " << ships[i] << " Scheduled For: " << dockyards[solutions[j][i]] << endl;
			cout << "Ship Arrival Time:" << arrival[i] << endl;
			cout << "Ship Departure Time:" << departure[i] << endl;
			cout << "Dock Opening Time:" << open[solutions[j][i]] << endl;
			cout << "Dock Closing Time:" << close[solutions[j][i]] << endl;
			extracting_minutes(time_taken, size[i], solutions[j][i]);
			cout << "------------------------------------------------------------------" << endl;
		}
		cout << "------------------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------" << endl;
	}
}
void find_least_fit(int* fitness, int& index1, int& index2)
{
	int m1 = 999999;

	for (int i = 0; i < 10; i++)
	{
		if (m1 > fitness[i])
		{
			m1 = fitness[i];
			index1 = i;
		}
	}

	int m2 = 999999;


	for (int i = 0; i < 10; i++)
	{
		if (m2 > fitness[i] && i != index1)
		{
			m2 = fitness[i];
			index2 = i;
		}
	}

}
void two_point_crossover(int* fitness, int** solutions, int* cfitness)
{
	int range = cfitness[9] + 1;
	int candidate;
	int p1;
	int p2;
	int x;
	int y;
	int index1;
	int index2;
	int* c1 = new int[10];
	int* c2 = new int[10];

	// selecting the parents
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			candidate = rand() % range;

			for (int j = 0; j < 10; j++)
			{
				if (candidate <= cfitness[j])
				{
					p1 = j;
					break;
				}
			}
		}
		else
		{
			candidate = rand() % range;

			for (int j = 0; j < 10; j++)
			{

				if (candidate <= cfitness[j])
				{

					p2 = j;
					break;
				}
			}

		}

	}

	x = rand() % 10;
	y = rand() % 10;


	for (int i = 0; i < 10; i++)
	{
		if (x < y)
		{
			if (i >= x && i <= y)
			{
				c1[i] = solutions[p2][i];
				c2[i] = solutions[p1][i];
			}
			else
			{
				c1[i] = solutions[p1][i];
				c2[i] = solutions[p2][i];
			}
		}
		else if (x > y)
		{
			if (i >= y && i <= x)
			{
				c1[i] = solutions[p2][i];
				c2[i] = solutions[p1][i];
			}
			else
			{
				c1[i] = solutions[p1][i];
				c2[i] = solutions[p2][i];
			}
		}
		else
		{
			if (i >= x)
			{
				c1[i] = solutions[p2][i];
				c2[i] = solutions[p1][i];
			}
			else
			{
				c1[i] = solutions[p1][i];
				c2[i] = solutions[p2][i];
			}
		}
	}


	find_least_fit(fitness, index1, index2);

	for (int i = 0; i < 10; i++)
	{
		solutions[index1][i] = c1[i];
		solutions[index2][i] = c2[i];
	}


}
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
int main()
{
	// declaring the ships 
	char ships[10][3] = { "S0","S1","S2","S3","S4","S5","S6","S7","S8","S9" };

	// size of ships in tonnage
	int size[10] = { 10000,30000,60000,20000,15000,15000,50000,10000,30000,60000 };

	// arrival and departure times of ships
	char arrival[10][6] = { "6:00","7:00","7:00","6:00","8:00","8:00","10:00","10:00","11:00","11:00" };
	char departure[10][6] = { "6:15","7:40","7:45","8:00","8:30","8:30","10:30","10:25","11:35","11:45" };

	// declaring the dockyards
	char dockyards[3][3] = { "D0","D1","D2" };

	// opening and closing times of dockyards
	char open[3][6] = { "10:00","6:00","6:00" };
	char close[3][6] = { "12:00","9:00","11:45" };

	//time taken in minutes by each dockyard to load or unload a ship of size 10k,15k,20k,30k,50k,60k
	// the time taken is variable as each dockyard has different number of resources
	char time_taken[3][6][3] = { { "10","15","20","30","25","30" },
									{"15","20","25","35","20","35"},
									{"25","25","35","40","30","45" } };

	// declaring the solutions array which will contain the chromosomes, population size is 10 and chromosome size is also 10
	int** solutions = new int* [10];
	int* fitness = new int[10];
	int* cfitness = new int[10];
	bool found = false;
	int count = 1;

	for (int i = 0; i < 10; i++)
	{
		solutions[i] = new int[10];
	}

	// generating chromosomes

	for (int i = 0; i < 10; i++)
	{

		chromosome_gen(solutions[i]);
	}


		
		while (found == false)
		{

			//calculating the fitness of the chromosomes
			for (int i = 0; i < 10; i++)
			{
				fitness_fun(solutions[i], fitness, arrival, departure, open, close, size, time_taken, i);

			}
			// checking if the diversity is finished
			if (check_fitness(fitness) == true)
			{
				cout << "Generation:" << count << endl;
				cout << "Fitness: " << fitness[0] << endl;
				cout << "Best Solution:" << endl;
				for (int m = 0; m < 10; m++)
				{

					cout << "Ship: " << ships[m] << " Scheduled For: " << dockyards[solutions[0][m]] << endl;
					cout << "Ship Arrival Time:" << arrival[m] << endl;
					cout << "Ship Departure Time:" << departure[m] << endl;
					cout << "Dock Opening Time:" << open[solutions[0][m]] << endl;
					cout << "Dock Closing Time:" << close[solutions[0][m]] << endl;
					extracting_minutes(time_taken, size[m], solutions[0][m]);
					cout << "------------------------------------------------------------------" << endl;
				}
				cout << "------------------------------------------------------------------" << endl;
				cout << "------------------------------------------------------------------" << endl;

				found = true;
				break;
			}

			//calculating the cumulative frequencies
			cumulative_frequency(fitness, cfitness);

			//two point crossover
			two_point_crossover(fitness, solutions, cfitness);

			
			count++;
		}

	



	system("pause");
	return 0;
}
