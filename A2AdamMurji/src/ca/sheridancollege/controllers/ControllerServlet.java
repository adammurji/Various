package ca.sheridancollege.controllers;

import java.io.IOException;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import ca.sheridancollege.beans.CelebOb;

/**
 * Servlet implementation class ControllerServlet
 */
@WebServlet("/ControllerServlet")
public class ControllerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	List<CelebOb> celebList = new CopyOnWriteArrayList<CelebOb>();
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ControllerServlet() {
        super();
        
		CelebOb test = new CelebOb("Paul", "Hewson", "bono@u2.com", 700000000.00);
		CelebOb test1 = new CelebOb("Stefani", "Germanotta", "lady_gaga@mtv.com", 275000000.00);
		CelebOb test2 = new CelebOb("Reginald", "Dwight", "eltonjohn@songwritersGuild.com", 450000000.00);
		celebList.add(test);
		celebList.add(test2);
		celebList.add(test1);
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
		String fName = request.getParameter("fName");
		String lName = request.getParameter("lName");
		String email = request.getParameter("email");
		double netWorth = Double.parseDouble(request.getParameter("netWorth"));
		CelebOb celeb = new CelebOb(fName, lName, email, netWorth);
		
		
		boolean present = false;
		int i = 0;
		for (CelebOb cel : celebList) {
			if (celeb.getEmail().equals(cel.getEmail())) {
				cel.setNetWorth(netWorth);
				present = true;
				celebList.set(i, cel);
			}
			i++;
		}
		if (!present)
			celebList.add(celeb);
		request.setAttribute("celebList", celebList);
		request.getRequestDispatcher("DisplayWorth").forward(request, response);
		}
		catch (Exception ex) {
			response.sendRedirect("addCelebrity.html");
		}
	}

}
