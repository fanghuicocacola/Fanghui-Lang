import com.example.Config.TxConfig;
import com.example.Dao.UserDao;
import com.example.Service.UserService;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.transaction.PlatformTransactionManager;

import java.util.ArrayList;
import java.util.List;

public class TestDemo {
    @Test
    public void testAccount(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
        UserService userService = context.getBean("userService", UserService.class);
        userService.accountMoney();
    }
    @Test
    public void testAccount_2(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring2.xml");
        UserService userService = context.getBean("userService", UserService.class);
        userService.accountMoney();
    }
    @Test
    public void testAccount_3(){
        ApplicationContext context = new AnnotationConfigApplicationContext(TxConfig.class);
        UserService userService = context.getBean("userService",UserService.class);
        userService.accountMoney();
    }
}
