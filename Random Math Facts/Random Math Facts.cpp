

#include <iostream>
#include <random>
#include <math.h>
#include <string>
#include <chrono>
#include <iomanip>
#include <limits>
#include <thread>

std::random_device rd;
std::mt19937 gen(rd());



int main()
{
    std::string Mathtype;
	std::string Factcount;
	
	int completed = 0;
	int correct = 0;
	int incorrect = 0;
	int question_number = 0;

	double total_time = 0.0;
	double min_time = std::numeric_limits<double>::infinity();
	double max_time = 0.0;

	std::cout << "Welcome to Random Math Facts!\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "Please remember to use proper spelling and capitalization to prevent glitches with the recognition software!\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "All word inputs are started with a capital and do not get punctuation: Ex: Addition \n";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "And remember, just keep numbers, numbers, Ex: 10 or -10 \n";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "Please enter the type of math desired (Addition, Multiplication, Division, Subtraction): ";
	std::cin >> Mathtype;
	std::cout << "Please enter the number of questions desired: ";
	std::cin >> Factcount;
	int Factcountint = stoi(Factcount);
	int diff = 0;
	int min = 0;
	int max = 0;
	float difficulty_levelmultiplyer = 0; //This multiplyer will be used to determine the acceptable time for a question to take, by dividing the time taken by the multiplyer.
	std::cout << "Please enter the difficulty level for the questions (0-10): ";
	std::cin >> diff;
	if (diff == 0) {
		min = -1;
		max = 1;
		difficulty_levelmultiplyer = 100;
	}
	else if (diff == 1) {
		min = -10;
		max = 10;
		difficulty_levelmultiplyer = 90;
	}
	else if (diff == 2) {
		min = -100;
		max = 100;
		difficulty_levelmultiplyer = 80;
	}
	else if (diff == 3) {
		min = -1000;
		max = 1000;
		difficulty_levelmultiplyer = 70;
	}
	else if (diff == 4) {
		min = -10000;
		max = 10000;
		difficulty_levelmultiplyer = 60;
	}
	else if (diff == 5) {
		min = -100000;
		max = 100000;
		difficulty_levelmultiplyer = 50;
	}
	else if (diff == 6) {
		min = -1000000;
		max = 1000000;
		difficulty_levelmultiplyer = 40;
	}
	else if (diff == 7) {
		min = -10000000;
		max = 10000000;
		difficulty_levelmultiplyer = 30;
	}
	else if (diff == 8) {
		min = -100000000;
		max = 100000000;
		difficulty_levelmultiplyer = 20;
	}
	else if (diff == 9) {
		min = -1000000000;
		max = 1000000000;
		difficulty_levelmultiplyer = 10;
	}
	else if (diff == 10) {
		min = -10000000000;
		max = 10000000000;
		difficulty_levelmultiplyer = 1;
	}
	std::uniform_int_distribution<int> Digit1(min, max);
	std::uniform_int_distribution<int> Digit2(min, max);
	while (completed < Factcountint){
		auto t0 = std::chrono::steady_clock::now();
		if (Mathtype == "Addition") {
			int answer;
			int num1 = Digit1(gen);
			int num2 = Digit2(gen);
			question_number++;
			std::cout << "Question " << question_number << ":\n";
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
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

			}
			else {
				std::cout << "Incorrect. The correct answer is " << num1 + num2 << "\n";
				completed++;
				incorrect++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

			}
		}
		else if (Mathtype == "Multiplication") {
			int answer;
			int num1 = Digit1(gen);
			int num2 = Digit2(gen);
			question_number++;
			std::cout << "Question " << question_number << ":\n";
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
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

			}
			else {
				std::cout << "Incorrect. The correct answer is " << num1 * num2 << "\n";
				completed++;
				incorrect++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

			}
		}
		else if (Mathtype == "Division") {
			int answer;
			int num2 = Digit2(gen) + 1; // avoid division by zero
			int num1 = num2 * (Digit1(gen) + 1); // ensure num1 is divisible by num2
			question_number++;
			std::cout << "Question " << question_number << ":\n";
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
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

			}
			else {
				std::cout << "Incorrect. The correct answer is " << num1 / num2 << "\n";
				completed++;
				incorrect++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

			}
		}
		else if (Mathtype == "Subtraction") {
			int answer;
			int num1 = Digit1(gen);
			int num2 = Digit2(gen);
			question_number++;
			std::cout << "Question " << question_number << ":\n";
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
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

			}
			else {
				std::cout << "Incorrect. The correct answer is " << num1 - num2 << "\n";
				completed++;
				incorrect++;
				std::cout << "(Time: " << std::fixed << std::setprecision(2) << elapsed << "s)\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

			}
		}
		else {
			std::cout << "Invalid math type entered." << std::endl;
			break;
		}
	}
	float percentage = (float)correct / (float)Factcountint * 100.0f;
	float incorrect_percentage = (float)incorrect / (float)Factcountint * 100.0f;
	
	std::cout << "All questions complete: Correct: "<<correct<<" Incorrect: "<<incorrect<<" Percent correct: "<<percentage<<" % \n";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	double avg_time = total_time / completed;
	if (incorrect == 0) {
		incorrect_percentage = 1.0f; // avoid division by zero
	}
	float MasteryCalculation = incorrect_percentage * avg_time;
	float TotalMastery = MasteryCalculation / difficulty_levelmultiplyer;
	std::cout << std::fixed << std::setprecision(2);
	float minutes = (float)total_time / 60;
	std::cout << "Total time: " << total_time << "seconds, or "<<minutes<<" minutes\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::cout << "Average time per question: " << avg_time << "s\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::cout << "Fastest question: " << min_time << "s\n";
	std::cout << "Slowest question: " << max_time << "s\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "Mastery Calculation (lower is better): " << MasteryCalculation << "\n";
	if (MasteryCalculation < 10.0f) {
		std::cout << "A Rayman Legend! Exceptional Performance!\n";
	}
	else if (MasteryCalculation < 30.0f) {
		std::cout << "Incomparable performance!\n";
	}
	else if (MasteryCalculation < 50.0f) {
		std::cout << "Significant Brilliance!\n";
	}
	else if (MasteryCalculation < 100.0f) {
		std::cout << "Interestingly procured...\n";
	}
	else if (MasteryCalculation < 200.0f) {
		std::cout << "Adequate understanding.\n";
	}
	else if (MasteryCalculation < 300.0f) {
		std::cout << "Erroneus calculator.\n";
	}
	else if (MasteryCalculation < 500.0f) {
		std::cout << "Terrible Trigonometry!\n";
	}
	else if (MasteryCalculation < 600.0f){
		std::cout << "Tragic terminology!\n";
	}
	else {
		std::cout << "You just plain old failed at this one. Better Luck next time.";
	}

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
