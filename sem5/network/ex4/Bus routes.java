//#815 - Bus Routes

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {

        if (source == target) return 0;

        HashMap<Integer, List<Integer>> nodesToRoutes = new HashMap<>();

        Queue<Integer> routeQ = new LinkedList<>();
        Queue<Integer> nodeQ = new LinkedList<>();

        HashSet<Integer> visitedRoutes = new HashSet<>();
        HashSet<Integer> visitedNodes = new HashSet<>();

        for(int i=0;i<routes.length;i++) {
            for(int j=0;j<routes[i].length;j++) {
                if (routes[i][j] == source) {
                    routeQ.add(i);
                    visitedRoutes.add(i);
                    
                }
                nodesToRoutes.computeIfAbsent(routes[i][j], t -> new ArrayList<>()).add(i);
            }
        }
        int busChange = 1;

        while(!routeQ.isEmpty() || !nodeQ.isEmpty()) {

            //First moving from R --> N;
            if (!routeQ.isEmpty()) {
                while(!routeQ.isEmpty()) {
                    int route = routeQ.poll();

                    for(int i=0;i<routes[route].length;i++) {
                        int node = routes[route][i];
                        if (node == target) return busChange;
                        if (!visitedNodes.contains(node)) {
                            visitedNodes.add(node);
                            nodeQ.add(node);
                        }
                    }
                }
            } 
            //Then moving from N --> R
            else {
                while(!nodeQ.isEmpty()) {
                    int node = nodeQ.poll();

                    for(int route : nodesToRoutes.get(node)) {
                        if (!visitedRoutes.contains(route)) {
                            routeQ.add(route);
                            visitedRoutes.add(route);
                        }
                    }
                }

                busChange++;

            }
        }

        return -1;

        
        
    }
}
