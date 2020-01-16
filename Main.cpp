#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void openFile(ifstream&, string);
void processFile(ifstream&);

int main() {
	ifstream inFile;
	
	openFile(inFile, "sentence.txt");
	// process file
	processFile(inFile);
	inFile.close();

	return 0;
}

void processFile(ifstream& inFile) {
	string line, word;
	istringstream iss;
	
	while (!inFile.eof()) {
		// process line by line in file
		getline(inFile, line);
		if (inFile.good()) {
			//cout << line << endl;
			// process word by word in line
			iss.clear();
			iss.str(line);
			while (iss.good()) {
				iss >> word;
				//cout << word << endl;
				// process char by char in word
				for (char c : word) {
					cout << c << endl;
				}
			}
		}
	}
}

void openFile(ifstream& inFile, string fname) {
	inFile.open(fname);
	if (inFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}

}

