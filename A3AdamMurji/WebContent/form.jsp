<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	<form action=Controller method=post>
		<input type=text name=feedback value=feedback />
		<select name = department>
  			<option value="accounting">Accounting</option>
  			<option value="hr">HR</option>
  			<option value="security">Security</option>
  			<option value="Tech">Tech</option>
		</select> 
		<input type=submit value=sure />
	</form> 
	<c:forEach var="feedback" items="${feedbackList}">
		<c:if test="${not empty feedback }">
			<h6>${feedback.department}		${feedback.feed}		${feedback.date}</h6>
		</c:if>
	</c:forEach>
	
</body>
</html>