// This file defines the term function to be used by the calculator program
double term()
{
    double left = primary();    // read and evaluate a Primary
    Token t = ts.get();  // get the  next Token from the Token stream
    while(true){
        switch(t.kind){
            case '*':
                left *= primary();  // evaluate next Primary and multiply
                t = ts.get();
                break;
            case '/':
                {
                    double d = primary();   // evaluate next primary
                    if (d == 0) error("divide by zero");
                    left /= d;  // perform division
                    t = ts.get();
                    break;
                }
            default:
                ts.putback(t);  //put t back into the Token stream
                return left;
        }
    }
}