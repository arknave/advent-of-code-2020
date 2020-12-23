#include <bits/stdc++.h>

using namespace std;

#ifdef KACTL
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
#endif
#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int32_t, int32_t>;
using vi = vector<int32_t>;

constexpr int N = 1e6;
// constexpr int N = 10 - 1;
//constexpr int M = 100;
constexpr int M = 1e7;
struct node {
    node* right;
    int val;
} nodes[N];

bool in_chunk(node*a, node*b, int x) {
    for(node*p = a; p != b; p=p->right) {
        if(p->val==x)
            return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < N; ++i) {
        nodes[i].right = &nodes[i + 1];
        nodes[i].val = i + 1;
    }

    //string s = "389125467";
    string s = "952438716";
    for (int i = 0; i + 1 < s.size(); ++i) {
        nodes[s[i] - '0' - 1].right = &nodes[s[i + 1] - '0' - 1];
    }

    nodes[s.back() - '0' - 1].right = &nodes[s.size()];
    assert(nodes[s.size()].val == 10);
    // nodes[s.back() - '0' - 1].right = &nodes[s[0] - '0' - 1];
    nodes[N - 1].right = &nodes[s[0] - '0' - 1];
    assert(nodes[N - 1].val == N);
    assert(nodes[N - 1].right->val == s[0]-'0');

    node * head = &nodes[s[0] - '0' - 1];
    assert(head->val == s[0]-'0');
    for(int iter = 0; iter < M; ++iter) {
        /*
        bool first=true;
        for(node*p=head;first||p!=head;p=p->right){
            cout << p->val << ' ';
            first = false;
        } cout << '\n';
        */

        node* rem_start = head->right;
        node* oops = head->right->right->right;
        node* rem_end = head->right->right->right->right;

        int goal = head->val - 1;
        if (goal == 0)
            goal = N;
        while (in_chunk(rem_start, rem_end, goal)){
            goal = (goal - 1 == 0) ? N : goal - 1;
        }

        // cout << "Inserting at goal " << goal << '\n';

        // printf("After %d comes %d\n", head->val, rem_end->val);
        head->right = rem_end;
        // printf("After %d comes %d\n", oops->val, nodes[goal - 1].val);
        oops->right = nodes[goal - 1].right;
        // printf("After %d comes %d\n", nodes[goal-1].val, rem_start->val);
        nodes[goal - 1].right = rem_start;

        head = head->right;
    }
    int i = 0;
    for(node*p=&nodes[0];i<10;++i,p=p->right){
        cout << p->val << ' ';
    } cout << '\n';
    cout<< '\n';

    return 0;
}
