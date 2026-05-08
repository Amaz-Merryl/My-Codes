import java.util.*;

class Item {
    int weight, profit, index;
    double ratio;

    Item(int weight, int profit, int index) {
        this.weight = weight;
        this.profit = profit;
        this.index = index;
        this.ratio = (double) profit / weight;
    }
}

class Node {
    int level, profit, weight;
    double bound;
    boolean[] path;

    Node(int level, int profit, int weight, int n) {
        this.level = level;
        this.profit = profit;
        this.weight = weight;
        this.path = new boolean[n];
    }
}

public class KnapsackBranchBound {

    static int n, W;
    static Item[] items;

    static double bound(Node u) {
        if (u.weight >= W)
            return 0;

        double profitBound = u.profit;
        int j = u.level + 1;
        int totalWeight = u.weight;

        while (j < n && totalWeight + items[j].weight <= W) {
            totalWeight += items[j].weight;
            profitBound += items[j].profit;
            j++;
        }

        if (j < n)
            profitBound += (W - totalWeight) * items[j].ratio;

        return profitBound;
    }

    static void knapsack() {

        Arrays.sort(items, (a, b) -> Double.compare(b.ratio, a.ratio));

        Queue<Node> q = new LinkedList<>();

        Node v = new Node(-1, 0, 0, n);
        v.bound = bound(v);
        q.add(v);

        int maxProfit = 0;
        boolean[] bestPath = new boolean[n];

        while (!q.isEmpty()) {
            v = q.poll();

            if (v.level == n - 1)
                continue;

            // Include item
            Node u = new Node(v.level + 1,
                    v.profit + items[v.level + 1].profit,
                    v.weight + items[v.level + 1].weight, n);

            u.path = v.path.clone();
            u.path[u.level] = true;

            if (u.weight <= W && u.profit > maxProfit) {
                maxProfit = u.profit;
                bestPath = u.path.clone();
            }

            u.bound = bound(u);

            if (u.bound > maxProfit)
                q.add(u);

            // Exclude item
            u = new Node(v.level + 1, v.profit, v.weight, n);
            u.path = v.path.clone();

            u.bound = bound(u);

            if (u.bound > maxProfit)
                q.add(u);
        }

        System.out.println("Maximum Profit : " + maxProfit);
        System.out.print("Chosen Items : ");

        for (int i = 0; i < n; i++) {
            if (bestPath[i]) {
                System.out.print("Item " + items[i].index + " ");
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Knapsack Capacity : ");
        W = sc.nextInt();

        System.out.print("No. of Items : ");
        n = sc.nextInt();

        items = new Item[n];

        for (int i = 0; i < n; i++) {

            System.out.print("Value of item " + (i + 1) + " : ");
            int profit = sc.nextInt();

            System.out.print("Weight of item " + (i + 1) + " : ");
            int weight = sc.nextInt();

            items[i] = new Item(weight, profit, i + 1);
        }

        knapsack();
    }
}
