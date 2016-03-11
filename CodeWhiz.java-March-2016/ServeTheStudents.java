import java.util.PriorityQueue;
import java.util.Scanner;

class Student {
    private int token;
    private String fname;
    private double cgpa;

    public Student(int id, String fname, double cgpa) {
        super();
        this.token = id;
        this.fname = fname;
        this.cgpa = cgpa;
    }

    public int getToken() {
        return token;
    }

    public String getFname() {
        return fname;
    }

    public double getCgpa() {
        return cgpa;
    }
}

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int totalEvents = Integer.parseInt(in.nextLine());
        PriorityQueue<Student> pq = new PriorityQueue<>(totalEvents, (Student o1, Student o2) -> {
            int cmp = Double.compare(o2.getCgpa(), o1.getCgpa());
            if (cmp != 0) {
                return cmp;
            }
            cmp = o1.getFname().compareTo(o2.getFname());
            if (cmp != 0) {
                return cmp;
            }
            return Integer.compare(o1.getToken(), o2.getToken());
        });

        while (totalEvents > 0) {
            String event = in.next();
            if (event.equals("ENTER")) {
                String name = in.next();
                double gpa = in.nextDouble();
                int token = in.nextInt();
                pq.add(new Student(token, name, gpa));
            } else if (!pq.isEmpty()) {
                Student student = pq.poll();                
            }
            totalEvents--;
        }

        if (pq.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            while (!pq.isEmpty()) {
                System.out.println(pq.poll().getFname());
            }
        }
    }
}
