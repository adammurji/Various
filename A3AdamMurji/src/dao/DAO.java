package dao;

import java.time.LocalDate;
import java.util.List;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.hibernate.query.Query;

import beans.Feedback;

public class DAO {
	
	SessionFactory sessionFactory = new Configuration().configure("config/hibernate.cfx.xml").buildSessionFactory();
	
	public void insertFeedback(Feedback feedback) {
		Session session = sessionFactory.openSession();
		session.beginTransaction();
		session.save(feedback);
		session.getTransaction().commit();
		session.close();
	}
	
	public List<Feedback> getMonthFeedback(String dept){
		Session session = sessionFactory.openSession();
		Query query = session.getNamedQuery("Feedback.byMonth");
		LocalDate now = LocalDate.now();
		int temp = now.getMonthValue();
		
		
		query.setParameter("today", temp);
		query.setParameter("dept",dept);
		
		List<Feedback> feedbackList = query.getResultList();
		session.close();
			return feedbackList;
		
	}

}
