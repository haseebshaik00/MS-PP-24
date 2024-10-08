int n,d,ans=0,badness=0;
cin>>n;
string s;
int a[n+1]={0};
for(int i=0;i<n;i++)
{
    cin>>s>>d;
    a[d]++;
}
int avail_rank = 1;
for(int i=1;i<=n;i++)
{
    while(a[i])
    {
        badness = abs(avail_rank - i);
        ans += badness;
        a[i]--;
        avail_rank++;
    }
}
cout<<ans<<endl; // Output : 5