package Package1;

public class 随机数 {
    public static void main(String[] args) {
        int a[][] = new int[4][4];
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                a[i][j] = (int)(Math.random()*10);
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("对角线之和为"+a[0][0]+a[3][3]);
    }
}
