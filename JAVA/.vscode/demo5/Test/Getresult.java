package demo5.Test;

import java.util.StringTokenizer;

public class Getresult {
    public static void main(String[] args) {
        String str = "现在时间是 20:58:18";
        str = str.replaceAll("[^0 - 9:]+ ","");
        StringTokenizer fenxi = new StringTokenizer(str,":");
        int h = Integer.parseInt(fenxi.nextToken());
        int m = Integer.parseInt(fenxi.nextToken());
        int s = Integer.parseInt(fenxi.nextToken());
        System.out.printf("%d: %d: %d",h,m,s);
    }
}
