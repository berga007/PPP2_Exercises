// Drill 01 from
// Chapter 10 Programming: Principles and Practice Using C++

#include "../../../std_lib_facilities.h"

// simple Point type
struct Point{
    double x;
    double y;
};

istream& operator>>(istream& is, Point& p)
// read two doubles and compose a point
// format: (x,y)
{
    char ch1;
    if(is >> ch1 && ch1!= '('){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2, ch3;
    double d1, d2;

    is >> d1 >> ch2 >> d2 >> ch3;
    if(!is || ch2 != ',' || ch3 != ')') error("bad coordinate reading");

    p.x = d1;
    p.y = d2;

    return is;

}

ostream& operator <<(ostream& os, Point& p){
    return os << '(' << p.x
              << ',' << p.y
              << ')'; 
}

void skip_to_point()
{
    if(cin.fail())  // something other than a Point was found
    cin.clear();    // let's try to examine the characters
    for(char ch; cin >> ch; ){  // throw away characters until finding a '('
        if(ch == '('){
            cin.unget();    // put the digit back so 
                            // that we can read the Point
            return;
        }
    }
    error("no input");  // eof or bad, give up
}

Point get_point()
{
    Point p{};
    while(true){
        if(cin >> p) return p;
        cout << "Sorry, that was not a Point, please try again\n";
        skip_to_point(); 
    }
}

int main(){
    string prompt{">>>"};
    vector<Point> original_points{};
    cout << "Please enter seven (x,y) pairs:\n";
    for (int i=0; i<7; ++i){
        cout << prompt;
        Point p = get_point();
        original_points.push_back(p);
    }

    for(Point p:original_points){
        cout << p << '\n';
    }
    
}