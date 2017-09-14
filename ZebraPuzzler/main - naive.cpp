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
		while (next_permutation(nationality.begin(), nationality.end())) {
			while (next_permutation(drink.begin(), drink.end())) {
				while (next_permutation(brand.begin(), brand.end())) {
					while (next_permutation(pet.begin(), pet.end())) {

						//Englishman in the red house?
						auto it = find(nationality.begin(), nationality.end(), "english");
						int index = distance(nationality.begin(), it);
						if (color.at(index) != "red")
							continue;

						//Spaniard owns dog?
						it = find(nationality.begin(), nationality.end(), "spanish");
						index = distance(nationality.begin(), it);
						if (pet.at(index) != "dog")
							continue;

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

						//green right to ivory
						it = find(color.begin(), color.end(), "green");
						index = distance(color.begin(), it);
						if (index < 0)
							continue;
						if (color.at(index-1) != "ivory")
							continue;

						//old gold smoker has snails
						it = find(brand.begin(), brand.end(), "old gold");
						index = distance(brand.begin(), it);
						if (pet.at(index) != "snails")
							continue;

						//kools in yellow
						it = find(brand.begin(), brand.end(), "kools");
						index = distance(brand.begin(), it);
						if (color.at(index) != "yellow")
							continue;

						//milk in middle
						it = find(drink.begin(), drink.end(), "milk");
						index = distance(drink.begin(), it);
						if (index != 2)
							continue;

						//norwegian in first
						it = find(nationality.begin(), nationality.end(), "norwegian");
						index = distance(nationality.begin(), it);
						if (index != 0)
							continue;

						//chesterfields next to fox	
						it = find(brand.begin(), brand.end(), "chesterfields");
						index = distance(brand.begin(), it);
						if (pet.at(index-1) != "fox" && pet.at(index+1) != "fox")
							continue;

						//kools next to horse
						it = find(brand.begin(), brand.end(), "kools");
						index = distance(brand.begin(), it);
						if (pet.at(index - 1) != "horse" && pet.at(index + 1) != "horse")
							continue;

						//lucky strike orange juice
						it = find(brand.begin(), brand.end(), "lucky strike");
						index = distance(brand.begin(), it);
						if (drink.at(index) != "orange juice")
							continue;

						//japanese parliaments
						it = find(brand.begin(), brand.end(), "parliaments");
						index = distance(brand.begin(), it);
						if (nationality.at(index) != "japanese")
							continue;

						//norwegian next to blue
						it = find(nationality.begin(), nationality.end(), "norwegian");
						index = distance(nationality.begin(), it);
						if (pet.at(index - 1) != "horse" && pet.at(index + 1) != "horse")
							continue;

						for (auto i = color.begin(); i != color.end(); ++i) {
							cout << *i << ' ';
						}
						cout << endl;

						for (auto i = nationality.begin(); i != nationality.end(); ++i) {
							cout << *i << ' ';
						}
						cout << endl;

						for (auto i = pet.begin(); i != pet.end(); ++i) {
							cout << *i << ' ';
						}
						cout << endl;

						for (auto i = brand.begin(); i != brand.end(); i++) {
							cout << *i << ' ';
						}
						cout << endl;

						for (auto i = drink.begin(); i != drink.end(); ++i) {
							cout << *i << ' ';
						}
						cout << endl;

						system("pause");
					}
				}
				//cout << "Done with permutation of brand" << endl;
			}
			cout << "Done with permutation of nationality" << endl;
		}
		cout << "Done with a full permutation" << endl;
	}

}