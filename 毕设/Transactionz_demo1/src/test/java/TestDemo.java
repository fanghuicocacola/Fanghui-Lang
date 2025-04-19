import com.example.Config.TxConfig;
import com.example.Service.UserService;
import com.example.User;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.GenericApplicationContext;

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

    //函数式风格创建对象，交给spring进行管理
    @Test
    public void testGenericApplicationContext(){
        //1 创建GenericApplicationContext对象
        GenericApplicationContext context = new GenericApplicationContext();
        //2 调用context的方法对象注册
        context.refresh();
        context.registerBean("user1",User.class,()->new User());
        //3 获取在spring注册的对象
        User user = (User) context.getBean("user1");

        System.out.println(user);
    }
}
