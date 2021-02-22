import java.util.Scanner;

public class Bundling {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCasesNumber = in.nextInt();
        for (int i = 0; i < testCasesNumber; i++){
            int n = in.nextInt();
            int k = in.nextInt();
            String[] strings = new String[n];
            for (int string = 0; string < n; string++){
                strings[string] = in.next();
            }
            System.out.printf("Case #%d: %d\n", i + 1, maxScoreSum(strings, k));
        }
    }

    public static int maxScoreSum(String[] strings, int groupSize){
        TrieNode root = new TrieNode();
        for (String word : strings){
            root.insert(word);
        }
        return root.count(groupSize); // find the max sum of scores possible
    }

    private static class TrieNode {
        private final TrieNode[] children;
        private char content;
        /**
         * The number of strings where the prefix occurred.
         */
        private int count;

        public TrieNode() {
            int count = 0;
            children = new TrieNode[26];
        }

        public TrieNode(char content){
            this();
            this.content = content;
        }

        /**
         * Inserts a new word to the trie.
         *
         * @param word  the word
         */
        public void insert(String word){
            insert(word.toCharArray(), 0);
        }

        /**
         * Inserts a word's character to the trie and updates the count.
         *
         * @param word  the word
         * @param index  the character's index
         */
        private void insert(char[] word, int index){
            if (word.length == index)
                return;
            char letter = word[index];
            if (children[letter - 'A'] == null)
                children[letter - 'A'] = new TrieNode(letter);
            children[letter - 'A'].count++;
            children[letter - 'A'].insert(word, index + 1);
        }

        /**
         * Counts the number of bundles the prefix of the trie contributed to
         * and finds the sum of this counts for all prefixes of the trie.
         *
         * @param groupSize  the group size
         * @return the sum of numbers of bundles each prefix of the trie contributed to
         */
        public int count(int groupSize){
            int generalCount = this.count / groupSize;
            for (int i = 0; i < 26; i++){
                if (children[i] != null){
                    generalCount += children[i].count(groupSize);
                }
            }
            return generalCount;
        }
    }
}
