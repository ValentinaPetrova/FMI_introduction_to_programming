#include <iostream>


//bool isPrime(int n)
//{
//	bool isPrime = true;
//	if (n <= 1)
//	{
//		isPrime = false;
//		std::cout << "is not prime" << std::endl;
//		return 0;
//	}
//
//	double sqrtOfNumber = sqrt(n);
//	for (int i = 2; i <= sqrtOfNumber; i++)
//	{
//		if (n % i == 0)
//		{
//			isPrime = false;
//			break;
//		}
//	}
//
//	return isPrime;
//}

//int main()
//{
//ex1

	/*unsigned int n, k;
	std::cin >> n >> k;

	unsigned int max = n > k ? n : k;
	unsigned int lcmCandidate = max;
	while (lcmCandidate % n != 0 || lcmCandidate % k != 0)
	{
		lcmCandidate += max;
	}
	std::cout << lcmCandidate << std::endl;*/

//ex2

	/*unsigned int n, k;
	std::cin >> n >> k;

	if (n < k)
	{
		unsigned int temp = n;
		n = k;
		k = temp;
	}
	while (k!= 0)
	{
		unsigned int mod = n % k;
		n = k;
		k = mod;
	}

	std::cout << n << std::endl;*/

//ex3

	/*unsigned int n = 0;
	std::cin >> n;
	bool isPrime = true;
	if (n <= 1)
	{
		isPrime = false;
		std::cout << "is not prime" << std::endl;
		return 0;
	}

	double sqrtOfNumber = sqrt(n);
	for (int i = 2; i <= sqrtOfNumber; i++)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime)
	{
		std::cout << "is prime" << std::endl;
	}
	else
	{
		std::cout << "is not prime" << std::endl;
	}

	return 0;*/

//ex4

	//int n;
	//std::cin >> n;

	//for (int i = n; i > 1; i--)
	//{
	//	//check if i is prime
	//	bool isPrime = true;
	//	double temp = sqrt(i);
	//	for (int k = 2; k <= temp; k++)
	//	{
	//		if (i % k == 0)
	//		{
	//			isPrime = false;
	//			break;
	//		}
	//	}

	//	if (!isPrime)
	//		continue;

	//	//check how many time i devides n
	//	int count = 0;
	//	while (n % i == 0)
	//	{
	//		count++;
	//		n /= i;
	//	}

	//	if (count >= 1)
	//	{
	//		std::cout << i << "^" << count << " ";
	//	}
	//}

//ex5

//int n;
//std::cin >> n;
//
//for (int i = 2; i <= n; i++)
//{
//
//	//check how many time i devides n
//	int count = 0;
//	while (n % i == 0)
//	{
//		count++;
//		n /= i;
//	}
//
//	if (count >= 1)
//	{
//		std::cout << i << "^" << count << " ";
//	}
//}

//ex6

	//int n;
	//std::cin >> n;

	//int mostCommonDigit = -1;
	//int mostCommonDigitOccurences = 0;
	//
	//for (int currentDigit = 0; currentDigit <= 9; currentDigit++)
	//{
	//	int copyOfN = n;
	//	int currentDigitOccurences = 0;
	//	while (copyOfN != 0)
	//	{
	//		int lastDigit = copyOfN % 10;
	//		if (lastDigit == currentDigit)
	//			currentDigitOccurences++;
	//		copyOfN /= 10; //removes the last digit;
	//	}

	//	if (currentDigitOccurences > mostCommonDigitOccurences)
	//	{
	//		mostCommonDigit = currentDigit;
	//		mostCommonDigitOccurences = currentDigitOccurences;
	//	}
	//}

	//std::cout << mostCommonDigit;

//ex7

//int n = 0;
//std::cin >> n;
//
//if (n % 2 == 0)
//{
//	n++;
//}
//
//for (int i = n; i > 0; i -= 2)
//{
//	int whiteSpaces = (n - i) / 2;
//	for (size_t j = 0; j < whiteSpaces; j++)
//	{
//		std::cout << " ";
//	}
//	for (size_t j = 0; j < i; j++)
//	{
//		std::cout << "*";
//	}
//	std::cout << std::endl;
//}
//
//for (size_t i = 3; i <= n; i += 2)
//{
//	int whiteSpaces = (n - i) / 2;
//	for (size_t j = 0; j < whiteSpaces; j++)
//	{
//		std::cout << " ";
//	}
//	for (size_t j = 0; j < i; j++)
//	{
//		std::cout << "*";
//	}
//	std::cout << std::endl;
//}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//homework ex

//ex1

	/*int n = 0;
	int total = 0;
	std::cin >> n;
	while (n!=0)
	{
		total += n;
		std::cin >> n;
		
	}
	std::cout << total << std::endl;*/

//ex2

//unsigned int n, k;
//std::cin >> n >> k;
//if (n < k)
//{
//	unsigned int temp = n;
//	n = k;
//	k = temp;
//}
//for (int i = k; i > 0; i--)
//{
//	if (n%i == 0 && k%i == 0)
//	{
//		std::cout << i << " ";
//	}
//}

