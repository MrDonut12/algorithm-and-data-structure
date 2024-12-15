#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using namespace chrono;

class System {
	public:
		string find_with_ID(int originalID, pair <int, string> arrayoftheProduct[], int n = (int) 2e5) 
		{
			for (int i = 1; i <= n; i++) 
			if (arrayoftheProduct[i].first == originalID) {
				return arrayoftheProduct[i].second;
				break;
			}
			return cerr << "Not found", "None";
		}
		
		virtual void test() = 0;
};

class InvoiceSystem: public System {

}; // chua dinh nghia ham nay

class DimProduct : public InvoiceSystem{
	public:
		int productID, price;
		vector< pair <int, string> > nameProduct; //with ID
		string category;
};

class DimCustom : public System {
	public:
		string education, fullname, address, status_marial, gender;
		int age, customID;
	private:
		string indentity_code_card;
};

class DimEmployee : public System {
	public:
		string fullname, address, status_marial, gender, position, education; 
		int age, employeeID;
	private:
		string indentity_code_card, salary;
};

int main(){
	while (true) {
		cout << "Please, choose 3 options:\n";
		cout << "1. Add bills\n";
		cout << "2. Check bills\n";
		int option; cin >> option;
		if (option == 1) 
		{
			
		} 
		else 
		{
			
		}
	}
	return 0; 
}

