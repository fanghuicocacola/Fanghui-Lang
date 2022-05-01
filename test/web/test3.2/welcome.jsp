<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="java.util.Date" %><%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/18
  Time: 14:49
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html; charset=UTF-8" language="java" %>
恭喜你于<%=request.getParameter("time")%>时刻登录成功!<br>
欢迎你,<%=request.getParameter("name")%>!
<%@ include file="footer.jsp" %>

<%
    Date d = new Date();
    SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    String now = df.format(d);
%>

当前时间：<%=now %>
