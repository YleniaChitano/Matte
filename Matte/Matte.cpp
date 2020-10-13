#include <iomanip>
#include <iostream>

//TODO: Sett riktig verdi på konstanten
const int NO_OF_RECTANGLES = 6;

bool numericFxA(float tStart, float tEnd, float fArr[2][NO_OF_RECTANGLES]);
bool IntegratedFxA(float tStart, float tEnd, float fArr[2][NO_OF_RECTANGLES]);
bool IntegratedFunction(float tStart, float tEnd, float fArr[2][NO_OF_RECTANGLES]);
bool RiemannSum(float tStart, float tEnd, float fArr[2][NO_OF_RECTANGLES]);
bool Display2(float arr[2][NO_OF_RECTANGLES]);




int main()
{
	//TODO: Sett fra og til verdi for simuleringa her
	const float FromX = -1.5;
	const float ToX = 1.5;

	float fxArray[2][NO_OF_RECTANGLES]{};
	float fxArray2[2][NO_OF_RECTANGLES]{};

	/*bool aOK = IntegratedFxA(0, 2.5, fxArray);
	bool bOK = numericFxA(0, 2.5, fxArray);*/

	bool aOK = IntegratedFunction(FromX, ToX, fxArray);
	bool bOK = RiemannSum(FromX, ToX, fxArray2);



	// Prints out title. \t = tab space
	std::cout << "X1\t" << "Y1\t" << "Y2\t" << "X2\t" << std::endl;

	for (int i = 0; i < NO_OF_RECTANGLES; i++) {
		std::cout << std::setprecision(2) << fxArray[0][i] << "  ";
		std::cout << "\t" << fxArray[1][i] << "  ";
		std::cout << "\t" << fxArray2[1][i] << "  ";
		std::cout << "\t" << fxArray2[0][i] << std::endl;

	}

	

}


// f(x) = cosx - x og F(x)=sinx- (x^2)/2
bool IntegratedFunction(float xStart, float xEnd, float fArr[2][NO_OF_RECTANGLES])
{
	float x = xStart;
	float dx = (xEnd - xStart) / NO_OF_RECTANGLES;
	int i = 0;
	x += dx;;// / 2;
	while (x <= xEnd && i < NO_OF_RECTANGLES) {
		fArr[0][i] = x;
		float function = sin(x) - pow(x, 2) / 2; //F(x)= sinx - (x^2)/2
		fArr[1][i] = function;
		++i;
		x += dx;
	}
	return true;
}
bool RiemannSum(float xStart, float xEnd, float fArr[2][NO_OF_RECTANGLES]) {
	float delta = (xEnd - xStart) / NO_OF_RECTANGLES;
	float x = xStart + delta;// / 2;
	//float x = xStart + delta;
	float function;
	float R = 0;

	for (int i = 0; i < NO_OF_RECTANGLES; i++) {
		function = cos(x) - (x); //f(x) = cosx - x

		fArr[0][i] = x;
		R += function * delta;
		fArr[1][i] = R;

		x = x + delta;
	}
	return true;
}

bool numericFxA(float xStart, float tEnd, float fArr[2][NO_OF_RECTANGLES]) {
	float delta = (tEnd - xStart) / NO_OF_RECTANGLES;
	float x = xStart + delta / 2;
	float function;
	float R = 0;

	for (int i = 0; i < NO_OF_RECTANGLES; i++) {
		function = pow(x, 3) - 3 * pow(x, 2) + 2 * x + 1;
		R += function * delta;

		fArr[0][i] = x;
		fArr[1][i] = R;

		x = x + delta;
	}
	return true;
}

bool IntegratedFxA(float tStart, float tEnd, float fArr[2][NO_OF_RECTANGLES])
{
	float t = tStart;
	float dt = (tEnd - tStart) / NO_OF_RECTANGLES;
	int i = 0;
	t += dt / 2;
	while (t < tEnd && i < NO_OF_RECTANGLES) {
		fArr[0][i] = t;
		float fx = pow(t, 4) / 4 - pow(t, 3) + pow(t, 2) + t;
		fArr[1][i] = fx;
		++i;
		t += dt;
	}
	return true;
}

// Prints out array
bool Display2(float arr[2][NO_OF_RECTANGLES])
{
	for (int i = 0; i < NO_OF_RECTANGLES; i++) {
		std::cout << arr[0][i] << std::endl;
	}
	return true;
}
