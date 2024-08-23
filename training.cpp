#include <iostream>

//NOK
int NOK(int n, int k)
{
	int max = n > k ? n : k;
	int candidate = max;
	while (candidate % n != 0 || candidate % k != 0)
	{
		candidate += max;
	}

	return candidate;
}

//NOD

int Nod(int n, int k)
{
	if (n < k)
	{
		int temp = n;
		n = k;
		k = temp;
	}
	while (k != 0)
	{
		int mod = n % k;
		n = k;
		k = mod;
	}

	return n;
}

//Subsets

void subsets(const int arr[], int size)
{
	int total = 1 << size;
	for (size_t mask = 1; mask < total; mask++)
	{
		std::cout << "{";
		for (size_t i = 0; i < size; i++)
		{
			if (mask & (1 << i))
			{
				std::cout << arr[i] << " ";
			}
		}
		std::cout << "}" << std::endl;
	}
}

//Binary Search

bool binarySearch(const int* arr, int size, int searched)
{
	if (!arr)
	{
		return false;
	}

	int mid = size / 2;

	if (arr[mid] == searched)
	{
		return true;
	}
	else if (arr[mid] < searched)
	{
		return binarySearch(arr + mid, size - mid, searched);
	}
	else if(arr[mid] > searched)
	{
		return binarySearch(arr, mid, searched);
	}
}

int swap(int& n, int& m)
{
	int temp = n;
	n = m;
	m = temp;
}

//insertion Sort

void InsertionSort(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		int elm = arr[i];
		int j = i - 1;
		while (j != -1 && arr[j] > elm)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		swap(arr[j + 1], elm);
	}
}

//countSystem

unsigned fromBinaryToDecimal(unsigned int n)
{
	int result = 0;
	int mult = 1;
	while (n != 0)
	{
		result += (n% 10) * mult;
		mult *= 2;
		n /= 10;

	}
	return result;
}

unsigned fromDecimalToBinary(unsigned int n)
{
	int result = 0;
	int mult = 1;
	while (n!= 0)
	{
		if (n%2 == 1)
		{
			result += mult;
		}
		mult *= 10;
		n /= 2;
	}
}

int getNumFromChar(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return 10 + (ch - 'A');
	}
	return -1;
}

char getChatFromNum(unsigned int n)
{
	if (n >= 0 && n <= 9)
	{
		return n + '0';
	}
	else if (n >= 10)
	{
		return  'A' + (n - 10) ;
	}
}

int fromRandomToDecimal(const char from[], int size, int k)
{
	int result = 0;
	int mult = 1;
	for (size_t i =  size - 1; i >= 0; i--)
	{
		
		result += getNumFromChar(from[i]) * mult;
		mult *= k;
	}
	return result;
}

void fromDecimalToRandom(unsigned int n, char to[], int size, int k)
{
	int result = 0;
	for (size_t i = size-1; i >= 0 ; i--)
	{
		int index = n % k;
		to[i] = getChatFromNum(index);
		n /= k;
	}
}

//isPrime

bool isPrime(int n)
{
	int sg = sqrt(n);
	for (size_t i = 0; i <= sg; i++)
	{
		if (n % i ==0)
		{
			return false;
		}
	}
	return true;
}

//Fibbonaci

unsigned fibb_rec(int n, int* cache)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}

	if (cache[n] != 0)
	{
		return cache[n];
	}

	else
	{
		int current = fibb_rec(n - 1, cache) + fibb_rec(n - 2, cache);
		cache[n] = current;
		return current;
	}

}

unsigned fibb(int n)
{
	int* cache = new int[n + 1] {0};
	int result = fibb_rec(n, cache);

	delete[] cache;
	return result;

}

//split String

bool isWordSymbol(char ch)
{
	return (ch >= 'a' && ch <= 'b') || (ch >= 'A' && ch <= 'Z');
}

unsigned getWordsCount(const char* str)
{
	if (!str)
	{
		return 0;
	}
	unsigned count = 0;
	while (*str)
	{
		if (isWordSymbol(*str) && !isWordSymbol(*(str+1)))
		{
			count++;
		}
		str++;
	}

	return count++;
}

