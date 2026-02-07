

#include <iostream>
#include <random>
#include <math.h>
#include <string>
#include <chrono>
#include <iomanip>
#include <limits>

std::random_device rd;
std::mt19937 gen(rd());



int main()
{
    std::string Mathtype;
	std::string Factcount;
	
	int completed = 0;
	int correct = 0;
	int incorrect = 0;

	double total_time = 0.0;
	double min_time = std::numeric_limits<double>::infinity();
	double max_time = 0.0;

	std::cout << "Welcome to Random Math Facts!\n";
	std::cout << "Please enter the type of math desired (Addition, Multiplication, Division, Subtraction): ";
	std::cin >> Mathtype;
	std::cout << "Please enter the number of questions desired: ";
	std::cin >> Factcount;
	int Factcountint = stoi(Factcount);
	int min = 0;
	int max = 0;
	std::cout << "Please enter the minimum number for the math problems: ";
	std::cin >> min;
	std::cout << "Please enter the maximum number for the math problems: ";
	std::cin >> max;
	std::uniform_int_distribution<int> Digit1(min, max);
	std::uniform_int_distribution<int> Digit2(min, max);
	while (completed < Factcountint){
		auto t0 = std::chrono::steady_clock::now();
		if (Mathtype == "Addition") {
			int answer;
			int num1 = Digit1(gen);
			int num2 = Digit2(gen);
			std::cout << " " << num1 << " + " << num2 << " = ";
			std::cin >> answer;
			auto t1 = std::chrono::steady_clock::now();
			double elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0).count();
			total_time += elapsed;
			if (elapsed < min_time) min_time = elapsed;
			if (elapsed > max_time) max_time = elapsed;

			int realanswer = num1 + num2;

			if (realanswer == answer) {
				std::cout << "Correct!\n";
				completed++;
				correct++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";

			}
			else {
				std::cout << "Incorrect. The correct answer is " << num1 + num2 << "\n";
				completed++;
				incorrect++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";

			}
		}
		else if (Mathtype == "Multiplication") {
			int answer;
			int num1 = Digit1(gen);
			int num2 = Digit2(gen);
			std::cout << " " << num1 << " * " << num2 << " = ";
			std::cin >> answer;
			int realanswer = num1 * num2;
			auto t1 = std::chrono::steady_clock::now();
			double elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0).count();
			total_time += elapsed;
			if (elapsed < min_time) min_time = elapsed;
			if (elapsed > max_time) max_time = elapsed;
			if (realanswer == answer) {
				std::cout << "Correct!\n";
				completed++;
				correct++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";

			}
			else {
				std::cout << "Incorrect. The correct answer is " << num1 * num2 << "\n";
				completed++;
				incorrect++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";

			}
		}
		else if (Mathtype == "Division") {
			int answer;
			int num2 = Digit2(gen) + 1; // avoid division by zero
			int num1 = num2 * (Digit1(gen) + 1); // ensure num1 is divisible by num2
			std::cout << " " << num1 << " / " << num2 << " = ";
			std::cin >> answer;
			int realanswer = num1 / num2;
			auto t1 = std::chrono::steady_clock::now();
			double elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0).count();
			total_time += elapsed;
			if (elapsed < min_time) min_time = elapsed;
			if (elapsed > max_time) max_time = elapsed;
			if (realanswer == answer) {
				std::cout << "Correct!\n";
				completed++;
				correct++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";

			}
			else {
				std::cout << "Incorrect. The correct answer is " << num1 / num2 << "\n";
				completed++;
				incorrect++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";

			}
		}
		else if (Mathtype == "Subtraction") {
			int answer;
			int num1 = Digit1(gen);
			int num2 = Digit2(gen);
			std::cout << " " << num1 << " - " << num2 << " = ";
			std::cin >> answer;
			int realanswer = num1 - num2;
			auto t1 = std::chrono::steady_clock::now();
			double elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0).count();
			total_time += elapsed;
			if (elapsed < min_time) min_time = elapsed;
			if (elapsed > max_time) max_time = elapsed;
			if (realanswer == answer) {
				std::cout << "Correct!\n";
				completed++;
				correct++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";

			}
			else {
				std::cout << "Incorrect. The correct answer is " << num1 - num2 << "\n";
				completed++;
				incorrect++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";

			}
		}
		else {
			std::cout << "Invalid math type entered." << std::endl;
			break;
		}
	}
	float percentage = (float)correct / (float)Factcountint * 100.0f;
	std::cout << "All questions complete: Correct: "<<correct<<" Incorrect: "<<incorrect<<" Percent correct: "<<percentage<<" % \n";
	double avg_time = total_time / completed;
	std::cout << std::fixed << std::setprecision(2);
	float minutes = (float)total_time / 60;
	std::cout << "Total time: " << total_time << "seconds, or "<<minutes<<" minutes\n";
	std::cout << "Average time per question: " << avg_time << "s\n";
	std::cout << "Fastest question: " << min_time << "s\n";
	std::cout << "Slowest question: " << max_time << "s\n";

	return 0;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
