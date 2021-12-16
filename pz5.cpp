#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Container
{
private:
    struct s {
        T val;
        int x;
        s* nextval;
        s* prevval;
    };
    s* head;
public:
    Container(T value) {
        head = new s;
        head->val = value;
        head->x= 0;
        head->nextval = nullptr;
        head->prevval= nullptr;
    }

    Container(const Container& other) { 
        s* n = other.head;
        while (n->nextval != nullptr) {
            this->head->add(n->val);
                n = n->nextval;
        }
        this->head->add(n->val);
    }

   void add(T value) {
        s* n = head;
        s* a = new s;
        a->val = value;
        a->x= 0;
        a->nextval = nullptr;
        while (n->nextval != nullptr)
            n = n->nextval;
        n->nextval = a;
        a->prevval= n;
    }
   int search(T vle) {
        s *st = head;
        s* a = new s;
        while (st->val != vle && st->nextval != nullptr) {
            st = st->nextval;
        }
        a = st;
        if ((st->nextval == nullptr) && (st->val != vle))
            return -1;
        else {
            if ((st->prevval!= nullptr)) {
                a->x++;              
                st->prevval->nextval = st->nextval;
                s* xs = head;
                while (a->x< xs->x) {
                    xs = xs->nextval;
                }
                a->prevval= xs->prevval;
                if (xs->prevval!= nullptr)
                    xs->prevval->nextval = a;
                xs->prevval= a;
                a->nextval = xs;
                if (a->prevval== nullptr)
                    head = a;
            }
            else a->x++;
        }
            
    }
   void see() {
       s* n = head;
       while (n->nextval != nullptr) {
           cout << n->val << ' ' << n->x<< endl;
           n = n->nextval;
       }
       cout << n->val << ' ' << n->x<< endl;
   }
    ~Container() {
        s* n;
        while (head->nextval != nullptr) {
            n = head->nextval;
            delete head;
            head = n;
        }
        delete head;
    }
};


int main()
{
   Container < string > mycont("xyz");
   mycont.add("item1");
   mycont.add("item2");
   mycont.add("item3");
   mycont.search("item1");
   mycont.search("item1");
   mycont.search("item3");
   mycont.search("item1");
   mycont.search("xyz");
   mycont.see();
   return(0);
}
