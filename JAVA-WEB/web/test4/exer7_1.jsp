<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/22
  Time: 8:32
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<% request.setCharacterEncoding("utf-8"); %>
<%@ page import="java.io.*" %>

<HTML>
<BODY bgcolor=cyan>
<span style="font-size: small; ">
    <FORM action="" method=get name=form>
        <INPUT type="text" name="number">
        <INPUT TYPE="submit" value="提交" name="submit">
    </FORM>
</span></BODY>
</HTML>
<%
    String textContent = request.getParameter("number");
    if (textContent == null) {
        out.println("请在文本框中输入数字，按提交按钮");
    }
    else {
        try{
            double n = Double.parseDouble(textContent);
            if(n>=0){
                double r=Math.sqrt(n);
                out.print("<BR>"+n+"的平方根：");
                out.print("<BR>"+r);
            }
            else{
                out.print("<BR>"+"请输入一个正数");
            }
        }
        catch(NumberFormatException e){
            out.print("<BR>"+"请输入数字字符");
        }
    }
%>
