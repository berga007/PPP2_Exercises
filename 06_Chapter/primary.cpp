// This file defines primary function used by calculator program
double primary()
{
    Token t = get_token();  // read next Token
    switch(t.kind){
        case '(':   // handle the case '('expression')'
            {
                double d = expression();    // read and evaluate Expression
                t = ts.get();  // read next Token from Token stream
                if (t.kind != ')') error("')' expected");
                return d;
            }
        case '8':   // digit 8 is used to represent numbers
            return t.value; // return the actual value of the number
        default:
            error("primary expected");
    }
}