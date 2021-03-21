package Package1;
import java.util.Scanner;
/*class Talk{
    int year,m,d;
    public Talk(int year,int m,int d){
        this.year = year;
        this.m = m;
        this.d = d;
    }
    public void run(){
        System.out.println(year+" "+m+" "+d);
    }
}*/
public class Hello {
    public static void main(String[] args) {
        int mouth[] ={31,28,31,30,31,30,31,31,30,31,30,31};
        Say(mouth);
    }
    public static void Say(int mouth[]){
        System.out.println("请输入年");
        Scanner reader = new Scanner(System.in);
        int n = reader.nextInt();
        if(Panduan(n)){
            mouth[1] = 29;
        }
        System.out.println(n);
        System.out.println("请输入月");
        Scanner reader2 = new Scanner(System.in);
        int m = reader.nextInt();
        System.out.println(m);
        System.out.println("请输入日");
        Scanner reader3 = new Scanner(System.in);
        int d = reader.nextInt();
        System.out.println(d);
        int ss = Sum(mouth,m,d);
        System.out.println("截至今日"+n+"已经过去了"+ss+"天");
    }
    public  static boolean Panduan(int n){
        if(n%4!=0) {
            System.out.println(n + "年不是闰年");
            return false;
        }
        else if(n%100==0&&n%400!=0) {
            System.out.println(n + "年不是闰年");
            return false;
        }
        else {
            System.out.println(n + "年是闰年");
            return true;
        }
    }
    public static int Sum(int mouth[],int m,int d){
        int s = 0;
        for(int i = 0;i < m-1;i++){
            s += mouth[i];
        }
        s += d;
        return s;
    }
}
