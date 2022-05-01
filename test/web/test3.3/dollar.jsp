<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/18
  Time: 15:12
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page import="java.nio.FloatBuffer" %>
<%!
    public float exchange(int num, float rate){
        return (float) (num*rate);
    }
%>
<%
    String a = request.getParameter("num");
    String b = request.getParameter("rate");
    int num = 0;
    float rate = (float) 0.001;
    if(a!=null){
        num = Integer.parseInt(a);
        rate = Float.parseFloat(b);
    }
%>
<html>
<body>
<p>请输入:</p>
<form action="#" method="post" name="form">
    金额<input type="text" name="num" value="<%=request.getParameter("num")%>"><br>
    汇率<input type="text" name="rate" value="<%=request.getParameter("rate")%>"><br>
    <input type="submit" name="submit" value="开始计算">
</form>
<table width="600" border="1" cellspacing="0">
    <thead>
    <tr>
        <th>美元</th>
        <th>汇率</th>
        <th>人民币</th>
    </tr>
    </thead>
    <tbody>
    <tr>
        <%--前两行表格为示例，第三行根据输入的数添加--%>
        <td>800</td>
        <td>6.3</td>
        <td><%=exchange(800, (float) 6.3)%></td>
    </tr>
    <tr>
        <td>1860</td>
        <td>6.3</td>
        <td><%=exchange(1860, (float) 6.3)%></td>
    </tr>
    <tr>
        <td><%=num%></td>
        <td><%=rate%></td>
        <td><%=exchange(num,rate)%></td>
    </tr>
    </tbody>
</table>
<hr>

《WEB程序设计实验三》
</body>
</html>

