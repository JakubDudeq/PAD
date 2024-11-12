#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;


void setConsoleColor(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
int countDecimalPlaces(float value) {
	stringstream ss;
	ss << fixed << setprecision(10) << value;
	string str = ss.str();

	size_t decimalPos = str.find('.');
	if (decimalPos == string::npos) {
		return 0;
	}

	int count = 0;
	for (size_t i = decimalPos + 1; i < str.size(); i++) {
		if (str[i] != '0') {
			count++;
		}
	}
	return count;
}


class Point2D {
private:
	Point2D operator + (const Point2D& p) {
		return Point2D(x + p.x, y + p.y);
	}
	Point2D operator - (const Point2D& p) {
		return Point2D(x - p.x, y - p.y);
	}
	Point2D operator * (const Point2D& p) {
		return Point2D(x * p.x, y * p.y);
	}
	Point2D operator / (const Point2D& p) {
		return Point2D(x / p.x, y / p.y);
	}
	friend ostream& operator << (ostream& os, const Point2D& p) {
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}
public:
	float x;
	float y;

	Point2D() {
		x = 0.0;
		y = 0.0;
	}
	Point2D(float x, float y) {
		this->x = x;
		this->y = y;
	}
	Point2D(const Point2D& p) {
		x = p.x;
		y = p.y;
	}

	static float getVectorLength(Point2D& a, Point2D& b){
		return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	}
	static float getVectorLength(Point2D& a) {
		Point2D x = Point2D(0, 0); 
		return getVectorLength(x, a);
	}
};
class Polygon2D {
private:
	string px = "  ";
	int multiplification = 0;
public:
	unsigned short vertexCount;
	Point2D* vertexTab;
	enum Colors {
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		CYAN = 3,
		RED = 4,
		MAGENTA = 5,
		BROWN = 6,
		LIGHTGRAY = 7,
		DARKGRAY = 8,
		LIGHTBLUE = 9,
		LIGHTGREEN = 10,
		LIGHTCYAN = 11,
		LIGHTRED = 12,
		LIGHTMAGENTA = 13,
		YELLOW = 14,
		WHITE = 15
	};

	Colors backgroundColor = Colors::DARKGRAY;
	Colors pointColor = Colors::WHITE;

	template <typename... Args>
	Polygon2D(const Args&... args) {
		vertexCount = sizeof... (args);
		vertexTab = new Point2D[vertexCount]{args...};
	}
	~Polygon2D() {
		delete[] vertexTab;
	}

	friend ostream& operator << (ostream& os, const Polygon2D& p) {
		for (int i = 0; i < p.vertexCount; i++) {
			os << endl << p.vertexTab[i];
			if (i != p.vertexCount - 1) {
				os << " ";
			}
		}
		return os;
	}

	double calculateArea() {


		return 0.0;
	}

	void transformToPositiveAndIntigers() {
		float lowestValue = vertexTab[0].x;
		int biggestDecimal = 0;


		for (int i = 0; i < vertexCount; i++) {
			if (lowestValue > vertexTab[i].x) {
				lowestValue = vertexTab[i].x;
			}
			if (lowestValue > vertexTab[i].y) {
				lowestValue = vertexTab[i].y;
			}

			biggestDecimal = max(biggestDecimal, countDecimalPlaces(vertexTab[i].x));
			biggestDecimal = max(biggestDecimal, countDecimalPlaces(vertexTab[i].y));
		}

		multiplification = biggestDecimal;

		for (int i = 0; i < vertexCount; i++) {
			vertexTab[i].x -= lowestValue;
			vertexTab[i].y -= lowestValue;
		}
		for (int i = 0; i < vertexCount; i++) {
			if (biggestDecimal != 0) {
				vertexTab[i].x = vertexTab[i].x * (pow(10, biggestDecimal));
				vertexTab[i].y = vertexTab[i].y * (pow(10, biggestDecimal));
			}
		}
	}
	void renderPoints() {
		/*

		transformToPositiveAndIntigers();

		float highestX = vertexTab[0].x;
		float highestY = vertexTab[0].y;

		for (int i = 0; i < vertexCount; i++){
			if (highestX < vertexTab[i].x) { highestX = vertexTab[i].x; }
			if (highestY < vertexTab[i].y) { highestY = vertexTab[i].y; }
		}

		setConsoleColor(0, backgroundColor);
		
		for (int i = highestY; i > 0; i--) {
			for (int j = 0; j < highestX + 1; j++) {
				
				bool check = false;

				for (int k = 0; k < vertexCount; k++) {
					if (vertexTab[k].x == j && vertexTab[k].y == i) {
						setConsoleColor(0, pointColor);
						cout << px;
						setConsoleColor(0, backgroundColor);
						check = true;
					}
				}
				if (!check) {
					cout << px;
				}
				check = false;
			}
			cout << endl;
		}
		*/
	}
};




int main()
{
	Point2D A = Point2D(2.5, 3);
	Point2D B = Point2D(6, 3);
	Point2D C = Point2D(6, 7);
	Point2D D = Point2D(2.5, 7);

	Polygon2D square = Polygon2D(A, B, C, D);
	square.renderPoints();

	return 0;
}