package Controller;

import java.io.IOException;
import java.time.LocalDate;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import beans.Feedback;
import dao.DAO;

/**
 * Servlet implementation class Controller
 */
@WebServlet("/Controller")
public class Controller extends HttpServlet {
	private static final long serialVersionUID = 1L;
       DAO dao = new DAO();
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Controller() {
        super();
        LocalDate now = LocalDate.now();
        System.out.println(now);
        int month = now.getMonthValue();
        Feedback f1 = new Feedback("Tech","terrible", month,now);
        Feedback f3 = new Feedback("Tech", "But I do", month, now);
        Feedback f4 = new Feedback("Not Tech", "I'm here", month, now);
        now = now.minusMonths(2);
        Feedback f2 = new Feedback("Tech", "I don't exist", now.getMonthValue(), now);
        dao.insertFeedback(f1);
        dao.insertFeedback(f3);
        dao.insertFeedback(f2);
        dao.insertFeedback(f4);
        
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.getRequestDispatcher("form.jsp").forward(request, response);
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String feedback = request.getParameter("feedback");
		String department = request.getParameter("department");
		LocalDate now = LocalDate.now();
		Feedback NEW = new Feedback(department, feedback, now.getMonthValue(), now);
		dao.insertFeedback(NEW);
		List<Feedback> feedbackList = dao.getMonthFeedback(department);
		request.setAttribute("feedbackList", feedbackList);
		request.getRequestDispatcher("form.jsp").forward(request, response);
	}

}
