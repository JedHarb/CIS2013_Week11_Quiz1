#include<iostream>
#include<cstring>

using namespace std;

int main() {
	int computerRows;
	int *a;
	int totalComputers = 0;
	int *computerGradeStorage;
	char keepAlive = 'y';
	int chosenRow;
	int chosenComputer;
	int chosenGrade;
	int computerCount = 0;

	cout << "How many rows are there? ";
	cin >> computerRows;
	while (computerRows > 99 || computerRows < 1) {
		cout << "Sorry, I can't do that. Choose between 1 and 99, please: ";
		cin >> computerRows;
	}

	a = new int[computerRows];

	for (int i = 0; i<computerRows; i++) {
		cout << "How many computers are on row " << i + 1 << "? ";
		cin >> a[i];
		totalComputers += a[i];
	}

	computerGradeStorage = new int[totalComputers];

	for (int b = 0; b <= totalComputers; b++) {
		computerGradeStorage[b] = 101;
		//cout << computerGradeStorage[b] << endl;
	}

	cout << endl;
	for (int y = 1; y<=computerRows; y++) {
		cout << y << ": ";
		for (int x = 0; x<a[y-1]; x++) {
			cout << " empty";
		}
		cout << endl;
	}

	cout << endl;
	while (keepAlive == 'y') {
		cout << "Pick a row: ";
		cin >> chosenRow;
		while (chosenRow < 0 || chosenRow > computerRows) {
			cout << "Try again: ";
			cin >> chosenRow;
		}
		cout << "Pick a computer starting from the left: ";
		cin >> chosenComputer;
		while (chosenComputer < 0 || chosenComputer > a[chosenRow - 1]) {
			cout << "Try again: ";
			cin >> chosenComputer;
		}
		cout << "What is the grade of this computer? ";
		cin >> chosenGrade;
		while (chosenGrade < 0 || chosenGrade > 100) {
			cout << "Try again: ";
			cin >> chosenGrade;
		}
		cout << endl;
		computerCount = 0;
		for (int x = 0; x < chosenRow - 1; x++) {
			computerCount += a[x];
		}
		computerCount += chosenComputer;
		computerGradeStorage[computerCount] = chosenGrade;
		computerCount = 0;
		for (int y = 1; y <= computerRows; y++) {
			cout << y << ": ";
			for (int x = 0; x < a[y - 1]; x++) {
					computerCount++;
				if (computerGradeStorage[computerCount] == 101) {
					cout << " empty";
				}
				else {
					cout << " " << computerGradeStorage[computerCount];
				}
			}
			cout << endl;
		}
		cout << endl << "Type 'y' to continue: ";
		cin >> keepAlive;
	}
	return 0;
}
