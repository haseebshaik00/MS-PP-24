#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // String i/o
    char *s= NULL; // null string - char pointer not pointing to anything - dangerous to handle - not a valid string - shows undefined behaviour
    string s0; // null string
    string s1="Hello", s2("ji"), s3(s2);
    string s4=s3;
    char a[] ={'j','o','\0'};
    string s5(a);
    cout<<s0<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<endl;

    // String functions
    string str, str1;
    getline(cin, str);
    cout<<str<<endl;
    cout<<str.empty()<<endl;
    cout<<str.length()<<endl;
    str.append(".");
    cout<<str<<endl;
    cout<<str[1]<<endl;
    cout<<str.compare("Apple is not a good fruit.")<<endl;
    cout<<str.find("good")<<endl;
    str.erase(0, 6);
    cout<<str<<endl;
    str.clear();
    cout<<"str = "<<str<<endl;

    // String Iterator
    string str1 = "Mango";
    for(auto it= str1.begin(); it != str1.end(); it++)
        cout<<(*it)<<endl;
    for(string::iterator it= str1.begin(); it != str1.end(); it++)
        cout<<(*it)<<endl;
    for(auto it : str1)
        cout<<it;

    string s2 = "abcd";
    cout<<s2+2; // cd

    return 0;
}
