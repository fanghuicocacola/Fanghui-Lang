package Package1;
import java.util.Scanner;

import javax.xml.namespace.QName;

class Talk{
    String name;
    int age;
    public Talk(String name,int age){
        this.name = name;
        this.age = age;
    }
    public void run(){
        System.out.println("我的名字是"+name+"我的年纪是"+age);
    }
}
public class Hello {
    public static void main(String[] args) {
        System.out.println("HelloWorld");
        Talk a = new Talk("阿辉",22);
        a.run();
        Say();
    }
    public static void Say(){
        System.out.println("Say Good");
        int a = Integer.MAX_VALUE;
        int n;
        long sum = 0;
        System.out.println("int类型的最大值为"+a);
        System.out.println("请输入若干个整数");
        Scanner reader = new Scanner(System.in);
        boolean t = reader.hasNextInt();
        while (t){
            n = reader.nextInt();
            sum += n;
            t = reader.hasNextInt();
        }
        System.out.println("和为"+sum);
    }
}
