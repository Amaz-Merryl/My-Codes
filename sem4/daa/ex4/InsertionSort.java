import java.util.Scanner;
import java.util.Arrays;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Size: ");
        int[] a = new int[sc.nextInt()];

        for (int i = 0; i < a.length; i++) a[i] = sc.nextInt();

        for (int i = 1; i < a.length; i++) {
            int key = a[i], j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j--];
            }
            a[j + 1] = key;
        }
        System.out.println("Sorted..!\n");
        for(int i=0;i<a.length;i++)
        {
           System.out.print(a[i]+"  ");
        }
        System.out.println("\n");
    }
}
