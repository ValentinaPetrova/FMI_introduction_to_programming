#include <iostream>


//int main()
//{
//ex1

	/*int n = 0;
	std::cin >> n;
	switch (n)
	{
	case 1: std::cout << "Monday" << std::endl; break;
	case 2: std::cout << "Tuesday" << std::endl; break;
	case 3: std::cout << "Wednesday" << std::endl; break;
	case 4: std::cout << "Thursday" << std::endl; break;
	case 5: std::cout << "Friday" << std::endl; break;
	case 6: std::cout << "Saturday" << std::endl; break;
	case 7: std::cout << "Sunday" << std::endl; break;
	default:
		std::cout << "This number is invalid!" << std::endl;
		break;
	}*/

//ex2

	//int n = 0;
	//std::cin >> n;
	//if (n < 100)
	//{
	//	std::cout << "Less than 100." << std::endl;
	//}
	//else if (n <= 200)
	//{
	//	std::cout << "Between 100 and 200." << std::endl;
	//}
	//else
	//{
	//	std::cout << "More than 200." << std::endl;
	//}

//ex3

	/*double speed;
	std::cin >> speed;

	if (speed <= 10)
		std::cout << "Slow" << std::endl;
	else if (speed < 50)
		std::cout << "Average" << std::endl;
	else if (speed < 150)
		std::cout << "Fast" << std::endl;
	else if (speed < 1000)
		std::cout << "Ultra fast" << std::endl;
	else
		std::cout << "Extremely fast" << std::endl;*/

//ex4

	/*const double PI = 3.14;
	char figure;
	std::cin >> figure;
	if (figure == 's')
	{
		double side;
		std::cin >> side;
		std::cout << side * side << std::endl;
	}
	else if (figure == 'r')
	{
		double sideA, sideB;
		std::cin >> sideA >> sideB;
		std::cout << sideA * sideB << std::endl;
	}
	else if (figure == 'c')
	{
		double R;
		std::cin >> R;
		std::cout << PI * R * R << std::endl;
	}
	else if (figure == 't')
	{
		double width;
		double height;
		std::cin >> width >> height;
		std::cout << width * height / 2 << std::endl;
	}
	else
	{
		std::cout << "Invalid figure!" << std::endl;
	}*/

//ex5

	/*int hours, mins;
	std::cin >> hours >> mins;

	(mins += 15) %= 60;

	if (mins < 15)
		(hours += 1) %= 24;

	if (hours <= 9)
		std::cout << 0;
	std::cout << hours << ":";

	if (mins <= 9)
		std::cout << 0;
	std::cout << mins << std::endl;*/

//ex6

//int a, b, c, d, e;
//cin >> a >> b >> c >> d >> e;
//
//if ((a <= b && b >= c && c <= d && d >= e)
//	|| (a >= b && b <= c && c >= d && d <= e))
//{
//	cout << "Yes";
//}
//else
//cout << "No";

//ex7

//int x;
//int y;
//int radius;
//
//cin >> x >> y >> radius;
//
//if (x * x + y * y < radius * radius)
//{
//	cout << "In the circle";
//}
//else if (x * x + y * y == radius * radius)
//{
//	cout << "On the circle";
//}
//else
//{
//	cout << "Out of the circle";
//}
//}
