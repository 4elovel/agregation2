#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Unit
{
public:
	string adress;
	string mask;
	Unit(string adress,string mask) {
		this->adress = adress;
		this->mask = mask;
		cout << "Unit " << adress <<  " is successfully created!\n";
	};

};

class Network
{
private:

	vector <Unit> vec;
	static int global_counter;
	int local_counter = 0;
	string mask;
	string main_adress;
public:
	Network(string main_adress,string mask) {
		this->main_adress = main_adress;
		this->mask = mask;
		cout << "Network " << main_adress <<" is successfully created!\n";
	};
	string get_mask() { return mask ; }
	string get_main_adress() { return main_adress; }

	void set_mask(string mask) { this->mask = mask; }
	void set_main_adress(string main_adress) { this->main_adress = main_adress; }

	void push_back(Unit &un1) {
		if (mask == un1.mask &&  (un1.adress.starts_with("169.254") || un1.adress.starts_with("192.168"))) {
			vec.push_back(un1);
			cout << "Unit " << un1.adress << " is successfully added in "<< main_adress <<" network!\n";
			global_counter++;
			local_counter++;
			return;
		}
		cout << "Unit can't be added!\n";
	}

	void pop_back() {
		if (!vec.empty()) {
			vec.pop_back();
			cout << "Last unit in " << main_adress <<" network was successfully poped!\n";
			return;
		}
		cout << "Network is empty!\n";
	}


	void info() {
		if (!vec.empty()) {
			cout << "There are "<<Network::global_counter << " units in all networks\n";
			cout << "and " << local_counter << " units in this network:\n";
			for (size_t i = 0; i < vec.size(); i++)
			{
				cout << "Unit with " << vec[i].adress << " adress\n";
 			}
			cout << "And all of them are with " << mask << " mask.\n";
			return;
		}
		cout << "Sorry but this network is empty ): \n";
	}

};

int Network::global_counter = 0;

int main() // я також додатково зробив метод pop_back, каунтери локальний та глобальний, геттери та сеттери і обробив випадки коли мережа пуста
{
	Network net1("192.168.0.0", "255.255.255.0");
	Network net2("169.254.0.0", "255.255.0.0");
	cout << endl;
	Unit u1("192.168.0.1", "255.255.255.0");
	Unit u2("192.168.0.2", "255.255.255.0");
	Unit u3("192.168.0.3", "255.255.255.0");
	cout << endl;
	net1.push_back(u1);
	net1.push_back(u2);
	net1.push_back(u3);
	cout << endl;
	Unit u01("169.254.0.1", "255.255.0.0");
	Unit u02("169.254.1.1", "255.255.0.0");
	cout << endl;
	net2.push_back(u01);
	net2.push_back(u02);
	cout << endl;
	net1.info();
	cout << endl;
	net2.info();
}
