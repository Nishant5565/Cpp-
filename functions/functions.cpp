#include <iostream>
#include <vector>
using namespace std;



int main(){
    int arra[]= {1,2,3,4,5,6};
    int arrb[]={7,8,9,10};
    int sizea = 6;
    int sizeb= 4;
    vector<int> ans;
    for(int i = 0; i<sizea;i++){
        ans.push_back(arra[i]); 
    }    
    for(int i = 0; i<sizeb;i++){
        ans.push_back(arrb[i]); 
    }
    for(int i =0;i<ans.size();i++){
        cout<< ans[i] <<" ";
    }
}