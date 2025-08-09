import java.util.*;

class Solution {
    public String findCommonResponse(List<List<String>> responses) {
        SortedMap<String, Integer> map = new TreeMap<>();
        
        for (int i = 0; i < responses.size(); i++) {
            Set<String> set = new HashSet<>();
            for (int j = 0; j < responses.get(i).size(); j++) {
                String word = responses.get(i).get(j);
                if (set.add(word)) {
                    map.put(word, map.getOrDefault(word, 0) + 1);
                }
            }
        }

        int amt = 0;
        String res = "";

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            int count = entry.getValue();
            if (count > amt) {
                amt = count;
                res = entry.getKey();
            }
        }

        return res;
    }
}
