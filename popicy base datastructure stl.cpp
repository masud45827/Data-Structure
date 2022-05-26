#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>,
                        rb_tree_tag, tree_order_statistics_node_update>;
int main() {
  int n, x;
  oset<int>st;
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> x;
      st.insert(x);
    } else if (t == 2) {
      cin >> x;
      cout << *st.find_by_order(x) << endl; // xth element
    } else {
      cin >> x;
       cout<<st.order_of_key(x)<<endl; // how many number less than x;
    }
  }
}
