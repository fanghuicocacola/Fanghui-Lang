import com.example.mapper.ParameterMapper;
import com.example.mapper.SelectMapper;
import com.example.pojo.User;
import com.example.utils.SqlSessionUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.Map;

public class SelectMapperTest {
    /*
    * MyBatis的各种查询功能
    * 1.若查询出的数据只有一条
    * a>可以通过实体类对象接收
    * b>可以通过list集合接收
    * c>可以通过mao集合接收
    * 结果:{password=123456, gender=男, name=admin3, id=3, age=23, email=12345@qq.com}
    * 2.若当前查询出的数据有多条
    * a>可以通过实体类类型的list集合接收
    * b>可以通过map类型的list集合接收
    * c>可以在mapper接口的方法上添加@MapKey注解，
    * 此时可以将每条数据转换的map集合作为值,以某个字段的值作为键，放在同一个map集合中
    * 注意：一定不能通过实体类对象接收，抛出异常TooManyResultException
    *
    * MyBatis中设置了默认的类型别名
    * */
    @Test
    public void testGetUserById(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        SelectMapper mapper = sqlSession.getMapper(SelectMapper.class);
        System.out.println(mapper.getUserById(3));
    }

    @Test
    public void testGetAllUser(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        SelectMapper mapper = sqlSession.getMapper(SelectMapper.class);
        System.out.println(mapper.getAllUser());
    }

    @Test
    public void testGetCount(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        SelectMapper mapper = sqlSession.getMapper(SelectMapper.class);
        System.out.println(mapper.getCount());
    }

    @Test
    public void testGetUserByIdToMap(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        SelectMapper mapper = sqlSession.getMapper(SelectMapper.class);
        System.out.println(mapper.getUserByIdToMap(3));
    }

    @Test
    public void testGetAllUserToMap(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        SelectMapper mapper = sqlSession.getMapper(SelectMapper.class);
        for (Map<String, Object> user:mapper.getAllUserToMap()){
            System.out.println(user);
        }
    }
}
