package com.cy.store.mapper;

import com.cy.store.entity.District;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Component;

import java.util.List;

/**
 * @author hcxs1986
 * @version 1.0
 * @description: 实体类District对应的mapper接口
 * @date 2022/7/14 15:14
 */

@Mapper
@Component
public interface DistrictMapper {

    //根据父代号查询区域信息
    List<District> queryDistrictByParent(String parent);

    //根据code查询当前省市区的名称
    String queryDistrictByCode(String code);
}
