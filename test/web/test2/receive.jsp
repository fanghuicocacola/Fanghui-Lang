<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/16
  Time: 23:35
  To change this template use File | Settings | File Templates.
--%>

<HTML>
<BODY bgcolor=cyan>
<span style="font-size: small; ">
        </span>
</BODY>
</HTML>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<%
    //从表单中获取数据

    out.print("姓名:"+request.getParameter("name"));
    out.print("<br>");
    out.print("性别:"+request.getParameter("R"));
    out.print("<br>");
    out.print("喜欢:"+request.getParameter("superstar"));
    out.print("<br>");
%>
