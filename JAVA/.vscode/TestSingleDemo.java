class Person3 {
    String name;
    // 在本类声明一 Person 对象 p，注意此对象用 final 标记，表示不能再重新实例化
    private static final Person3 p = new Person3();

    private Person3() {
        name = "张三";
    }

    public static Person3 getP() {
        return p;
    }
}

public class TestSingleDemo {
    public static void main(String[] args) {
        Person3 p = Person3.getP();
        System.out.println(p.name);
    }
}
