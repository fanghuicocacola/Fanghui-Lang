package TEST;

import java.util.Scanner;

public class test2 {
    static int gcd(int a,int b){
        int temp;
        while(b>0){
            temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    } 
    static int lcm(int a,int b){
        if(a * b == 0)
            return 0;//其中一个数为0，则最小公倍数为0；
        int temp= a > b ? a : b;//取出较大的一个
        while(true)
        {
            if((temp%a==0) && (temp%b==0))//同时满足整除a和b的数即是所求
                break;      
            temp++;
        }
        return temp;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("请输入两个数");
        int m = s.nextInt();
        int n = s.nextInt();
        s.close();
        // 辗转相除法gcd
        System.out.println(gcd(n,m));
        System.out.println(lcm(n,m));
        

    }
}
