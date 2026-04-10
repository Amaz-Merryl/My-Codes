class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        int res=0;
        //int temp = x;
        /*int temp1 = x, count = 0;
        for(int i=0;temp1!=0;temp=temp/10)
        {
            count++;
        }*/
        for(int temp = x;temp!=0;temp=temp/10)
        {
            res = (res*10) + (temp%10);
        }
        if(res == x)
        {
            return true;
        }
        return false;
    }
}
