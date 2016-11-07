#include <iostream>
int parent[201];
int rank[201];
int set[201];
int find(int x)// find the representation of the set containing x
{
	if (parent[x] == x)
		return x;
	else
	{
		parent[x] = find(parent[x]);
		return parent[x];
	}
}
void makeSet() // make all number a 1-element set
{
	for (int i = 0; i < 201; i++)
	{
		if (set[i] != -1)
		{
			parent[i] = i;
			rank[i] = 0;
		}
 	}
}

void union_merge(int x, int y) // merge the set containing x and y
{
	int xRoot = find(x);
	int yRoot = find(y);
	if (rank[xRoot] == rank[yRoot])
	{
		parent[yRoot] = xRoot;
		rank[xRoot]++;
	}
	else
	{
		if (rank[xRoot] > rank[yRoot])
		{
			parent[yRoot] = xRoot;
		}
		else
		{
			parent[xRoot] = yRoot;
		}
	}
}


bool check(int x, int y) // check whether x and y are in the same set
{
	int xRoot = find(x);
	int yRoot = find(y);
	if (xRoot == yRoot)
		return true;
	else
		return false;
}

 
void main()
{
	for (int i = 0; i < 201; i++)
	{
		set[i] = -1;
	}
	int n(0);
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		set[a] = 1;
	}
	makeSet();
	int select(0);
	while (1)
	{
		std::cout << "1. Same set\n";
		std::cout << "2. Check\n";
		std::cout << "3. Find\n";
		std::cin >> select;
		switch(select)
		{
		case 1:
		{
			int x, y;
			std::cin >> x >> y;
			union_merge(x, y);
			break;
		}
		case 2:
		{
			int x, y;
			std::cin >> x >> y;
			if (check(x, y))
				std::cout << "Same\n";
			else
				std::cout << "Different\n";
			break;
		}
		case 3:
		{
			int x;
			std::cin >> x ;
			std::cout <<"Representation is "<< find(x)<<'\n';
			break;
		}
		}
	}
}