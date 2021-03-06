#include "LoadLevel.h"

namespace spacey{ namespace level{

	void loadObject(vector<CircleObject> &systemVector, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening level file named '" << fileName << "' failed.\n";
		}
		else{
			string line, filename;
			int x, y, size, amount;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> size >> filename; //read the values for the planet and add them to the vector

						CircleObject temp(x, y, size, filename);

						systemVector.push_back(temp);
						cout << "Added element to vector.\n";
					}

				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}
		}

	}

	void loadObject(vector<Merchant> &container, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening level file named '" << fileName << "' failed.\n";
		}
		else{
			string line, filename;
			int x, y, amount;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> filename; //read the values for the planet and add them to the vector

						Merchant temp(x, y, filename);

						container.push_back(temp);
						cout << "Added element to vector.\n";
					}

				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}
		}
	}

} }