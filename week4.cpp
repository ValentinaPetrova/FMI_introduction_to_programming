#include <iostream>

bool isPrime(int n)
{
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

	return isPrime;
}

unsigned reverse(unsigned n)
{

	unsigned reversed = 0;
	while (n!= 0)
	{
		unsigned lastDigit = n % 10;
		(reversed *= 10) += lastDigit;
		n /= 10;
	}
	return reversed;
}

bool isPalindrome(unsigned n)
{
	return n == reverse(n);
}

bool isSuffix(unsigned n, unsigned k)
{
	while (k!= 0)
	{
		unsigned lastNDigit = n % 10;
		unsigned lastKDigit = k % 10;

		if (lastNDigit != lastKDigit)
		{
			return false;
		}
		n /= 10;
		k /= 10;
	}

	return true;
}

bool isPrefix(unsigned n, unsigned k)
{
	while (n >= k)
	{
		if (n == k)
		{
			return true;
		}

		n /= 10;
	}
	return false;
}

bool isInfix(unsigned n, unsigned k)
{
	while (n >= k)
	{
		if (isSuffix(n,k))
		{
			return true;
		}
		n /= 10;
	}
	return false;
}

//int power(int n, int k)
//{
//	int result = 1;
//	for (size_t i = 0; i < k; i++)
//	{
//		result *= n;
//	}
//	return result;
//}

unsigned int log(unsigned n, unsigned k)
{
	unsigned powerOfK = 1;
	unsigned count = 0;
	while (powerOfK<= n)
	{
		powerOfK *= k; 
		count++;
	}
	return count - 1;
}

double distBetweentwoPoints(int px1, int py1, int px2, int py2)
{
	int dx = px1 - px2;
	int dy = py1 - py2;

	return sqrt(dx * dx + dy * dy);
}

int absolutValue(int n)
{
	if (n < 0)
	{
		return -n;
	}

	return n;
}

bool isOnOneCircle1(int px1, int py1, int px2,int py2)
{
	return px1 * px1 + py1 + py1 == px2 * px2 + py2 * py2;
}

bool isOnOneCircle2(int px1, int py1, int px2, int py2)
{
	return absolutValue(distBetweentwoPoints(px1, py1, 0, 0) - distBetweentwoPoints(px2, py2, 0, 0)) <= 0.0001;
}

int digitsCounter(int n)
{
	int counter = 0;
	while (n > 0)
	{
		n /= 10;
		counter++;
	}

	return counter;
}

double perimeterOfTriangle(int px1, int py1, int px2, int py2, int px3, int py3)
{
	return distBetweentwoPoints(px1, py1, px2, py2) + distBetweentwoPoints(px2, py2, px3, py3) + distBetweentwoPoints(px3, py3, px1, py1);
}

int concatDigit(int a, int b)
{
	if (b > 9)
	{
		return 0;
	}

	return a * 10 + b;
}

int concatNumbers(int a, int b)
{
	if (a == 0)
		return 0;

	if (b == 0 || b <= 9)
		return concatDigit(a, b);

	int result = a;
	int reversedB = reverse(b);

	while (reversedB != 0)
	{
		int digitToConcatenate = reversedB % 10;
		result = concatDigit(result, digitToConcatenate);
		reversedB /= 10;
	}

	while (b % 10 == 0)
	{
		result = concatDigit(result, 0);
		b /= 10;
	}

	return result;
}

int countOfPrimeDivisors(int a)
{
	if (a <= 1)
	{
		return 1;
	}
	int counter = 0;
	for (size_t i = 2; i < a; i++)
	{
		if (a%i == 0 && isPrime(i))
		{
			counter++;
		}
	}

	return counter;
}

bool isNumberWithSortedDigits(int n)
{
	while (n != 0)
	{
		int lastNumber = n % 10;
		n /= 10;
		int preLastNumber = n % 10;
		if (lastNumber < preLastNumber)
		{
			return false;
		}
		n /= 10;
	}

	return true;
}

