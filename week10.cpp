#include <iostream>

const int SIZE = 100;

int myStrlen(char* text)
{
	if (!text)
	{
		return 0;
	}

	int count = 0;
	while (*text)
	{
		count++;
		text++;
	}

	return count;
}

void replaceInText(char* text, char* what, char* where)
{
	int textLen = myStrlen(text);
	int whatLen = myStrlen(what);
	int whereLen = myStrlen(where);

	char buffer[SIZE];
	int bufferLen = 0;

	for (size_t i = 0; i < textLen; i++)
	{
		bool match = true;
		for (size_t j = 0; j < whereLen; j++)
		{
			if (text[i + j] != where[j])
			{
				match = false;
				break;
			}
		}

		if (match)
		{
			for (size_t j = 0; j < whatLen; j++)
			{
				buffer[bufferLen] = what[j];
				bufferLen++;
			}
			i += whereLen;
		}

		else
		{
			buffer[bufferLen] = text[i];
			bufferLen++;
			/*i++;*/
		}

	}

	buffer[bufferLen] = '\0';

	int i = 0;
	while (buffer[i] != '\0')
	{
		text[i] = buffer[i];
		i++;
	}

	text[i] = '\0';
}

void toUpper(char* text)
{
	while (*text)
	{
		if (*text >= 'a' && *text <= 'z')
		{
			*text -= ('a' - 'A');
		}
		text++;
	}
}

char toLower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c + ('a' - 'A');
	}
	return c;
}

void toLower(char* text)
{
	while (*text)
	{
		if (*text >= 'A' && *text <= 'Z')
		{
			*text += ('a' - 'A');
		}

		text++;
	}
}

bool isDeliter(char c)
{
	return c == ' ' || c == '\t' || c == '.' || c == ',' || c == '!' ||
		c == '?' || c == ';' || c == ':' || c == '-' || c == '\'' ||
		c == '\"' || c == '(' || c == ')' || c == '[' || c == ']' ||
		c == '{' || c == '}' || c == '/' || c == '\\' || c == '|';
}

int countWordsInString(const char* text)
{
	int counter = 0;
	bool inWord = false;

	while (*text)
	{
		if (!isDeliter(*text))
		{
			if (!inWord)
			{
				inWord = true;
				counter++;
			}
		}
		else
		{
			inWord = false;
		}
		text++;
	}

	return counter;
}

void addOrUpdateWord(char words[SIZE][50], int wordCounts[], int& wordCount, const char* currentWord)
{
	for (int i = 0; i < wordCount; i++) {
		// Сравняваме дали думата съществува вече
		bool isSame = true;
		for (int j = 0; currentWord[j] != '\0' || words[i][j] != '\0'; j++) {
			if (currentWord[j] != words[i][j]) {
				isSame = false;
				break;
			}
		}

		if (isSame) {
			wordCounts[i]++;
			return;
		}
	}

	// Ако думата не е намерена, добавяме нова
	int j = 0;
	while (currentWord[j] != '\0') {
		words[wordCount][j] = currentWord[j];
		j++;
	}
	words[wordCount][j] = '\0';
	wordCounts[wordCount] = 1;
	wordCount++;

}


const char* findMostFrequentWord(const char* text)
{
	char words[SIZE][50];
	int wordCounts[SIZE];
	int wordCount = 0;
	char currentWord[50];
	int currentWordLength = 0;

	while (*text) {
		char c = toLower(*text); 
		if (!isDeliter(c)) {
			currentWord[currentWordLength++] = c;
		}
		else if (currentWordLength > 0) {
			currentWord[currentWordLength] = '\0';
			addOrUpdateWord(words, wordCounts, wordCount, currentWord);
			currentWordLength = 0;
		}
		text++;
	}

	// Добавяне на последната дума, ако е необходимо
	if (currentWordLength > 0) {
		currentWord[currentWordLength] = '\0';
		addOrUpdateWord(words, wordCounts, wordCount, currentWord);
	}

	// Намиране на най-често срещаната дума
	int maxCount = 0;
	const char* mostFrequentWord = nullptr;
	for (int i = 0; i < wordCount; i++) {
		if (wordCounts[i] > maxCount) {
			maxCount = wordCounts[i];
			mostFrequentWord = words[i];
		}
	}

	return mostFrequentWord;
}

void myStrcpy(const char* first, char* depo)
{
	if (!first)
	{
		return;
	}

	while (*first)
	{
		*depo = *first;
		first++;
		depo++;
	}

	*depo = '\0';
}

void myStrcat(char* first, char* second)
{
	if (!first || !second)
	{
		return;
	}

	size_t firstLen = myStrlen(first);
	first += firstLen;
	myStrcpy(second, first);
}

int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
	{
		return 0;
	}
	while (*first && *second && (*first == *second))
	{
		first++; 
		second++;
	}

	return (*first - *second);
}

const char* findSmallestLexikographicWord(const char* text)
{
	static char smallestWord[50];
	char currentWord[50];
	int currentWordLenght = 0;
	bool isFirst = true;

	while (*text)
	{
		char c = toLower(*text);
		if (!isDeliter(*text))
		{
			if (currentWordLenght <= 50)
			{
				currentWord[currentWordLenght++] = c;
			}
		}
		else if (currentWordLenght > 0)
		{
			currentWord[currentWordLenght] = '\0';
			if (isFirst || myStrcmp(currentWord, smallestWord) < 0)
			{
				myStrcpy(currentWord, smallestWord);
				isFirst = false;
			}
			currentWordLenght = 0;
		}
		text++;
	}

	if (currentWordLenght > 0)
	{
		currentWord[currentWordLenght] = '\0';
		if (isFirst || myStrcmp(currentWord, smallestWord) < 0)
		{
			myStrcpy(currentWord, smallestWord);
		}
	}

	return smallestWord;
}

int convertCharToDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}

	return -1;
}

unsigned converStringToNum(const char* text)
{
	if (!text)
	{
		return 0;
	}
	unsigned result = 0;
	while (*text)
	{
		int digit = convertCharToDigit(*text);
		if (digit == -1)
		{
			return 0;
		}

		(result *= 10) += digit;
		text++;
	}

	return result;
}

char convertDigitToChar(int digit)
{
	if (digit < 0 || digit > 9)
	{
		return '\0';
	}
	return digit + '0';
}

unsigned getNumLenght(unsigned int num)
{
	if (num == 0)
	{
		return 1;
	}
	unsigned result = 0;
	while (num != 0)
	{
		result++;
		num /= 10;
	}

	return result;
}

void convertNumToString(unsigned int num, char* str)
{
	int len = getNumLenght(num);
	for (int i = len - 1; i >= 0; i--)
	{
		str[i] = convertDigitToChar(num % 10);
		num /= 10;
	}
	str[len] = '\0';
}

//int main()
//{
	/*char text[] = "My name is Valentina is.";
	char what[] = "Boris";
	char where[] = "Valentina";*/
//std::cout << text;
//ex1 
	/*replaceInText(text, what, where);*/

//ex2
	/*toUpper(text);*/
	/*toLower(text);*/

//ex3
	/*std::cout << countWordsInString(text) << std::endl;*/

//ex4

	/*const char* text = "This is an example, an example with words for example!";
	const char* mostFrequentWord = findMostFrequentWord(text);
	std::cout << mostFrequentWord << std::endl;*/

//ex5

	/*const char* text = "Me? Why always me?";
	std::cout << findSmallestLexikographicWord(text) << std::endl;*/

//converter 
	/*std::cout << converStringToNum("123") << std::endl;

	char str[50];
	convertNumToString(123, str);
	std::cout << str << std::endl;*/
//}

