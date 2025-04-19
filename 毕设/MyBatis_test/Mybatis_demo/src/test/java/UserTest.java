import com.mapper.UserMapper;
import com.pojo.User;
import com.utils.SqlSessionFactoryUtil;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

public class UserTest {
    @Test
    public void testInsert() {
        //从工具方法中获取 SqlSession
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        //获取接口对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        //测试功能
        int result = userMapper.insertUser();
        sqlSession.commit();
        System.out.println("result:"+result);
        sqlSession.close();
    }
    @Test
    public void testUpdate(){
        //从工具方法中获取 SqlSession
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        //获取接口对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        //测试功能
        userMapper.updateUser();
        sqlSession.commit();
        sqlSession.close();
    }
    @Test
    public void testDelete(){
        //从工具方法中获取 SqlSession
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        //获取接口对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        //测试功能
        userMapper.deleteUser();
        sqlSession.commit();
        sqlSession.close();
    }
    @Test
    public void testSelect(){
        //从工具方法中获取 SqlSession
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        //获取接口对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        //测试功能
        User user = userMapper.selectUserById();
        System.out.println(user);
        sqlSession.commit();
        sqlSession.close();
    }
    @Test
    public void testSelectAll(){
        //从工具方法中获取 SqlSession
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        //获取接口对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        //测试功能
        List<User> users = userMapper.selectUserAll();
        for (User user:users){
            System.out.println(user);
        }
        sqlSession.commit();
        sqlSession.close();
    }
}
