import java.util.*;

public class NQueens {

    static int[] x = new int[100]; // x[row] = column

    static boolean place(int k, int i) {
        for (int j = 1; j < k; j++) {
            if (x[j] == i || Math.abs(x[j] - i) == Math.abs(j - k)) {
                return false;
            }
        }
        return true;
    }

    static void printBoard(int n) {
        for (int i = 1; i <= n; i++) {          // row
            for (int j = 1; j <= n; j++) {      // column
                if (x[i] == j)
                    System.out.print("Q ");
                else
                    System.out.print(". ");
            }
            System.out.println();
        }
    }

    static void printSolution(int n) {
        System.out.print("Solution Array : ");
        for (int i = 1; i <= n; i++) {
            System.out.print(x[i] + " ");
        }
        System.out.println();

        System.out.println("Chess Board:");
        printBoard(n);
    }

    static boolean nQueens(int k, int n) {
        for (int i = 1; i <= n; i++) {

            if (place(k, i)) {
                x[k] = i;

                if (k == n) {
                    printSolution(n);
                    return true;
                } else {
                    if (nQueens(k + 1, n))
                        return true;
                }

            } else {
                System.out.println("Backtrack at (" + k + "," + i + ")");
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("No. of Queens: ");
        int n = sc.nextInt();

        nQueens(1, n);
    }
}
