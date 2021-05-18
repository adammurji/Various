package ca.sheridancollege.tags;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@AllArgsConstructor
@NoArgsConstructor

public class Repeat extends TagSupport {
	private String input;
	private int numTimes;
	
	public int doStartTag() throws JspException{
		JspWriter out = pageContext.getOut();
		for(int x=0; x < numTimes; x++) {
			try {
			out.print(input);
			}
			catch (Exception ex) {
				
			}
		}
		return SKIP_BODY;
	}
	
}
