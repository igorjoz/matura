#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

fstream input, output;

const int NUMBERS_QUANTITY = 500;
int numbers[NUMBERS_QUANTITY];

int silnia(int number) {
	int sum = 1;

	for (int i = 1; i <= number; i++) {
		sum *= i;
		//cout << number << ", " << sum << " i:" << i << endl;
	}
	return sum;
}

int nwd(int a, int b) {
	if (b == 0)
		return a;
	return nwd(b, (a % b));
}

int main()
{
	input.open("liczby.txt", ios::in);
	if (input.good()) {

		for (int i = 0; i < NUMBERS_QUANTITY; i++) {
			input >> numbers[i];
		}

		output.open("wyniki4.txt", ios::out);
		if (output.good()) {
			// 4.1
			int counter = 0;

			for (int i = 0; i < NUMBERS_QUANTITY; i++) {
				int number_copy = numbers[i];
				while (true) {
					if (number_copy == 1) {
						counter++;
						break;
					}
					else if (number_copy % 3 == 0) {
						number_copy /= 3;
					}
					else {
						break;
					}
				}
			}
			cout << counter << endl << endl;

			output << "4.1: " << counter << endl << endl;


			// 4.2
			output << "4.2:" << endl;

			for (int i = 0; i < NUMBERS_QUANTITY; i++) {
				string numberStr = to_string(numbers[i]);
				int sum = 0;

				for (int k = 0; k < numberStr.length(); k++) {
					sum += silnia(numberStr[k] - '0');
				}
				//cout << number << " i " << sum;

				if (numbers[i] == sum) {
					cout << numbers[i] << endl;
					output << numbers[i] << endl;
				}
				//cout << endl;
			}
			cout << endl;

			// 4.3
			//int nwdCounter = 1;
			//int nwdMaxCounter = 0;

			//int lastNwd = nwd(numbers[0], numbers[1]);
			//int currentNwd = 0;
			//int maxNwd = 0;

			//int firstNumber = 0, maxFirstNumber = 0;

			//for (int i = 2; i < NUMBERS_QUANTITY; i++) {

			//	currentNwd = nwd(lastNwd, numbers[i]);
			//	cout << currentNwd << " - " << lastNwd << endl;

			//	if (currentNwd == lastNwd && currentNwd != 1) {
			//		cout << " |-| ";
			//		nwdCounter++;

			//		//if (nwdCounter == 1) {

			//			//firstNumber = numbers[i - 1];

			//			//if (numbers[i - 1] > numbers[i - 1]) biggestNumber = numbers[i - 1];
			//			//else biggestNumber = numbers[i];
			//		//}
			//	}
			//	else {
			//		nwdCounter = 1;
			//	}

			//	if (nwdCounter > nwdMaxCounter) {
			//		nwdMaxCounter = nwdCounter;
			//	}

			//	lastNwd = currentNwd;
			//}
			//cout << nwdMaxCounter << " " << maxFirstNumber << " " << endl;

			// 4.3
			int streakNwd;
			int currentNwd;
			int counter = 1;

			cout << streakNwd;
			for (int i = 2; i < NUMBERS_QUANTITY; i++) {
				currentNwd = nwd(nwd(numbers[i - 2], numbers[i - 1]), numbers[i]);

				if (counter == 1) {
					streakNwd = currentNwd;
				}
				else if () {

				}
			}

		}
		else {
			cout << "Problem z plikiem wyjsciowym";
		}

	}
	else {
		cout << "Problem otworzeniem pliku wejsciowego";
	}

	input.close();
}