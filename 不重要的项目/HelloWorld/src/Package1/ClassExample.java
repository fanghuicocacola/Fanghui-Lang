package Package1;

class result
{
    public void getresult(int n, int ... x)
    {
        for(int i=0;i < x.length;i++){
            System.out.println(x[i]);
        }
    }
}
class Person
{
    int age;
    String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public Person(int x){
        System.out.println("有"+x+"人");
    }
}
public class ClassExample {
    public static void main(String[] args) {
        Person p1 = new Person(1);
    }
}