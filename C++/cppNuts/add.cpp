#include<iostream>
#include<vector>
//#include<functional>
#include<algorithm>
using namespace std;

int main(){
int total=0;
vector<int> vec = {1,2,3,4,5,6};
for_each(vec.begin(),vec.end(),[&](int x){total+=x;});
cout<<total<<endl;
}
