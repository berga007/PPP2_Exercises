//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include "Graph.h"

//------------------------------------------------------------------------------

namespace Graph_lib {

//------------------------------------------------------------------------------

Shape::Shape() :
    lcolor(fl_color()),      // default color for lines and characters
    ls(0),                   // default style
    fcolor(Color::invisible) // no fill
{}

//------------------------------------------------------------------------------
Shape::Shape(initializer_list<Point> lst)
{
    for(Point p: lst) add(p);
}

//------------------------------------------------------------------------------

void Shape::add(Point p)     // protected
{
    points.push_back(p);
}

//------------------------------------------------------------------------------

void Shape::set_point(int i, Point p)        // not used; not necessary so far
{
    points[i] = p;
}

//------------------------------------------------------------------------------

void Shape::draw_lines() const
{
    if (color().visibility() && 1<points.size())    // draw sole pixel?
        for (unsigned int i=1; i<points.size(); ++i)
            fl_line(points[i-1].x,points[i-1].y,points[i].x,points[i].y);
}

//------------------------------------------------------------------------------

void Shape::draw() const
{
    Fl_Color oldc = fl_color();
    // there is no good portable way of retrieving the current style
    fl_color(lcolor.as_int());            // set color
    fl_line_style(ls.style(),ls.width()); // set style
    draw_lines();
    fl_color(oldc);      // reset color (to previous)
    fl_line_style(0);    // reset line style to default
}

//------------------------------------------------------------------------------

void Shape::move(int dx, int dy)    // move the shape +=dx and +=dy
{
    for (int i = 0; i<points.size(); ++i) {
        points[i].x+=dx;
        points[i].y+=dy;
    }
}

//------------------------------------------------------------------------------

void Group::draw() const
{
    for (int i = 0; i<shapes.size(); ++i)
        shapes[i].draw();
}

//------------------------------------------------------------------------------

void Group::move(int dx,int dy)
{
    for (int i = 0; i<shapes.size(); ++i)
        shapes[i].move(dx,dy);
}

//------------------------------------------------------------------------------

void Group::set_color(Color col)
{
    Shape::set_color(col);
    for (int i = 0; i<shapes.size(); ++i)
        shapes[i].set_color(col);
}

//------------------------------------------------------------------------------

void Group::set_style(Line_style sty)
{
    Shape::set_style(sty);
    for (int i = 0; i<shapes.size(); ++i)
        shapes[i].set_style(sty);
}

//------------------------------------------------------------------------------

void Group::set_fill_color(Color col)
{
    Shape::set_fill_color(col);
    for (int i = 0; i<shapes.size(); ++i)
        shapes[i].set_fill_color(col);
}

//------------------------------------------------------------------------------

//void Group::draw_lines() const
//{
//    for (int i = 0; i<shapes.size(); ++i)
//        shapes[i].draw_lines();
//}

//------------------------------------------------------------------------------

Bar_chart::Bar_chart(Point orig, double yscale, int width, int space)
    :ysc(yscale), wd(width), sp(space)
{
    if (width<2) error("Bar_chart width must be at least 2");
    if (space<1) error("Bar_char space must be at least 1");
    add(orig);
}

//------------------------------------------------------------------------------

void Bar_chart::move(int dx, int dy)
{
    Shape::move(dx,dy);
    for (int i = 0; i<labels.size(); ++i)
        labels[i].move(dx,dy);
}

//------------------------------------------------------------------------------

void Bar_chart::add_val(double d)
{
    values.push_back(d);
    int x = point(0).x + (values.size()-1)*(wd+sp) + sp/2;
    int y = point(0).y - (ysc*d);
    if (d<0) y += 30;
    else y -= 20;
    labels.push_back(new Text(Point(x,y),""));
}

//------------------------------------------------------------------------------

void Bar_chart::draw_lines() const
{
    for (int i = 0; i<values.size(); ++i) {
        labels[i].draw();
        int x = point(0).x + i*(wd+sp) + sp/2;
        int y = point(0).y - (values[i]>0 ? values[i]*ysc : 0);

        if (fill_color().visibility()) {    // fill
            fl_color(fill_color().as_int());
            fl_rectf(x,y,wd,ceil(abs(values[i]*ysc)));
            fl_color(color().as_int());    // reset color
        }

        if (color().visibility()) {    // lines on top of fill
            fl_color(color().as_int());
            fl_rect(x,y,wd,ceil(abs(values[i]*ysc)));
        }
    }
}

//------------------------------------------------------------------------------

void Line::set_point(int i, Point p)
{
    Shape::set_point(i, p);
}

//------------------------------------------------------------------------------

Line::Line(Point p1, Point p2)    // construct a line from two points
{
    add(p1);    // add p1 to this shape
    add(p2);    // add p2 to this shape
}

//------------------------------------------------------------------------------
Arrow::Arrow(Point p1, Point p2)
      :Line(p1, p2){}

void Arrow::draw_lines() const
{
    Line::draw_lines();
    // let us define the vector AB
    double vectBA_x = point(0).x - point(1).x;   
    double vectBA_y = point(0).y - point(1).y;

    // The norm or magnitude of the vector AB
    double normAB{sqrt(pow(vectBA_x, 2) + pow(vectBA_y, 2))};

    // coordinates of point c which is 8 away from B
    double cx{point(1).x + 8 * vectBA_x/normAB};   
    double cy{point(1).y + 8 * vectBA_y/normAB};

    // vector orthogonal to BA
    double vectBA_ort_x{vectBA_y};
    double vectBA_ort_y{-vectBA_x};

    // point CL is 4 to the left of C in direction perpendicular to AB
    double CL_x{cx - 4 * vectBA_ort_x/normAB};   
    double CL_y{cy - 4 * vectBA_ort_y/normAB};

    // point CR is 4 to the right of C in direction perpendicular to AB
    double CR_x{cx + 4 * vectBA_ort_x/normAB};   
    double CR_y{cy + 4 * vectBA_ort_y/normAB};

    // draw the arrowhead using point B, CL and CR
    fl_begin_complex_polygon();
    fl_vertex(point(1).x, point(1).y);
    fl_vertex(CL_x, CL_y);
    fl_vertex(CR_x, CR_y);
    fl_end_complex_polygon();
}

//------------------------------------------------------------------------------
Lines::Lines(initializer_list<pair<Point, Point>> lst)
{
    for(auto p:lst) add(p.first, p.second);
}

//------------------------------------------------------------------------------
void Lines::add(Point p1, Point p2)
{
    Shape::add(p1);
    Shape::add(p2);
}

//------------------------------------------------------------------------------

// draw lines connecting pairs of points
void Lines::draw_lines() const
{
    if (color().visibility())
        for (int i=1; i<number_of_points(); i+=2)
            fl_line(point(i-1).x,point(i-1).y,point(i).x,point(i).y);
}

//------------------------------------------------------------------------------

// does two lines (p1,p2) and (p3,p4) intersect?
// if so return the distance of the intersect point as distances from p1
inline pair<double,double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel)
{
    double x1 = p1.x;
    double x2 = p2.x;
    double x3 = p3.x;
    double x4 = p4.x;
    double y1 = p1.y;
    double y2 = p2.y;
    double y3 = p3.y;
    double y4 = p4.y;

    double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
    if (denom == 0){
        parallel= true;
        return pair<double,double>(0,0);
    }
    parallel = false;
    return pair<double,double>( ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
                                ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
}

//------------------------------------------------------------------------------

//intersection between two line segments
//Returns true if the two segments intersect,
//in which case intersection is set to the point of intersection
bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection){
   bool parallel;
   pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
   intersection.x = p1.x + u.first*(p2.x - p1.x);
   intersection.y = p1.y + u.first*(p2.y - p1.y);
   return true;
}

