class Person5 {
    private String name;

    private int age;

    public Person5(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // 复写父类（Object 类）中的 equals 方法
    public boolean equals(Object o) {
        boolean temp = true;
        // 声明一 p1 对象，此对象实际上就是当前调用 equals 方法的对象
        Person5 p1 = this;
        // 判断 Object 类对象是否是 Person 的实例
        if (o instanceof Person5) {
            // 如果是 Person 类实例，则进行向下转型
            Person5 p2 = (Person5) o;
            // 调用 String 类中的 equals 方法
            if (!(p1.name.equals(p2.name) && p1.age == p2.age)) {
                temp = false;
            }
        } else {
            // 如果不是 Person 类实例，则直接返回 false
            temp = false;
        }
        return temp;
    }
}

class TestOverEquals2 {
    public static void main(String[] args) {
        Person5 t_p1 = new Person5("张三", 25);
        Person5 t_p2 = new Person5("张三", 25);

        System.out.println(t_p1.equals(t_p2) ? "是同一个人！" : "不是同一个人");
    }
}
