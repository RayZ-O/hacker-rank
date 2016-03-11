import java.util.BitSet;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        BitSet[] Bs = new BitSet[2];
        Bs[0] = new BitSet(n);
        Bs[1] = new BitSet(n);
        while (m-- > 0) {
            String op = sc.next();
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (op.equals("AND")) {
                Bs[x-1].and(Bs[y-1]);
            } else if (op.equals("SET")) {
                Bs[x-1].set(y);
            } else if (op.equals("FLIP")) {
                Bs[x-1].flip(y);
            } else if (op.equals("OR")) {
                Bs[x-1].or(Bs[y-1]);
            } else if (op.equals("XOR")) {
                Bs[x-1].xor(Bs[y-1]);
            }
            System.out.println(Bs[0].cardinality() + " " + Bs[1].cardinality());
        }
    }
}
