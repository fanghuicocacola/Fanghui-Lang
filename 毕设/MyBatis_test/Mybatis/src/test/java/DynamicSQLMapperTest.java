import com.example.mapper.DynamicSQLMapper;
import com.example.pojo.Emp;
import com.example.utils.SqlSessionUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

public class DynamicSQLMapperTest {

    /*
    * 动态SQL:
    * 1.if:根据标签中test属性所对应的表达式决定标签中的内容是否需要拼接到SQL中
    * 2.where:
    * 当where标签中有内容时,会自动生成where关键字,并且将内容前多余的and或or去掉
    * 当where标签中没有where没有内容时,此时where标签没有任何效果
    * 注意:where标签不能将其中内容后面多余的and或or去掉
    * 3.trim:
    * prefix/suffix:将trim标签内容前或后面添加指定内容
    * suffixOverrides/prefixOverrides:将trim标签内容前或后面去掉指定内容
    * 若标签中没有内容,trim标签也没有任何效果
    * 4.choose,when,otherwise,相当于if...else if...else
    * when至少要有一个，otherwise最多只能有一个
    * 5.foreach
    * */
    @Test
    public void testGetEmpByConditionTest(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DynamicSQLMapper mapper = sqlSession.getMapper(DynamicSQLMapper.class);
        List<Emp> empList = mapper.getEmpByCondition(new Emp(null,"张三",23,"","",1));
        System.out.println(empList);
    }

    @Test
    public void testGetEmpByChooseTest(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DynamicSQLMapper mapper = sqlSession.getMapper(DynamicSQLMapper.class);
        List<Emp> empList = mapper.getEmpByChoose(new Emp(null,"",null,"","",1));
        for (Emp emp:empList) {
            System.out.println(emp);
        }
    }
    @Test
    public void testGetEmpByForeachTest(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DynamicSQLMapper mapper = sqlSession.getMapper(DynamicSQLMapper.class);
        List<Emp> empList = mapper.getEmpByCondition(new Emp(null,"张三",23,"","",1));
        System.out.println(empList);
    }
}
