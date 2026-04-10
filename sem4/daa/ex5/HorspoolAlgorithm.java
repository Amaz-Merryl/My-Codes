import java.util.Scanner;
public class HorspoolAlgorithm {

    static void shiftTable(String p, int[] table) {
        int m = p.length();

        for (int i = 0; i < 256; i++)
            table[i] = m;

        for (int j = 0; j < m - 1; j++)
            table[(int) p.charAt(j)] = m - 1 - j;
    }

    static int horspool(String p, String t) {
        int m = p.length();
        int n = t.length();

        int[] table = new int[256];
        shiftTable(p, table);

        int i = m - 1;

        while (i <= n - 1) {
            int k = 0;

            while (k <= m - 1 && p.charAt(m - 1 - k) == t.charAt(i - k)) {
                k++;
            }

            if (k == m)
                return i - m + 1;
            else
                i = i + table[(int) t.charAt(i)];
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text;
        String pattern;
        System.out.println("Enter the text : ");
        text = sc.nextLine();
        System.out.println("Enter the Pattern : ");
        pattern = sc.nextLine();

        int pos = horspool(pattern, text);

        if (pos == -1)
            System.out.println("Pattern not Found..!");
        else
            System.out.println("Pattern found at position: " + (pos + 1));
    }
}
