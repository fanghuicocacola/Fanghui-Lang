import com.example.mapper.EmpMapper;
import com.example.pojo.Emp;
import com.example.utils.SqlSessionUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

public class ResultMapperTest {
    /*
    * 解决字段名和属性名不一致的情况
    * a>为字段起别名，保持和属性名的一致
    * b>设置全局配置，将_自动映射为驼峰
    * (mapUnderscoreToCamelCase)
    * c>通过resultMap设置自定义的映射
    *
    * */
    @Test
    public void testGetAllEmp(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        EmpMapper mapper = sqlSession.getMapper(EmpMapper.class);
        List<Emp> list = mapper.getAllEmp();
        list.forEach(emp -> System.out.println(emp));
    }
    @Test
    public void testGetEmpAndDept(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        EmpMapper mapper = sqlSession.getMapper(EmpMapper.class);
        Emp emp = mapper.getEmpAndDept(1);
        System.out.println(emp);
    }
}
