#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> districts;
	vector<string> wards;
	vector<string> streets;
	vector<vector<int>> numberOfWardsAndStreets;

	ifstream file_in;
	file_in.open("hcmAddresses.txt", ios_base::in);
	int numberOfDistricts = 0, numberOfWards = 0, numberOfStreets = 0;

	//read numberOfDistricts
	file_in >> numberOfDistricts;
	file_in.ignore();

	string districtName = "", wardName = "", streetName = "";
		
	for (int i = 0; i < numberOfDistricts; i++) {
		vector<int> numberOfWardAndStreet;

		getline(file_in, districtName);
		districts.push_back(districtName);

		file_in >> numberOfWards;
		file_in.ignore();

		numberOfWardAndStreet.push_back(numberOfWards);

		for (int j = 0; j < numberOfWards; j++) {
			getline(file_in, wardName);
			wards.push_back(wardName);
		}

		file_in >> numberOfStreets;
		file_in.ignore();

		numberOfWardAndStreet.push_back(numberOfStreets);
		numberOfWardsAndStreets.push_back(numberOfWardAndStreet);

		for (int j = 0; j < numberOfStreets; j++) {
			getline(file_in, streetName);
			streets.push_back(streetName);
		}
	}

	for (auto district:districts) {
		cout << district << "\n";
	}

	for (auto ward:wards) {
		cout << ward << "\n";
	}

	for (auto street:streets) {
		cout << street << "\n";
	}

	for (int i = 0; i < numberOfWardsAndStreets.size(); i++) {
		cout << "[";
		for (int j = 0; j < numberOfWardsAndStreets[i].size(); j++) {
			cout << numberOfWardsAndStreets[i][j] << ", ";
		}
		cout << "]\n";
	}
}