import java.util.ArrayList;

/**
 * Outputs text with vowels removed.
 *
 * Point of discussion: why generics can only be parameterized by 
 * reference types.
 *
 * @author Drue Coles
 */
public class JavaApplication2 {

    public static void main(String[] args) {
        ArrayList<Object> list = new ArrayList<>();
        list.add("PICTURE YOURSELF IN A BOAT ON A RIVER");
        list.add("TANGERINE TREES AND MARMALADE SKIES");
        list.add("NEWSPAPER TAXIS APPEAR ON THE SHORE");        
        disemvowel(list);
    }
    
    private static void disemvowel(ArrayList<Object> list) {
        for (Object obj : list) {
            String str = (String) obj;
            str = str.replaceAll("[AEIOU]", "").replaceAll("  ", " ");
            System.out.println(str);
        }
    }
}