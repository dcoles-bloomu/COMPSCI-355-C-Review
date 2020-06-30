import java.util.ArrayList;

/**
 * Outputs text with vowels removed.
 *
 * Point of discussion: ArrayList as a raw type.
 *
 * @author Drue Coles
 */
public class JavaApplication1 {

    public static void main(String[] args) {
        ArrayList list = new ArrayList();
        list.add("PICTURE YOURSELF IN A BOAT ON A RIVER");
        list.add("TANGERINE TREES AND MARMALADE SKIES");
        list.add("NEWSPAPER TAXIS APPEAR ON THE SHORE");        
        disemvowel(list);
    }
    
	/**
     * Outputs each line of text in list with vowels removed.
     */
    private static void disemvowel(ArrayList list) {
        for (Object obj : list) {
            String str = (String) obj;
            str = str.replaceAll("[AEIOU]", "").replaceAll("  ", " ");
            System.out.println(str);
        }
    }
}