package newQuestion;
//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//Note:
//The solution is guaranteed to be unique. 

//每个gas station有gas[i]的 汽油  是一个cycled 环形路上的站
//从第i站开车到第第i+i站要耗费 cost[i]的汽油. eg: 0开到1就是 cost[0]
//你油箱无限大 从任意一个gas点出发 能走完一圈的起点是哪个 如果不能返回-1


public class GasStation {
//暴力法 n^2 每个加油站都当起点走一圈 试试看？ 肯定被面试官鄙视
 //巧妙地on做法
	public int canCompleteCircuit(int[] gas, int[] cost) {
	   if(gas==null||cost==null||gas.length==0||cost.length==0){
		   return -1;
	   }
	   int sum=0;   //当前驾驶的所剩油量
	   int total=0; //for循环结束后得出。一圈开下来还有多少油
	   int index=-1;
	   for(int i=0;i<gas.length;i++){
		   sum=sum+gas[i]-cost[i];
		   total=total+gas[i]-cost[i];
		   if(sum<0){ //说明从i-1开到i的路上没油了 
			   index=i; //新的起点就从i开始 
		//每次不够油就更新index,所以跑完for循环后的index是最后一次没油的地方
	 //如果total总油量够 那么 index~n 肯定是能独立跑完的 又总油量够 1~index肯定也是够
			   sum=0;  
				   }           
	   }
	   
		if(total<0){return -1;}
		return index+1; //index是下标
		
		
	    }

}
