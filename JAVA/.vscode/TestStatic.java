class Person2 {
    static String city = "江苏";
    String name;
    int age;

    public Person2(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String Talk() {
        return "我是:" + this.name + this.age + "岁,来自" + city;
    }
    static public void Setcity(String c){
        city = c;
    }
    static{
        // 静态代码块，首先被执行，且只执行一次
        System.out.println("开始自我介绍");
    }

}

public class TestStatic {
    public static void main(String[] args) {
        Person2 p1 = new Person2("张三", 18);
        Person2 p2 = new Person2("李四", 21);
        System.out.println("修改前\n"+p1.Talk()+"\n"+p2.Talk()+"\n");
        Person2.Setcity("兴化");
        System.out.println("修改后\n"+p1.Talk()+"\n"+p2.Talk()+"\n");
    }
}
