#include "iostream"
using namespace std;

int *Multiply(int *tmparr, int n, int& set) {

	int *arr = new int[1000];

	int index = 0;
	int carry = 0;

	if (set > 0)
	{
		for (int x = 0; x < set; x++) {

			int mul = tmparr[x] * n + carry;
			arr[index] = mul % 10;
			carry = mul / 10;
			index++;
		}
	}
	else {
		int mul = n;
		arr[index] = mul % 10;
		carry = mul / 10;
		index++;
	}

	while (carry > 0)
	{
		arr[index] = carry % 10;
		carry = carry / 10;
		index++;
	}

	set = index;

	return arr;
}


void Fact(int n) {

	int *tmpArr = new int[1000];
	int set = 0;
	for (int x = 1; x <= n; x++) {
		tmpArr = Multiply(tmpArr, x, set);
	}


    cout << "\nOutput:";
	for (int index = set-1; index >= 0; index--) {
		cout << *(tmpArr + index);
	}
}


int main() {
	int n = 0;
    cout << "Please enter number to calculate the factorial : ";
    cin >> n;
    cout << n;
	Fact(n);
	return 0;
}