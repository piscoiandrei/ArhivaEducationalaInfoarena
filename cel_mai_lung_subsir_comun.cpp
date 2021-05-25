#include <fstream>
#include <stack>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define MAX 1030


short int mat[MAX][MAX];
short int X[MAX], Y[MAX], T[MAX];

void LCS(int m, int n)
{
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(X[i]==Y[j])
                mat[i][j] = 1 + mat[i-1][j-1];
            else
                // equivalent of: mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
                mat[i][j] = (mat[i-1][j] > mat[i][j-1])? mat[i-1][j] : mat[i][j-1];

}

void reconstruct(int i, int j)
{
    stack<int> solution;

    while(i&&j)
    {
        if(mat[i][j] > mat[i][j-1] && mat[i][j] > mat[i-1][j]){
            solution.push(X[i]);
            --i; --j;
        }
        else
            if(mat[i-1][j] == mat[i][j]){
                --i;
            }
            else if(mat[i][j-1] == mat[i][j]){
                --j;
            }
    }
    while(!solution.empty()){
        out<<solution.top()<<' ';
         solution.pop();
    }
}


int main()
{
    int m, n;
    in>>m>>n;
    for(int i = 1; i <= m; i++)
        in>>X[i];
    for(int i = 1; i <= n; i++)
        in>>Y[i];

    LCS(m,n);
    out<<mat[m][n]<<'\n';
    reconstruct(m,n);


    return 0;
}
