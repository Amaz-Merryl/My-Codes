class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.length, n = nums2.length;
        int start = 0, end = m;
        
        while (start <= end) {
            int i = (start + end) / 2; 
            int j = (m + n + 1) / 2 - i; 
            int maxLeft1 = (i == 0) ? Integer.MIN_VALUE : nums1[i - 1];
            int minRight1 = (i == m) ? Integer.MAX_VALUE : nums1[i];
            
            int maxLeft2 = (j == 0) ? Integer.MIN_VALUE : nums2[j - 1];
            int minRight2 = (j == n) ? Integer.MAX_VALUE : nums2[j];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 != 0) {
                    return Math.max(maxLeft1, maxLeft2);
                } 
                return (Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) / 2.0;
            } 
            else if (maxLeft1 > minRight2) {
                end = i - 1; // Move left in nums1
            } else {
                start = i + 1; // Move right in nums1
            }
        }
        return 0.0;
    }
}
