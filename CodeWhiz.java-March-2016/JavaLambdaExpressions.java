import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

interface performOperation {
    int check(int a);
}

class Math {
    public static int checker(performOperation p, int num) {
        return p.check(num);
    }

    performOperation checkEvenOdd() {
        return (int i) -> i % 2;
    }

    performOperation checkPrime() {
        return (int i) -> {
            for (int a = 2; a <= java.lang.Math.sqrt(i); a++) {
                if (i % a == 0) return 1;
            }
            return 0;
        };
    }

    performOperation checkPalindrome() {
        return (int x) -> {
            int r = 0, y = x;
            while (x > 0) {
                int n = x % 10;
                if ((Integer.MAX_VALUE - n) / 10 < r) {
                    return 1;
                }
                r = r * 10 + n;
                x /= 10;
            }
            return r == y ? 0 : 1;
        };
    }
}

public class Solution {

    public static void main(String[] args)throws IOException {
        Math ob = new Math();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        performOperation op;
        int ret = 0;
        String ans = null;
        while(T-- > 0){
            String s = br.readLine().trim();
            StringTokenizer st = new StringTokenizer(s);
            int ch = Integer.parseInt(st.nextToken());
            int num = Integer.parseInt(st.nextToken());
            if(ch == 1){
                op = ob.checkEvenOdd();
                ret = ob.checker(op,num);
                ans = (ret == 0)?"EVEN":"ODD";
            }
            else if(ch == 2){
                op = ob.checkPrime();
                ret = ob.checker(op,num);
                ans = (ret == 0)?"PRIME":"COMPOSITE";
            }
            else if(ch == 3){
                op = ob.checkPalindrome();
                ret = ob.checker(op,num);
                ans = (ret == 0)?"PALINDROME":"NOT PALINDROME";

            }
            System.out.println(ans);
        }
    }
}
