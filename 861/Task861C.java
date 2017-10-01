import java.util.Scanner;

public class Task861C {
    public static boolean is_vowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s; s = scanner.next();

        int state = 0;
        char[] window = {0, 0, 0};
        for (int i = 0; i != s.length(); ++i) {
            if (is_vowel(s.charAt(i))) {
                for (int j = 0; j != state; ++j) {
                    System.out.print(window[j]);

                    window[j] = 0;
                }

                state = 0;

                System.out.print(s.charAt(i));
            } else {
                if (state != 3) {
                    window[state] = s.charAt(i);

                    ++state;
                }

                if (state == 3) {
                    if (window[0] == window[1] && window[1] == window[2]) {
                        System.out.print(window[0]);

                        window[0] = window[1];
                        window[1] = window[2];

                        state = 2;
                    } else {
                        System.out.print(window[0]);
                        System.out.print(window[1]);
                        System.out.print(' ');

                        window[0] = window[2];

                        state = 1;
                    }
                }
            }
        }

        for (int j = 0; j != state; ++j) {
            System.out.print(window[j]);

            window[j] = 0;
        }

        state = 0;

        System.out.println();
    }
}
