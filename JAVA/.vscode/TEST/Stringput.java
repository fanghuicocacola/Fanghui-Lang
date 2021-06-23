package TEST;

import java.io.BufferedReader;
import java.io.InputStreamReader;
/*
编写一个Java 应用程序，从键盘读取用户输入两个字符串，并重载3个函数分别实现
这两个字符串的拼接、整数相加和浮点数相加。要进行异常处理，对输入的不符合要求的
字符串提示给用户，不能使程序崩溃。
*/
public class Stringput {

    public static void main(String[] args) {

        String s1 = null, s2 = null, ss, si, sf;
        int i1, i2;
        float f1, f2;
        BufferedReader strin = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.print("请输入第一个字符串：");
            s1 = strin.readLine();// 按行读取，当读到流的末尾时返回null
            System.out.print("请输入第二个字符串：");
            s2 = strin.readLine();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try {
            i1 = Integer.parseInt(s1);
            i2 = Integer.parseInt(s2);
            f1 = Float.parseFloat(s1);
            f2 = Float.parseFloat(s2);
            ss = strAdd(s1, s2);
            si = strAdd(i1, i2);
            sf = strAdd(f1, f2);
            System.out.println("输入的两个字符串相加结果为：" + ss);
            System.out.println("输入的两个字符串转换成整数相加结果为：" + si);
            System.out.println("输入的两个字符串转换成浮点数相加结果为：" + sf);
        } catch (Exception e) {
            System.out.println("输入的不合法，请重新输入！");
        }

    }

    static String strAdd(String str1, String str2) {
        return str1 + str2;
    }

    static String strAdd(int i1, int i2) {
        return String.valueOf(i1 + i2);
    }

    static String strAdd(float f1, float f2) {
        return String.valueOf(f1 + f2);
    }
}
