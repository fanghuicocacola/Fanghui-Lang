package Package1;

public class 级数 {
    public static void main(String[] args) {
        int i = 0;
        int jc;
        double s,sum = 0;
        while (i < 20) {
            i++;
            jc = digui(i);
            s = 1.0/jc;
            sum += s;
        }
        System.out.println(sum);
    }
    public static int digui(int n) {
        if (n == 1) {
            return 1;
        }else {
            return n * digui(n - 1);
        }
    }
}