//------------------------------------------------------------------------------

void Polygon::add(Point p)
{
    int np = number_of_points();

    if (1<np) {    // check that the new line isn't parallel to the previous one
        if (p==point(np-1)) error("polygon point equal to previous point");
        bool parallel;
        line_intersect(point(np-1),p,point(np-2),point(np-1),parallel);
        if (parallel)
            error("two polygon points lie in a straight line");
    }

    for (int i = 1; i<np-1; ++i) {    // check that new segment doesn't interset and old point
        Point ignore(0,0);
        if (line_segment_intersect(point(np-1),p,point(i-1),point(i),ignore))
            error("intersect in polygon");
    }

    Closed_polyline::add(p);
}

//------------------------------------------------------------------------------

void Polygon::draw_lines() const
{
    if (number_of_points() < 3) error("less than 3 points in a Polygon");
    Closed_polyline::draw_lines();
}

//------------------------------------------------------------------------------

Poly::Poly(initializer_list<Point> lst)
{
    for(Point p:lst) add(p);
}

//------------------------------------------------------------------------------

void Poly::add(Point p)
{
    Polygon::add(p);
}

//------------------------------------------------------------------------------

void Poly::draw_lines() const
{
    Polygon::draw_lines();
}

//------------------------------------------------------------------------------

Regular_hexagon::Regular_hexagon(Point xy, int ss)
    : s{ss}
{
    // add all points that comprise the hexagon
    for(float alpha=0; alpha<2*pi; alpha+=pi/3){
        int x = xy.x + round(s*cos(alpha));
        int y = xy.y+round(s*sin(alpha));
        add(Point{x,y});
    }
}

//------------------------------------------------------------------------------

Point Regular_hexagon::center() const{
    return Point{point(0).x-s, point(0).y};
}

//------------------------------------------------------------------------------

void Regular_hexagon::set_length(int new_length){
    // center remains in the same point
    // the coordinates of every point must be updated
    s = new_length;
    for(int i=0; i<6; ++i){
        int x = center().x + round(s*cos(i*pi/3));
        int y = center().y + round(s*sin(i*pi/3));
        set_point(i, Point{x,y});
    }
}

//------------------------------------------------------------------------------

void Regular_hexagon::draw_lines() const {
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for(int i=0; i<number_of_points(); ++i){
            fl_vertex(point(i).x, point(i).y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());    // reset color
    }

    if (color().visibility())
        Shape::draw_lines();

    // then draw closing line:
    if (2<number_of_points() && color().visibility()) {
        fl_line(point(number_of_points()-1).x,
            point(number_of_points()-1).y,
            point(0).x,
            point(0).y);
    }   
}

//------------------------------------------------------------------------------

Regular_polygon::Regular_polygon(Point xy, int nn, int ss)
    :n{nn}, s{ss} 
    {
        for(int i=0; i<n; ++i)
        {
            float alpha = i*2*pi/n;
            int x = xy.x + round(s*cos(alpha));
            int y = xy.y + round(s*sin(alpha));
            add(Point{x,y});
        }
    }

//------------------------------------------------------------------------------

Point Regular_polygon::center() const{
    return Point{point(0).x-s, point(0).y};
}

//------------------------------------------------------------------------------

void Regular_polygon::set_length(int new_length){
    s = new_length;
    for(int i=0; i<n; ++i){
            float alpha = i*2*pi/n;
            int x = center().x + round(s*cos(alpha));
            int y = center().y + round(s*sin(alpha));
            set_point(i, Point{x,y});
    }
}

//------------------------------------------------------------------------------

void Regular_polygon::draw_lines() const{
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for(int i=0; i<number_of_points(); ++i){
            fl_vertex(point(i).x, point(i).y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());    // reset color
    }

    if (color().visibility())
        Shape::draw_lines();

    // then draw closing line:
    if (2<number_of_points() && color().visibility()) {
        fl_line(point(number_of_points()-1).x,
            point(number_of_points()-1).y,
            point(0).x,
            point(0).y);
    }   
}

//------------------------------------------------------------------------------

Star::Star(Point xy, int nn, int ss, int step)
    :Regular_polygon(xy, nn, ss), st{step}{}


//------------------------------------------------------------------------------

void Star::set_step(int s){
    st = s;
}

//------------------------------------------------------------------------------

void Star::draw_lines() const{
    /*
    Points are not connected sequentially like regular polygons.
    Here point 0 will be connected to point step, and point step
    to 2*step. If this is higher than the total number of points, 
    we wrap around 0 and continue. This cycle is similar to the way
    we sum hours. 10h00 a.m + 3 == 1 p.m
    We stop when we reach point 0 again. 
    */
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for(int i=0; i<number_of_points(); ++i){
            fl_vertex(point((st*i)%number_of_points()).x, point((st*i)%number_of_points()).y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());    // reset color
    }

    if (color().visibility()){
        for(int i=0; i<number_of_points(); ++i){
            fl_line(
                point((st*i)%number_of_points()).x, 
                point((st*i)%number_of_points()).y,
                point((st*(i+1))%number_of_points()).x, 
                point((st*(i+1))%number_of_points()).y);
        }
    }
}

