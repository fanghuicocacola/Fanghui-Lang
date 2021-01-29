abstract class Animal {
    String name;
    int age;
    public Animal(String name,int age){
        this.name = name;
        this.age = age;
    }
    public abstract void cry(); 
}

// 抽象类可以被继承
// 当继承的父类是抽象类时，需要将抽象类中的所有抽象方法全部实现。
// 当继承的父类是抽象类时，父类若有构造方法，构造方法必须被调用。
class dog extends Animal {
    public dog(String name, int age) {
        super(name, age);
    }

    // 实现父类的cry抽象方法
    public void cry() {
        System.out.println("狗叫："+name);

    }
}

public class TestAbstract {
    public static void main(String[] args) {
        dog c1 = new dog("Oscar",3);
        c1.cry();
        c1.name = "奥斯卡";
        c1.age = 3;
        c1.cry();
    }
}