//https://www.infoarena.ro/problema/ssm
#include <fstream>
using namespace std;
ifstream in("ssm.in");
ofstream out("ssm.out");

int main()
{
    int bestsum = -(1<<31), sum = 0;
    int best_i, best_j, start;
    int n, x;
    in>>n;
    for(int k = 1; k <= n; k++){
        in>>x;

        if(sum < 0)
        /**
        if sum is negative then
        anything we add it's not
        going to yield a max sum
        */
            sum=x, start = k;

        else
            sum+=x;

        if(sum > bestsum){
            bestsum = sum;
            best_i = start;
            best_j = k;
        }
    }

    out<<bestsum<<' '<<best_i<<' '<<best_j;
}
