import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findMaximumXOR(int[] nums) {
        int maxXOR = 0;
        int mask = 0;
        for (int i = 30; i >= 0; i--) {
            mask = mask | (1 << i);
            Set<Integer> prefixes = new HashSet<>();
            for (int num : nums) {
                prefixes.add(num & mask);
            }
            int candidate = maxXOR | (1 << i);
            for (int prefix : prefixes) {
                if (prefixes.contains(prefix ^ candidate)) {
                    maxXOR = candidate; 
                    break; 
                }
            }
        }
        return maxXOR;
    }
}
