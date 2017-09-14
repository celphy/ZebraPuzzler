#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> color = {"red", "green", "blue", "ivory", "yellow"};
vector<string> nationality = {"english", "spanish", "ukranian", "norwegian", "japanese"};
vector<string> drink = { "WATER", "tea", "milk", "orange juice", "coffee" };
vector<string> brand = {"kools", "chesterfield", "old gold", "lucky strike", "parliament"};
vector<string> pet = {"fox", "horse", "snails", "dog", "ZEBRA"};


void main(void) {
	sort(color.begin(), color.end());
	sort(nationality.begin(), nationality.end());
	sort(drink.begin(), drink.end());
	sort(brand.begin(), brand.end());
	sort(pet.begin(), pet.end());

	while (next_permutation(color.begin(), color.end())) {

		//green right to ivory
		auto it = find(color.begin(), color.end(), "green");
		int index = distance(color.begin(), it);
		if (index < 1)
			continue;
		if (color.at(index - 1) != "ivory")
			continue;

		while (next_permutation(nationality.begin(), nationality.end())) {

			//Englishman in the red house?
			it = find(nationality.begin(), nationality.end(), "english");
			index = distance(nationality.begin(), it);
			if (color.at(index) != "red")
				continue;

			//norwegian in first
			it = find(nationality.begin(), nationality.end(), "norwegian");
			index = distance(nationality.begin(), it);
			if (index != 0)
				continue;

			//norwegian next to blue

			it = find(nationality.begin(), nationality.end(), "norwegian");
			index = distance(nationality.begin(), it);
			if (color.at(1) != "blue")
				continue;

			while (next_permutation(drink.begin(), drink.end())) {

				//Coffee in green house
				it = find(drink.begin(), drink.end(), "coffee");
				index = distance(drink.begin(), it);
				if (color.at(index) != "green")
					continue;

				//Ukrainian drinks tea
				it = find(nationality.begin(), nationality.end(), "ukranian");
				index = distance(nationality.begin(), it);
				if (drink.at(index) != "tea")
					continue;

				//milk in middle
				it = find(drink.begin(), drink.end(), "milk");
				index = distance(drink.begin(), it);
				if (index != 2)
					continue;

				while (next_permutation(brand.begin(), brand.end())) {

					//kools in yellow
					it = find(brand.begin(), brand.end(), "kools");
					index = distance(brand.begin(), it);
					if (color.at(index) != "yellow")
						continue;

					//lucky strike orange juice
					it = find(brand.begin(), brand.end(), "lucky strike");
					index = distance(brand.begin(), it);
					if (drink.at(index) != "orange juice")
						continue;

					//japanese parliaments
					it = find(brand.begin(), brand.end(), "parliament");
					index = distance(brand.begin(), it);
					if (nationality.at(index) != "japanese")
						continue;

					while (next_permutation(pet.begin(), pet.end())) {

						//Spaniard owns dog?
						it = find(nationality.begin(), nationality.end(), "spanish");
						index = distance(nationality.begin(), it);
						if (pet.at(index) != "dog")
							continue;

						//old gold smoker has snails
						it = find(brand.begin(), brand.end(), "old gold");
						index = distance(brand.begin(), it);
						if (pet.at(index) != "snails")
							continue;

						//chesterfields next to fox	
						it = find(brand.begin(), brand.end(), "chesterfield");
						index = distance(brand.begin(), it);
						if (index != 0 && pet.at(index - 1) != "fox" && index != 4 && pet.at(index + 1) != "fox")
							continue;

						//kools next to horse
						it = find(brand.begin(), brand.end(), "kools");
						index = distance(brand.begin(), it);
						if (index != 0 && pet.at(index - 1) == "horse")
							(void)0;
						else if (index != 4 && pet.at(index + 1) == "horse")
							(void)0;
						else
							continue;

						int fillTo = 15;
						for (auto i = color.begin(); i != color.end(); ++i) {
							cout << *i;
							for (int j = 0; j < fillTo - (*i).length(); j++)
								cout << ' ';
						}
						cout << endl;

						for (auto i = nationality.begin(); i != nationality.end(); ++i) {
							cout << *i;
							for (int j = 0; j < fillTo - (*i).length(); j++)
								cout << ' ';
						}
						cout << endl;

						for (auto i = pet.begin(); i != pet.end(); ++i) {
							cout << *i;
							for (int j = 0; j < fillTo - (*i).length(); j++)
								cout << ' ';
						}
						cout << endl;

						for (auto i = brand.begin(); i != brand.end(); i++) {
							cout << *i;
							for (int j = 0; j < fillTo - (*i).length(); j++)
								cout << ' ';
						}
						cout << endl;

						for (auto i = drink.begin(); i != drink.end(); ++i) {
							cout << *i;
							for (int j = 0; j < fillTo - (*i).length(); j++)
								cout << ' ';
						}
						cout << endl;

						auto out = find(pet.begin(), pet.end(), "ZEBRA");
						index = distance(pet.begin(), out);
						cout << "ZEBRA is at house " << index+1 << endl;
						
						out = find(drink.begin(), drink.end(), "WATER");
						index = distance(drink.begin(), out);
						cout << "WATER is at house " << index+1 << endl;
						
					}
				}
			}
		}
	}
	getchar();
	return;
}