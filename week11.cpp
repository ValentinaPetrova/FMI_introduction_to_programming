//#include <iostream>
//
//int myStrlen(const char* text)
//{
//	if (!text)
//	{
//		return 0;
//	}
//
//	int count = 0;
//	while (*text)
//	{
//		count++;
//		text++;
//	}
//
//	return count;
//}
//
////bool isDigit(char ch)
////{
////	return ch >= '0' && ch <= '9';
////}
//
//unsigned getDigitsCount(const char* text)
//{
//	if (!text)
//	{
//		return 0;
//	}
//
//	unsigned counter = 0;
//	while (*text)
//	{
//		if (isDigit(*text))
//		{
//			counter++;
//		}
//		text++;
//	}
//	return counter;
//}
//
//unsigned getNumbersCount(const char* text)
//{
//	if (!text)
//	{
//		return 0;
//	}
//	unsigned counter = 0;
//	while (*text)
//	{
//		if (isDigit(*text) && !isDigit(*(text + 1)))
//		{
//			counter++;
//		}
//		text++;
//	}
//	return counter;
//}
//
////char* censore(const char* text)
////{
////	if (!text)
////	{
////		return nullptr;
////	}
////
////	unsigned resultSize = myStrlen(text) - getDigitsCount(text) + getNumbersCount(text);
////	char* result = new char[resultSize + 1];
////
////	unsigned index = 0;
////	while (*text)
////	{
////		if (!isDigit(*text))
////		{
////			result[index++] = *text;
////		}
////		else if (!isDigit(*(text + 1)))
////		{
////			result[index++] = '*';
////		}
////		text++;
////	}
////	result[index] = '\0';
////	return result;
////}
//
////bool isLower(char ch)
////{
////	return ch >= 'a' && ch <= 'z';
////}
////
////bool isUpper(char ch)
////{
////	return ch >= 'A' && ch <= 'Z';
////}
////
////void getLowerAndUpperCount(const char* text, unsigned& lower, unsigned& upper)
////{
////	upper = lower = 0;
////	if (!text)
////	{
////		return;
////	}
////	while (*text)
////	{
////		if (isLower(*text))
////		{
////			lower++;
////		}
////		else if (isUpper(*text))
////		{
////			upper++;
////		}
////		text++;
////	}
////}
//
////void getLowerAndUpperString(const char* text, char*& lower, char*& upper)
////{
////	if (!text)
////	{
////		return;
////	}
////
////	unsigned lowerSize = 0, upperSize = 0;
////	getLowerAndUpperCount(text, lowerSize, upperSize);
////
////	lower = new char[lowerSize + 1];
////	upper = new char[upperSize + 1];
////
////	unsigned lowerIndex = 0;
////	unsigned upperIndex = 0;
////
////	while (*text)
////	{
////		if (isUpper(*text))
////		{
////			upper[upperIndex++] = *text;
////		}
////		else if(isLower(*text))
////		{
////			lower[lowerIndex++] = *text;
////		}
////		text++;
////	}
////
////	lower[lowerSize] = '\0';
////	upper[upperSize] = '\0';
////}
//
//void merge(const int* arr1, int size1, const int* arr2, int size2, int* result)
//{
//	unsigned arr1Index = 0, arr2Index = 0, resultIndex = 0;
//
//	while (arr1Index < size1 && arr2Index < size2)
//	{
//		if (arr1[arr1Index] <= arr2[arr2Index])
//		{
//			result[resultIndex++] = arr1[arr1Index++];
//		}
//		else if (arr1[arr1Index] > arr2[arr2Index])
//		{
//			result[resultIndex++] = arr2[arr2Index++];
//		}
//	}
//
//	while (arr1Index < size1)
//	{
//		result[resultIndex++] = arr1[arr1Index++];
//	}
//	while (arr2Index < size2)
//	{
//		result[resultIndex++] = arr2[arr2Index++];
//	}
//}
//
//int getBound(const int arr[], size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		if (arr[i] > arr[i+1])
//		{
//			return i + 1;
//		}
//	}
//	return -1;
//}
//
//void sortArrOfTwoConacatArrays(int arr[], size_t size)
//{
//	int secondArrStart = getBound(arr, size);
//
//	if (secondArrStart == -1)
//	{
//		return;
//	}
//
//	int* temp = new int[size];
//	merge(arr, secondArrStart, arr + secondArrStart, size - secondArrStart, temp);
//
//	for (int i = 0; i < size; i++)
//		arr[i] = temp[i];
//	delete[] temp;
//
//}
//
////unsigned getLowerCount(const char* text)
////{
////	if (!text)
////	{
////		return 0;
////	}
////	unsigned count = 0;
////	while (*text)
////	{
////		if (isLower(*text))
////		{
////			count++;
////		}
////		text++;
////	}
////	return count;
////}
//
//void addMoreLowerChars(char* text, unsigned& currIndex, char ch, int count)
//{
//	for (size_t i = 0; i < count; i++)
//	{
//		text[currIndex + i] = ch;
//	}
//	currIndex += count;
//}
//
////char* sortLower(const char* text)
////{
////	unsigned lowerCount = getLowerCount(text);
////	char* result = new char[lowerCount + 1];
////	result[lowerCount] = '\0';
////
////	constexpr unsigned alphabet = 26;
////	constexpr char first = 'a';
////
////	int countLower[alphabet]{ 0 };
////
////	unsigned resultIndex = 0;
////	while (*text)
////	{
////		if (isLower(*text))
////		{
////			countLower[*text - first]++;
////		}
////		text++;
////	}
////
////	for (size_t i = 0; i < alphabet; i++)
////	{
////		addMoreLowerChars(result, resultIndex, first + i, countLower[i]);
////	}
////	return result;
////
////}
//
//void partitionArray(int arr[], int n, int element)
//{
//	int* temp = new int[n + 1];
//	temp[n] = '\0';
//
//	int leftIndex = 0;
//	int rightIndex = n - 1;
//
//	for (size_t i = 0; i < n; i++)
//	{
//		if (arr[i] < element)
//		{
//			temp[leftIndex++] = arr[i];
//		}
//		else if (arr[i] > element)
//		{
//			temp[rightIndex--] = arr[i];
//		}
//	}
//
//	while (leftIndex <= rightIndex)
//	{
//		temp[leftIndex++] = element;
//	}
//	
//	for (size_t i = 0; i < n; i++)
//	{
//		arr[i] = temp[i];
//	}
//
//	delete[] temp;
//}
//
//void printSubarrays(int arr[], int n)
//{
//	int totalCombination = 1 << n;
//
//	for (int mask = 1; mask < totalCombination; mask++)
//	{
//		std::cout << "{ ";
//		for (int i = 0; i < n; i++)
//		{
//			if (mask & (1 << i))
//			{
//				std::cout << arr[i] << " ";
//			}
//		}
//		std::cout << "}" << std::endl;
//	}
//}
//
//
////int main() 
////{
////ex1
//	/*char* text = censore("advb567hb8j98vhjfgh");
//	std::cout << text << std::endl;
//
//	delete[] text;*/
//
////ex2
//
//	/*char* lower = nullptr;
//	char* upper = nullptr;
//	getLowerAndUpperString("valentinaPETROVAvhBJ", lower, upper);
//	std::cout << lower << " " << upper << std::endl;
//
//	delete[] lower;
//	delete[] upper;
//	return 0;*/
//
////ex3
//	/*constexpr size_t size = 6;
//	int arr[size] = { 1,5,9,12,4,7 };
//
//	sortArrOfTwoConacatArrays(arr, size);
//
//	for (int i = 0; i < size; i++)
//		std::cout << arr[i] << " ";
//	return 0;*/
//
////ex4
//	/*char* str = sortLower("zAzAbbzazQc");
//
//	std::cout << str;
//	delete[] str;
//
//	return 0;*/
//
////ex5
//
//	/*int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int pivotElement = 5;
//
//	partitionArray(arr, n, pivotElement);
//
//	for (int i = 0; i < n; i++) {
//		std::cout << arr[i] << " ";
//	}
//	std::cout << std::endl;*/
//
////ex6
//
//	/*int arr[] = { 1, 2, 3, 4 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	printSubarrays(arr, n);*/
//
////}