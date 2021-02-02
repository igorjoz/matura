#include <iostream>
#include <math.h>

using namespace std;

bool czyPierwsza(int a) {
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

bool czyGoldbach(int a) {
	for (int i = 2; i <= a - i; i++) {
		if (czyPierwsza(i) && czyPierwsza(a - i)) {
			return true;
		}
	}
	return false;
}

void rozlozGoldbach(int a) {
	for (int i = 2; i <= a - i; i++) {
		if (czyPierwsza(i) && czyPierwsza(a - i)) {
			cout << a << " = " << i << " + " << a - i << "\n";
			return;
		}
	}
	cout << a << " nie jest liczba Goldbacha\n";
}

void rozlozGoldbachWszystkie(int a) {
	bool znalezione = false;
	cout << a;
	for (int i = 2; i <= a - i; i++) {
		if (czyPierwsza(i) && czyPierwsza(a - i)) {
			cout << " = " << i << " + " << a - i;
			znalezione = true;
		}
	}
	if(!znalezione)
		cout << " nie jest liczba Goldbacha";
	cout << endl;
}

int main() {
	int a;
	cout << "Podaj liczbe do sprawdzenia:\n";
	cin >> a;
	rozlozGoldbachWszystkie(a);
	system("pause");
	return 0;
}
