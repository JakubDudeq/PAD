#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double findArea(double a1, double a2, double b1, double b2, double c1, double c2){
	
	double x,y,z;
	
	x = sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2));
	y = sqrt((a1-c1)*(a1-c1)+(a2-c2)*(a2-c2));
	z = sqrt((c1-b1)*(c1-b1)+(c2-b2)*(c2-b2));
	double p = (x+y+z)/2;
	double Area = sqrt(p*(p-x)*(p-y)*(p-z));
	
	return Area;	
}




int main(){
	
	double a1,a2,b1,b2,c1,c2;
	
	
	cout << "Dany jest trojkat ABC, podaj koordynaty jego wierzcholkow\nA(";
    cin >> a1;
    system("cls");
    cout << "Dany jest trojkat ABC, podaj koordynaty jego wierzcholkow\nA(" << a1 << ",";
    cin >> a2;
    system("cls");
    cout << "Dany jest trojkat ABC, podaj koordynaty jego wierzcholkow\nA(" << a1 << "," << a2 << ") B(";
    cin >> b1;
    system("cls");
    cout << "Dany jest trojkat ABC, podaj koordynaty jego wierzcholkow\nA(" << a1 << "," << a2 << ") B(" << b1 << ",";
    cin >> b2;
    system("cls");
    cout << "Dany jest trojkat ABC, podaj koordynaty jego wierzcholkow\nA(" << a1 << "," << a2 << ") B(" << b1 << "," << b2 << ") C(";
    cin >> c1;
    system("cls");
    cout << "Dany jest trojkat ABC, podaj koordynaty jego wierzcholkow\nA(" << a1 << "," << a2 << ") B(" << b1 << "," << b2 << ") C(" << c1 << ",";
    cin >> c2;
    system("cls");
    cout << "O to twoj trojkat ABC\nA(" << a1 << "," << a2 << ") B(" << b1 << "," << b2 << ") C(" << c1 << "," << c2 << ")" << endl;
	
	cout << "Jego pole jest rowne " << findArea(a1,a2,b1,b2,c1,c2);
	
	
	
	
	
	
	return 0;
}
