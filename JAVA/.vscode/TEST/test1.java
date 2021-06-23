package TEST;
public class test1{
    public static void main(String[] args) {
        int sum = 0;
        int j;
        for (int i = 2; i <= 10; i++) {
            for (j = 2; j < i; j++) {
                if (i % j == 0) {
                    break;
                }
            }
            if (j == i) {
                sum += i;
            }
        }
        System.out.println(sum);
    }

}
