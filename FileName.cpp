#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void add(int* arr) {
	int x = arr[2] * arr[0];
	int y = arr[3] * arr[0] + arr[1] * arr[2];
	int u = x;
	int v = y;
	while (v != 0) {
		int tmp = u % v;
		u = v;
		v = tmp;

	}
	if (x / u == 1) {
		cout << y / x;
	}
	else
	cout << (y / u) << "/" << (x / u);

}
void minuus(int* arr) {
	int x = arr[2] * arr[0];
	int y = arr[3] * arr[0] - arr[1] * arr[2];
	int u = x;
	int v = abs(y);
	while (v != 0) {
		int tmp = u % v;
		u = v;
		v = tmp;

	}
	if (y < 0) {
		if (x / u == 1) {
			cout<<"-" << y / x;
		}
		else
			cout << "-" << ((-1 * y) / u) << "/" << (x / u);
	}
	else
		if (x / u == 1) {
			cout << y / x;
		}
		else
			cout << (y / u) << "/" << (x / u);
}
void sup(int* arr) {
	int x = arr[2] * arr[0];
	int y = arr[3] * arr[1] ;
	int u = x;
	int v = y;
	while (v != 0) {
		int tmp = u % v;
		u = v;
		v = tmp;

	}
	if (x / u == 1) {
		cout << y / x;
	}
	else
		cout << (y / u) << "/" << (x / u);
}
int main() {
	string s;
	cin >> s;
	int arr[4] = { 0 };
	int n = 0;
	int sum = 0;
	int j = 0;
	char a;
	for (int i = s.length() - 1; i >= 0; i--) {
		int t = s[i] - '0';
		if (0 <= t && 9 >= t) {
			sum = sum + t * (pow(10, n));
			n++;
		}
		else {
			
			arr[j] = sum;
			j++;
			sum = 0;
			n = 0;
			if (j == 2) {
				a = s[i];
			}
		}
	}
	arr[j] = sum;
	switch (a) {
	case '+':
		add(arr);
		break;
	case '-':
		minuus(arr);
		break;
	case '*':
		sup(arr);
		break;
	case '/':
		swap(arr[0], arr[1]);
		sup(arr);
		break;
	default:
		break;
	}
	return 0;
}
