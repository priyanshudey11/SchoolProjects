#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// Define the Point class with private x and y coordinates
class Point 
{
private:
    double xCoord;
    double yCoord;
public:
    // Default constructor
    Point() {};

    // Constructor with x and y coordinates
    Point(double x, double y) 
    {
        xCoord = x;
        yCoord = y;
    }

    // Getter and setter for x coordinate
    double getX() 
    { 
        return xCoord;
    }
    void setX(double x) 
    { 
        xCoord = x;
    }

    // Getter and setter for y coordinate
    double getY()
    { 
        return yCoord; 
    }
    void setY(double y) 
    { 
        yCoord = y; 
    }

    // Calculate the distance between two points
    double distance(Point p) 
    {
        return pow(pow(p.xCoord - xCoord, 2.0) +
            pow(p.yCoord - yCoord, 2.0), 0.5);
    }

    // Determine the quadrant that the point is located in
    string getQuadrant() 
    {
        if ((xCoord == 0.0) && (yCoord == 0.0)) return "Origin";
        else if (xCoord == 0.0) return "Y-axis";
        else if (yCoord == 0.0) return "X-axis";
        else if ((xCoord > 0.0) && (yCoord > 0.0)) return "Quadrant I";
        else if ((xCoord < 0.0) && (yCoord > 0.0)) return "Quadrant II";
        else if ((xCoord < 0.0) && (yCoord < 0.0)) return "Quadrant III";
        else return "Quadrant IV";
    }

    // Calculate the midpoint between two points
    Point midpoint(Point p) 
    {
        Point pAux;
        pAux.xCoord = (xCoord + p.xCoord) / 2.0;
        pAux.yCoord = (yCoord + p.yCoord) / 2.0;
        return pAux;
    }
};

// Define the Line class with two points
class Line 
{
private:
    Point p1;
    Point p2;
public:
    // Constructor with two points
    Line(Point p1, Point p2) 
    {
        this->p1 = p1;
        this->p2 = p2;
    }

    // Print the equation of the line
    void printEquation() 
    {
        double slope = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
        double yIntercept = p1.getY() - slope * p1.getX();
        double xIntercept = -yIntercept / slope;

        if (isinf(slope)) 
        {
            cout << "x = " << p1.getX() << endl;
        } else if (slope == 0) 
        {
            cout << "y = " << yIntercept << endl;
        } 
        else 
        {
            cout << "y = " << slope << "x + " << yIntercept << endl;
        }
    }
};
int main() 
{
    // Declare a variable for input, and two Point objects: p1 and p2.
    double d;
    Point p1;
    Point p2(0.0,0.0);
    
    // Prompt the user to enter the x and y coordinates of the first point.
    cin >> d;
    p1.setX(d);
    cin >> d;
    p1.setY(d);
    
    // Prompt the user to enter the x and y coordinates of the second point.
    cout << "Enter the x and y coordinates of the second point: ";
    cin >> d;
    p2.setX(d);
    cin >> d;
    p2.setY(d);
    
    // Set output precision to four decimal places.
    cout << fixed << setprecision(4);
    
    // Display the x and y coordinates of the first point, and its quadrant location.
    cout << "p1 = (" << p1.getX() << "," << p1.getY() << ")" << endl;
    cout << "Location = " << p1.getQuadrant() << endl;
    
    // Display the x and y coordinates of the second point, and its quadrant location.
    cout << "p2 = (" << p2.getX() << "," << p2.getY() << ")" << endl;
    cout << "Location = " << p2.getQuadrant() << endl;
    
    // Calculate and display the midpoint of the two points.
    Point midP = p1.midpoint(p2);
    cout << "The midpoint is at (" << midP.getX() << "," << midP.getY() <<
    ")" << endl;
    
    // Calculate and display the distance between the two points.
    d= p1.distance(p2);
    cout << "Distance = " << d << endl;
    
    // End the program.
    return 0;
}
