class Student2 extends Person {
    /*
     * 当一个子类继承一父类，而子类中的方法与父类中的方法的名称，参数个数、类型都完全一致时，
     * 就称子类中的这个方法复写了父类中的方法。同理，如果子类中重复定义了父类中已有的属性，
     * 则称此子类中的属性复写了父类中的属性。
     */
    String school;
    String a;
    int n;
    private void Talk() {
        System.out.println("下面开始自我介绍");
    }
    public void Say(){
        Talk();
    }
    public Student2() {
        super.setname("张三");
        super.setage(21);
        a = super.getname();
        n = super.getage();
    }

    public void Function(String aa, int nn) {
        a = aa;
        n = nn;
    }
}

public class TestSuper {
    // super 主要的功能是完成子类调用父类中的内容，也就是调用父类中的属性或方法。
    public static void main(String[] args) {
        Student2 stu = new Student2();
        stu.Say();
        System.out.println(stu.a + stu.n);
        stu.Function("李四", 26);
        System.out.println(stu.a + stu.n);
    }
}