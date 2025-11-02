import com.sun.source.tree.Tree;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        String trie = cin.next();

        int ans = 0;

        while(cin.hasNext()) {
            String str = cin.next();

            if(str.charAt(0) == trie.charAt(0)) {
                ans++;
            }
        }

        System.out.println(ans);

        cin.close();
    }

}

