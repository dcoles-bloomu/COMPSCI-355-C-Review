import java.util.ArrayList;

/**
 * Outputs text with vowels removed.
 *
 * Point of discussion: the difference between template classes in C++
 * and generics in Java. 
 *
 * @author Drue Coles
 */
public class JavaApplication3 {

    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("PICTURE YOURSELF IN A BOAT ON A RIVER");
        list.add("TANGERINE TREES AND MARMALADE SKIES");
        list.add("NEWSPAPER TAXIS APPEAR ON THE SHORE");        
        disemvowel(list);
    }
    
    /**
     * Outputs each line of text in list with vowels removed.
     */
    private static void disemvowel(ArrayList<String> list) {
        for (String str : list) {
            str = str.replaceAll("[AEIOU]", "").replaceAll("  ", " ");
            System.out.println(str);
        }
    }
}