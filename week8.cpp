#include <iostream>

const int MAX_SIZE = 1024;

int findSingleNumber(int arr[], int size)
{
	int unique_number = 0;
	for (size_t i = 0; i < size; i++)
	{
		unique_number ^= arr[i];
	}
	return unique_number;
}

int countOnes(int n)
{
	int count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}

	return count;
}

int flipRightMostOne(int n)
{
	return n & (n - 1);
}

int extractLastKBits(int n, int k)
{
	int mask = (1 << k) - 1;
	return n & mask;
}

bool isBinarySubstring(int n, int k)
{
	int k_bits = 0;
	int temp_k = k;

	while (temp_k > 0)
	{
		temp_k >>= 1;
		k_bits++;
	}

	int mask = (1 << k_bits) - 1;

	while (n >= k)
	{
		if ((n & mask) == k)
		{
			return true;
		}
		n >>= 1;
	}
	return false;
}

unsigned powerOfTwo(int n)
{
	return 1 << n;
}

void printSubset(int arr[], int size, int mask)
{
	std::cout << "{ ";
	for (int i = 0; i < size ; i++)
	{
		if (mask % 2 !=0)
		{
			std::cout << arr[i] << " ";
		}
		mask /= 2;
	}
	std::cout << "}" << std::endl;
}

void generateSybstrings(int arr[], int size)
{
	unsigned pt = powerOfTwo(size);
	for (int i = 0; i < pt; i++)
	{
		printSubset(arr, size, i);
	}
}

//int main()
//{
//	int arr[MAX_SIZE];
//	int n = 0;
//	std::cin >> n;
//	for (size_t i = 0; i < n; i++)
//	{
//		std::cin >> arr[i];
//	}

//ex1
	/*std::cout << findSingleNumber(arr, n) << std::endl;*/

//ex2
	/*std::cout << countOnes(n) << std::endl;*/

//ex3
	/*std::cout << flipRightMostOne(n) << std::endl;*/

//ex4
	/*std::cout << extractLastKBits(n, k) << std::endl;*/

//ex5
	/*std::cout << isBinarySubstring(n, k) << std::endl;*/

//ex6

	/*generateSybstrings(arr, n);*/
//}