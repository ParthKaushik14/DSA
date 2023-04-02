#include <iostream>
using namespace std;
class hero
{
    int health;

public:

hero(){
    cout<<"default constructor called just after creating object";
}

//parameterised constructor
hero(int health)
{
   this -> health = health; 
}
    void sethealth(int h )
    {
        health = h;
    }
    int gethealth()
    {
        return health; 
    }
};
int main()
{

    hero ramesh(10 ) ; 
    hero *h = new hero(13);
    cout<< h ->gethealth();
    hero copy(*h);
    cout<< copy.gethealth();
      
   /*
    //static allocation craetion of object jjj
    hero h1;
    //dynamic allocation
    hero *b = new hero; 
    h1.sethealth(55);
    //static
    cout<<"h1 health "<<h1.gethealth()<<endl;
    //dynamic 
    b->sethealth(69);
    cout<<"b health "<<(*b).gethealth()<<endl;
 // or
    cout<<"b health "<<b->gethealth()<<endl;

    cout << sizeof(h1) << endl;
    //cout << "health is " << h1.health;
    */

    return 0;
}