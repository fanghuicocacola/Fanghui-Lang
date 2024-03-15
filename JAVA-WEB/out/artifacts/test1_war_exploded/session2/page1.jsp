<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/5/1
  Time: 21:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>选课</title>
</head>
<body>
<h3>请选择选修的课程：</h3>
<form action="page1.jsp" method ="post">
    <input type ="checkbox" name ="choice" value ="JSP">JSP<br>
    <input type ="checkbox" name ="choice" value ="PHP">PHP<br>
    <input type ="checkbox" name ="choice" value ="Java">Java<br>
    <input type ="checkbox" name ="choice" value ="C语言">C语言<br>
    <input type = "submit" value ="提交" name ="submit">
    <input type = "reset" value ="重置" name ="reset">
</form>
<%
    request.setCharacterEncoding("UTF-8");
    String[] course;
    course = request.getParameterValues("choice");
    if(course != null) {
        session.setAttribute("courseSelection", course);
        response.sendRedirect("page2.jsp");
    }
%>
</body>
</html>
