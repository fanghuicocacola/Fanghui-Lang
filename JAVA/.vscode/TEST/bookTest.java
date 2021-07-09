package TEST;
public class bookTest {
    public static void main(String[] args) {
     Book book=new Book("《小王子》","abc",34.6);
     System.out.println("书名："+book.getTitle());
     System.out.println("作者："+book.getAuthor());
     System.out.println("价格："+book.getPrice()+"元");
     }
    }
    