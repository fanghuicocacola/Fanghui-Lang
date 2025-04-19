package demo5.Test;
public class FindError{
    public static void main(String[] args) {
        String str = new String("ABCD");
        boolean m = str.equals("");
        byte [] b = str.getBytes();
        String s = str.substring(1);
        char [] c = str.toCharArray();
    }
}