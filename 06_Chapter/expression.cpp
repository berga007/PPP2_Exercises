// This file defines the expression function to be used by calculator program
double expression()
{
    double left = term();   // read and evaluate a Term
    Token t = ts.get();  // get the next Token from the Token stream
    while(true) {
        switch (t.kind){
            case '+':
                left += term(); // evaluate next Term and add
                t = ts.get();
                break;
            case '-':
                left -= term(); // evaluate next Term and subtract
                t = ts.get();
                break;
            default:
                ts.putback(t);  // put t back into the Token stream
                return left;    // finally no more + or - found; return the answer

        }
    }
}