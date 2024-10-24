package com.cy.store.mapper;

import com.cy.store.entity.District;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.List;

@RunWith(SpringRunner.class)
@SpringBootTest
public class DistrictMapperTests {
    @Autowired
    private DistrictMapper districtMapper;

    @Test
    public void queryDistrictByParent() {
        String parent = "110100";
        List<District> list = districtMapper.queryDistrictByParent(parent);
        System.out.println("count=" + list.size());
        for (District district : list) {
            System.out.println(district);
        }
    }

    @Test
    public void queryDistrictByCode() {
        String code = "540000";
        String name = districtMapper.queryDistrictByCode(code);
        System.out.println(name);
    }
}
