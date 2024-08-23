#include <iostream>

const int size = 64;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverse(int arr[], const int size)
{
	for (size_t i = 0; i < size/2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
}

bool isPalindrome(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != arr[size - 1 - i])
		{
			return false;
		}
	}

	return true;
}

bool isPalindrome2(int arr[], int start, int end)
{
	while (start < end)
	{
		if (arr[start]!= arr[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void printArr(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int gcd(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}

	while (b!=0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int lcm_WithGCD(int a, int b)
{
	return (a / gcd(a, b) * b);
}

int lcm(int a, int b)
{
	if (a > b)
	{
		swap(a, b);
	}
	int lcm = b;
	while (lcm % a != 0 || lcm % b != 0)
	{
		lcm += b;
	}

	return lcm;
}
int lcmInArr(int arr[], int size)
{
	int result = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		result = lcm(result, arr[i]);
	}
	return result;
}

int gcdInArr(int arr[], int size)
{
	int result= arr[0];
	for (size_t i = 1; i < size; i++)
	{
		result = gcd(result, arr[i]);
		if (result == 1)
		{
			return 1;
		}
	}

	return result;
}

bool isArrFromPalindroms(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (isPalindrome2(arr, 0, i - 1) && isPalindrome2(arr, i, size - 1))
		{
			return true;
		}
	}
	return false;
}

int countOfInversions(int arr[], int size)
{
	int count = 0;
	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = i+1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				count++;
			}
		}
	}
	return count;
}

int findSmallestMissingNumber(int arr[], int n)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == arr[0] + mid)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return arr[0] + left;
}

int findBiggestMissingNumber(int arr[], int size)
{
	int left = 0;
	int right = size - 1;
	int missing = -1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]!=arr[0] + mid)
		{
			missing = arr[0] + mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return missing;

}

void markAllAs(bool arr[], int n, bool value)
{
	for (size_t i = 0; i <= n; i++)
	{
		arr[i] = value;
	}
}

void markAllAsNotPrime(bool arr[], int n, int current)
{
	int toMark = current + current;
	while (toMark < n)
	{
		arr[toMark] = true;
		toMark += current;
	}
}

void sieveOfEratosten(bool arr[], int n)
{
	for (size_t i = 2; i <= n; i++)
	{
		if (!arr[i])
		{
			std::cout << i << std::endl;
			markAllAsNotPrime(arr, n, i);
		}
	}

}

int binarySearch(const int arr[], int n, int el)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (el > arr[mid])
		{
			left = mid + 1;
		}
		else if (el < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

//int main()
//{
//
//	int arr[size];
//	int n = 0;
//	std::cin >> n;
//	for (size_t i = 0; i < n; i++)
//	{
//		std::cin >> arr[i];
//	}

//ex1	
	/*std::cout << isPalindrome(arr, n) << std::endl;
	reverse(arr, n);
	printArr(arr, n);*/

//ex2
	/*std::cout << lcmInArr(arr, n) << std::endl;*/

//ex3
	/*std::cout << gcdInArr(arr, n) << std::endl;*/

//ex4
	/*std::cout << isArrFromPalindroms(arr, n) << std::endl;*/

//ex5

	/*std::cout << countOfInversions(arr, n) << std::endl;*/

//ex6

	/*std::cout << findSmallestMissingNumber(arr, n) << std::endl;*/

//-------------------------------------------------------------------------------------------------
// Binary SURCHING ALGORITUMS
	/*int num = 0;
	std::cin >> num;
	std::cout << binarySearch(arr, n, num) << std::endl;*/


//Sieve of Eratosten

	/*markAllAs(arr, n, false);
	sieveOfEratosten(arr, n);*/

//}

