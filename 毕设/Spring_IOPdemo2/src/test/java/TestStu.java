import com.example.Book;
import com.example.Stu;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestStu {
    @Test
    public void testCollection1(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        Stu stu = context.getBean("stu",Stu.class);
        stu.test();
    }

    @Test
    public void testCollection2(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        Book book = context.getBean("book",Book.class);
        book.test();
    }
}
