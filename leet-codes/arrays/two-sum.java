class Solution {
    public int[] twoSum(int[] nums, int target) {
        int temp =0;
        int[] res  = {0,0};
        for(int i=0;i<nums.length;i++){
            temp = target - nums[i];
            for(int j=i+1;j<nums.length;j++)
            {
                if(temp == nums[j]){
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
}
