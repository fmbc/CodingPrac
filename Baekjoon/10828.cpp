#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void){
    int N;
    cin >> N;

    stack<int> st;
    string str;

    for(int i=0; i<N; i++){
        cin >> str;
        if (str =="push"){
            int x;
            cin >> x;
            st.push(x);
        }else if(str == "pop"){
            if(!st.empty()){
                cout << st.top() << endl;
                st.pop();
            }else{
                cout << "-1" <<endl;
            }
        }else if(str =="size"){
            cout << st.size() << endl;
        }else if(str == "empty"){
            if(st.empty()) {
                cout << "1" << endl;
            }else {
                cout << "0" << endl;
            }
        }else if (str == "top"){
            if(!st.empty()){
                cout << st.top() << endl;
            }else{
                cout << "1" << endl;
            }
        }
    }
    return 0;
}