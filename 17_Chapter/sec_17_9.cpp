// "Programming: Principles and Practice Using C++"
// Sec. 17.9.3 - 17.10.1  

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>

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
Link* add(Link* p, Link* n) // add n after p; return n
{
    // similar to insert (see exercise 11)
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
Link* Link::find(const std::string & s)   // find s in list; return nullptr
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
        if(p=p->next()) std::cout << ", ";
    }
    std::cout << "}";
}
//------------------------------------------------------------------------------
int main()
try{
    Link* norse_gods = new Link{"Thor"};
    // insert Odin before Thor
    norse_gods = norse_gods->insert(new Link {"Odin"});
    // insert Zeus before Odin
    norse_gods = norse_gods->insert(new Link("Zeus"));
    // insert Freia before Zeus
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link {"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    // correcting god of war's name
    Link* p = greek_gods->find("Mars");
    // careful p could be a nullptr
    if(p) p->value = "Ares";

    Link* p2 = norse_gods->find("Zeus");
    if(p2){
        if(p2 == norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);

    }
    print_all(norse_gods);
    std::cout << "\n";
    print_all(greek_gods);
    std::cout << "\n";
    return 0;
}
catch(std::exception& e){
    std::cerr << e.what();
    return 1;
}
catch(...){
    std::cerr<< "Unknown exception raised...";
    return 2;
}

//------------------------------------------------------------------------------