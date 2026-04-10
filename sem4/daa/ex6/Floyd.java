import java.util.Scanner;

public class Floyd{

    static final int INF = 99999;

    static void floyd(int[][] w, int n) {
        int[][] D = new int[n][n];

        // Copy matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                D[i][j] = w[i][j];
            }
        }

        // Floyd Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (D[i][k] + D[k][j] < D[i][j]) {
                        D[i][j] = D[i][k] + D[k][j];
                    }
                }
            }
        }

        // Print result
        System.out.println("\nShortest Distance Matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(D[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int n = sc.nextInt();

        int[][] w = new int[n][n];

        System.out.println("Enter the weight matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                w[i][j] = sc.nextInt();
            }
        }

        floyd(w, n);
        sc.close();
    }
