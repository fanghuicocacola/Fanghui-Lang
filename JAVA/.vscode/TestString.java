public class TestString{
    public static void main(String[] args) {
        String s = "人类还有希望吗";
        System.out.println(s.length());
        String a = new String("1234567890");
        String b = new String("1234567890");
        if(a == b){
            System.out.println("a和b地址相同");
        }
        else if(a.equals(b)){
            System.out.println("a和b内容相同");
        }
        else{
            System.out.println("a和b无关");
        }
    }
}