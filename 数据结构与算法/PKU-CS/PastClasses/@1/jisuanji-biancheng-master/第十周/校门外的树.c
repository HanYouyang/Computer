#include "iostream"
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	int L, M;
	cin >> L >> M;
	int array[M][2];
	
//输入数据
	for(int i =0 ; i< M; ++i) {  
    	for(int j = 0; j < 2; ++j) {
    		cin >> array[i][j];
    	}
    }

//对区间排序
    for(int i =0 ; i< M-1; ++i) {  
        for(int j = 0; j < M-i-1; ++j) {  
            if(array[j][0] > array[j+1][0])  
            {  
                int tmp1 = array[j][0] ; array[j][0] = array[j+1][0] ;  array[j+1][0] = tmp1;
                int tmp2 = array[j][1] ; array[j][1] = array[j+1][1] ;  array[j+1][1] = tmp2;  
            }  
        }  
    }  

 //测试排序后区间结果
    // for(int i =0 ; i< M; ++i) {  
    // 	for(int j = 0; j < 2; ++j) {
    // 		cout << setw(4) << array[i][j];
    // 	} 
    // 	cout << endl;
    // }
 
    int count = 0; //统计多少颗树被砍了
    int flag = 0;  //纪录是否要开始一个新的区间，0表示要开始，1表示合并中
    int temps = 0, tempe = 0; //纪录临时连续区间的前后端点
    for (int i = 0; i < M; i++)
    {
    	if(flag == 0)
    	{
    		temps = array[i][0]; //一段新的连续区间，将开端和终端纪录下来
    		tempe = array[i][1];
    	}    	
    	//如果在合并中，不记录开端（沿用上一个开端），但是纪录终端（如果新的终端比旧的大）
    	else {
    		if (tempe < array[i][1])
    		{
    			tempe = array[i][1];
    		}
			
    	}
    	if (i == M - 1){
    		count += tempe - temps + 1;
    	}
    	else if (tempe < array[i+1][0])
    	{
    		//当前区间与后一个区间不重合
    		tempe = array[i][1]; //连续区间的终端就是当前区间的终端
    		count += tempe - temps + 1;
    		flag = 0; //开始新的区间
    	}
    	else  //当前区间与后一个区间重合
    		flag = 1; //标记为合并区间中，继续循环，在下一个循环中尝试寻找连续区间的终端
    }
    cout << L + 1 - count;
	return 0;
}
