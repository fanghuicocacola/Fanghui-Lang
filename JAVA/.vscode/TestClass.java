public class TestClass {
    // 空参构造方法
    public TestClass() {
        System.out.println("来自TestClass 空参构造方法");
    }

    // 带参构造方法
    public TestClass(String info) {
        System.out.println("来自TestClass 带参构造方法，传入参数：" + info);
    }

    // 带参构造方法(多参数)
    public TestClass(int x, int y, int z, String info) {
        System.out.println("来自TestClass 多参构造方法");
        System.out.println("the sum is : " + (x + y + z));
        System.out.println("the informathion is : " + info);
    }

}