bool isNumberWithsameDigits(int n)
{
	int lastNumber = n % 10;
	while (n != 0)
	{
		int currentDigit = n % 10;
		if (lastNumber != currentDigit)
		{
			return false;
		}
		n /= 10;
	}

	return true;
}

int countDigitOccurrancies(int n, int digit)
{
	int count = 0;
	while (n!= 0)
	{
		if (n%10 == digit)
		{
			count++;
		}
		n /= 10;
	}

	return count;
}

int sortNumber(int n)
{
	int result = 0;
	for (size_t i = 1; i <= 9; i++)
	{
		if (countDigitOccurrancies(n,i) != 0)
		{
			for (size_t j = 0; j < countDigitOccurrancies(n,i); j++)
			{
				result = concatDigit(result, i);
			}
		}
	}

	return result;

}
//
//bool isUpper(char ch)
//{
//	if (ch >= 'A' && ch <= 'Z')
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

char changeToUpper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return ch - 32;
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return ch;
	}
	else
	{
		return 0;
	}
}

char isDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch;
	}
	return -1;
}

//int main()
//{
//	char n = 0;
//	/*int k = 0;
//	std::cin >> n >> k;*/
//	std::cin >> n;

//ex1
	/*for (size_t i = 6; i <= n; i+=6)
	{
		if (isPrime(i - 1) && isPrime(i+1))
		{
			std::cout << i - 1 << " " << i + 1 << std::endl;
		}
	}*/

//ex2

	/*std::cout << reverse(n) << std::endl;*/

//ex3

	/*std::cout << isPalindrome(n) << std::endl;*/

//ex4

	/*std::cout << isSuffix(n, k) << std::endl;*/

//ex5

	/*std::cout << isPrefix(n, k) << std::endl;*/

//ex6 

	/*std::cout << isInfix(n, k) << std::endl;*/

//ex7
	/*std::cout << power(n, k) << std::endl;*/

//ex8

	/*std::cout << log(n, k) << std::endl;*/

//ex9
	/*int px1, py1, px2, py2;
	std::cin >> px1 >> py1 >> px2 >> py2;

	std::cout << isOnOneCircle1(px1, py1, px2, py2) << std::endl;
	std::cout << isOnOneCircle2(px1, py1, px2, py2) << std::endl;*/


	//HOMEWORK EXERCISES

//ex1

	/*std::cout << absolutValue(n) << std::endl;*/

//ex2

	//if (n < 0)
	//{
	//	std::cout << digitsCounter(-n) << std::endl;
	//}
	//else
	//{
	//	std::cout << digitsCounter(n) << std::endl;
	//}

//ex3

	/*int px1, py1, px2, py2, px3, py3;
	std::cin >> px1 >> py1 >> px2 >> py2 >> px3 >> py3;
	double perimeter = perimeterOfTriangle(px1, py1, px2, py2, px3, py3);
	std::cout << perimeter << std::endl;*/

//ex4

	/*std::cout << concatNumbers(n, k) << std::endl;*/

//ex5

	/*int reversed = reverse(n);
	std::cout << concatNumbers(reversed, n) << std::endl;*/

//ex6

	/*int a, b, k;
	std::cin >> a >> b >> k;

	int counter = 0;
	for (size_t i = a; i <= b; i++)
	{
		if (countOfPrimeDivisors(i) == k)
		{
			counter++;
		}
	}

	std::cout << counter << std::endl;*/

//ex7

	/*std::cout << isNumberWithSortedDigits(n) << std::endl;*/

//ex8

	/*std::cout << isNumberWithsameDigits(n) << std::endl;*/

//ex9

	/*std::cout << sortNumber(n) << std::endl;*/

//ex10

	/*std::cout << isUpper(n) << std::endl;*/

//ex11

	/*std::cout << changeToUpper(n) << std::endl;*/

//ex12

	/*std::cout << isDigit(n) << std::endl;*/

//}

