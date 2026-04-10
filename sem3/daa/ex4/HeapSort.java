import java.util.Scanner;
import java.util.Arrays;

public class HeapSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Size Of the Array: ");
        int[] nums = new int[sc.nextInt()];
        System.out.println("Enter the elements : \n");
        for (int i = 0; i < nums.length; i++) nums[i] = sc.nextInt();

        for (int i = nums.length / 2 - 1; i >= 0; i--) {
            heapify(nums, nums.length, i);
        }

        for (int i = nums.length - 1; i > 0; i--) {
            int temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;

            heapify(nums, i, 0);
        }
        System.out.println("Sorted..!\n");
        for(int i=0;i<nums.length;i++)
        {
           System.out.print(nums[i]+"  ");
        }
        System.out.println("\n");
    }
    static void heapify(int[] a, int size, int root) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        if (left < size && a[left] > a[largest]) largest = left;
        if (right < size && a[right] > a[largest]) largest = right;

        if (largest != root) {
            int temp = a[root];
            a[root] = a[largest];
            a[largest] = temp;
            heapify(a, size, largest);
        }
    }
}