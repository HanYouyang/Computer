#include "iostream"
#include <vector>
using namespace std;
long long int target_num, shredded_num;
int current_sum, best_sum;
int rejected;
vector<int> shredded;
vector<int> best_result;
vector<int>::iterator it;
int min_possible(int number) {
    int result = 0;
    while (number != 0) {
        result += number % 10;
        number = number / 10;
    }
    return result;
}
int digit(int number) {
    int result = 0;
    while (number != 0) {
        result++;
        number = number / 10;
    }
    return result;
}
int power(int i, int j){
    int result = 1;
    while(j--)
        result = result * i;
    return result;
}

void dfs(int target_num_, int shredded_num_) {
    if (min_possible(shredded_num_) > target_num_)  //全部分割都比目标值大
        return;
    if (shredded_num_ <= target_num_)  //最大（本身）值都比目标值小，直接取本身
    {
        if (current_sum + shredded_num_ == best_sum)
            rejected = 1;
        else if (current_sum + shredded_num_ > best_sum)
        {
            shredded.push_back(shredded_num_);
            best_sum = current_sum + shredded_num_;
            rejected = 0;
            best_result.clear();
            best_result.assign(shredded.begin(), shredded.end());
            shredded.pop_back();
        }

        return;
    }
    if (current_sum > target_num) //已经超过目标值
        return;
    if (shredded_num_ <= 0 || target_num_ <= 0)
        return;
    if ((current_sum == best_sum) && (best_sum != 0))
        rejected = 1;
    else if (current_sum > best_sum)
    {
        best_sum = current_sum;
        rejected = 0;
        best_result.clear();
        best_result.assign(shredded.begin(), shredded.end());
    }
    for (int i = 1; i < digit(shredded_num_); ++i)
    {
        int temp = power(10, i);
        current_sum += shredded_num_ % temp;
        shredded.push_back(shredded_num_ % temp);
        dfs(target_num_ - shredded_num_ % temp, shredded_num_ / temp);
        current_sum -= shredded_num_ % temp;
        shredded.pop_back();
    }
}
int main(int argc, char const *argv[])
{
    while (cin >> target_num >> shredded_num) {
        rejected = 0;
        shredded.clear();
        current_sum = 0;
        best_sum = 0;
        if (target_num == 0 && shredded_num == 0)
            break;
        if (min_possible(shredded_num) > target_num)
        {
            cout << "error" << endl;
            continue;
        }
        dfs(target_num, shredded_num);
        if (rejected == 1)
        {
            cout << "rejected" << endl;
            continue;
        }
        cout << best_sum;
        it = best_result.end();
        while (it != best_result.begin())
        {
            cout << " " << *(--it);
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}