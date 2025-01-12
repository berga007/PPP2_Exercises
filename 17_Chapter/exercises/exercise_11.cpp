// "Programming: Principles and Practice Using C++" CH 17
// Exercise 11

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
std::string prompt{">>>"};

//------------------------------------------------------------------------------
// doubly linked list
class Link{
public:
    std::string value;
    Link(const std::string v, Link* p=nullptr, Link* s=nullptr)
        : value{v}, prev{p}, succ{s} { }
    Link* insert(Link* n);  // insert n before this object
    Link* add(Link* n);     // insert n after this object
    Link* erase();          // remove this object from list
    Link* find(const std::string& s); // find s in list
    const Link* find (const std::string& s) const;  // find s in const list
    Link* advance(int n);   // advance n positions in list
    Link* next() const { return succ; }
    Link* previous() const{ return prev; }
private:
    Link* prev;
    Link* succ;
};

//------------------------------------------------------------------------------
Link* Link::insert(Link* n) // insert n before p; return n
{
    if(n==nullptr) return this;
    if(this==nullptr) return n;
    n->succ = this;    // this object comes after n

    if(prev) prev->succ = n;  // this object's predecessor sucessor becomes n
    n->prev = prev;  // this object's predecessor becomes n's predecessor
    prev = n;  // n becomes this predecessor
    return n;
}

//------------------------------------------------------------------------------
Link* Link::add(Link* n) // add n after p; return n
{
    // similar to insert (see exercise 11)
    if(n==nullptr) return this;
    if(this==nullptr) return n;

    n->prev = this; // n's predecessor is this object

    if(succ) succ->prev = n; // this object's sucessor's predecessor becomes n
    n->succ = succ; // this object's sucessor becomes n's sucessor
    succ = n;       // n becomes this object's successor
    return n;
    
}

//-----------------------------------------------------------------------------
Link* Link::erase()    // remove *p from list; return p's sucessor
{
    if(this==nullptr) return nullptr;
    if(succ) succ->prev = prev;
    if(prev) prev->succ = succ;
    return succ;
}

//------------------------------------------------------------------------------
Link* Link::find(const std::string& s)   // find s in list; return nullptr
                                          // for not found
{
    Link* p = this;
    while(p) {
        if(p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

//------------------------------------------------------------------------------
const Link* Link::find(const std::string& s) const
{
    const Link* p = this;
    while(p) {
        if(p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}
//------------------------------------------------------------------------------
Link* Link::advance(int n)   // move n positions in list
                             // return nullptr for not found
                             // positive moves forward, negative backward
{
    Link* p = this;
    if(p==nullptr) return nullptr;
    if(0<n){
        while(n--){
            if(p->succ == nullptr) return nullptr;
            p = p->succ;
        }
    }
    else if(n<0){
        while(n++){
            if(p->prev==nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
}

//------------------------------------------------------------------------------
void print_all(Link* p)
{
    std::cout << "{";
    while(p) {
        std::cout << p->value;
        if( (p=p->previous()) ) std::cout << ", ";
    }
    std::cout << "}";
}

//------------------------------------------------------------------------------
int main()
try{
    // start with the norse god Freia
    Link* norse_gods = new Link{"Freia"};
    // add Odin after Freia
    norse_gods = norse_gods->add(new Link {"Odin"});
    // add Thor after Odin
    norse_gods = norse_gods->add(new Link("Thor"));
  
    print_all(norse_gods);
    return 0;
}
catch(std::exception& e){
    std::cerr << e.what();
    return 1;
}
catch(...){
    std::cerr << "Something went wrong somewhere...";
    return 2;
}

//------------------------------------------------------------------------------