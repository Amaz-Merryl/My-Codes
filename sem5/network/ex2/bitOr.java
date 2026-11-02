import java.util.HashSet;
import java.util.Set;

class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> ans = new HashSet<>();
        Set<Integer> prev = new HashSet<>();
        
        for (int x : arr) {
            Set<Integer> curr = new HashSet<>();
            curr.add(x);
            for (int y : prev) {
                curr.add(x | y);
            }
            ans.addAll(curr);
            prev = curr;
        }
        
        return ans.size();
    }
}
