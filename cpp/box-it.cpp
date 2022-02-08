#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    private:
        int l, b, h;
    public:
        Box(){
            l = b = h= 0;
        }
        Box(int x, int y, int z){
            l = x;
            b = y;
            h = z; 
        }
        Box(Box &B){
            l = B.l;
            b = B.b;
            h = B.h;
        }
        int getLength(){
            return l;
        }
        int getBreadth(){
            return b;
        }  
        int getHeight(){
            return h;
        }
        long long CalculateVolume(){
            return (long long)(l)*h*b;
        }
        bool operator<(Box &B){
            if(l<B.l){
                return true;
            }
            else if(b<B.b && l == B.l){
                return true;
            }
            else if(h<B.h && b==B.b && l==B.l){
                return true;
            }
            return false;
        }
};
ostream &operator<<(ostream &out, Box &B){
    out<<B.getLength()<<" "<<B.getBreadth()<<" "<<B.getHeight();
    return out;
}
