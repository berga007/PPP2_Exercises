// Drills 5, 6 and 7 from Chapter 10 
// Programming: Principles and Practice Using C++

#include "../../../std_lib_facilities.h"

// check the the stream state, if bad or fail throw an exception
void end_of_loop(istream& ist, const string& message)
{
    if(ist.fail() || ist.bad()){
        ist.clear();
        error(message);
    }
}

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
    if(!is) return is;
    if(ch2 != ',' || ch3 != ')') error("bad coordinate reading");

    p.x = d1;
    p.y = d2;

    return is;

}

ostream& operator <<(ostream& os, Point& p){
    return os << '(' << p.x
              << ',' << p.y
              << ')'; 
}

bool operator ==(const Point& p1, const Point& p2){
    return p1.x==p2.x && p1.y == p2.y;
}

bool operator !=(const Point& p1, const Point& p2){
    return !(p1==p2);
}

void skip_to_point()
{
    if(cin.fail()){  // something other than a Point was found
        cin.clear();    // let's try to examine the characters
        for(char ch; cin >> ch; ){  // throw away characters until finding a '('
            if(ch == '('){
                cin.unget();    // put the digit back so 
                            // that we can read the Point
                return;
            }
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

    cout << "Please enter name of output file: \n"
         << prompt;
    string oname;
    cin >> oname;
    ofstream ost{oname};    // ost is an output stream for a file named oname
    if(!ost) error("can't open output file ", oname);

    for(Point p:original_points){
        ost << p << '\n';
    }

    ost.close();    // close file explicitly

    ifstream ifs{"mydata"};
    if(!ifs) error("can't open input file stream");
    vector<Point> processed_points{};

    // read Points from file stream ifs
    for(Point p{}; ifs >> p; ){
        processed_points.push_back(p);
    }
    string error_message = "bad end of file"; 
    end_of_loop(ifs, error_message);

    if(processed_points.size()!=original_points.size())
        error("The size of the two lists does not match");

    // print both vector of Points
    cout << "The list of points introduced is:\n";
    cout << "Original list" << '\t' << "Processed list" << '\n';

    for(int i=0; i<original_points.size(); ++i){
        if(original_points[i] != processed_points[i]){
            cout << "Something's wrong!";
            break;

        }
        cout << original_points[i]  << '\t' << processed_points[i] << '\n';
    }
}