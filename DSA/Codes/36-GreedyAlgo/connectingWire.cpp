int n,d,ans=0;
cin>>n;
vector<int> white,black;
for(int i=0;i<n/2;i++)
{
    cin>>d;
    white.push_back(d);
}
for(int i=0;i<n/2;i++)
{
    cin>>d;
    black.push_back(d);
}
sort(white.begin(),white.end());
sort(black.begin(),black.end());
for(int i=0;i<n/2;i++)
    ans += black[i]-white[i];
cout<<ans<<endl;