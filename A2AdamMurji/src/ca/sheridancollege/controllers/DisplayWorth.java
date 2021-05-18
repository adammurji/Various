package ca.sheridancollege.controllers;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import ca.sheridancollege.beans.CelebOb;

/**
 * Servlet implementation class DisplayWorth
 */
@WebServlet("/DisplayWorth")
public class DisplayWorth extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DisplayWorth() {
        super();
        
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		List<CelebOb> celebList = (List<CelebOb>) request.getAttribute("celebList");
		response.setContentType("text/html");
		response.getWriter().append("<style>" +
				"table {" +
				"border-collapse: collapse" +
				"}" +
				"td {" + 
				"border: 1px solid #dddddd;" +
				"}" +
				"tr:nth-child(even) {" +
				"background-color: #dddfff;" +
				"}" +
				"</style>" +
				"<center>" +
				"<body style=background-color:#EEEFFF;>" +
				"<h1> Alright! Let's get back to work</h1>"
				);
		
		response.getWriter().append("<table>");
		for (CelebOb celeb : celebList) {
			response.getWriter().append( "<tr>" +
					"<td>" + celeb.getFName() + "</td>" + 
					"<td>" + celeb.getLName() + "</td>" +
					"<td>" + celeb.getEmail() + "</td>" +
					"<td>" + celeb.getNetWorth() + "</td>" +
					"</tr>"
					
					);
			}
		response.getWriter().append("</table>");
		response.getWriter().append("<form method=post action=addCelebrity.html>" +
				"<input type=submit value=return>" +
				"</form>" +
				"</center>"
				
				);
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
