import java.util.Scanner;

public class Solution {

    public static void print(int A[],int i){
        try {
            System.out.println(A[i]);
        } catch (Exception e) {
            throw e;
        } finally {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < A.length; j++) {
                min = Math.min(min, A[j]);
                max = Math.max(max, A[j]);
            }
            System.out.println(max + " " + min);
        }
    }

    public static void main(String[] args) {
        Scanner st = new Scanner(System.in);
        int N = st.nextInt();
        int A[] = new int[N];
        for(int i = 0; i < N; i++) {
            A[i] = st.nextInt();
        }
        int i = st.nextInt();
        try {
            print(A,i);

        } catch(Exception e){
            System.out.println(e.getClass().getName());
        }

    }
}
