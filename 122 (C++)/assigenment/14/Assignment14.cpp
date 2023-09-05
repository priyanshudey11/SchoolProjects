//Priyanshu Dey point slop calculator with two points (x,y)
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Point {
private:
    // attributes
    double xCoord;
    double yCoord;
public:
    // constructors
    Point () {};
    Point (double x, double y) {
        xCoord = x;
        yCoord = y;
    }
    // accessors
    double getX () { return xCoord; }
    void setX (double x) { xCoord = x; }
    double getY () { return yCoord; }
    void setY (double y) { yCoord = y; }
    // methods
    double distance (Point p) {
        return pow(pow(p.xCoord - xCoord, 2.0) +
                   pow(p.yCoord - yCoord, 2.0), 0.5);
    }
    string getQuadrant () {
        if ((xCoord == 0.0) && (yCoord == 0.0)) return "Origin";
        else if (xCoord == 0.0) return "Y-axis";
        else if (yCoord == 0.0) return "X-axis";
        else if ((xCoord > 0.0) && (yCoord > 0.0)) return "Quadrant I";
        else if ((xCoord < 0.0) && (yCoord > 0.0)) return "Quadrant II";
        else if ((xCoord < 0.0) && (yCoord < 0.0)) return "Quadrant III";
        else return "Quadrant IV";
    }
    Point midpoint (Point p) {
        Point pAux;
        pAux.xCoord = (xCoord + p.xCoord)/2.0;
        pAux.yCoord = (yCoord + p.yCoord)/2.0;
        return pAux;
    }
};

class Line {
private:
    Point p1, p2;
public:
    Line (Point p1, Point p2) {
        this->p1 = p1;
        this->p2 = p2;
    }
void printEquation() 
{
    double slope = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    double intercept = p1.getY() - slope * p1.getX();
    // If the slope is undefined, print the equation in the form of x=c
        if (isinf(slope)) 
        {
            cout << "x = " << p1.getX() << endl;
        } 
        // If the slope is 0, print the equation in the form of y=b
        else if (slope == 0) 
        {
            cout << "y = " << intercept << endl;
        } 
        //if the slope and a no point
        else if (isinf(slope)&&p1.getX() == 0) 
        {
            cout << "point"  << endl;
        }
        // Otherwise, print the equation in the form of y=mx+b
        else 
        {
            cout << "y = " << slope << "x + " << intercept << endl;
        }
    }
};

int main () {
double d;
Point p1, p2;
double x1, y1, x2, y2;
// prompt user for coordinates of p1 and p2
cout << "Enter coordinates of point 1 (x,y): ";
cin >> x1 >> y1;
cout << "Enter coordinates of point 2 (x,y): ";
cin >> x2 >> y2;

// create Point objects
p1.setX(x1);
p1.setY(y1);
p2.setX(x2);
p2.setY(y2);

// output information about the Points
cout << fixed << setprecision(4);
cout << "p1 = (" << p1.getX() << "," << p1.getY() << ")" << endl;
cout << "Location = " << p1.getQuadrant() << endl;
cout << "p2 = (" << p2.getX() << "," << p2.getY() << ")" << endl;
cout << "Location = " << p2.getQuadrant() << endl;
Point midP = p1.midpoint(p2);

cout << "The midpoint is at (" << midP.getX() << "," << midP.getY() << ")" << endl;
d= p1.distance(p2);
cout << "Distance = " << d << endl;

// create Line object
Line line(p1, p2);
line.printEquation();

return 0;
}