#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");


int euclid(int a, int b)
{
    return b ? euclid(b, a%b) : a;
}

int main()
{
    int t, x, y;
    in>>t;

    for(int i = 0; i < t; i++)
    {
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }
}