//ex3

//int n;
//std::cin >> n;
//
//int length = 0;
//int firstDigit, lastDigit;
//int copy = n;
//while (copy != 0)
//{
//	length++;
//	copy /= 10;
//}
//int lastPart = 1;
//int firstPart = 1;
//int lastPartCounter = length/2;
//if (length % 2 == 0)
//{
//	lastPartCounter--;
//}
//
//for (size_t i = 0; i < lastPartCounter; i++)
//{
//	lastPart *= 10;
//}
//for (size_t i = 0; i < length - lastPartCounter; i++)
//{
//	firstPart *= 10;
//}
//
//firstDigit = n / firstPart;
//lastDigit = n % lastPart;
//int newNumber = firstDigit * lastPart + lastDigit;
//std::cout << newNumber << ", " << newNumber + 1 << std::endl;

//ex4

//int n, k;
//std::cin >> n >> k;
//if (n < k)
//	{
//		unsigned int temp = n;
//		n = k;
//		k = temp;
//	}
//for (size_t i = k; i <= n; i++)
//{
//	if (isPrime(i))
//	{
//		std::cout << i << " ";
//	}
//}

//ex5

//int n;
//std::cin >> n;
//if ((n & (n - 1)) == 0)
//{
//	std::cout << "true" << std::endl;
//}
//else
//{
//	std::cout << "false" << std::endl;
//}

//ex6

//int a, b, c, d, e;
//std::cin >> a >> b >> c >> d >> e;
//
//for (int x = -100; x <= 100; x++)
//{
//	long long f_x = (long long)a * (x * x * x * x) + (long long)b * (x * x * x) + (long long)c * (x * x) + (long long)d * x + (long long)e;
//	if (f_x >= 0)
//	{
//		std::cout << x << std::endl;
//	}
//}

//ex8

//int n;
//std::cin >> n;
//
//for (size_t i = 1; i <= n; i++)
//{
//	for (size_t j = 1; j <= i; j++)
//	{
//		std::cout << "$" << " ";
//	}
//	std::cout << std::endl;
//}

//ex9

//int n;
//std::cin >> n;
//
//for (size_t i = 1; i <= n; i++)
//{
//	for (size_t j = n - i; j >= 1 ; j--)
//	{
//		std::cout << " ";
//	}
//	for (size_t j = i; j >= 1; j--)
//	{
//		std::cout << j;
//	}
//	std::cout << std::endl;
//}
//
//for (size_t i = n-1; i >= 1; i--)
//{
//	for (size_t j = n - i; j >= 1; j--)
//	{
//		std::cout << " ";
//	}
//	for (size_t j = i; j >= 1; j--)
//	{
//		std::cout << j;
//	}
//	std::cout << std::endl;
//}

//ex10

//int n;
//std::cin >> n;
//
//for (size_t i = 1; i <= n; i++)
//{
//	for (size_t j = 0; j < n; j++)
//	{
//		if (j%2 == 0)
//		{
//			std::cout << i + (n * j) << " ";
//		}
//		else
//		{
//			std::cout << (j + 1) * n - (i - 1) << " ";
//		}
//	}
//	std::cout << std::endl;
//}

//ex11

//int n = 0;
//std::cin >> n;
//
//for (size_t i = 1; i <= n; i++)
//{
//	if ( i % 2 != 0)
//	{
//		for (size_t j = 1 + (i-1)*n; j <= i*n; j++)
//		{
//			std::cout << j;
//		}
//	}
//	else
//	{
//		for (size_t j = i * n; j > (i - 1) * n; j--)
//		{
//			std::cout << j;
//		}
//
//	}
//
//	std::cout << std::endl;
//}

//ex12
//
//int n = 0;
//std::cin >> n;
//
//for (size_t i = 1; i <= n; i++)
//{
//	if (i == 1 || i == n)
//	{
//		std::cout << "+";
//	}
//	else
//	{
//		std::cout << "|";
//	}
//
//	for (size_t j = 1; j <= n-2; j++)
//	{
//		std::cout << " -";
//	}
//
//	if (i == 1 || i == n)
//	{
//		std::cout << " +";
//	}
//	else
//	{
//		std::cout << " |";
//	}
//
//	std::cout << std::endl;
//}

//ex13

//int n = 0;
//std::cin >> n;
//
//for (size_t i = 1; i <= ((n*2) - 1); i++)
//{
//	if (i == 1 || i == ((n*2) - 1))
//	{
//		for (size_t j = 0; j < n; j++)
//		{
//			std::cout << ".";
//		}
//		for (size_t j = 0; j < n / 2; j++)
//		{
//			std::cout << " ";
//		}
//		for (size_t j = 0; j < n; j++)
//		{
//			std::cout << ".";
//		}
//	}
//	else if (i % 2 == 0)
//	{
//		std::cout << std::endl;
//		continue;
//	}
//	else
//	{
//		std::cout << ".";
//		for (size_t j = 0; j < n / 2; j++)
//		{
//			std::cout << " ";
//		}
//		for (size_t j = 0; j < n; j++)
//		{
//			std::cout << ".";
//		}
//		for (size_t j = 0; j < n / 2; j++)
//		{
//			std::cout << " ";
//		}
//		std::cout << ".";
//	}
//}

