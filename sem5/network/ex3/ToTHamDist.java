class Solution {
    public int totalHammingDistance(int[] nums) {
        int totalDistance = 0;
        int n = nums.length;
        
        // Iterate through all 32 bit positions of an integer
        for (int i = 0; i < 32; i++) {
            int countOnes = 0;
            
            // Count how many numbers have the i-th bit set to 1
            for (int num : nums) {
                // Shift the number right by i bits and check the least significant bit
                if (((num >> i) & 1) == 1) {
                    countOnes++;
                }
            }
            
            // The number of elements with the i-th bit set to 0
            int countZeros = n - countOnes;
            
            // Add the combinations of 1s and 0s to the total distance
            totalDistance += (countOnes * countZeros);
        }
        
        return totalDistance;
    }
}
