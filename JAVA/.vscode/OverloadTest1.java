public class OverloadTest1 {
    public static int sum(int x,int y){
        return x + y;
    }
    public static long sum(long x,long y){
        return x + y;
    }
    public static double sum(double x,double y){
        return x + y;
    }
    public static void main(String[] args) {
        int x = sum(10,10);
        System.out.println(x);
    }
}