//------------------------------------------------------------------------------
int inner_product(Point p1, Point p2)
{
    return p1.x*p2.x+p1.y*p2.y;
}

//------------------------------------------------------------------------------
Right_triangle::Right_triangle(Point p1, Point p2, Point p3)
{
    // calculate the vectors

    // between Point 1 and 2
    Point p1p2{p2.x-p1.x, p2.y-p1.y};

    // between Point 2 and 3
    Point p2p3{p3.x-p2.x, p3.y-p2.y};

    // between Point 1 and 3
    Point p1p3{p3.x-p1.x, p3.y-p1.y};

    // compute the inner product between them, one of the result has to be 0
    // if A is perpendicular to B, their inner product is 0
    int inner_1{inner_product(p1p2, p2p3)};
    int inner_2{inner_product(p2p3, p1p3)};
    int inner_3{inner_product(p1p2, p1p3)};

    /* 
    if (inner_1!=0 && inner_2!=0 && inner_3!=0){
        error("Points given do not form a right triangle");
    }
    */

    add(p1);
    add(p2);
    add(p3);

    // compute the norm of the vectors
    float d1_2(sqrt(pow(p1p2.x, 2) + pow(p1p2.y, 2)));
    float d2_3(sqrt(pow(p2p3.x, 2) + pow(p2p3.y, 2)));
    float d1_3(sqrt(pow(p1p3.x, 2) + pow(p1p3.y, 2)));

    // sort the distances in ascending order
    vector<float> dis{d1_2, d2_3, d1_3};
    sort(dis.begin(), dis.end());

    // smallest distance is the height
    h = dis[0];

    // next is the base
    b = dis[1];

}


//------------------------------------------------------------------------------
int Right_triangle::base() const{
    return b;
}


//------------------------------------------------------------------------------
int Right_triangle::height() const{
    return h;
}


//------------------------------------------------------------------------------
void Right_triangle::draw_lines() const{
    
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for(int i=0; i<number_of_points(); ++i){
            fl_vertex(point(i).x, point(i).y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());    // reset color
    }

    if (color().visibility())
        Shape::draw_lines();

    if (2<number_of_points() && color().visibility()) {
        fl_line(point(number_of_points()-1).x,
            point(number_of_points()-1).y,
            point(0).x,
            point(0).y);
    }
}


//------------------------------------------------------------------------------
void Open_polyline::draw_lines() const
{
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for(int i=0; i<number_of_points(); ++i){
            fl_vertex(point(i).x, point(i).y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());    // reset color
    }

    if (color().visibility())
        Shape::draw_lines();
}

//------------------------------------------------------------------------------

void Closed_polyline::draw_lines() const
{
    Open_polyline::draw_lines();    // first draw the "open poly line part"
    // then draw closing line:
    if (2<number_of_points() && color().visibility()) {
        fl_line(point(number_of_points()-1).x,
            point(number_of_points()-1).y,
            point(0).x,
            point(0).y);
    }
}

//------------------------------------------------------------------------------

// uses even-odd for filling
void Striped_closed_polyline::draw_lines() const
{
    if (number_of_points() > 1) {
        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());

            // get bounding box, pad with 5px in x-direction
            int x_min = point(0).x;
            int x_max = point(0).x;
            int y_min = point(0).y;
            int y_max = point(0).y;
            for (int i = 0; i<number_of_points(); ++i) {
                if (point(i).x < x_min) x_min = point(i).x;
                if (point(i).x > x_max) x_max = point(i).x;
                if (point(i).y < y_min) y_min = point(i).y;
                if (point(i).y > y_max) y_max = point(i).y;
            }
            x_min -= 5;
            x_max += 5;

            // for each horizontal line in bounding box, check for intersection with all polygon lines
            // and add found intersections to vector of points
            for (int y = y_min; y<y_max; y+=2) {
                vector<Point> is;   // vector of intersections
                Point intersec;
                for (int i = 1; i<number_of_points(); ++i) {
                    if (line_segment_intersect(Point(x_min,y),Point(x_max,y),point(i),point(i-1),intersec))
                        is.push_back(intersec);
                }
                // add closing line
                if (line_segment_intersect(Point(x_min,y),Point(x_max,y),
                    point(number_of_points()-1),point(0),intersec))
                    is.push_back(intersec);

                // sort vector by x-values
                sort(is.begin(),is.end());

                // draw line between every 2nd pair of points
                for (int i = 1; i<is.size(); i+=2) {
                    fl_line(is[i-1].x,is[i-1].y,is[i].x,is[i].y);
                }

            }
                fl_color(color().as_int());    // reset color
        }

        if (color().visibility()) {
            Shape::draw_lines();
            // draw closing line
            fl_line(point(number_of_points()-1).x,
                point(number_of_points()-1).y,
                point(0).x,
                point(0).y);
        }
    }
}

//------------------------------------------------------------------------------

void draw_mark(Point xy, char c)
{
    static const int dx = 4;
    static const int dy = 4;

    string m(1,c);
    fl_draw(m.c_str(),xy.x-dx,xy.y+dy);
}

//------------------------------------------------------------------------------

void Marked_polyline::draw_lines() const
{
    Open_polyline::draw_lines();
    for (int i=0; i<number_of_points(); ++i)
        draw_mark(point(i),mark[i%mark.size()]);
}

//------------------------------------------------------------------------------
Marked_polyline::Marked_polyline(const string& m, initializer_list<Point> lst)
                :Open_polyline{lst}, mark{m}
{
    if(m=="") mark="*";
}

//------------------------------------------------------------------------------

void Rectangle::draw_lines() const
{
    if (fill_color().visibility()) {    // fill
        fl_color(fill_color().as_int());
        fl_rectf(point(0).x,point(0).y,w,h);
        fl_color(color().as_int());    // reset color
    }

    if (color().visibility()) {    // lines on top of fill
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,w,h);
    }
}

//------------------------------------------------------------------------------
Point n(const Rectangle& r)
{
    return Point{r.point(0).x + r.width()/2, r.point(0).y};
}

//------------------------------------------------------------------------------
Point s(const Rectangle& r)
{
    return Point{r.point(0).x+r.width()/2, r.point(0).y + r.height()};
}

