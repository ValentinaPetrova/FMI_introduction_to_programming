#include <iostream>

const int rows = 6;
const int colls = 5;

bool isValidCoordinate(int x, int y)
{
	return x >= 0 && y >= 0 && x <= 5 && y <= 6;
}

bool findPath(const char fields[rows][colls], bool visited[rows][colls], int currentX, int currentY, int destX, int destY)
{
	if (!isValidCoordinate(currentX,currentY) || visited[currentX][currentY] || fields[currentX][currentY] != ' ')
	{
		return false;
	}

	visited[currentX][currentY] = true;

	if (currentX == destX && currentY == destY)
	{
		return true;
	}

	

	bool foundPath = findPath(fields, visited, currentX + 1, currentY, destX, destY) ||
		findPath(fields, visited, currentX, currentY + 1, destX, destY) ||
		findPath(fields, visited, currentX - 1, currentY, destX, destY) ||
		findPath(fields, visited, currentX, currentY - 1, destX, destY);

	if (!foundPath)
	{
		visited[currentX][currentY] = false;
	}

	return foundPath;
}

void printPath(const char fields[rows][colls], bool visited[rows][colls])
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colls; j++)
		{
			if (visited[i][j])
			{
				std::cout << "|1|";
			}
			else
			{
				std::cout << "|" << fields[i][j] << "|";
			}
		}

		std::cout << std::endl;
	}
}

bool functionPath(const char fields[rows][colls], int startX, int startY, int destX, int destY)
{
	bool visited[rows][colls]{ false };
	bool pathExist = findPath(fields, visited, startX, startY, destX, destY);

	if (pathExist)
	{
		printPath(fields, visited);
	}
	else
	{
		std::cout << "No exicting path!" << std::endl;
	}

	return pathExist;
}

bool zerosAndOnesAreEqual(const bool* arr, int size)
{
	int zeroes = 0, ones = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			zeroes++;
		}
		else if (arr[i] == 1)
		{
			ones++;
		}
	}

	return zeroes == ones;
}

void genBoolVector(bool* arr, int size, bool (*filter)(const bool* arr, int size), int beginIndex = 0)
{
	if (beginIndex == size )
	{
		if (filter(arr,size))
		{
			for (int i = 0; i < size; i++)
				std::cout << arr[i] << " ";
			std::cout << std::endl;
		}
		
		return;
	}

	arr[beginIndex] = 0;
	genBoolVector(arr, size, filter, beginIndex + 1);
	arr[beginIndex] = 1;
	genBoolVector(arr, size, filter, beginIndex + 1);
}

unsigned fibbRec(int n, unsigned* cache)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n ==  1)
	{
		return 1;
	}
	if (cache[n] != 0)
	{
		return cache[n];
	}
	else
	{
		int current = fibbRec(n - 1, cache) + fibbRec(n - 2, cache);
		cache[n] = current;
		return current;
	}

}

unsigned fibb(int n)
{
	unsigned* cache = new unsigned[n + 1] {0};
	unsigned result = fibbRec(n, cache);
	delete[] cache;
	return result;
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

unsigned getCharsCountCond(const char* text, bool (*pred)(char))
{
	if (!text)
	{
		return 0;
	}
	unsigned count = 0;
	while (*text)
	{
		if (pred(*text))
		{
			count++;
		}
		text++;
	}

	return count;
}

unsigned min(unsigned a, unsigned b)
{
	return a < b ? a : b;
}
unsigned min(unsigned a, unsigned b, unsigned c)
{
	return min(min(a, b), c);
}

unsigned getMinOperations_rec(unsigned n, unsigned* cache)
{
	if (n == 1)
		return 0;

	if (cache[n] != 0)
	{
		return cache[n];
	}

	unsigned div2 = INT_MAX, div3 = INT_MAX, min1 = INT_MAX;

	if (n % 3 == 0)
	{
		div3 = getMinOperations_rec(n / 3, cache);
	}
	if (n % 2 == 0)
	{
		div2 = getMinOperations_rec(n / 2, cache);
	}
	min1 = getMinOperations_rec(n - 1, cache);

	unsigned res = min(div2, div3, min1) + 1;
	cache[n] = res;
	return res;

}

unsigned getMinOperations(unsigned n)
{
	unsigned* cache = new unsigned[n + 1] {0};
	unsigned res = getMinOperations_rec(n, cache);
	delete[] cache;
	return res;
}

unsigned getSumOfNumbersInString(const char* text, unsigned currAccNum = 0, unsigned sum = 0)
{
	if (!*text)
	{
		sum += currAccNum;
		return sum;
	}
	if (isDigit(*text))
	{
		(currAccNum *= 10) += (*text - '0');
	}
	else
	{
		sum += currAccNum;
		currAccNum = 0;
	}

	return getSumOfNumbersInString(text + 1, currAccNum, sum);
}

//int main()
//{
//backtracking
	/*char field[rows][colls]
	{
		{' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' '},
		{' ', 'X', ' ', ' ', ' '},
		{' ', 'X', ' ', 'X', 'X'},
		{'X', 'X', ' ', ' ', ' '},
		{' ', ' ', ' ', 'X', ' '}

	};

	functionPath(field, 3, 0, 5, 4);*/

//are Zeroes and Ones Equal
	/*const size_t size = 4;
	bool arr[4];

	genBoolVector(arr, size, zerosAndOnesAreEqual);*/

//fibb memoization

	/*std::cout << fibb(45) << std::endl;*/

//high order functions

	/*std::cout << "Digits count: " << getCharsCountCond("abc341XY", isDigit) << std::endl;
	std::cout << "All chars: " << getCharsCountCond("abc341XY", [](char ch) {return true; }) << std::endl;*/

//minOperationMemoization

	/*std::cout << getMinOperations(200);*/

//getSum of Numbers in string

	/*std::cout << getSumOfNumbersInString("asd123as33d");*/

//}