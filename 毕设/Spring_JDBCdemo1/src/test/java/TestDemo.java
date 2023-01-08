import com.example.Dao.BookService;
import com.example.entity.Book;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.util.ArrayList;
import java.util.List;

public class TestDemo {
    @Test
    public void testAdd(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        Book book = new Book();
        book.setUserID("1");
        book.setUserName("JAVA基础");
        book.setUStatus("J");
        bookService.addBook(book);
    }
    @Test
    public void testUpdate(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        Book book = new Book();
        book.setUserID("1");
        book.setUserName("Python基础");
        book.setUStatus("P");
        bookService.updateBook(book);
    }
    @Test
    public void testDelete(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        Book book = new Book();
        book.setUserID("1");
        bookService.deleteBook(book.getUserID());
    }
    @Test
    public void testSelect(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        int count = bookService.findCount();
        System.out.println(count);
    }
    @Test
    public void testObject(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        Book one = bookService.findOne("3");
        System.out.println(one);
    }
    @Test
    public void testList(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        List<Book> bookList = bookService.finAll();
        System.out.println(bookList);
    }

    @Test
    public void testBatchAdd(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        List<Object[]> batchArgs = new ArrayList<>();
        Object[] o1 = {"4","MySQL基础","A"};
        Object[] o2 = {"5","JavaScript基础","A"};
        Object[] o3 = {"6","Linux基础","A+"};
        batchArgs.add(o1);
        batchArgs.add(o2);
        batchArgs.add(o3);
        bookService.batchAdd(batchArgs);
    }

    @Test
    public void testBatchUpdate(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        List<Object[]> batchArgs = new ArrayList<>();
        Object[] o1 = {"MySQL基础","A+","4"};
        Object[] o2 = {"JavaScript基础","A+","5"};
        Object[] o3 = {"Linux基础","A++","6"};
        batchArgs.add(o1);
        batchArgs.add(o2);
        batchArgs.add(o3);
        bookService.batchUpdate(batchArgs);
    }

    @Test
    public void testBatchDelete(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        List<Object[]> batchArgs = new ArrayList<>();
        Object[] o1 = {"4"};
        Object[] o2 = {"5"};
        batchArgs.add(o1);
        batchArgs.add(o2);
        bookService.batchDelete(batchArgs);
    }
}