//------------------------------------------------------------------------------
Point e(const Rectangle& r)
{
    return Point{r.point(0).x+r.width(), r.point(0).y+r.height()/2};
}

//------------------------------------------------------------------------------
Point w(const Rectangle& r)
{
    return Point{r.point(0).x, r.point(0).y+r.height()/2};
}

//------------------------------------------------------------------------------
Point center(const Rectangle& r)
{
return Point{r.point(0).x+r.width()/2, r.point(0).y + r.height()/2};
}

//------------------------------------------------------------------------------
Point ne(const Rectangle& r)
{
    return Point{r.point(0).x + r.width(), r.point(0).y};
}

//------------------------------------------------------------------------------
Point nw(const Rectangle& r)
{
    return r.point(0);
}

//------------------------------------------------------------------------------
Point sw(const Rectangle& r)
{
    return Point{r.point(0).x, r.point(0).y + r.height()};
}

//------------------------------------------------------------------------------
Point se(const Rectangle& r)
{
    return Point{r.point(0).x + r.width(), r.point(0).y + r.height()};
}

//------------------------------------------------------------------------------

void Striped_rectangle::draw_lines() const
{
    if (fill_color().visibility()) {    // fill
        fl_color(fill_color().as_int());
        for (int i = point(0).y+2; i<point(0).y+height(); i+=2)
            fl_line(point(0).x,i,point(0).x+width()-1,i);
        fl_color(color().as_int());    // reset color
    }

    if (color().visibility()) {    // lines on top of fill
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,width(),height());
    }
}

//------------------------------------------------------------------------------

void Box::draw_lines() const
{
    if (fill_color().visibility()) {	// fill
        
        fl_color(fill_color().as_int());
        // fill the rectangles
        fl_rectf(point(0).x - r,point(0).y,w+2*r,h);
        fl_rectf(point(0).x - r,point(0).y - r,w,r);
        fl_rectf(point(0).x, point(0).y+h,w,r);
        
        // fill corners
        fl_pie(point(0).x+w-r,point(0).y-r,r+r-1,r+r-1,0,90);
		fl_pie(point(0).x-r,point(0).y-r,r+r-1,r+r-1,90,180);
		fl_pie(point(0).x-r,point(0).y+h-r-r,r+r-1,r+r-1,180,270);
		fl_pie(point(0).x+w-r,point(0).y+h-r,r+r-1,r+r-1,270,360);
		
        fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {

        fl_color(color().as_int());
        
        // 4 lines and 4 arcs

        // top line
        fl_line(point(0).x-1, point(0).y-r, point(0).x+w, point(0).y - r);
        // bottom line
        fl_line(point(0).x-1, point(0).y+h+r-1, point(0).x+w, point(0).y+h+r-1);
        // left line
        fl_line(point(0).x - r, point(0).y-1, point(0).x-r, point(0).y+h);
        // right line
        fl_line(point(0).x+w+r-1, point(0).y-1, point(0).x+w+r-1, point(0).y+h);

        // upper right arc
        fl_arc(point(0).x+w-r, point(0).y-r, r+r, r+r, 0, 90);
        // upper left arc
        fl_arc(point(0).x-r, point(0).y-r, r+r, r+r, 90, 180);
        // lower left arc
        fl_arc(point(0).x-r, point(0).y+h-r, r+r, r+r, 180, 270);
        // lower right arc
        fl_arc(point(0).x+w-r, point(0).y+h-r, r+r, r+r, 270, 360);
	}
}

//------------------------------------------------------------------------------

Pseudo_window::Pseudo_window(Point xy, int ww, int hh, string lab)
    :Box(xy,ww,hh,10),
     win_name(Point(xy.x+8,xy.y+22),lab),
     ctrl(Point(xy.x+ww-26,xy.y+4),22,22,3),
     bg(Point(xy.x+4,xy.y+32),Point(xy.x+ww-4,xy.y+hh-4)),
     content(Point(xy.x+4,xy.y+32),"pics_and_txt/Rita_path.gif")
{
    set_color(Color::invisible);
    set_fill_color(Color::blue);
    win_name.set_font_size(15);
    win_name.set_color(Color::white);
    win_name.set_font(Font::helvetica_bold);
    ctrl.set_color(Color::white);
    ctrl.set_fill_color(Color::red);
    x.add(Point(xy.x+ww-20,xy.y+10),Point(xy.x+ww-10,xy.y+20));
    x.add(Point(xy.x+ww-20,xy.y+20),Point(xy.x+ww-10,xy.y+10));
    x.set_style(Line_style(Line_style::solid,3));
    x.set_color(Color::white);
    bg.set_color(Color::invisible);
    bg.set_fill_color(fl_rgb_color(236,233,216));
    content.set_mask(Point(0,0),bg.width(),bg.height());
}

//------------------------------------------------------------------------------

void Pseudo_window::draw_lines() const
{
    Box::draw_lines();
    win_name.draw();
    ctrl.draw();
    x.draw();
    bg.draw();
    content.draw();
}

//------------------------------------------------------------------------------

void Pseudo_window::move(int dx, int dy)
{
    Box::move(dx,dy);
    win_name.move(dx,dy);
    ctrl.move(dx,dy);
    x.move(dx,dy);
    bg.move(dx,dy);
    content.move(dy,dy);
}

//------------------------------------------------------------------------------

Point n(const Graph_lib::Box& box)
{
    return Point(box.point(0).x+box.width()/2,box.point(0).y);
}

//------------------------------------------------------------------------------

Point s(const Box& box)
{
    return Point(box.point(0).x+box.width()/2,box.point(0).y+box.height());
}

//------------------------------------------------------------------------------

Point e(const Box& box)
{
    return Point(box.point(0).x+box.width(),box.point(0).y+box.height()/2);
}

//------------------------------------------------------------------------------

Point w(const Box& box)
{
    return Point(box.point(0).x,box.point(0).y+box.height()/2);
}

//------------------------------------------------------------------------------

Point center(const Box& box)
{
    return Point(box.point(0).x+box.width()/2,box.point(0).y+box.height()/2);
}

//------------------------------------------------------------------------------

Point ne(const Box& box)
{
    return Point(box.point(0).x+box.width(),box.point(0).y);
}

//------------------------------------------------------------------------------

Point se(const Box& box)
{
    return Point(box.point(0).x+box.width(),box.point(0).y+box.height());
}

//------------------------------------------------------------------------------

Point sw(const Box& box)
{
    return Point(box.point(0).x,box.point(0).y+box.height());
}

//------------------------------------------------------------------------------

Point nw(const Box& box)
{
    return box.point(0);
}

//------------------------------------------------------------------------------

Circle::Circle(Point p, int rr)    // center and radius
    :r{rr}
{
    add(Point(p.x-r,p.y-r));       // store top-left corner
}

//------------------------------------------------------------------------------

Point Circle::center() const
{
    return Point(point(0).x+r, point(0).y+r);
}

//------------------------------------------------------------------------------

void Circle::draw_lines() const
{
  	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,r+r-1,r+r-1,0,360);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	}
}

