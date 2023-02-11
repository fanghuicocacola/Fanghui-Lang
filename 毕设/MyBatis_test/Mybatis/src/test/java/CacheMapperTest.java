import com.example.mapper.CacheMapper;
import com.example.pojo.Emp;
import com.example.utils.SqlSessionUtils;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;

public class CacheMapperTest {
    @Test
    public void testOneCache(){
        SqlSession sqlSession1 = SqlSessionUtils.getSqlSession();
        CacheMapper mapper1 = sqlSession1.getMapper(CacheMapper.class);
        Emp emp1 = mapper1.getEmpByEid(1);
        System.out.println(emp1);

        //mapper1.insertEmp(new Emp(null,"abc",23,"男","123@qq.com",1));
        sqlSession1.clearCache();
        Emp emp2 = mapper1.getEmpByEid(1);
        System.out.println(emp2);

        CacheMapper mapper2 = sqlSession1.getMapper(CacheMapper.class);
        Emp emp3 = mapper2.getEmpByEid(1);
        System.out.println(emp3);

        SqlSession sqlSession2 = SqlSessionUtils.getSqlSession();
        CacheMapper mapper3 = sqlSession2.getMapper(CacheMapper.class);
        Emp emp4 = mapper3.getEmpByEid(1);
        System.out.println(emp4);
    }

    @Test
    public void testTwoCache(){
        try {
            InputStream is = Resources.getResourceAsStream("mybatis-config.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(is);
            SqlSession sqlSession1 = sqlSessionFactory.openSession(true);
            CacheMapper mapper1 = sqlSession1.getMapper(CacheMapper.class);
            System.out.println(mapper1.getEmpByEid(1));
            sqlSession1.close();

            SqlSession sqlSession2 = sqlSessionFactory.openSession(true);
            CacheMapper mapper2 = sqlSession2.getMapper(CacheMapper.class);
            System.out.println(mapper2.getEmpByEid(1));
            sqlSession2.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        SqlSessionUtils.getSqlSession();
    }
}