void skipInvalid(const char*& str)
{
	while (*str && !isWordSymbol(*str))
	{
		str++;
	}
}

char* getWord(const char*& str)
{
	int index = 0;
	while (isWordSymbol(str[index]))
	{
		index++;
	}

	char* word = new char[index + 1];
	word[index] = '\0';

	for (size_t i = 0; i < index; i++)
	{
		word[i] = str[i];
	}
	str += index;
	return word;
}

char** splitStrToWords(const char* str)
{
	unsigned wordsCount = getWordsCount(str);
	char** words = new char*[wordsCount];

	int wordIndex = 0;
	while (*str)
	{
		skipInvalid(str);
		if (!*str)
		{
			break;
		}
		words[wordIndex++] = getWord(str);
	}

	return words;
}
//+ free and print

//Bitwise Operations

unsigned makeBitZero(unsigned n, unsigned int ind)
{
	int mask = 1;
	mask <<= ind;
	mask = ~mask;
	return n & mask;
}

unsigned makeBitOne(unsigned n, unsigned int ind)
{
	int mask = 1;
	mask <<= ind;
	return n | ind;
}

unsigned toglebit(unsigned n, unsigned int ind)
{
	int mask = 1;
	mask <<= ind;
	return n ^ mask;
}

bool isEven(int n)
{
	return !(n & 1);
}

unsigned firstMissing(const int arr[], int size)
{
	int result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result ^= arr[i];
	}
	return result;
}

//sortArrOfTwoConcats

int getBound(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > arr[i+1])
		{
			return i + 1;
		}
	}
	return 0;
}

void merge(int* arr1, int* arr2, int size1, int size2, int* temp)
{
	unsigned arr1Inx = 0, arr2Inx = 0, tempInx = 0;

	while (arr1Inx < size1 && arr2Inx < size2)
	{
		if (arr1[arr1Inx] <= arr2[arr2Inx])
		{
			temp[tempInx++] = arr1[arr1Inx++];
		}
		else
		{
			temp[tempInx++] = arr2[arr2Inx++];
		}
	}

	while (arr1Inx < size1)
	{
		temp[tempInx++] = arr1[arr1Inx++];
	}
	while (arr2Inx < size2)
	{
		temp[tempInx++] = arr2[arr2Inx++];
	}
}

void sort(int arr[], int size)
{
	int secondArrStart = getBound(arr, size);
	int* temp = new int[size];
	merge(arr, arr + secondArrStart, secondArrStart, size - secondArrStart, temp);

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = temp[i];
	}
	delete[] temp;
}

//search in text

unsigned myStrlen(const char* str)
{
	if (!str)
		return 0;

	unsigned result = 0;
	while (*str) //is the same as (*str) != '\0'
	{
		result++;
		str++;
	}
	return result;
}

bool isPrefix(const char* text, const char* pattern)
{
	while (*text != '\0' && *pattern != '\0')
	{
		if (*text != *pattern)
		{
			return false;
		}
		text++;
		pattern++;
	}

	return *pattern == '\0';
}

bool searchInText(const char* text, const char* pattern)
{
	size_t textLen = myStrlen(text);
	size_t patternLen = myStrlen(pattern);
	while (patternLen <= textLen)
	{
		if (isPrefix(pattern, text))
			return true;
		text++; //подминаваме първия символ
		textLen--;
	}
	return false;
}

//Eratostens 
void assignValueToAllCells(bool arr[], int len, bool value)
{
	for (int i = 0; i < len; i++)
		arr[i] = value;
}
void markAsNotPrime(bool sieve[], int len, int current)
{
	int toMark = current + current;

	while (toMark < len)
	{
		sieve[toMark] = true;
		toMark += current;
	}
}
void sieveErathostenes(bool sieve[], int len)
{
	for (int i = 2; i <= len; i++)
	{
		if (!sieve[i])
		{
			std::cout << i << std::endl;
			markAsNotPrime(sieve, len, i);
		}

	}
}


int main()
{
	int arr[4] = { 1,2,3,4 };
	subsets(arr, 4);

}