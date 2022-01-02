#include<iostream>

using namespace std;

const int SIZ_c = 4;
const int SIZ_r = 6;
void sortingMatrix(int m[][SIZ_c], int rowSize, int colSize);
int main() {

	// SIZ_r = 6, is INDEX of a row
	// SIZ_c = 4, is INDEX of a column
	int matrix[SIZ_r][SIZ_c];
	srand(time(0));

	// asighn values
	for (int i = 0; i < SIZ_r; i++) {
		for (int j = 0; j < SIZ_c; j++) {

			matrix[i][j] = rand() % 100;
		}
	}

	// print them out
	for (int i = 0; i < SIZ_r; i++) {
		for (int j = 0; j < SIZ_c; j++) {
			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}
	
	sortingMatrix(matrix, SIZ_c, SIZ_r);

	for (int i = 0; i < SIZ_r; i++) {
		for (int j = 0; j < SIZ_c; j++) {
			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}
	return 0;

}

void sortingMatrix(int m[][SIZ_c], int rowSize, int colSize){

	for (int i = 0; i < rowSize * colSize-1; i++) {

		// main idea is to use math operators / %  to control indexes of the matrix otherwise the same selection sort
		int currentMin = m[i / rowSize][i % rowSize];
		int currentRMIN = i / rowSize;
		int currentCMIN = i % rowSize;
		for (int j = i + 1; j < rowSize * colSize; j++) {


			if (currentMin > m[j / rowSize][j % rowSize]) {

				currentMin = m[j / rowSize][j % rowSize];
				currentRMIN = j / rowSize;
				currentCMIN = j % rowSize;
			}
		}
		if (currentRMIN != i / rowSize || currentCMIN != i % rowSize) {

			m[currentRMIN][currentCMIN] = m[i / rowSize][i % rowSize];
			m[i / rowSize][i % rowSize] = currentMin;
				
		}
		

	}

}