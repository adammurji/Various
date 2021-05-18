package beans;
import java.io.Serializable;
import java.time.LocalDate;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.NamedQuery;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Entity
@NamedQuery(name="Feedback.byMonth", query="from Feedback where today = :today and department = :dept")
public class Feedback implements Serializable{
	@Id
	@GeneratedValue
	private int id;
	private int today;
	private String department;
	private String feed;
	private LocalDate date;
	
	public Feedback(String department, String feed, int today, LocalDate date) {
		this.department = department;
		this.feed = feed;
		this.today = today;
		this.date = date;
	}

}
