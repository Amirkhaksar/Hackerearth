#include <iostream>

struct Point
{
	int x, y;
};

void printValue(Point*, Point*, int);
void quickSort(Point*, int, int);
int partition(Point*, int, int);
int binarySearch(Point*, int, Point);
void sortY(Point*, int);
void quickSortY(Point*, int, int, bool);
int partitionAscendingY(Point*, int, int);
int partitionDecendingY(Point*, int, int);

int main()
{
	int N = 0;
	std::cin >> N;
	Point* points = new Point[N];
	Point* sorted = new Point[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> points[i].x;
		sorted[i].x = points[i].x;
		std::cin >> points[i].y;
		sorted[i].y = points[i].y;
	}
	quickSort(sorted, 0, N - 1);
	sortY(sorted, N);
	printValue(points, sorted, N);
	return 0;
}

void printValue(Point* points, Point* sorted, int N)
{
	for (int i = 0; i < N; i++)
	{
		std::cout << binarySearch(sorted, N, points[i]) << std::endl;
	}
}

void quickSort(Point* points, int start, int end)
{
	if (start < end)
	{
		int piv = partition(points, start, end);
		quickSort(points, start, piv - 1);
		quickSort(points, piv + 1, end);
	}
}

int partition(Point* points, int start, int end)
{
	Point pivot = points[start];
	int i = start;
	for (int j = start + 1; j <= end; j++)
	{
		if ((points[j].x < pivot.x))
		{
			i++;
			Point temp = points[i];
			points[i] = points[j];
			points[j] = temp;
		}
	}
	Point temp = points[i];
	points[i] = points[start];
	points[start] = temp;
	return (i);
}

int binarySearch(Point* sorted, int lentgh, Point target)
{
	int low = 0, high = lentgh - 1;
	while (low <= high)
	{
		int temp = (low + high) / 2;
		if (sorted[temp].x == target.x && sorted[temp].y == target.y)
		{
			return temp;
		}
		else if (sorted[temp].x == target.x)
		{
			for (int i = temp + 1, j = temp - 1;;)
			{
				if (sorted[i].x == target.x && sorted[i].y == target.y)
				{
					return i;
				}
				else if (sorted[j].x == target.x && sorted[j].y == target.y)
				{
					return j;
				}
				if (i + 1 <= high)
				{
					i++;
				}
				if (j - 1 >= low)
				{
					j--;
				}
			}
		}
		else if (sorted[temp].x < target.x)
		{
			low = temp + 1;
		}
		else
		{
			high = temp - 1;
		}
	}
	return -1;
}

//need to check
void sortY(Point* sorted, int length)
{
	bool ascending = true;
	int low = 1, high = 1;
	int x = sorted[0].x;
	for (int i = 0; i < length; i++)
	{
		if (sorted[i].x == x)
		{
			high = i;
			continue;
		}
		else
		{
			if (low < high)
			{
				quickSortY(sorted, low, high, ascending);
			}
			ascending = ascending ? false : true;
			low = i;
			x = sorted[i].x;
		}
	}
}

void quickSortY(Point* sorted, int start, int end, bool ascending)
{
	if (start < end)
	{
		int piv = 0;
		if (ascending)
		{
			piv = partitionAscendingY(sorted, start, end);
		}
		else
		{
			piv = partitionDecendingY(sorted, start, end);
		}
		quickSortY(sorted, start, piv - 1, ascending);
		quickSortY(sorted, piv + 1, end, ascending);
	}
}

int partitionAscendingY(Point* points, int start, int end)
{
	Point pivot = points[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; j++)
	{
		if ((points[j].y < pivot.y))
		{
			i++;
			Point temp = points[i];
			points[i] = points[j];
			points[j] = temp;
		}
	}
	Point temp = points[i + 1];
	points[i + 1] = points[end];
	points[end] = temp;
	return (i + 1);

}

int partitionDecendingY(Point* points, int start, int end)
{
	Point pivot = points[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; j++)
	{
		if ((points[j].y > pivot.y))
		{
			i++;
			Point temp = points[i];
			points[i] = points[j];
			points[j] = temp;
		}
	}
	Point temp = points[i + 1];
	points[i + 1] = points[end];
	points[end] = temp;
	return (i + 1);
}


