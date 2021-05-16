import java.util.Arrays;

public class Test1 {
    private static final String S = "\n";
    public static void main(String[] args) {
        int a1[] = { 3, 7, 6, 8, 10, 5 }, a2[];
        a2 = new int[4];
        System.arraycopy(a1, 1, a2, 0, 4);
        for (int i = 0; i < a2.length; i++)
            System.out.print(a2[i] + " ");
        Arrays.sort(a2);
        System.out.print("\n 排序后 \n");
        line();
        for (int i = 0; i < a2.length; i++)
            System.out.print(a2[i] + " ");
    }

    public static void line() {
        for (int i = 0; i < 9; i++)
            System.out.print("*");
        System.out.print(S);
    }
}
