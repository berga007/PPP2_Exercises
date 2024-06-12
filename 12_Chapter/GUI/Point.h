
#ifndef POINT_GUARD
#define POINT_GUARD

//typedef void (*Callback)(void*,void*);

namespace Graph_lib {

struct Point {
	int x,y;
	Point(int xx, int yy) : x(xx), y(yy) { }
	Point() :x(0), y(0) { }

//	Point& operator+=(Point d) { x+=d.x; y+=d.y; return *this; }
};

inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; }

inline bool operator!=(Point a, Point b) { return !(a==b); }

// used to sort points by x-value in Striped_closed_polyline
inline bool operator<(Point a, Point b) { return a.x < b.x; }

//------------------------------------------------------------------------------

// used to sort points by x-value in Striped_closed_polyline
inline bool operator>(Point a, Point b) { return a.x > b.x; }

//------------------------------------------------------------------------------

}
#endif