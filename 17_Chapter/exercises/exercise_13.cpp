// "Programming: Principles and Practice Using C++" CH 17
// Exercise 13

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <vector>

//------------------------------------------------------------------------------
std::string prompt{">>>"};

//------------------------------------------------------------------------------
struct God{
    God(std::string n, std::string myt, std::string vehi, std::string weap)
        : name{n}, mythology{myt}, vehicle{vehi}, weapon{weap} { }
    
    std::string name{};
    std::string mythology{};
    std::string vehicle{};
    std::string weapon{};
};

// overloading the output operator for god struct
std::ostream& operator<<(std::ostream& os, const God& g)
{
    os << "Name: " << g.name << " Mythology: " << g.mythology
       << " Vehicle: " << g.vehicle << " Weapon: " << g.weapon;
    
    return os;
}

//------------------------------------------------------------------------------
// doubly linked list
class Link{
public:
    God value;
    Link(const God v, Link* p=nullptr, Link* s=nullptr)
        : value{v}, prev{p}, succ{s} { }
    Link* insert(Link* n);  // insert n before this object
    Link* add(Link* n);     // insert n after this object
    Link* erase();          // remove this object from list
    Link* find(const std::string& s); // find s in list
    const Link* find (const std::string& s) const;  // find s in const list
    Link* advance(int n);   // advance n positions in list
    Link* next() const { return succ; }
    Link* previous() const{ return prev; }
    Link* add_ordered(Link* n); // add's the new element in lexicographical
                                // order
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
        if(p->value.name==s) return p;
        p = p->succ;
    }
    return nullptr;
}

//------------------------------------------------------------------------------
const Link* Link::find(const std::string& s) const
{
    const Link* p = this;
    while(p) {
        if(p->value.name==s) return p;
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
Link* Link::add_ordered(Link* n){
    // add elements lexicographically from lowest to highest like a language
    // dictionary
    // return pointer to 1st element of the list

    if(n==nullptr) return this;

    // if list is empty simply point to the link given (n)
    // set n's successor and predecessor to nullptr
    if(this==nullptr){
        n->prev = nullptr;
        n->succ = nullptr;
        return n;
    }

    Link* p = this;

    // 1st element changes
    if(n->value.name < value.name){
        return insert(n);
    }

    while(n->value.name >= p->value.name){
        // we reached the end of the list
        if(p->succ == nullptr){
            p->add(n);
            return this;
        }
        p = p->succ;
    }

    // insert n before p
    p->insert(n);
    return this;
}

//------------------------------------------------------------------------------
template<typename T> void print_element(T t, const int& width)
{
    std::cout << std::left << std::setw(width) << std::setfill(' ') << t;
}

//------------------------------------------------------------------------------
void print_all(Link* p)
{
    std::cout << "{\n";
    while(p) {
        std::cout << p->value << '\n';
        p=p->next();
    }
    std::cout << "}";
}

//------------------------------------------------------------------------------
Link* extract(Link* p, const std::string& s)
// extract god with name s from p
// erases p from the list
// returs a pointer to p
{
    Link* nl = p->find(s);
    if(nl){
        if(nl==p && p->next()) p = p->next();
        else p = nullptr;
        nl->erase();
        return nl;
    }
    else{
        return nullptr;
    }
}

//------------------------------------------------------------------------------
int main()
try
{
    // start with the norse god Freia
    Link* gods = new Link{God{"Freia", "Norse", "", ""}};
    // add Odin after Freia
    gods = gods->insert(new Link{God{"Odin", "Norse", "Eight-legged flying horse", "Spear called Gungnir"}});
    // add Thor after Odin
    gods = gods->insert(new Link{God{"Thor", "Norse", "", "Mjölnir"}});

    // now add greek gods
    gods = gods->insert(new Link{God{"Zeus", "Greek", "", "Lightning"}});
    gods = gods->insert(new Link{God{"Poseidon", "Greek", "", "Trident"}});
    gods = gods->insert(new Link{God{"Ares", "Greek", "", ""}});
    gods = gods->insert(new Link{God{"Athena", "Greek", "", ""}});

    // finally some Roman gods
    gods = gods->insert(new Link{God{"Jupiter", "Roman", "", "Thunder"}});
    gods = gods->insert(new Link{God{"Neptune", "Roman", "", "Trident"}});
    gods = gods->insert(new Link{God{"Venus", "Roman", "", ""}});
    gods = gods->insert(new Link{God{"Mars", "Roman", "", ""}});

    print_all(gods);

    std::cout << '\n';

    // build one ordered list for each mythology
    
    Link* norse_gods = nullptr;

    // find and extract from one list to another
    std::vector<std::string> nords{"Freia", "Odin", "Thor"};
    for(std::string word:nords){
        norse_gods = norse_gods->add_ordered(extract(gods, word));
    }

    Link* greek_gods = nullptr;
    std::vector<std::string> greeks{"Zeus", "Poseidon", "Ares", "Athena"};
    for(std::string w:greeks){
        greek_gods = greek_gods->add_ordered(extract(gods, w));
    }
    
    Link* roman_gods = nullptr;
    std::vector<std::string> romans{"Jupiter", "Neptune", "Venus", "Mars"};
    for(std::string w:romans){
        roman_gods = roman_gods->add_ordered(extract(gods, w));
    }

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