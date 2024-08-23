//#include <iostream>
//
//int factoriel(int num)
//{
//	if (num == 0)
//	{
//		return 1;
//	}
//	return num * factoriel(num - 1);
//}
//
//int fibb(int num)
//{
//	if (num == 0 || num == 1) 
//	{
//		return 1;
//	}
//
//	return fibb(num - 1) + fibb(num - 2);
//}
//
//int power(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//
//	return n * power(n, k - 1);
//}
//
//int sumOfArr(int* arr, size_t size)
//{
//	if (size == 0)
//	{
//		return 0;
//	}
//	return arr[0] + sumOfArr(arr + 1, size - 1);
//}
//
//bool linearSearch(int* arr, int size, int searched)
//{
//	if (size== 0)
//	{
//		return false;
//	}
//
//	return arr[0] == searched || linearSearch(arr + 1, size - 1, searched);
//}
//
//bool binarySearch(int* arr, int size, int searched)
//{
//	if (size == 0)
//	{
//		return false;
//	}
//	int mid = size / 2;
//	if (arr[mid] == searched)
//	{
//		return true;
//	}
//	else if (arr[mid] > searched)
//	{
//		return binarySearch(arr, mid, searched);
//	}
//	else
//	{
//		return binarySearch(arr + mid + 1, size - mid - 1, searched);
//	}
//}
//
//bool isPalindrome(const char* arr, size_t len)
//{
//	if (len <= 1)
//	{
//		return true;
//	}
//
//	return arr[0] == arr[len - 1] && isPalindrome(arr + 1, len - 2);
//}
//
//bool isLower(char ch)
//{
//	return ch >= 'a' && ch <= 'z';
//}
//
//bool isUpper(char ch)
//{
//	return ch >= 'A' && ch <= 'Z';
//}
//
//void lowerUpperCount(const char* text, int& lower, int& upper)
//{
//	if (*text == '\0')
//	{
//		return;
//	}
//	if (isLower(*text))
//	{
//		lower++;
//	}
//	else if (isUpper(*text))
//	{
//		upper++;
//	}
//	lowerUpperCount(text + 1, lower, upper);
//}
//
//int currentMax(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//int getMaxInArr(int* arr, int size)
//{
//	if (size == 0)
//	{
//		return 0;
//	}
//
//	return currentMax(arr[0], getMaxInArr(arr + 1, size - 1));
//}
//
//int getMaxInArr2(int* arr, int size)
//{
//	if (size == 0)
//	{
//		return 0;
//	}
//	else if (size == 1)
//	{
//		return arr[0];
//	}
//	else
//	{
//		int mid = size / 2;
//		return currentMax(getMaxInArr2(arr, mid), getMaxInArr2(arr + mid, size - mid));
//	}
//}
//
//bool isPrefix(const char* text, const char* pattern)
//{
//	if (!*pattern)
//	{
//		return true;
//	}
//
//	return *text == *pattern && isPrefix(text + 1, pattern + 1);
//}
//
//bool isInText(const char* text, int textLen, const char* pattern, int patternLen)
//{
//	if (patternLen > textLen)
//	{
//		return false;
//	}
//
//	return isPrefix(text, pattern) || isInText(text + 1, textLen - 1, pattern, patternLen);
//}
//
////int main()
////{
////	int num[4] = { 1, 2 ,7,9 };
//
////ex1
//	/*std::cout << factoriel(5) << std::endl;*/
//
////ex2
//
//	/*std::cout << fibb(5) << std::endl;*/
//
////ex3
//
//	/*std::cout << power(2, 4) << std::endl;*/
//
////ex4
//	/*std::cout << sumOfArr(num, 4) << std::endl;*/
//
////ex5
//
//	/*std::cout << linearSearch(num, 4, 7) << std::endl;*/
//
////ex6
//
//	/*std::cout << binarySearch(num, 4, 9) << std::endl;*/
//
////ex7
//
//	/*std::cout << isPalindrome("abccba", 6) << std::endl;*/
//
////ex8
//	/*int lower = 0, upper = 0;
//	lowerUpperCount("abcDFGvbHbHbH", lower, upper);
//	std::cout << lower << " " << upper << std::endl;*/
//
////max in Arr
//
//	/*std::cout << getMaxInArr(num, 4) << std::endl;
//	std::cout << getMaxInArr2(num, 4) << std::endl;*/
//
////search in Text
//
//	/*std::cout << isInText("abcdefg", 7, "cve", 3) << std::endl;*/
//
////}