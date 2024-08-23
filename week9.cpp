#include <iostream>
//#include "week6.cpp"

const int SIZE = 100;

void swap1(double& a, double& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//void swapRows(double arr1[], double arr2[], int n)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		swap1(arr1[i], arr2[i]);
//	}
//}

void swapRows(double* row1, double* row2, int n) {
	for (int i = 0; i < n; i++) {
		swap1(row1[i], row2[i]);
	}
}

void transposeMatrix(int arr[][SIZE], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}	
	}
}

void printMatrix(double arr[][SIZE], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void printMatrix(int arr[][SIZE], int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool isReflexive(int arr[][SIZE], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i][i] != 1)
		{
			return false;
		}
	}
	return true;
}

bool isSymmetric(int arr[][SIZE], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (arr[i][j] != arr[j][i])
			{
				return false;
			}
		}
	}

	return true;
}

bool isTransitive(int arr[][SIZE], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				if (arr[i][j] && arr[j][k] && !arr[i][k])
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool isEquvalentRelation(int arr[][SIZE], int n)
{
	return isReflexive(arr, n) && isSymmetric(arr, n) && isTransitive(arr, n);
}

void multiplyMatricies(int A[][SIZE], int B[][SIZE], int C[][SIZE], int N, int M, int K)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < K; j++)
		{
			C[i][j] = 0;
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < K; j++)
		{
			for (size_t k = 0; k < M; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

bool invertMatrix(double arr[][SIZE], double inverted[][SIZE], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i == j)
			{
				inverted[i][j] = 1;
			}
			else
			{
				inverted[i][j] = 0;
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		if (arr[i][i] == 0)
		{
			bool swapped = false;
			for (size_t j = i + 1; j < n; j++)
			{
				if (arr[j][i] != 0)
				{
					swapRows(arr[i], arr[j], n);
					swapRows(inverted[i], inverted[j], n);
					swapped = true;
					break;
				}

			}
			if (!swapped)
			{
				return false;
			}
		}
		
		double diagonal = arr[i][i];
		for (size_t j = 0; j < n; j++)
		{
			arr[i][j] /= diagonal;
			inverted[i][j] /= diagonal;
		}

		for (size_t j = 0; j < n; j++)
		{
			if (i != j)
			{
				double factor = arr[j][i];
				for (size_t k = 0; k < n; k++)
				{
					arr[j][k] -= factor * arr[i][k];
					inverted[j][k] -= factor * inverted[i][k];
				}
			}

		}
	}

	return true;

}

//int main()
//{
//	int n = 0;
//	std::cin >> n;
//	double arr[SIZE][SIZE];
//	for (size_t i = 0; i < n; i++)
//	{
//		for (size_t j = 0; j < n; j++)
//		{
//			std::cin >> arr[i][j];
//		}
//	}

//ex1

	/*transposeMatrix(arr, n);
	printMatrix(arr, n);*/

//ex2

	/*std::cout << isEquvalentRelation(arr, n) << std::endl;*/

//ex3

	/*int n = 0, m = 0, k = 0;
	int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

	std::cin >> n >> m >> k;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cin >> A[i][j];
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < k; j++)
		{
			std::cin >> B[i][j];
		}
	}

	multiplyMatricies(A, B, C, n, m, k);
	printMatrix(C, n, k);*/

//ex4

	/*double inverted[SIZE][SIZE];
	if (invertMatrix(arr, inverted, n))
	{
		printMatrix(inverted, n);
	}
	else
	{
		std::cout << "Doesn't exist!" << std::endl;
	}*/
	
	

//}