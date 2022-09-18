/**
 * @file huawei_01.cpp
 * @author wangs7
 * @brief huawei01
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getNum(int x,int y){
    int z = y;
    while(x % y){
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}


int main(int argc, char const *argv[])
{
    int n;
    int x,y;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        int maxNum = max(x,y);
        int minNum=min(x,y);
        if((maxNum/getNum(maxNum,minNum))%2==0){
            cout<<"B"<<endl;
        }else{
            cout<<"A"<<endl;
        }
    }
    return 0;
    return 0;
}


