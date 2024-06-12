// Exercise 7 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

// Define class arrow, which draws a line with an arrowhead

int main()
{
    using namespace Graph_lib;
    const Point x(100, 100);
    Simple_window win(x, 1000, 1000, "RGB Color Chart");

    Vector_ref<Rectangle> vr;

    const int box_w{20};
    const int box_h{20};

    /*  adding explanation below...
        <R,G,B> is tri-dimensional, a color chart is 2D
        hence a transformation <R,G,B> -> <i,j> is needed to make the plot

        4 loop variables: i,j,k,l
        <k,l> represent the rows and columns of each RGB chart. 
        Each chart has has one value for R fixed. 
        We will draw a grid ixj. In each <i,j> a colour chart kxl is drawn.

        After iterating over rows and columns of the colour chart, j is updated.

        By updating j we draw a new kxl RGB colour chart to the right
        of the previous one. Everytime j is updated, so is the R value.

        Afterwards, variable i is updated and we start drawing charts below the previous "row" of charts

        Everytime we update i, the R value is updated. For each increment in i, j has been incremented 4 times
        Thus ++i has to increment R by 5

        Analogy: 
        10 in decimal is 1*10^{1} +0*10^{0} == 9 + 1 (digits go from 0 to 9)
        R == i*5^{1}+j*5^{0} (because the digits i and j go from 0 to 4 we use a base 5)
    */ 

    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            for(int k=0; k<10; ++k)
                for(int l=0; l<10; ++l){
                    vr.push_back(new Rectangle{Point{(10*j+l)*box_w, (10*i+k)*box_h}, box_w, box_h});
                    vr[vr.size()-1].set_fill_color(fl_rgb_color(10*(5*i+j), 25*k, 25*l));
                    win.attach(vr[vr.size()-1]);
        }

    win.wait_for_button();
}