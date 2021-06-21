/**
 * AnagramCounter.java 
 * [Jelaskan kegunaan class ini]
 * @author 18219075 Graciella Valeska Liander
 */

import java.util.*;

public class AnagramCounter_grace {
    /**
     * Count Anagram 
     * - Menghitung jumlah kata yang memiliki anagram pada array yang sama
     * - Sebagai contoh, countAnagram(["buku", "kubu", "tikus"]) = 2
     */
    public static int countAnagram(ArrayList<String> arr) {
        int count = 0;
        for (HashMap.Entry<String, Integer> item : countOccurences(arr).entrySet()) {
            if (item.getValue()!=1) {
                count = count + item.getValue();
            }
        }
        return count;
    }

    /**
     * (Array of String) to (Array of) Sorted String
     * - Mengembalikan ArrayList dengan String yang di-sort lexicographically
     * - Sebagai contoh, toSortedString(["buku", "kubu", "tikus"]) = ["bkuu", "bkuu", "ikstu"]
     */
    public static ArrayList<String> toSortedString(ArrayList<String> arr) {
        ArrayList<String> sortedString = new ArrayList<>();
        for (String s: arr) {
            char charArray[] = s.toCharArray();
            Arrays.sort(charArray);
            sortedString.add(new String(charArray));
        }
        return sortedString;
    }

    /**
     * Count Occurences
     * - Mengembalikan HashMap berisi kemunculan dari tiap String pada ArrayList
     * - Sebagai contoh, countOccurences(["bkuu", "bkuu", "ikstu"]) = <bkuu=2, ikstu=1>
     */
    public static HashMap<String, Integer> countOccurences(ArrayList<String> arr) {
        arr = toSortedString(arr);
        HashMap<String, Integer> count = new HashMap();
        for (String c: arr) {
            if (count.containsKey(c)) {
                count.replace(c, count.get(c) + 1);
            } else {
                count.put(c, 1);
            }
        }
        return count;
    }
}