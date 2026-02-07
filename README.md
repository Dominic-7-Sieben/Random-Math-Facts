This is a simple math fact generator that runs in the terminal.
It starts by asking for the desired type of math facts: (Addition, Multiplication, Subtraction, Division).
Then it requests the desired amount of questions for the round.
Then it requests the desired difficulty level (0-10).
The difficulty level sets the maximum and minimum for the random numbers generated:

	0: -1 to 1
	1: -10 to 10
	2: -100 to 100
	3: -1000 to 1000
	4: -10000 to 10000
	5: -100000 to 100000
	6: -1000000 to 1000000
	7: -10000000 to 10000000
	8: -100000000 to 100000000
	9: -1000000000 to 1000000000
	10: -10000000000 to 10000000000

Essentially, each level increases the number of zeros by 1.
Once the initializing factors are completed, the program will begin giving out questions similar to as follows:

	Question 1:
 	-10 + 5 = 
	
 If the question is answered correctly, it says "Correct!" and displays the time taken to answer the quesiton:
	
	 Question 1:
	 -10 + 5 = -5
	 Correct!
	(Time: 3.07s)

If a question is answered incorrectly, it says "Incorrect." then displays the real answer and the time taken:

	Question 3:
	 -6 + -2 = 2
	Incorrect. The correct answer is -8
	(Time: 1.71s)
	
Once a round is completed, the system displays how many questions were right, how many were wrong, and the percent correct:

	All questions complete: Correct: 9 Incorrect: 1 Percent correct: 90.00 %	
Then it displays the total time taken to complete the round in seconds and minutes:

	Total time: 20.73seconds, or 0.35 minutes
Then it displays time the fastest question time, and the slowest question time:

	Fastest question: 1.70s
	Slowest question: 2.69s
Then it performs a "Mastery Calculation" where the lower the number is, the better you are at the round of questions:

	Mastery Calculation (lower is better): 20.73
And finally, based on the mastery calculation, it gives you a title:

	Incomparable performance!
So a whole round with 10 addition questions set at level 1 looks like this:

	Welcome to Random Math Facts!
	Please remember to use proper spelling and capitalization to prevent glitches with the recognition software!
	All word inputs are started with a capital and do not get punctuation: Ex: Addition
	And remember, just keep numbers, numbers, Ex: 10 or -10
	Please enter the type of math desired (Addition, Multiplication, Division, Subtraction): Addition
	Please enter the number of questions desired: 10
	Please enter the difficulty level for the questions (0-10): 1
	Question 1:
	 -9 + -7 = -16
	Correct!
	(Time: 2.69s)
	Question 2:
	 -7 + 7 = 0
	Correct!
	(Time: 1.74s)
	Question 3:
	 -6 + -2 = 2
	Incorrect. The correct answer is -8
	(Time: 1.71s)
	Question 4:
	 -1 + 9 = 8
	Correct!
	(Time: 2.34s)
	Question 5:
	 1 + -7 = -6
	Correct!
	(Time: 1.70s)
	Question 6:
	 2 + -8 = -6
	Correct!
	(Time: 2.27s)
	Question 7:
	 -2 + 5 = 3
	Correct!
	(Time: 2.07s)
	Question 8:
	 -2 + -10 = -12
	Correct!
	(Time: 1.81s)
	Question 9:
	 -8 + -1 = -9
	Correct!
	(Time: 1.79s)
	Question 10:
	 -2 + 8 = 6
	Correct!
	(Time: 2.63s)
	All questions complete: Correct: 9 Incorrect: 1 Percent correct: 90.00 %
	Total time: 20.73seconds, or 0.35 minutes
	Average time per question: 2.07s
	Fastest question: 1.70s
	Slowest question: 2.69s
	Mastery Calculation (lower is better): 20.73
	Incomparable performance!

C:\Users\dcsie\source\repos\Random Math Facts\x64\Debug\Random Math Facts.exe (process 18760) exited with code 0 (0x0).
Press any key to close this window . . .