//------------------------------------------------------------------------------

Point n(const Circle& c)
{
    return Point{c.point(0).x+c.radius(), c.point(0).y};
}

//------------------------------------------------------------------------------

Point s(const Circle& c)
{
    return Point{c.point(0).x+c.radius(), 2*c.radius()};
}

//------------------------------------------------------------------------------

Point e(const Circle& c)
{
    return Point{c.point(0).x+2*c.radius(), c.point(0).y + c.radius()};
}

//------------------------------------------------------------------------------

Point w(const Circle& c)
{
    return Point{c.point(0).x, c.point(0).y+c.radius()};
}

//------------------------------------------------------------------------------

Point center(const Circle& c)
{
    return c.center();
}

//------------------------------------------------------------------------------

Point ne(const Circle& c)
{
    return Point{c.point(0).x+2*c.radius(), c.point(0).y};
}

//------------------------------------------------------------------------------

Point nw(const Circle& c)
{
    return c.point(0);
}

//------------------------------------------------------------------------------

Point sw(const Circle& c)
{
    return Point{c.point(0).x, c.point(0).y+2*c.radius()};
}

//------------------------------------------------------------------------------

Point se(const Circle& c)
{
    return Point{c.point(0).x+2*c.radius(), c.point(0).y+2*c.radius()};
}

//------------------------------------------------------------------------------

Clock::Clock(Point p, int rr)
    :Circle(p,rr), hh(0), mm(0), ss(0)
{
    set_style(Line_style(Line_style::solid,4));

    // calculate ticks
    double inner_radius = 0.8 * r; // radius of inner end of ticks
    for (int i = 0; i<12; ++i) {
        double angle = i*pi/6;
        int tx1 = p.x + inner_radius*cos(pi/2-angle);
        int tx2 = p.x + r*cos(pi/2-angle);
        int ty1 = p.y + inner_radius*sin(pi/2-angle);
        int ty2 = p.y + r*sin(pi/2-angle);
        ticks.add(Point(tx1,ty1),Point(tx2,ty2));
        ticks.set_style(Line_style(Line_style::solid,1));
    }

    // get system time, set hh/mm/ss
    time_t t = time(0);
    struct tm* now = localtime(&t);
    hh = now->tm_hour % 12;
    mm = now->tm_min;
    ss = now->tm_sec;

    // calculate angles, set hands
    // angle is zero at 12:00, increases clockwise
    double phi = (hh+mm/60.0)/6.0*pi;
    int hx = round(p.x + 0.6*r*cos(pi/2-phi));  // hour.x
    int hy = round(p.y + 0.6*r*sin(-pi/2+phi)); // hour.y
    hands.push_back(new Line(p,Point(hx,hy)));
    hands[0].set_style(Line_style(Line_style::solid,3));

    phi = mm/30.0*pi;
    hx = round(p.x + 0.9*r*cos(pi/2-phi));      // minute.x
    hy = round(p.y + 0.9*r*sin(-pi/2+phi));     // minute.y
    hands.push_back(new Line(p,Point(hx,hy)));
    hands[1].set_style(Line_style(Line_style::solid,3));

    phi = ss/30.0*pi;
    hx = round(p.x + 0.9*r*cos(pi/2-phi));      // second.x
    hy = round(p.y + 0.9*r*sin(-pi/2+phi));     // second.y
    hands.push_back(new Line(p,Point(hx,hy)));
    hands[2].set_style(Line_style(Line_style::solid,2));
    hands[2].set_color(Color::red);
}

//------------------------------------------------------------------------------

void Clock::draw_lines() const
{
    Circle::draw_lines();
    ticks.draw();
    for (int i = 0; i<3; ++i)
        hands[i].draw();
}

//------------------------------------------------------------------------------

void Clock::increase_time()
{
    ++ss;
    if (ss == 60) {
        ++mm;
        ss = 0;
        if (mm == 60) {
            ++hh;
            mm = 0;
            if (hh == 12) {
                hh = 0;
            }
        }
    }
}

//------------------------------------------------------------------------------

void Clock::update_hands()
// moves points at ends of hands
{
    double phi = (hh+mm/60.0)/6.0*pi;
    int hx = round(center().x + 0.6*r*cos(pi/2-phi));   // hour.x
    int hy = round(center().y + 0.6*r*sin(-pi/2+phi));  // hour.y
    hands[0].set_point(1,Point(hx,hy));

    phi = mm/30.0*pi;
    hx = round(center().x + 0.9*r*cos(pi/2-phi));   // minute.x
    hy = round(center().y + 0.9*r*sin(-pi/2+phi));  // minute.y
    hands[1].set_point(1,Point(hx,hy));

    phi = ss/30.0*pi;
    hx = round(center().x + 0.9*r*cos(pi/2-phi));   // second.x
    hy = round(center().y + 0.9*r*sin(-pi/2+phi));  // second.y
    hands[2].set_point(1,Point(hx,hy));
}

//------------------------------------------------------------------------------

void Striped_circle::draw_lines() const
{
  	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
        for (int i = center().y-radius(); i<center().y+radius(); i+=2) {
            int dy = center().y - i;
            int dx = round(sqrt(radius()*radius()-dy*dy)) - 1;
            fl_line(center().x-dx,i,center().x+dx,i);
        }
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,2*radius(),2*radius(),0,360);
	}
}

//------------------------------------------------------------------------------

void Ellipse::draw_lines() const
{
   if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,w+w-1,h+h-1,0,360);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,w+w,h+h,0,360);
	}
}

//------------------------------------------------------------------------------

Point Ellipse::center() const
{
    return Point(point(0).x+w,point(0).y+h); 
}

//------------------------------------------------------------------------------

