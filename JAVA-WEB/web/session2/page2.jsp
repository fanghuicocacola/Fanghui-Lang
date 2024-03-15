<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/5/1
  Time: 21:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>选课结果</title>
</head>
<body>
你选择的课程为：<p>
    <%
        String[] a = (String[]) session.getAttribute("courseSelection");
        for(int i = 0;i<=a.length-1;i++)
            out.print(a[i]+"<br>");
    %>
</p>
    <a href="page1.jsp">返回重新选择</a>
</body>
</html>
