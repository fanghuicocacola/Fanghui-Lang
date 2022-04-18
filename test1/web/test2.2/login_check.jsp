<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/18
  Time: 14:39
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html; charset=UTF-8" import="java.text.DateFormat"%>
<%@ page import="java.util.Date" %>
<%@ page import="java.text.SimpleDateFormat" %>
<%! String getDate(){
    Date d = new Date();
    SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    String now = df.format(d);
    return now;
}
%>
<html>
<body>
<!--这是是一个典型的JSP，它包含了JSP中常用的各种元素-->
<%--进行登录检查--%>
<%
    String name=request.getParameter("name");
    String password=request.getParameter("password");
    // if验证通过，forward-->welcome.jsp
    //else forward-->login.jsp
    if(password.equals("jspuser"))
    {
%>
<jsp:forward page="welcome.jsp">
    <jsp:param name="user" value="<%=name%>"/>
    <jsp:param name="time" value="<%=getDate()%>"/>
</jsp:forward>
<%
} else {
        out.print("密码错误");
%>
<jsp:forward page="login.jsp">
    <jsp:param name="user" value="<%=name%>"/>
</jsp:forward>
<%}%>
</body>
</html>
