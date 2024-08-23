#include <iostream>

int** createMatrix(int rows)
{
	int** matrix = new int*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		int colls = 0;
		std::cin >> colls;
		matrix[i] = new int[colls + 2] {0};
		matrix[i][0] = colls;
	}
	return matrix;
}

void deleteMatrix(int** matrix, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void printMatrix(int** matrix, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		int sizeOfRow = matrix[i][0];
		for (size_t j = 2; j < sizeOfRow + 2; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void swap(int*& first, int*& second)
{
	int* temp = first;
	first = second;
	second = temp;
}

void moveTheRowToTheCorrectPosition(int** matrix, int lastModified)
{
	int current = lastModified;
	while (current > 0 && matrix[current][1] > matrix[current - 1][1])
	{
		swap(matrix[current], matrix[current - 1]);
		current--;
	}
}

void addPoints(int** matrix, int row, int coll, int points)
{
	matrix[row][coll + 2] += points;
	matrix[row][1] += points;
	moveTheRowToTheCorrectPosition(matrix, row);
}
bool isWord(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

unsigned getWordsCount( const char* text)
{
	unsigned count = 0;
	while (*text)
	{
		if (isWord(*text) && !isWord(*(text + 1)))
		{
			count++;
		}
		text++;
	}
	return count;
}

void skipCharakter(const char*& text)
{
	while (*text && !isWord(*text))
	{
		text++;
	}
}

char* getNextWord(const char*& text)
{
	unsigned wordLenght = 0;
	while (isWord(text[wordLenght]))
	{
		wordLenght++;
	}

	char* word = new char[wordLenght + 1];
	word[wordLenght] = '\0';

	for (size_t i = 0; i < wordLenght; i++)
	{
		word[i] = text[i];
	}

	text += wordLenght;
	return word;
}

char** tokenize(const char* text, size_t& size)
{
	unsigned wordsCount = getWordsCount(text);

	char** words = new char* [wordsCount];

	int wordIndex = 0;
	while (*text)
	{
		skipCharakter(text);

		if (!(*text))
		{
			break;
		}

		char* word = getNextWord(text);
		words[wordIndex++] = word;
	}

	size = wordsCount;
	return words;
}

void printWords(char** words, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << words[i] << std::endl;
	}
}

void free(char** words, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}

unsigned countTokens(const char* text, char separator)
{
	unsigned counter = 0;
	while (*text)
	{
		if (*text == separator)
		{
			counter++;
		}
		text++;
	}

	return counter;
}

unsigned getEndOfToken(const char* text, char separator)
{
	for (size_t i = 0; ; i++)
	{
		if (text[i] == '\0' || text[i] ==  separator)
		{
			return i;
		}
	}

	return 0;
}

void copyNCharFromOnetoAnotherStr(const char* first, char* second, unsigned N)
{
	for (size_t i = 0; i < N; i++)
	{
		second[i] = first[i];
	}
}

char** split(const char* text, char separator)
{
	unsigned tokensCount = countTokens(text, separator) + 2;

	char** result = new char* [tokensCount];
	result[tokensCount - 1] = nullptr;

	int index = 0;
	while (*text)
	{
		unsigned endOfToken = getEndOfToken(text, separator);
		char* currentToken = new char[endOfToken + 1];
		currentToken[endOfToken] = '\0';

		copyNCharFromOnetoAnotherStr(text, currentToken, endOfToken);

		text += endOfToken;

		result[index++] = currentToken;

		if (*text == separator)
		{
			text++;
		}
	}
	return result;
}

void print(char** text)
{
	while (*text)
	{
		std::cout << *text << std::endl;
		text++;
	}
}

void freeTokens(char** text)
{
	for (size_t i = 0; text[i] != nullptr; i++)
	{
		delete[] text[i];
	}

	delete[] text;
}

//int main()
//{
//ex1 - teams Score
	//int rows;
	//std::cin >> rows;

	//int** mtx = createMatrix(rows);

	//printMatrix(mtx, rows);

	//int queriesCount;
	//std::cin >> queriesCount;

	//for (int i = 0; i < queriesCount; i++)
	//{
	//	int row, coll, points;
	//	std::cin >> row >> coll >> points;
	//	addPoints(mtx, row, coll, points);
	//	printMatrix(mtx, rows);
	//}

	///*printMatrix(mtx, rows);*/

	//deleteMatrix(mtx, rows);

//ex2

	/*size_t count;
	char** res = tokenize("hello i am a sentence", count);

	printWords(res, count);
	free(res, count);
	return 0;*/
//ex3

	/*char** res = split("this!is!test!spliting", '!');

	print(res);

	freeTokens(res);

	return 0;*/
//}


//ex4

/*#include <iostream>

// Custom function to determine if a character is alphanumeric
bool isAlphaNumeric(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

// Custom function to get the length of a string
unsigned strLength(const char* str) {
    unsigned length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}

// Custom function to copy a substring
void strCopy(const char* src, char* dest, unsigned length) {
    for (unsigned i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';  // Null-terminate the string
}

// Function to count the number of words in a text
unsigned countWords(const char* text) {
    unsigned count = 0;
    bool inWord = false;

    while (*text) {
        if (isAlphaNumeric(*text)) {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
        text++;
    }

    return count;
}

// Function to extract words into a dynamic array of char arrays
char** extractWords(const char* text, unsigned& wordCount) {
    wordCount = countWords(text);

    // Create an array of char pointers to hold words
    char** words = new char*[wordCount];
    unsigned currentWord = 0;

    const char* start = nullptr;
    bool inWord = false;
    unsigned length = 0;

    while (*text) {
        if (isAlphaNumeric(*text)) {
            if (!inWord) {
                start = text;
                inWord = true;
                length = 0;
            }
            length++;
        } else {
            if (inWord) {
                words[currentWord] = new char[length + 1];
                strCopy(start, words[currentWord], length);
                words[currentWord][length] = '\0';
                currentWord++;
                inWord = false;
            }
        }
        text++;
    }

    // Handle the last word if the text doesn't end with a delimiter
    if (inWord) {
        words[currentWord] = new char[length + 1];
        strCopy(start, words[currentWord], length);
        words[currentWord][length] = '\0';
    }

    return words;
}

// Function to censor a word by replacing all its characters with '*'
void censorWord(char* word) {
    while (*word) {
        *word = '*';
        word++;
    }
}

// Function to print all words
void printWords(char** words, unsigned wordCount) {
    for (unsigned i = 0; i < wordCount; i++) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
}

// Function to free allocated memory
void freeWords(char** words, unsigned wordCount) {
    for (unsigned i = 0; i < wordCount; i++) {
        delete[] words[i];
    }
    delete[] words;
}

int main() {
    char text[2048];
    std::cout << "Enter the text (up to 2048 characters): ";
    std::cin.getline(text, 2048);

    unsigned wordCount;
    char** words = extractWords(text, wordCount);

    char action;
    unsigned index;

    while (true) {
        std::cout << "Choose an action (c - censor, u - uncensor, r - replace, q - quit): ";
        std::cin >> action;

        if (action == 'q') {
            break;
        }

        std::cout << "Enter the index of the word: ";
        std::cin >> index;

        if (index >= wordCount) {
            std::cout << "Invalid index!" << std::endl;
            continue;
        }

        if (action == 'c') {
            censorWord(words[index]);
        } else if (action == 'u') {
            // Uncensor is simulated by re-extracting the original text
            freeWords(words, wordCount);
            words = extractWords(text, wordCount);
        } else if (action == 'r') {
            char newWord[100];
            std::cout << "Enter the new word: ";
            std::cin >> newWord;

            unsigned newWordLength = strLength(newWord);
            delete[] words[index];
            words[index] = new char[newWordLength + 1];
            strCopy(newWord, words[index], newWordLength);
        } else {
            std::cout << "Invalid action!" << std::endl;
            continue;
        }

        printWords(words, wordCount);
    }

    freeWords(words, wordCount);

    return 0;
}
*/

//ex5

/*#include <iostream>

const int MAX_PLAYERS = 10;

// Структура за представяне на играч
struct Player {
    char* name;
    int points;
};

// Функция за добавяне на точки на играч по име
void addPoints(Player* players, int playerCount, const char* name, int points) {
    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].points += points;
            return;
        }
    }
}

// Функция за сортиране на играчите по точки (низходящо)
void sortPlayers(Player* players, int playerCount) {
    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = i + 1; j < playerCount; j++) {
            if (players[j].points > players[i].points) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

// Функция за отпечатване на играчите
void printPlayers(const Player* players, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        std::cout << players[i].name << ": " << players[i].points << std::endl;
    }
}

// Функция за освобождаване на паметта за низовете
void freeMemory(Player* players, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        delete[] players[i].name;
    }
}

int main() {
    int playerCount = 0;
    Player players[MAX_PLAYERS];

    while (true) {
        std::cout << "Enter player name (or 'end' to stop): ";
        char tempName[1024];
        std::cin.getline(tempName, 1024);

        if (strcmp(tempName, "end") == 0) {
            break;
        }

        // Динамично заделяне на памет за името на играча
        players[playerCount].name = new char[strlen(tempName) + 1];
        strcpy(players[playerCount].name, tempName);
        players[playerCount].points = 0;

        playerCount++;
        if (playerCount >= MAX_PLAYERS) {
            std::cout << "Maximum number of players reached." << std::endl;
            break;
        }
    }

    while (true) {
        std::cout << "Enter player name to add points (or 'end' to stop): ";
        char name[1024];
        std::cin.getline(name, 1024);

        if (strcmp(name, "end") == 0) {
            break;
        }

        std::cout << "Enter points to add: ";
        int points;
        std::cin >> points;
        std::cin.ignore();  // Изчистване на новия ред след въвеждането на точки

        addPoints(players, playerCount, name, points);
        sortPlayers(players, playerCount);

        std::cout << "Players sorted by points:" << std::endl;
        printPlayers(players, playerCount);
    }

    // Освобождаване на заделената памет за имената на играчите
    freeMemory(players, playerCount);

    return 0;
}
*/