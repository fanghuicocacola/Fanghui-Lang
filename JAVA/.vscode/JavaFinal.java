class Student3 extends Person {

}

public class JavaFinal {
    /**
     * Java 中声明类、属性和方法时，可使用关键字 final 来修饰。
     *  1、 final 标记的类不能被继承。final class Person 
     *  2、 final 标记的方法不能被子类复写。final public String talk() 
     *  3、 final 标记的变量（成员变量或局部变量）即为常量，只能赋值一次。final int i = 10 ;
     */
    public static void main(String[] args) {
        Student3 stu = new Student3();
        if (stu.ok() + 1 == 1) {
            System.out.println("存在");
        } else {
            System.out.println("不存在");
        }
    }

}
