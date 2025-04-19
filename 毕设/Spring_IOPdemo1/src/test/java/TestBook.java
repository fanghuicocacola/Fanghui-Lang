import org.example.Book;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestBook {
    public static void main(String[] args){
        //1.加载spring配置文件
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        //2.获取xml配置文件创建的对象
        Book book = context.getBean("book", Book.class);
        //3.测试是否为name进行赋值
        book.test();
        book.test_2();
        book.test_3();
    }
}
