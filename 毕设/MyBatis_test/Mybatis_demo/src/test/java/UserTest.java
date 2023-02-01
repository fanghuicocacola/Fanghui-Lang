import com.dao.UserDao;
import com.pojo.User;
import com.utils.SqlSessionFactoryUtil;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;


import java.util.List;

public class UserTest {
    @Test
    public void test() {
        //从工具方法中获取 SqlSession
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        UserDao userDao = sqlSession.getMapper(UserDao.class);
        List<User> users = userDao.userList();
        sqlSession.commit();
        System.out.println(users);
    }
}
