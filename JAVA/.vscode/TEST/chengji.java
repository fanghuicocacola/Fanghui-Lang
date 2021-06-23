package TEST;

/* 1）类Student 的成员变量：sNO 表示学号； sName 表示姓名； sSex表示性别； sAge 表示年龄； sJava：表示Java课
程成绩。
   2)类Student 带参数的构造方法：在构造方法中通过形参完成对成员变量的赋值操作。
   3)类Student 的方法成员：
     getNo（）：获得学号；
     getName（）：获得姓名；
     getSex（）：获得性别；
     getAge（）获得年龄；
     getJava（）：获得Java 课程成绩
   4)根据类Student 的定义， 创建五个该类的对象，输出每个学生的信息，
   计算并输出这五个学生Java语言成绩的平均值，以及计算并输出他们Java 语言成绩的最大值和最小值。
*/
class Student {
    private String sNO;
    private String sName;
    private String sSex;
    private int sAge;
    private int sJava;

    public Student(String sNO, String sName, String sSex, int sAge, int sJava) {
        super();
        this.sNO = sNO;
        this.sName = sName;
        this.sSex = sSex;
        this.sAge = sAge;
        this.sJava = sJava;
    }

    public String getNO() {
        return sNO;
    }

    public String getName() {
        return sName;
    }

    public String getSex() {
        return sSex;
    }

    public int getAge() {
        return sAge;
    }

    public int getJava() {
        return sJava;
    }
}

public class chengji {

    public static void main(String[] args) {
        double avrage, K1, K2, K3, K4, K5;
        Student A1 = new Student("13190310", "李一", "男", 18, 80);
        Student A2 = new Student("13190311", "刘二", "女", 19, 83);
        Student A3 = new Student("13190312", "张三", "男", 19, 82);
        Student A4 = new Student("13190313", "杨四", "女", 20, 88);
        Student A5 = new Student("13190314", "韩舞", "女", 20, 90);
        K1 = A1.getJava();
        K2 = A2.getJava();
        K3 = A3.getJava();
        K4 = A4.getJava();
        K5 = A5.getJava();
        avrage = (K1 + K2 + K4 + K3 + K5) / 5;
        System.out.println("Java平均成绩:" + avrage);
        double a[] = { K1, K2, K3, K4, K5 };
        double max = 0, min = 0, ck;
        for (int i = 0; i < 4; i++) {
            max = K1;
            if (max < a[i + 1]) {
                ck = max;
                max = a[i + 1];
                a[i + 1] = ck;
            }
        }
        System.out.println("Java的最高分为:" + max);
        for (int i = 0; i < 4; i++) {
            max = K1;
            if (min > a[i + 1]) {
                ck = min;
                min = a[i + 1];
                a[i + 1] = ck;
            }
        }
        System.out.println("Java的最低分为:" + max);
    }
}
