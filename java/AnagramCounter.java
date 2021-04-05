/**
 * AnagramCounter.java 
 * @author 18219036 Zachrandika Alif Syahreza
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class AnagramCounter {
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
        ArrayList<String> sort = new ArrayList<>();
        for (String str: arr) {
            char charArr[] = str.toCharArray();
            Arrays.sort(charArr);
            sort.add(new String(charArr));
        }
        return sort;
    }

    /**
     * Count Occurences
     * - Mengembalikan HashMap berisi kemunculan dari tiap String pada ArrayList
     * - Sebagai contoh, countOccurences(["bkuu", "bkuu", "ikstu"]) = <bkuu=2, ikstu=1>
     */
    public static HashMap<String, Integer> countOccurences(ArrayList<String> arr) {
        arr = toSortedString(arr);
        HashMap<String, Integer> hash = new HashMap();
        for(String str :arr){
            if(hash.containsKey(str)){
                hash.replace(str, hash.get(str)+1);
            }
            else{
                hash.put(str,1);
            }
        }
        return hash;
    }
}