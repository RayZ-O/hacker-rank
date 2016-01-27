#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

//Implement the class Box
class Box {
//l,b,h are integers representing the dimensions of the box
    int l;
    int b;
    int h;
// The class should have the following functions :
public:
// Constructors:
    Box() : l(0), b(0), h(0) {
        BoxesCreated++;
    }
    Box(int length, int breadth, int height) : l(length), b(breadth), h(height) {
        BoxesCreated++;
    }
    Box(const Box &other) : l(other.l), b(other.b), h(other.h) {
        BoxesCreated++;
    }

// Destructor
    ~Box() {
        BoxesDestroyed++;
    }

   int getLength() { // Return box's length
       return l;
   }
   int getBreadth () { // Return box's breadth
       return b;
   }
   int getHeight () {  //Return box's height
       return h;
   }
   long long CalculateVolume() { // Return the volume of the box
       return static_cast<long long>(l) * b * h;
   }

//Overload operator < as specified
   bool operator<(Box &other) {
       if (l < other.l) {
           return true;
       } else if (b < other.b && l == other.l) {
           return true;
       } else if (h < other.h && b == other.b && l == other.l) {
           return true;
       } else {
           return false;
       }
   }

//Overload operator << as specified
   friend ostream& operator<<(ostream& out, Box B) {
       out << B.l << " " << B.b << " " << B.h;
       return out;
   }
};

void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}
