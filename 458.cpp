class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int state = minutesToTest / minutesToDie + 1; //每个比特的状态数，不明白为什么加一
		//懂了，留下的理由是，最后一列可以不喝，如果活着就表明是最后一列
		//详细地说：对于minutes非整除的情况，加一是为了向上取整
		//对于整除的情况，加一是最后一列可以自然地得到结果
		
        //int state = ceil((double)minutesToTest/minutesToDie); //直接这样写会出现devide by zero异常
        int pig = ceil(log(buckets)/log(state));    //对数公式，以状态数为底取桶的对数
        return pig;
    }
};
