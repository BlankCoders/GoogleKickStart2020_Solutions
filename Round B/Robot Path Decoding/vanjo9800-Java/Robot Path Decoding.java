import java.io.*;
import java.text.*;
import java.util.*;

public class Solution {

  public static class Pair<T1, T2> {
    private T1 first;
    private T2 second;

    public Pair(T1 first, T2 second) {
      this.first = first;
      this.second = second;
    }

    public T1 getFirst() {
      return this.first;
    }

    public T2 getSecond() {
      return this.second;
    }

    public void setFirst(T1 first) {
      this.first = first;
    }

    public void setSecond(T2 second) {
      this.second = second;
    }
  }

  private static final Long MOD = 1000000000L;

  private static Pair<Long, Long> process_command(InputStream commands)
    throws IOException {
    // No commands to process if we have finished the command string
    if (commands.available() == 0) {
      return new Pair<Long, Long>(0l, 0l);
    }
    // Otherwise process current command
    Pair<Long, Long> displacement = new Pair<Long, Long>(0l, 0l);

    Integer times = 0;
    // Try to extract a number
    char currentSymbol = (char) commands.read();
    while (Character.isDigit(currentSymbol)) {
      times *= 10;
      times += currentSymbol - '0';
      currentSymbol = (char) commands.read();
    }
    if (currentSymbol == '(') {
      // If we were able to extract a number and see an opening bracket '(',
      // it means we have a repeating command
      displacement = process_command(commands);
      // Multiply by the repetition index
      displacement.setFirst(displacement.getFirst() * times);
      displacement.setSecond(displacement.getSecond() * times);
    } else {
      // If number extraction was not successful, the symbol must be any of these
      switch (currentSymbol) {
        case 'N':
          displacement = new Pair<Long, Long>(0l, -1l);
          break;
        case 'S':
          displacement = new Pair<Long, Long>(0l, 1l);
          break;
        case 'E':
          displacement = new Pair<Long, Long>(1l, 0l);
          break;
        case 'W':
          displacement = new Pair<Long, Long>(-1l, 0l);
          break;
        case ')':
          return new Pair<Long, Long>(0l, 0l);
      }
    }
    // Get the next command in the sequence
    Pair<Long, Long> following = process_command(commands);

    // Apply the modulus to simulate the torus
    displacement.setFirst(displacement.getFirst() + following.getFirst() + MOD);
    displacement.setSecond(
      displacement.getSecond() + following.getSecond() + MOD
    );
    displacement.setFirst(displacement.getFirst() % MOD);
    displacement.setSecond(displacement.getSecond() % MOD);

    return displacement;
  }

  public static void main(String[] args) throws IOException {
    Scanner scan = new Scanner(System.in);
    int T = scan.nextInt();
    scan.nextLine();
    for (int i = 0; i < T; i++) {
      String commands = scan.nextLine();
      // Turn command into stream for easier parsing
      InputStream commandStream = new ByteArrayInputStream(commands.getBytes());
      
      // Process the whole command
      Pair<Long, Long> displacement = process_command(commandStream);

      // Add start from (1,1)
      displacement.setFirst(displacement.getFirst() + 1);
      displacement.setSecond(displacement.getSecond() + 1);

      System.out.println(
        "Case #" +
        (i + 1) +
        ": " +
        displacement.getFirst() +
        " " +
        displacement.getSecond()
      );
    }
  }
}
