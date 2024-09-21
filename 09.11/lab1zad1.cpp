#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


double* quadratic(int a, int b, int c) {
    double* arr = new double[3];
    double delta = (b * b) - (4 * a * c);
    
    if (delta > 0) {
    	arr[0] = 2;
        arr[1] = (-b + sqrt(delta)) / (2 * a); 
        arr[2] = (-b - sqrt(delta)) / (2 * a);
    } else if (delta == 0) {
    	arr[0] = 1;
        arr[1] = -b / (2 * a);
        arr[2] = 0;
    }
    else {
    	arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
	}

    return arr;
}

void readQuadratic(double* array){
	if(array[0] == 2){
		cout << "x = " << array[0] << "\n";
		cout << "x = " << array[1] << "\n";
	}
	if(array[0] == 1){
		cout << "x = " << array[0] << "\n";
	}
	if(array[0] == 0){
		cout << "x != R";
	}
}

void showQuadratic(double a, double b, double c){
	if(b >= 0 && c >= 0){
    	cout << "Funkcja Kwadratowa: "<< a <<"x^2 + " <<  b << "x + " <<  c << "\n";
	}
	else if(b < 0 && c < 0){
		cout << "Funkcja Kwadratowa: "<< a <<"x^2 - " <<  b*-1 << "x - " <<  c*-1 << "\n";
	}
	else if(b < 0 && c >= 0){
		cout << "Funkcja Kwadratowa: "<< a <<"x^2 - " <<  b*-1 << "x + " <<  c << "\n";
	}
	else if(b >= 0 && c < 0){
		cout << "Funkcja Kwadratowa: "<< a <<"x^2 + " <<  b << "x - " <<  c*-1 << "\n";
	}
}

int main() {
    int a, b, c;

    cout << "Funkcja Kwadratowa: ax^2 + bx + c\n";
    cout << "Podaj a: ";
    cin >> a;
    system("cls");
    cout << "Funkcja Kwadratowa: " << a << "x^2 + bx + c\n";
	cout << "Podaj b: ";
    cin >> b;
    system("cls");
    if(b >= 0){cout << "Funkcja Kwadratowa: "<< a <<"x^2 + " <<  b << "x + c\n";} else{cout << "Funkcja Kwadratowa: "<< a <<"x^2 - " <<  b*-1 << "x + c\n";}
    cout << "Podaj c: ";
    cin >> c;
	system("cls");
	
	
    double* array = quadratic(a, b, c); // arr[0] is number of roots, if it's <2 then rest elements are 0s
	showQuadratic(a, b, c);
	readQuadratic(array);

	delete[] array;
    return 0;
}
