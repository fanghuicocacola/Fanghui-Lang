import java.util.jar.Attributes.Name;

import javax.print.attribute.standard.PrinterInfo;

class Person1{
    Person1(String name,int age){
        System.out.println(name+age);
    }
    public void Talk(String name,int age){
        if(age >= 18){
            System.out.println(name+"已成年！必须履行刑事责任！");
        }
        else{
            System.out.println(name+"未成年！");
        }
    }
}
public class TestInit {
    public static void main(String[] args) {
        Person1 p = new Person1("张三", 18);
        p.Talk("张三", 18);
    }
}
