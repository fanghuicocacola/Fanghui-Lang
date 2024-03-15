<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<html>
<body>
<table style="color: red">
    <tr>
        <th>序号</th>
        <th>随机数</th>
    </tr>
    <%
        int max = 0;
        for(int i=0;i<=9;i++){
        int num = (int)(Math.random()*100);
        if(num >= max)
            max = num;
    %>
    <tr>
        <td>第<%=i+1%>个</td>
        <td><%=num%></td>
    </tr>
    <%}%>
</table>
获得的最大随机数为：<%=max%>
</body>
</html>