class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n == 1 || n ==2)
        {
            return true;
        }
        if(n%2 !=0 || n ==0)
        {
            return false;
        }
        int temp = n;
        while(temp != 1)
        {
            temp = temp/2;
            if(temp%2 !=0)
            {
                return false;
            }
            if(temp == 2)
            {
                return true;
            }
        }
        return false;
    }
}