//ex14

//int n = 0;
//std::cin >> n;
//
//int counter = 0;
//
//for (size_t i = 1; i <= ((n*2) - 1); i++)
//{
//	if (i <= n)
//	{
//		for (size_t j = 0; j < n - i; j++)
//		{
//		std::cout << " ";
//		}
//
//		for (size_t j = 1; j <= n; j++)
//		{
//			if (j <= i)
//			{
//				std::cout << j;
//			}
//		}
//		for (size_t j = n; j >= 1; j--)
//		{
//			if (j < i)
//			{
//				std::cout << j;
//			}
//		}
//		for (size_t j = 0; j < n - i; j++)
//		{
//			std::cout << " ";
//		}
//	}
//	else
//	{
//		for (size_t j = 0; j < n - 1; j++)
//		{
//			std::cout << " ";
//		}
//		counter++;
//		std::cout << n - counter;
//		for (size_t j = 0; j < n - 1; j++)
//		{
//			std::cout << " ";
//		}
//	}
//	std::cout << std::endl;
//}

//ex15

//int n = 0;
//std::cin >> n;
//
//for (size_t i = 1; i < n; i++)
//{
//	int counter = 0;
//	for (size_t j = 1; j <= n; j++)
//	{
//		if (j <= i)
//		{
//			std::cout << j;
//			counter++;
//		}
//	}
//	for (size_t k = 0; k < 3 * n - 2*counter; k++)
//	{
//		std::cout << " ";
//	}
//	for (size_t j = n; j >= 1; j--)
//	{
//		if (j <= i)
//		{
//			std::cout << j;
//		}
//	}
//
//	std::cout << std::endl;
//}
//
//for (size_t i = 1; i <= n; i++)
//{
//	std::cout << i;
//}
//for (size_t i = 0; i < n; i++)
//{
//	std::cout << "-";
//}
//for (size_t i = n; i >= 1; i--)
//{
//	std::cout << i;
//}
//std::cout << std::endl;
//
//for (size_t i = n - 1; i >= 1; i--)
//{
//	int counter = 0;
//	for (size_t j = 1; j <= n; j++)
//	{
//		if (j <= i)
//		{
//			std::cout << j;
//			counter++;
//		}
//	}
//	for (size_t k = 0; k < 3 * n - 2 * counter; k++)
//	{
//		std::cout << " ";
//	}
//	for (size_t j = n; j >= 1; j--)
//	{
//		if (j <= i)
//		{
//			std::cout << j;
//		}
//	}
//
//	std::cout << std::endl;
//}

//ex16
//int n = 0;
//std::cin >> n;
//
//for (size_t i = 0; i < n + 2; i++)
//{
//	std::cout << "#";
//}
//
//std::cout << std::endl;
//
//for (size_t i = 0; i < n; i++)
//{
//	std::cout << "#";
//	for (size_t j = 0; j < n ; j++)
//	{
//		std::cout << (i + j) % n + 1;
//	}
//	std::cout << "#";
//	std::cout << std::endl;
//}
//
//if (n%2 == 0)
//{
//	for (size_t i = 0; i < n/2; i++)
//	{
//		std::cout << " ";
//	}
//	std::cout << "XX";
//	for (size_t i = 0; i < n / 2; i++)
//	{
//		std::cout << " ";
//	}
//}
//else
//{
//	for (size_t i = 0; i < n / 2 + 1; i++)
//	{
//		std::cout << " ";
//	}
//	std::cout << "X";
//	for (size_t i = 0; i < n / 2 + 1; i++)
//	{
//		std::cout << " ";
//	}
//}
//
//std::cout << std::endl;
//
//for (int i = 0; i < n; i++)
//{
//	std::cout << "#";
//	for (int j = 0; j < n; j++)
//	{
//		std::cout << (n - 1 - i + j) % n + 1;
//	}
//	std::cout << "#";
//	std::cout << std::endl;
//}
//
//
//for (size_t i = 0; i < n + 2; i++)
//{
//	std::cout << "#";
//}

//ex17

//int n = 0;
//std::cin >> n;
//
//int maxNum = n;
//int secondMaxNum = 0;
//int num = 0;
//for (size_t i = 0; i < n; i++)
//{
//	std::cin >> num;
//	if (num >= maxNum)
//	{
//		secondMaxNum = maxNum;
//		maxNum = num;
//	}
//	else if (num < maxNum && num > secondMaxNum)
//	{
//		secondMaxNum = num;
//	}
//}
//
//std::cout << maxNum << " " <<  secondMaxNum;

//}