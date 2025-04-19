package demo5;
import java.util.*;
public class Tokenizer {
    public static void main(String[] args) {
        String s = "We are students, hello world.Yes";
        StringTokenizer fenxi = new StringTokenizer(s,", .");
        System.out.println(fenxi.countTokens());
        while(fenxi.hasMoreTokens()){
            String a = fenxi.nextToken();
            System.out.println("切割"+a+"还剩"+fenxi.countTokens());
        }
    }
}
