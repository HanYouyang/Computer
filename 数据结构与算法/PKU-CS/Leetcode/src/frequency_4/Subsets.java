package frequency_4;

//Subsets

//
//Given a set of distinct integers, S, return all possible subsets.
//
//Note:
//
//    Elements in a subset must be in non-descending order.
//    The solution set must not contain duplicate subsets.
//产生一个集合的所有子集  和CC 8-3一样 
//// For example S = {1, 2, 3} then P(s) = {{}, {1}, {2}, {3}, {1,2}, {1, 3}, {2, 3}, {1, 2, 3}}.

//对于一个集合，它的子集一共有2^n 个(包括空集和它本身)。(初中数学)
//这道题目为什么可以用递归？ 因为我们能找到比原问题规模小却同质的问题。(请注意 这个思想非常重要)
//比方说 我先把1 拿出来 可以让我求2 3的子集，那么2 3的子集（2，3，  2 3）同时也是123的子集
//然后我把这个2 3的自己（2，3，23） 都把1加进去，于是就有了（1 2，1 3，123）还有 2 3 1 ，23 和空集

//所以此时 {} 1，2，3 123 和12，13，23都有了

//和cc微小不同的地方是 这题要求 所有subset内部有序，有因为在往subset里加数字的时候是由index从小到大的 所以 我们先sort一下数组
//因为这recursive是到数组最后才开始返回的 返回后才开始填数字
//然后再从后到到的加入array list

//
//和CC8_3是一样的 通过recursive来做。EG: 请注意 这题是组合 不是排列。
//(假设 给的int[]是『1，2，3，4』) 每次都是把数组的[0]留下 然后把[1…n]递归下去，
//直到最后只有一个数了（List.size=index）然后此时返回一个result arraylist<ArrayList<Integer>>[4][空] 
//		然后返回给上层 上层3再在上面返回来的2个arraylist<Integer> 里面每个都加上3，
//		再加到result里 所以此时result里就有[3,4][3][4][空]再返回给上层2,然后2把所有arraylist[Integer]里面都插入2 
//		（当然 原始返回上来的那些元素都保留的 ）
//
//此时 result里 [2，3,4][2 3][24][2 ][3,4][3][4][空] 然后 1再以此类推
import java.util.ArrayList;
import java.util.Arrays;
//九章算法模板 
public class Subsets {
    public ArrayList<ArrayList<Integer>> subsets(int[] num) {
        Arrays.sort(num);
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> list = new ArrayList<Integer>();

        subsetsHelper(result, list, num, 0);

        return result;
}


private void subsetsHelper(ArrayList<ArrayList<Integer>> result,
                ArrayList<Integer> list, int[] num, int pos) {

        result.add(new ArrayList<Integer>(list));

        for (int i = pos; i < num.length; i++) {

                list.add(num[i]);
                subsetsHelper(result, list, num, i+1);
                list.remove(list.size()-1);
        }
}


	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
