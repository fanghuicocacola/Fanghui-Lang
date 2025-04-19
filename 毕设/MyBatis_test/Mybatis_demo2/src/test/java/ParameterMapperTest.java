import com.example.mapper.ParameterMapper;
import com.example.pojo.User;
import com.example.utils.SqlSessionUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.lang.reflect.Parameter;
import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ParameterMapperTest {
    @Test
    public void testGetAllUser(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        ParameterMapper mapper = sqlSession.getMapper(ParameterMapper.class);
        List<User> list = mapper.getAllUser();
        list.forEach(user -> System.out.println(user));
    }
    /*
    * MyBatis获取参数值的两种方式：${}和#{}
    * ${}本质是字符串拼接
    * #{}本质是占位符赋值
    * MyBatis获取参数值的各种情况:
    * 1.mapper接口方法的参数为单个的字面量案例
    * 可以通过${}和#{}以任意的字符串获取参数值，但是需要注意${}的单引号问题
    * 2.mapper接口方法的参数为多个时
    *此时MyBatis会将这些参数放在一个map集合中，以两种方式进行存储
    * a>以agr0，arg1...为键，以参数为值
    * b>以param1，param2...为键，以参数为值
    * c>两者混用
    * 因此只需要通过#{}和${}以键的方式访问值即可，但是需要注意${}的单引号问题
    * 3.若mapper接口的方法的参数有多个时,可以手动将这些参数放在一个map中存储
    * 4.若mapper接口的方法的参数是实体类类型的参数时
    * 5.使用@Param注解命名参数
    * 此时MyBatis会将这些参数放在一个map集合中，以两种方式进行存储
    * a>以@Param为键,以参数为值
    * b>以param1，param2...为键，以参数为值
    *  * */

    @Test
    public void testJDBC() throws Exception{
        String name = "张三";
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/user_db?characterEncoding=utf8&serverTimezone=UTC&useSSL=false","root","123456");
        PreparedStatement ps = connection.prepareStatement("select * from t_user where name = ?");
        ps.setString(1,name);
        System.out.println(ps);
    }

    @Test
    public void testGetUserByName(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        ParameterMapper mapper = sqlSession.getMapper(ParameterMapper.class);
        User user = mapper.getUserByName("admin");
        System.out.println(user);
    }

    @Test
    public void testCheckLogin(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        ParameterMapper mapper = sqlSession.getMapper(ParameterMapper.class);
        User user = mapper.checkLogin("张三","123456");
        System.out.println(user);
    }

    @Test
    public void testCheckLoginByMap(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        ParameterMapper mapper = sqlSession.getMapper(ParameterMapper.class);
        Map<String,Object> map = new HashMap<>();
        map.put("name","admin");
        map.put("password","123456");
        User user = mapper.checkLoginByMap(map);
        System.out.println(user);
    }

    @Test
    public void testInsertUser(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        ParameterMapper mapper = sqlSession.getMapper(ParameterMapper.class);
        User user1 = new User(4,"李四","123456",25,"男","234@qq.com");
        int result = mapper.insertUser(user1);
        System.out.println(result);
    }

    @Test
    public void testCheckLoginByParam(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        ParameterMapper mapper = sqlSession.getMapper(ParameterMapper.class);
        User user = mapper.checkLoginByParam("admin","123456");
        System.out.println(user);
    }
}
