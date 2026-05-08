import java.util.*;

class Node {
    char ch;
    int freq;
    Node left, right;

    Node(char ch, int freq) {
        this.ch = ch;
        this.freq = freq;
        left = right = null;
    }
}

class HuffmanCoding {
    static Map<Character, String> huffmanCodesMap = new HashMap<>();

    static void generateCodes(Node root, String code) {
        if (root == null) return;

        if (root.left == null && root.right == null) {
            huffmanCodesMap.put(root.ch, code);
            System.out.println(root.ch + " : " + code);
        }

        generateCodes(root.left, code + "0");
        generateCodes(root.right, code + "1");
    }

    static void huffmanCodes(char[] data, int[] freq, int n) {
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.freq));

        for (int i = 0; i < n; i++) {
            pq.add(new Node(data[i], freq[i]));
        }

        while (pq.size() > 1) {
            Node left = pq.poll();
            Node right = pq.poll();

            Node merged = new Node('$', left.freq + right.freq);
            merged.left = left;
            merged.right = right;
            pq.add(merged);
        }

        System.out.println("\nGenerated Huffman Codes:");
        generateCodes(pq.peek(), "");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of characters: ");
        int n = sc.nextInt();

        char[] arr = new char[n];
        int[] freq = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter character " + (i + 1) + ": ");
            arr[i] = sc.next().charAt(0);
            System.out.print("Enter frequency for " + arr[i] + ": ");
            freq[i] = sc.nextInt();
        }

        huffmanCodes(arr, freq, n);

        System.out.print("\nEnter a string to encode (using the characters above): ");
        String input = sc.next();

        StringBuilder encodedString = new StringBuilder();
        boolean isValid = true;

        for (char c : input.toCharArray()) {
            if (huffmanCodesMap.containsKey(c)) {
                encodedString.append(huffmanCodesMap.get(c));
            } else {
                System.out.println("Error: Character '" + c + "' was not in the original set.");
                isValid = false;
                break;
            }
        }

        if (isValid) {
            System.out.println("Encoded Huffman Code: " + encodedString.toString());
        }
    }
}
