// 第二题
#include <iostream>
#include <vector>
#include <string>
using namespace  std;

// 先乘后加
int cal1(string s){
    vector<char> ops;
    vector<int> nums;
    int last = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+' || s[i]=='*'){
            nums.push_back(stoi(s.substr(last,i-last)));
            ops.push_back(s[i]);
            last = i+1;
        }
    }
    nums.push_back(stoi(s.substr(last)));
    vector<int> nums1;// 先算乘法
    int last_num = nums[0];
    for(int i=0;i<ops.size();i++){
        if(ops[i]=='+'){
            nums1.push_back(last_num);
            last_num = nums[i+1];
        }else if(ops[i]=='*'){
            last_num *= nums[i+1];
        }
    }
    nums1.push_back(last_num);
    int res = 0;  // 算法加法
    for(int i=0;i<nums1.size();i++){
        res+= nums1[i];
    }
    return res;

}
// 从左到右
int cal2(string s){
    vector<char> ops; // 后缀表达式
    vector<int> nums;
    int last = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+' || s[i]=='*'){
            nums.push_back(stoi(s.substr(last,i-last)));
            ops.push_back(s[i]);
            last = i+1;
        }
    }
    nums.push_back(stoi(s.substr(last)));
    int res = nums[0];
    for(int i=0;i<ops.size();i++){
        if(ops[i]=='+'){
            res += nums[i+1];
        }else if(ops[i]=='*'){
            res*=nums[i+1];
        }
    }
    return res;
}

int main(){
    // 实现两种计算顺序，比较结果
    string s;
    int n;
    cin>>s;
    cin>>n;
    int res1 = cal1(s);
    int res2 = cal2(s);
    if(res1==res2 && res2==n){
        cout<<"U"<<endl;
    }else if(res1==n){
        cout<<"M"<<endl;
    }else if(res2==n){
        cout<<"L"<<endl;
    }else{
        cout<<"I"<<endl;
    }
    return 0;

}