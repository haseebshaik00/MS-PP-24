#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int a, b=0, p=1;
	int lDigit=0;
	cin>>a;
	while(a>9){
		lDigit = a%10;
		if(lDigit >= 5) lDigit = 9 - lDigit;;
		b += lDigit*p;
		p *= 10;
		a /= 10;
	}
	if( a>=5 && a < 9) a = 9-a;
	b += a*p;
	cout<<b;

	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    cin >> x;
    for (auto& digit : x)
    {
        if (digit > '4')
            digit = '9' - digit + '0';
    }
    if (x.front() == '0')
        x.front() = '9';
    cout << x << endl;
    return 0;
}
