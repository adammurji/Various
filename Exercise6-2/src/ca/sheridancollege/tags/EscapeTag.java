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
public class EscapeTag extends TagSupport {
	private String input;
	public int doStartTag() throws JspException{
		input = input.replace("<>", "&lt;");
		input = input.replaceAll(">", "&gt;");
		
		JspWriter out = pageContext.getOut();
		try {
		out.println(input);
		}
		catch (Exception ex) {
			
		}
		return SKIP_BODY;
		
	}

}
