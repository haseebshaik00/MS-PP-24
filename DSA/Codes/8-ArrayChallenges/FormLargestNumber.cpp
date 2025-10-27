// User function template for C++
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        string s = "";
        sort(arr.begin(), arr.end(), [](int a, int b){
            string x = to_string(a), y=to_string(b);
            return x+y>y+x;
        });
        if(arr[0] == 0) return "0";
        for(auto &x: arr)
            s += to_string(x);
        return s;
    }
};