class TwoSum {
public:
    /*
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        /*if(nums.empty())
            nums.push_back(number);
        int i = 0;
        for(; i < nums.size(); i++)
            if(nums[i] > number)
                break;
        if(nums.size() == i)
            nums.push_back(number);
        else    
            nums.insert(nums.begin() + i, number);
        */          
        if(existNum.find(number) == existNum.end())
            existNum[number] = 1;
        else
            existNum[number]++;
    }

    /*
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        map<int, int>::iterator it;
        for(it = existNum.begin(); it != existNum.end(); it++){
            if(existNum.find(value - it->first) != existNum.end()){
                if(value - it->first == it->first){
                    if(existNum[it->first] > 1)
                        return true;
                }
                else
                    return true;
            }
            //existNum[nums[i]] = true;
        }
        return false;
    }
    map<int, int> existNum;
    vector<int> nums;
};
