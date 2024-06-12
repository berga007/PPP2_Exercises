// Exercise 12 from Chapter 12 of the book
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows library
#include "../GUI/Graph.h"          // get access to our graphics library facilities
#include <cmath>                   // get access to trig functions
#include <iostream>                

//------------------------------------------------------------------------
string prompt(">>>");

//------------------------------------------------------------------------
float largest(const vector<float> &v){
    float largest = v[0];
    for(int i=1; i<v.size(); ++i){
        if(largest < v[i]) largest = v[i];
    }

    return largest;
}
//------------------------------------------------------------------------
//function to return the sign of the argument
int sign(float num)
{
    return 0? num==0: num/abs(num);
}

//------------------------------------------------------------------------
// superellipse class
class Superellipse{
public:
    // contructor: check for valid superellipse and initialise
    Superellipse(float a, float b, float m, float n);
    // t is a value between 0 and pi/2
    double x(double t) const; // x value for a given t argument
    double y(double t) const; // y value for a given t argument

private:
    float a, b, m, n;
    bool is_valid();    // true if equation defined is a superellipse

};

Superellipse::Superellipse(float aa, float bb, float mm, float nn)
             : a(aa), b(bb), m(mm), n(nn)  // initialise data members
{
    // check for validity
    if(!is_valid()) error("m and n should be greater than 0");
}

bool Superellipse::is_valid()
{
    if(!(m>0 && n > 0)) return false;
    return true;
}

double Superellipse::x(double t) const
{
    return pow(abs(cos(t)), 2/m) * a * sign(cos(t));
}

double Superellipse::y(double t) const
{
    return pow(abs(sin(t)), 2/n) * b * sign(sin(t));
}

//------------------------------------------------------------------------
vector<Point>& scale_points(vector<Point>& v, float factor)
{
    for(Point& p:v){
        p.x *= factor;
        p.y *= factor;
    }

    return v;
}
//------------------------------------------------------------------------
vector<Point>& translation(vector<Point>& v, float x_dis, float y_dis)
{
    for(Point& p:v){
        p.x += x_dis;
        p.y += y_dis;
    }

    return v;
}

//------------------------------------------------------------------------
vector<Point> find_points(int N_points, Superellipse se)
{
    vector<Point> points; 
    float interval = (pi/2)/(N_points/4);
    
    // vector of values from 0 up to pi/2
    // in increments of interval
    for(int i=0; i < N_points/4 + 1; i++)
    {
        double t = i*interval;
        Point p1(se.x(t), se.y(t));
        points.push_back(p1);

        if(i==0){
            Point p2(-p1.x, p1.y);
            points.push_back(p2);
        }
        else if(i == N_points/4){
            Point p2(p1.x, -p1.y);
            points.push_back(p2);
        }
        else{
            Point p2(-p1.x, p1.y);
            points.push_back(p2);

            Point p3(-p1.x, -p1.y);
            points.push_back(p3);

            Point p4(p1.x, -p1.y);
            points.push_back(p4);
        }
    }
    return points;
    
}
//------------------------------------------------------------------------
Point max_point_values(vector<Point> points)
{
    vector <float> x_values;
    vector <float> y_values;

    for(Point p:points)
    {
        x_values.push_back(p.x);
        y_values.push_back(p.y);
    }

    // find max x
    float max_x(largest(x_values));
    // find max y
    float max_y(largest(y_values));

    // return point
    return Point(max_x, max_y);
}
//------------------------------------------------------------------------
ostringstream& message_1()
{
    ostringstream os;    // string stream to compose message to user
    os << "<<< Hello, to define a superellipse please provide:\n"
       << "<<< The value of a, b, m and n\n"
       << "<<< Both m and n have to be greater than 0 \n";

    return os;
}

ostringstream& message_2()
{
    ostringstream os;
    os << "<<< Please provide number of points:\n"
       << "<<< The number must be a multiple of 4\n";

    return os;
}

//------------------------------------------------------------------------
void make_plot(vector<Point> points)
{
    Closed_polyline poly_ellipse_1;
    Closed_polyline poly_ellipse_2;
    Point tl(200, 200);     // top left corner of window
    Simple_window win(tl, 1200, 800, "Exercise 12");
    
    // apply geometrical translation to all the points
    // find max x_value and y_value of the ellipse points
    points = scale_points(points, 50);

    Point max_point(max_point_values(points));
    float x_translation = abs(max_point.x);
    float y_translation = abs(max_point.y);

    points = translation(points, x_translation, y_translation);

    // make every point connected to all other points
    // use different colours on the superellipse
    for(int i=0; i<points.size()/2 -1; ++i)
    {
        for(int j=i+1; j<points.size(); ++j)
        {
            poly_ellipse_1.add(points[i]);
            poly_ellipse_1.add(points[j]);
        }
    }
    
    poly_ellipse_1.set_color(Color::blue);
    for(int i=points.size()/2; i<points.size() -1; ++i)
    {
        for(int j=i+1; j<points.size(); ++j)
        {
            poly_ellipse_2.add(points[i]);
            poly_ellipse_2.add(points[j]);
        }
    }
    poly_ellipse_2.set_color(Color::yellow);

    win.attach(poly_ellipse_1);
    win.attach(poly_ellipse_2);
    
    win.wait_for_button();
}

//------------------------------------------------------------------------
int main()
{
    try
    {
        // display message to user
        std::cout << message_1().str();

        // read the values
        float a, b, m, n;
        std::cout << prompt;
        std::cin >> a;

        std::cout << prompt;
        std::cin >> b;

        std::cout << prompt;
        std::cin >> m;

        std::cout << prompt;
        std::cin >> n;

        // define the superellipse
        Superellipse se(a, b, m, n);

        // how many points to plot?
        int N_points;
        std::cout << message_2().str();
        std::cout << prompt;
        std::cin >> N_points;

        if(N_points%4 != 0) error("The number of points must be a multiple of 4");

        // calculate points
        vector<Point> points_to_plot = find_points(N_points, se);

        // make plot
        make_plot(points_to_plot);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unkown exception";
    }
}