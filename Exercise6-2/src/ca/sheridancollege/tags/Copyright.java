package ca.sheridancollege.tags;

import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;

public class Copyright extends TagSupport {
	
	public int doStartTag() throws JspException{
		JspWriter out = pageContext.getOut();
		LocalDate now = LocalDate.now();
		LocalDate parsed = LocalDate.
		
		try {
			out.print("<hr />&copy; AdamMurji" + now);
		}
		catch(IOException ex) {
			
		}
		return SKIP_BODY;
	}

}
