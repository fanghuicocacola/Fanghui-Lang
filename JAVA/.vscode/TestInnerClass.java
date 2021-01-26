class Outer {
    String a = "外部";

    void OuterTalk() {
        Inner in = new Inner();
        in.InnerTalk();
    }

    class Inner {
        String b = "内部";

        void InnerTalk() {
            Outer.Inner inner = new Outer.Inner();//外部类可以被内部类访问，内部类不可以被外部类访问
            System.out.println("内部引用\t" + a);
            System.out.println(inner.b);
        }
    }
}

public class TestInnerClass {
    public static void main(String[] args) {
        Outer out = new Outer();
        out.OuterTalk();
        Outer.Inner inner2 = out.new Inner();// 内部类的调用，需要通过创建对象，在外部类之外引用
        inner2.InnerTalk();
    }
}
