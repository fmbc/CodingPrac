#include <iostream>
#include <vector>
 
using namespace std;
 
void dfs(int cnt, vector<bool>& sel, bool& pass, const int N, const vector<pair<int, int>>& clauses)
{
    if (pass)
        return;
 
    if (cnt == N + 1) {
        pass = true;
        printf("1\n");
        for (int i = 0; i < cnt - 1; i++) {
            printf("%d ", sel[i] ? 1 : 0);
        }
        return;
    }
 
    for (auto& clause : clauses) {
        int a = clause.first;
        int b = clause.second;
        if (abs(a) <= cnt && abs(b) <= cnt) {
            bool ret = false;
 
            ret |= (a > 0 ? sel[abs(a) - 1] : !sel[abs(a) - 1]);
            ret |= (b > 0 ? sel[abs(b) - 1] : !sel[abs(b) - 1]);
 
            if (!ret)
                return;
        }
    }
 
    sel.push_back(true);
    dfs(cnt + 1, sel, pass, N, clauses);
    sel.pop_back();
 
    sel.push_back(false);
    dfs(cnt + 1, sel, pass, N, clauses);
    sel.pop_back();
}
 
int main(int argc, char** argv)
{
    int N, M;
    scanf("%d %d", &N, &M);
 
    vector<pair<int, int>> clauses(M);
 
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        clauses[i].first = a;
        clauses[i].second = b;
    }
 
    vector<bool> sel;
    bool pass = false;
    dfs(0, sel, pass, N, clauses);
 
    if (!pass)
        printf("0\n");
 
    return 0;
}
