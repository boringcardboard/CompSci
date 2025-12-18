#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;


const int SIZE_X = 89;
const int SIZE_Y = 6;

string pieceArray[SIZE_X][SIZE_Y];


int main(){

	ifstream inputFS;
	string fileName = "";
	string fileLine = "";

	int inputMin_X = 0;
	int inputMax_X = 0;
	int inputMin_Y = 0;
	int inputMax_Y = 0;


	for (int i = 0; i < SIZE_X; i++) {
		for (int j = 0; j < SIZE_Y; j++) {
			pieceArray[i][j] = " ";
		}
	}

	cout << "Please enter a valid .csv file." << endl;

	cin >> fileName;
	inputFS.open(fileName);

	if (!inputFS.is_open()) {
		cout << fileName << " could not be opened." << endl;
		return 0;
	}


	while (inputFS.peek() != EOF) {
		getline(inputFS, fileLine);
		fileLine.erase(remove(fileLine.begin(), fileLine.end(), ' '), fileLine.end());
		int xCoordPos = fileLine.find(",");
		int yCoordPos = fileLine.find(",", xCoordPos + 1);
		int blockPos = fileLine.find(",", yCoordPos);
		if ((xCoordPos > 0) && (yCoordPos > 0)) {
			int x = stoi(fileLine.substr(0, xCoordPos));
			int y = stoi(fileLine.substr(xCoordPos + 1, yCoordPos));
			string block = fileLine.substr(blockPos + 1);
			pieceArray[x][y] = block;
			if (x < inputMin_X) {
				inputMin_X = x;
			}
			if (y < inputMin_Y) {
				inputMin_Y = y;
			}
			if (x > inputMax_X) {
				inputMax_X = x;
			}
			if (y > inputMax_Y) {
				inputMax_Y = y;
			}
		}
	}
	
	cout << "Max x: " << inputMax_X << " Max y: " << inputMax_Y << endl;
	cout << "Min x: " << inputMin_X << " Min y: " << inputMin_Y << endl;
	

	cout << "Now time to decode!" << endl;
	for (int i = 0; i < SIZE_X; i++) {
		for (int j = 0; j < SIZE_Y; j++) {
			cout << "X: " << i << " Y: " << j << " Block: " << pieceArray[i][j] << endl;
		}
	}


	for (int i = 0; i <= SIZE_Y; i++) {
		for (int j = 0; j < SIZE_X; j++) {
			cout << pieceArray[j][i];
		}
		cout << endl;
	}


	inputFS.close();
	return 0;
}

