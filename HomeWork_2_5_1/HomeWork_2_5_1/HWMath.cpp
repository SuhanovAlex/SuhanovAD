#include "HWMath.h"
#include <cmath>

int addition(int num1, int num2) {
	return num1 + num2;
};

int subtraction(int num1, int num2) {
	return num1 - num2;
};

int multiplication(int num1, int num2) {
	return num1 * num2;
};

double division(int num1, int num2) {
	return static_cast<double>(num1) / num2;
};

double power(int num1, int num2) {
	return pow(num1, num2);
};