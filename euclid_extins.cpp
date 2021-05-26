#include <fstream>
using namespace std;
ifstream in("euclid3.in");
ofstream out("euclid3.out");


void eea(int a, int b, int &d, int &x, int &y)
{
    if(b==0){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        int x0, y0;
        eea(b, a%b, d, x0, y0);
        x = y0;
        y = x0 - (a/b)*y0;
    }
}

int main()
{
    int t;
    in>>t;
    while(t--)
    {
        int coef_1, coef_2, gcd;
        int a,b,c;
        in>>a>>b>>c;
        eea(a,b,gcd,coef_1,coef_2);
        if(c%gcd==0){
            out<<coef_1*(c/gcd)<<' '<<coef_2*(c/gcd)<<'\n';
        }
        else{
            out<<0<<' '<<0<<'\n';
        }
    }

}
