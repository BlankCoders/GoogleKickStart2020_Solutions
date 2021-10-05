import java.util.*;

class DAGraph {

	public Map<Character, ArrayList<Character>> adjacentGraph;
	public int vertices;

	public DAGraph(int v, List<Character> chars) {
		this.vertices = v;
		this.adjacentGraph = new HashMap<>();
		for (Character ch : chars) {
			this.adjacentGraph.put(ch, new ArrayList<Character>());
		}
	}

	public void addEdge(char source, char child) {
		ArrayList<Character> ch = this.adjacentGraph.get(source);
		if (!ch.contains(child)) {
			ch.add(child);
			adjacentGraph.put(source, ch);
		}
	}
}

class Solution {
	public static List<Character> characters;

	public static void main(String[] args) throws java.lang.Exception {
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int i = 0;

		while (i < T) {
			int R = sc.nextInt();
			int C = sc.nextInt();

			characters = new ArrayList<>();
			Character[][] wall = new Character[R][C];

			for (int p = 0; p < R; p++) {
				String temp = sc.next();
				for (int c = 0; c < C; c++) {
					wall[p][c] = temp.charAt(c);
					if (!characters.contains(temp.charAt(c))) {
						characters.add(temp.charAt(c));
					}
				}
			}
			String result = checkStability(R, C, wall);
			i++;
			System.out.println("Case #" + i + ": " + result);
		}
		sc.close();
	}

	private static String checkStability(int r, int c, Character[][] wall) {
		DAGraph graph = new DAGraph(c, characters);

		for (int i = 0; i < r - 1; i++) {
			for (int j = 0; j < c; j++) {
				if (wall[i][j] != wall[i + 1][j]) {
					ArrayList<Character> temp = graph.adjacentGraph.get(wall[i + 1][j]);
					if (temp.contains(wall[i][j]))
						return "-1";
					graph.addEdge(wall[i][j], wall[i + 1][j]);
				}
			}
		}

		return topologicalSort(graph);
	}

	private static String topologicalSort(DAGraph graph) {
		Stack<Character> stack = new Stack<>();
		Map<Character, Boolean> charVisited = new HashMap<>();
		for (int i = 0; i < characters.size(); i++) {
			charVisited.put(characters.get(i), false);
		}
		for (Map.Entry element : charVisited.entrySet()) {
			Boolean visited = (Boolean) element.getValue();
			Character ch = (Character) element.getKey();
			if (!visited) {
				topologicalSortNode(charVisited, stack, graph, ch);
			}
		}
		String result = "";

		for (Character ch : stack) {
			result += String.valueOf(ch);
		}
		return result;
	}

	private static void topologicalSortNode(Map<Character, Boolean> charVisited, Stack<Character> stack, DAGraph graph,
			Character ch) {
		charVisited.put(ch, true);
		ArrayList<Character> temp = graph.adjacentGraph.get(ch);
		for (Character chars : temp) {
			Boolean var = charVisited.get(chars);
			if (!var) {
				topologicalSortNode(charVisited, stack, graph, chars);
			}
		}
		stack.push(ch);
	}
}