Point Ellipse::focus1() const
{
    if (h<=w)   // foci are on the x-axis:
		return Point(center().x+int(sqrt(double(w*w-h*h))),center().y);
	else	// foci are on the y-axis:
		return Point(center().x,center().y+int(sqrt(double(h*h-w*w))));
}

//------------------------------------------------------------------------------

Point Ellipse::focus2() const
{
    if (h<=w)
		return Point(center().x-int(sqrt(double(w*w-h*h))),center().y);
	else
		return Point(center().x,center().y-int(sqrt(double(h*h-w*w))));
}

//------------------------------------------------------------------------------

Point n(const Ellipse& e)
{
    return Point{e.point(0).x+e.major(), e.point(0).y};
}

//------------------------------------------------------------------------------

Point s(const Ellipse& e)
{
    return Point(e.point(0).x+e.major(), e.point(0).y+2*e.minor());
}

//------------------------------------------------------------------------------

Point e(const Ellipse& e)
{
    return Point(e.point(0).x+2*e.major(), e.point(0).y+e.minor());
}

//------------------------------------------------------------------------------

Point w(const Ellipse& e)
{
    return Point(e.point(0).x, e.point(0).y+e.minor());
}

//------------------------------------------------------------------------------

Point center(const Ellipse& e)
{
    return e.center();
}

//------------------------------------------------------------------------------

Point ne(const Ellipse& e)
{
    // horizontal distance from center of ellipse to a point
    // at an angle of pi/4 radians
    int x_dist = round(e.major()*e.minor()*sqrt(1/(pow(e.minor(), 2) + pow(e.major(), 2))));
    int y_dist{x_dist};

    return Point{e.center().x+x_dist, e.center().y-y_dist};
}

//------------------------------------------------------------------------------

Point nw(const Ellipse& e)
{
    // horizontal distance from center of ellipse to a point
    // at an angle of pi/4 radians
    int x_dist = round(e.major()*e.minor()*sqrt(1/(pow(e.minor(), 2) + pow(e.major(), 2))));
    int y_dist{x_dist};

    return Point{e.center().x-x_dist, e.center().y-y_dist};
}

//------------------------------------------------------------------------------

Point sw(const Ellipse& e)
{
    // horizontal distance from center of ellipse to a point
    // at an angle of pi/4 radians
    int x_dist = round(e.major()*e.minor()*sqrt(1/(pow(e.minor(), 2) + pow(e.major(), 2))));
    int y_dist{x_dist};

    return Point{e.center().x-x_dist, e.center().y+y_dist};
}

//------------------------------------------------------------------------------

Point se(const Ellipse& e)
{
   // horizontal distance from center of ellipse to a point
    // at an angle of pi/4 radians
    int x_dist = round(e.major()*e.minor()*sqrt(1/(pow(e.minor(), 2) + pow(e.major(), 2))));
    int y_dist{x_dist};

    return Point{e.center().x+x_dist, e.center().y+y_dist}; 
}

//------------------------------------------------------------------------------
Point Arc::center() const
{
    return Point(point(0).x+w, point(0).y+h);
}

//------------------------------------------------------------------------------

Point Arc::focus1() const
{
    if (h<=w)   // foci are on the x-axis:
		return Point(center().x+int(sqrt(double(w*w-h*h))),center().y);
	else	// foci are on the y-axis:
		return Point(center().x,center().y+int(sqrt(double(h*h-w*w))));
}

//------------------------------------------------------------------------------

Point Arc::focus2() const
{
    if (h<=w)
		return Point(center().x-int(sqrt(double(w*w-h*h))),center().y);
	else
		return Point(center().x,center().y-int(sqrt(double(h*h-w*w))));
}

//------------------------------------------------------------------------------

void Arc::draw_lines() const
{
    if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,w+w-1,h+h-1,a1,a2);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,w+w,h+h,a1,a2);
	}
}

//------------------------------------------------------------------------------

Circle_face::Circle_face(Point p, int rr)
    : Circle(p,rr),
      l_eye(Point(p.x-rr/5,p.y-rr/2),rr/8,rr/3),
      r_eye(Point(p.x+rr/5,p.y-rr/2),rr/8,rr/3),
      mouth(p,rr*0.66,rr*0.66,180,360)  // Smiley initialisation
{
    l_eye.set_color(Color::invisible);
    l_eye.set_fill_color(color());
    r_eye.set_color(Color::invisible);
    r_eye.set_fill_color(color());
}

//------------------------------------------------------------------------------

void Circle_face::draw_lines() const
{
    Circle::draw_lines();
    if (color().visibility()) {
        l_eye.draw();
        r_eye.draw();
        mouth.draw();
    }
}

//------------------------------------------------------------------------------

void Circle_face::set_color(Color c)
{
    Shape::set_color(c);
    l_eye.set_fill_color(c);
    r_eye.set_fill_color(c);
    mouth.set_color(c);
}

//------------------------------------------------------------------------------

void Circle_face::set_style(Line_style ls)
{
    Circle::set_style(ls);
    mouth.set_style(ls);
}

//------------------------------------------------------------------------------

void Circle_face::move(int dx,int dy)
{
    Shape::move(dx,dy);
    l_eye.move(dx,dy);
    r_eye.move(dx,dy);
    mouth.move(dx,dy);
}

//------------------------------------------------------------------------------

void Circle_face::set_radius(int rr)
{
    Circle::set_radius(rr);
    l_eye.set_minor(rr/3);
    l_eye.set_major(rr/8);
    r_eye.set_minor(rr/3);
    r_eye.set_major(rr/8);

    // move eyes
    int dx = rr/5 - (r_eye.center().x-center().x);
    int dy = (center().y-r_eye.center().y) - rr/2;
    l_eye.move(-dx,dy);
    r_eye.move(dx,dy);

    // scale mouth
    mouth.set_minor(rr*0.66);
    mouth.set_major(rr*0.66);
}

//------------------------------------------------------------------------------

Smiley::Smiley(Point p, int rr) : Circle_face(p,rr) { }

//------------------------------------------------------------------------------

