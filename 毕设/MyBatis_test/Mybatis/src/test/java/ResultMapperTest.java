import com.example.mapper.DeptMapper;
import com.example.mapper.EmpMapper;
import com.example.pojo.Dept;
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
        list.forEach(System.out::println);
    }
    @Test
    public void testGetEmpAndDept(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        EmpMapper mapper = sqlSession.getMapper(EmpMapper.class);
        Emp emp = mapper.getEmpAndDept(1);
        System.out.println(emp);
    }
    @Test
    public void testGetEmpAndDeptByStep(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        EmpMapper mapper = sqlSession.getMapper(EmpMapper.class);
        Emp emp = mapper.getEmpAndDeptByStepOne(3);
        DeptMapper mapper2 = sqlSession.getMapper(DeptMapper.class);
        Dept dept = mapper2.getEmpAndDeptByStepTwo(3);
        System.out.println(emp.getEmpName());
        System.out.println("+++++++++++++++++++++++++++");
        System.out.println(dept);
    }
    @Test
    public void testGetDeptAndEmp(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DeptMapper mapper = sqlSession.getMapper(DeptMapper.class);
        Dept dept = mapper.getDeptAndEmp(1);
        System.out.println(dept);
    }
    @Test
    public void testGetDeptAndEmpByStep(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DeptMapper mapper = sqlSession.getMapper(DeptMapper.class);
        Dept dept = mapper.getDeptAndEmpByStepOne(1);
        System.out.println(dept);
    }
}
