import com.example.mapper.ParameterMapper;
import com.example.mapper.SelectMapper;
import com.example.pojo.User;
import com.example.utils.SqlSessionUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

public class SelectMapperTest {
    /*
    * MyBatis的各种查询功能
    * 1.若查询出的数据只有一条，可以通过实体类对象接收
    * a>可以通过实体类对象接收
    * b>可以通过list集合接收
    * c>
    * 2.若当前查询出的数据有多条
    * a>可以通过list集合接收
    * b>
    * 一定不能通过实体类对象接收，抛出异常TooManyResultException
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
}