Hat_smiley::Hat_smiley(Point p, int rr) : Smiley(p,rr)
{
    // add top hat
    hat.add(Point(p.x-0.8*rr,p.y-0.8*rr));
    hat.add(Point(p.x-0.8*rr,p.y-0.9*rr));
    hat.add(Point(p.x-0.6*rr,p.y-0.9*rr));
    hat.add(Point(p.x-0.6*rr,p.y-1.9*rr));
    hat.add(Point(p.x+0.6*rr,p.y-1.9*rr));
    hat.add(Point(p.x+0.6*rr,p.y-0.9*rr));
    hat.add(Point(p.x+0.8*rr,p.y-0.9*rr));
    hat.add(Point(p.x+0.8*rr,p.y-0.8*rr));
    hat.set_fill_color(color());
}

//------------------------------------------------------------------------------

void Hat_smiley::set_color(Color c)
{
    Smiley::set_color(c);
    hat.set_color(c);
    hat.set_fill_color(c);
}

//------------------------------------------------------------------------------

Frowny::Frowny(Point p, int rr) : Circle_face(p,rr)
{
    // turn around mouth
    mouth.set_angles(0,180);
    mouth.move(0,0.66*rr);
}

//------------------------------------------------------------------------------

Hat_frowny::Hat_frowny(Point p, int rr)
    :Frowny(p,rr),
     rim(Point(p.x-0.8*rr,p.y-0.9*rr),Point(p.x+0.8*rr,p.y-0.8*rr)),
     bowl(Point(p.x,p.y-0.9*rr),0.6*rr,0.6*rr,0,180)
{
    // set colors
    rim.set_color(Color::invisible);
    rim.set_fill_color(color());
    bowl.set_color(Color::invisible);
    bowl.set_fill_color(color());
}

//------------------------------------------------------------------------------

void Hat_frowny::set_color(Color c)
{
    Frowny::set_color(c);
    rim.set_fill_color(c);
    bowl.set_fill_color(c);
}

//------------------------------------------------------------------------------

void Text::draw_lines() const
{
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(fnt.as_int(),fnt_sz);
    fl_draw(lab.c_str(),point(0).x,point(0).y);
    fl_font(ofnt,osz);
}

//------------------------------------------------------------------------------

void Textbox::draw_lines() const
{
    Box::draw_lines();
    label.draw();
}

//------------------------------------------------------------------------------

void Textbox::set_label(const string& s)
{
    label.set_label(s);
}

//------------------------------------------------------------------------------

void Textbox::set_font(Font f)
{
    label.set_font(f);
}

//------------------------------------------------------------------------------

void Textbox::move(int dx, int dy)
{
    Box::move(dx, dy);
    label.move(dx, dy);
}

//------------------------------------------------------------------------------

void Textbox::set_color(Color c)
{
    Box::set_color(c);
    label.set_color(c);
}

//------------------------------------------------------------------------------

Axis::Axis(Orientation d, Point xy, int length, int n, string lab) :
    label(Point(0,0),lab)
{
    if (length<0) error("bad axis length");
    switch (d){
    case Axis::x:
    {
        Shape::add(xy); // axis line
        Shape::add(Point(xy.x+length,xy.y));

        if (0<n) {      // add notches
            int dist = length/n;
            int x = xy.x+dist;
            for (int i = 0; i<n; ++i) {
                notches.add(Point(x,xy.y),Point(x,xy.y-5));
                x += dist;
            }
        }
        // label under the line
        label.move(length/3,xy.y+20);
        break;
    }
    case Axis::y:
    {
        Shape::add(xy); // a y-axis goes up
        Shape::add(Point(xy.x,xy.y-length));

        if (0<n) {      // add notches
            int dist = length/n;
            int y = xy.y-dist;
            for (int i = 0; i<n; ++i) {
                notches.add(Point(xy.x,y),Point(xy.x+5,y));
                y -= dist;
            }
        }
        // label at top
        label.move(xy.x-10,xy.y-length-10);
        break;
    }
    case Axis::z:
        error("z axis not implemented");
    }
}

//------------------------------------------------------------------------------

void Axis::draw_lines() const
{
    Shape::draw_lines();
    notches.draw();  // the notches may have a different color from the line
    label.draw();    // the label may have a different color from the line
}

//------------------------------------------------------------------------------

void Axis::set_color(Color c)
{
    Shape::set_color(c);
    notches.set_color(c);
    label.set_color(c);
}

//------------------------------------------------------------------------------

void Axis::move(int dx, int dy)
{
    Shape::move(dx,dy);
    notches.move(dx,dy);
    label.move(dx,dy);
}

//------------------------------------------------------------------------------

Function::Function(Fct f, double r1, double r2, Point xy,
                   int count, double xscale, double yscale)
// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
// x coordinates are scaled by xscale and y coordinates scaled by yscale
{
    if (r2-r1<=0) error("bad graphing range");
    if (count <=0) error("non-positive graphing count");
    double dist = (r2-r1)/count;
    double r = r1;
    for (int i = 0; i<count; ++i) {
        add(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
        r += dist;
    }
}

//------------------------------------------------------------------------------

Flex_function::Flex_function(Fct f, double r1, double r2, Point xy,int count,
                             double xscale, double yscale, double precision)
    :Function(f,r1,r2,xy,count,xscale,yscale),
     fct(f), range1(r1), range2(r2), origin(xy),
     c(count), xsc(xscale), ysc(yscale), prec(precision)
{
    reset();
}

//------------------------------------------------------------------------------

void Flex_function::reset_range(double r1, double r2) {
    if (r2<=r1) error("bad graphing range");
    range1 = r1;
    range2 = r2;
    reset();
}

//------------------------------------------------------------------------------

void Flex_function::reset_count(int count) {
    if (count<=0) error("non-positive graphing count");
    c = count;
    reset();
}

//------------------------------------------------------------------------------

void Flex_function::reset_xscale(double xscale) {
    if (xscale==0) error("xscale must not be zero");
    xsc = xscale;
    reset();
}

//------------------------------------------------------------------------------

void Flex_function::reset_yscale(double yscale) {
    if (yscale==0) error("yscale must not be zero");
    ysc = yscale;
    reset();
}

//------------------------------------------------------------------------------

void Flex_function::reset()
{
    double dist = (range2-range1)/c;
    double r = range1;
    clear_points();
    for (int i = 0; i<c; ++i) {
        add(Point(origin.x+int(int(r*xsc)/prec)*prec,
            origin.y-int(int(fct(r)*ysc)/prec)*prec));
        r += dist;
    }
}

//------------------------------------------------------------------------------

bool can_open(const string& s)
// check if a file named s exists and can be opened for reading
{
    ifstream ff(s.c_str());
    return ff.is_open();
}

//------------------------------------------------------------------------------

#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

Suffix get_encoding(const string& s)
{
    struct SuffixMap
    {
        const char*      extension;
        Suffix suffix;
        // Suffix::Encoding suffix;
    };

    static SuffixMap smap[] = {
        {".jpg",  Suffix::jpg},
        {".jpeg", Suffix::jpg},
        {".gif",  Suffix::gif},
    };

    for (int i = 0, n = ARRAY_SIZE(smap); i < n; i++)
    {
        int len = strlen(smap[i].extension);

        if (s.length() >= len && s.substr(s.length()-len, len) == smap[i].extension)
            return smap[i].suffix;
    }

    return Suffix::none;
}

//------------------------------------------------------------------------------

// somewhat over-elaborate constructor
// because errors related to image files can be such a pain to debug
Image::Image(Point xy, string s, Suffix e)
    :w(0), h(0), fn(xy,"")
{
    add(xy);

    if (!can_open(s)) {    // can we open s?
        fn.set_label("cannot open \""+s+'\"');
        p = new Bad_image(30,20);    // the "error image"
        return;
    }

    if (e == Suffix::none) e = get_encoding(s);

    switch(e) {        // check if it is a known encoding
    case Suffix::jpg:
        p = new Fl_JPEG_Image(s.c_str());
        break;
    case Suffix::gif:
        p = new Fl_GIF_Image(s.c_str());
        break;
    default:    // Unsupported image encoding
        fn.set_label("unsupported file type \""+s+'\"');
        p = new Bad_image(30,20);    // the "error image"
    }
}

//------------------------------------------------------------------------------

void Image::draw_lines() const
{
    if (fn.label()!="") fn.draw_lines();

    if (w&&h)
        p->draw(point(0).x,point(0).y,w,h,cx,cy);
    else
        p->draw(point(0).x,point(0).y);
}

//------------------------------------------------------------------------------

Binary_tree::Binary_tree(Point xy, int levels, string edge_style) : lvls(levels)
{
    if (levels<0) error("Binary_tree: levels must be at least zero");
    if (levels==0) return;  // tree ist empty
    add(xy);    // if levels==1, only root is added
    int dx = 35;    // distance between nodes on lowest level
    int dy = 100;    // distance between levels
    for (int i = 2; i<=levels; ++i) {
        for (int j = 0; j<pow(2,i-1); ++j) {
            int x = xy.x - ((pow(2,i-1)-1)/2-j) * pow(2,levels-i)*dx;
            int y = xy.y + (i-1)*dy;
            add(Point(x,y));
        }
    }

    // add lines
    for (int i = 0; i<number_of_points()/2; ++i) {
        if (edge_style=="ad") { // arrow down
            edges.push_back(new Arrow(point(i),
                Point(point(2*i+1).x,point(2*i+1).y-12)));
            edges.push_back(new Arrow(point(i),
                Point(point(2*i+2).x,point(2*i+2).y-12)));
        }
        else if (edge_style=="au") {    // arrow up
            edges.push_back(new Arrow(point(2*i+1),
                Point(point(i).x,point(i).y+12)));
            edges.push_back(new Arrow(point(2*i+2),
                Point(point(i).x,point(i).y+12)));
        }
        else {  // normal line
            edges.push_back(new Line(point(i),point(2*i+1)));
            edges.push_back(new Line(point(i),point(2*i+2)));
        }
    }

    // add label - empty for the moment
    for (int i = 0; i<number_of_points(); ++i)
        labels.push_back(new Text(Point(point(i).x+13,point(i).y-13),""));
}

//------------------------------------------------------------------------------

void Binary_tree::draw_lines() const
{
    if (color().visibility()) {
        for (int i = 0; i<edges.size(); ++i)
            edges[i].draw();

        // draw labels
        for (int i = 0; i<number_of_points(); ++i)
            labels[i].draw();

        // draw circles
        const int r = 12;
        fl_color(fl_rgb_color(192,192,192));
        for (int i = 0; i<number_of_points(); ++i)
            fl_pie(point(i).x-r,point(i).y-r,r+r-1,r+r-1,0,360);
        fl_color(color().as_int());	// reset color
        for (int i = 0; i<number_of_points(); ++i)
            fl_arc(point(i).x-r,point(i).y-r,r+r,r+r,0,360);
    }
}

//------------------------------------------------------------------------------

void Binary_tree::move(int dx, int dy)
{
    Shape::move(dx,dy);
    for (int i = 0; i<edges.size(); ++i)
        edges[i].move(dx,dy);
    for (int i = 0; i<number_of_points(); ++i)
            labels[i].move(dx,dy);
}

//------------------------------------------------------------------------------

// set label of node specified by string n to lbl. n is a sequence of l and r
// for navigating left and right in the tree
void Binary_tree::set_node_label(string n, string lbl)
{
    if (n.size()<1 || n.size()>lvls) error("set_node_label: illegal node string ",n);
    istringstream iss(n);
    char ch;
    iss.get(ch);    // look at first character
    if (n.size()==1) {
        switch (ch) {
        case 'l':
        case 'r':
            labels[0].set_label(lbl);
            return;
        default:
            error("set_node_label: illegal character in node string: ",string(1,ch));
        }
    }
    int n_idx = 0;  // node index in point list
    while (iss.get(ch)) {
        switch (ch) {
        case 'l':
            n_idx = 2*n_idx + 1;
            break;
        case 'r':
            n_idx = 2*n_idx + 2;
            break;
        default:
            error("set_node_label: illegal character in node string: ",string(1,ch));
        }
    }
    labels[n_idx].set_label(lbl);
}

//------------------------------------------------------------------------------

void Binary_tree_squares::draw_lines() const
{
    if (color().visibility()) {
        for (int i = 0; i<edges.size(); ++i)
            edges[i].draw();

        // draw labels
        for (int i = 0; i<number_of_points(); ++i)
            labels[i].draw();

        // draw squares
        const int s = 12;
        fl_color(fl_rgb_color(192,192,192));
        for (int i = 0; i<number_of_points(); ++i)
            fl_rectf(point(i).x-s,point(i).y-s,2*s,2*s);
        fl_color(color().as_int());	// reset color
        for (int i = 0; i<number_of_points(); ++i)
            fl_rect(point(i).x-s,point(i).y-s,2*s,2*s);
    }
}

//------------------------------------------------------------------------------

} // of namespace Graph_lib

