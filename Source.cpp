#define _USE_MATH_DEFINES
#include <iostream>

using namespace std;

const int n = 10000;
int choise;

int menu() {
	cout << "1: Linear congr" << endl;
	cout << "2: Quadr congr" << endl;
	cout << "3: Phibonachi" << endl;
	cout << "4: Inverted congr" << endl;
	cout << "5: Union" << endl;
	cout << "6: 3 sigma" << endl;
	cout << "7: Polar coordinates" << endl;
	cout << "8: Interrelation" << endl;
	cout << "9: Log" << endl;
	cout << "10: Arens" << endl;
	cin >> choise;
	return choise;
}

int gistogram[10];
void show_gistogram(int *gistogram) {
	for (int i = 0; i < 10; i++) {
		cout << "[" << (double)(i) / 10 << "; " << (double)(i + 1) / 10 << "]" << "	" << (double)gistogram[i] / n << endl;
		*(gistogram + i) = 0;
	}
}

int x = 53, m = 9679;

int method01() {
	int a = 13, c = 190;
	x = (a * x + c) % m;
	return x;
}

int method02() {
	int a = 13, c = 19, d = 11;
	x = (d * (x*x) + a * x + c) % m;
	return x;
}

int method03() {
	x = (x + x) % m;
	return x;
}

int m_invers(int a, int m) {
	int b0 = m, u, v;
	int x_ = 0, y = 1;
	while (a > 1) {
		v = a / m;
		u = m, m = a % m, a = u;
		u = x_, x_ = y - v * x_, y = u;
	}
	if (y < 0) y += b0;
	return y;
}

int m4(int m, int a, int c, int x) {
	if (x == 0) return c;
	return (a * m_invers(x, m) + c) % m;
}

int method04() {
	const int a = 2, c = 3;
	x = m4(m, a, c, x);
	return x;
}

int method05() {
	int xn = method01();
	int yn = method03();
	int z = (xn + yn + m) % m;
	return z;
}

int gistogram_2[24];
void show_gistogram_2(int *gistogram_2) {
	for (int i = 5; i < 17; i++) {
		cout << "[" << (double)(i) / 2 - 5.5  << "; " << (double)(i + 1) / 2 - 5.5  << "]" << "	" << (double)gistogram_2[i] / n << endl;
		*(gistogram_2 + i) = 0;
	}
}

double sum6() {
	double sum = 0;
	for (int i = 0; i < 12; i++) {
		sum += (double)method01() / m;
	}
	return sum;
}

double method06() {
	int m_ = 0, sigma = 1;
	double sum = sum6();
	double X = m_ + (sum - 6)*sigma;
	return X;
}

double x1, x2;
bool var = false;

double method07() {
	double S = 1, v1, v2;
	if (var) {
		var = !var;
		return x2;
	}
	while(S>=1) { 
		double u1 = (double)method01() / m;
		double u2 = (double)method01() / m;
		v1 = 2 * u1 - 1;
		v2 = 2 * u2 - 1;
		S = v1 * v1 + v2 * v2;
	}
	x1 = v1 * sqrt((-2 * log(S)) / S);
	x2 = v2 * sqrt((-2 * log(S)) / S);
	return x1;
}

double method08() {
	double u, v, X;
	do {
		u = (double)method03() / m;
		v = (double)method03() / m;
		X = sqrt(8 / M_E)*((v - 1 / 2) / u);
		if (X*X <= 5 - 4 * pow(M_E, 1 / 4)*u) return X;
	} while ((X*X > (-4)*log(u)) || (X*X >= (4 * pow(M_E, (-1.35))) / u + 1.4));
	return X;
}

int gistogram_3[10];
void show_gistogram_3(int *gistogram_3) {
	for (int i = 0; i < 10; i++) {
		cout << "[" << (double)(i)*10 << "; " << (double)(i + 1)*10 << "]" << "	" << (double)gistogram_3[i] / n << endl;
		*(gistogram_3 + i) = 0;
	}
}

double method09() {
	int M = 251;
	double u, X, y;
	u = (double)method03() / m;
	X = -M * log(u);
	if (y = 1 - pow(M_E, (-X / M))) return X;
	return X;
}

double method10() {
	int a = 1.5;
	double u, y, v, X;
	do {
		u = (double)method03() / m;
		y = tan(M_PI*u);
		X = sqrt(2 * a - 1)*y + a - 1;
		if (X > 0) return X;
		v = (double)method03() / m;
	} while (v > (1 + y * y)*exp((a - 1)*log(X / (a - 1)) - sqrt(2 * a - 1)*y));
	return X;
}

int main() {
	int choise = -1;
	while (choise) {
		cout << "\n" << "Choose the method from ten below: " << endl;
		choise = menu();
		if (!(choise)) break;
		switch (choise) {
		case 1: method01();
			for (int i = 0; i < n; i++) {
				double u = (double)method01() / m;
				gistogram[(int)(u * 10)]++;
			}
			show_gistogram(gistogram);
			break;
		case 2: method02();
			for (int i = 0; i < n; i++) {
				double u = (double)method02() / m;
				gistogram[(int)(u * 10)]++;
			}
			show_gistogram(gistogram);
			break;
		case 3: method03();
			for (int i = 0; i < n; i++) {
				double u = (double)method03() / m;
				gistogram[(int)(u * 10)]++;
			}
			show_gistogram(gistogram);
			break;
		case 4: method04();
			for (int i = 0; i < n; i++) {
				double u = (double)method04() / m;
				gistogram[(int)(u * 10)]++;
			}
			show_gistogram(gistogram);
			break;
		case 5: method05();
			for (int i = 0; i < n; i++) {
				double u = (double)method05() / m;
				gistogram[(int)(u * 10)]++;
			}
			show_gistogram(gistogram);
			break;
		case 6: method06();
			for (int i = 0; i < n; i++) {
				gistogram_2[(int)((method06()+6)/0.5)]++;
			}
			show_gistogram_2(gistogram_2);
			break;
		case 7: method07();
			for (int i = 0; i < n; i++) {
				gistogram_2[(int)((method07() + 6) / 0.5)]++;
			}
			show_gistogram_2(gistogram_2);
			break;
		case 8: method08();
			for (int i = 0; i < n; i++) {
				gistogram_2[(int)((method08() + 6) / 0.5)]++;
			}
			show_gistogram_2(gistogram_2);
			break;
		case 9: method09();
			for (int i = 0; i < n; i++) {
				gistogram_3[(int)(method09() / 100)]++;
			}
			show_gistogram_3(gistogram_3);
			break;
		case 10: method10();
			for (int i = 0; i < n; i++) {
				gistogram_3[(int)(method10() / 100)]++;
			}
			show_gistogram_3(gistogram_3);
			break;
		}
	}
	return 0;
}