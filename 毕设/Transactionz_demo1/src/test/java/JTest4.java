import com.example.Service.UserService;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import org.springframework.test.context.junit.jupiter.SpringJUnitConfig;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

//@ExtendWith(SpringExtension.class)
//@ContextConfiguration("classpath:spring.xml")
@SpringJUnitConfig(locations = "classpath:spring.xml")
public class JTest4 {
    @Autowired
    private UserService userService;

    @Test
    public void test(){
        userService.accountMoney();
    }
}
