class Person {
    private String name;
    private int age;
    final public int ok()
    {
        return 0;
    }
    private void Talk(){
        System.out.println("我的名字是"+name+"年龄"+age);
    }
    public void Say(){
        Talk();
    }
    public void setname(String str){
        name = str;
    }
    public void setage(int n){
        age = n;
    }
    public String getname(){
        return name;
    }
    public int getage(){
        return age;
    }
    public Person(){
        System.out.println("大家好 ！");
    }
}

public class Test_class1 
{
    public static void main(String[] arcg){
        Person p1 = new Person();
        p1.setname("张三"); ;
        p1.setage(18);
        p1.Say(); 
        Person p2 = p1;
        p2.setname("李四");
        p2.setage(28);
        p2.Say();
    }
}
