package TEST;

public class test3 {
    public static void main(String[] args) {
        double h = 100;
        double H = 100.0;
        for(int i = 1;i<10;i++){
            h = h*1.0 / 2.0;
            H = H + h;
        }
        System.out.println(H);
        System.out.println(h*1.0/2);
    }
    
}
