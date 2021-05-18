package ca.sheridancollege.tags;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;

public class CurrentDateTimeTag extends TagSupport {

	public int doStartTag() throws JspException{
		LocalDateTime now = LocalDateTime.now();
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
		String currentDateTimeFormatted = now.format(formatter);
		JspWriter out = pageContext.getOut();
		try {
		out.print(currentDateTimeFormatted);
		}
		catch (Exception ex) {
			
		}
		return SKIP_BODY;
	}
	
}
