import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Arrays;

public class write_file {

    private static String USAGE_MSG = "usage: write_file <file_size>[kb|mb|gb] <buf_size>[kb|mb|gb]\n";

    private static int sizeInBytes(String multiBytes) {
        if (multiBytes == null) {
            System.err.println(USAGE_MSG);
            System.exit(1);
        }

        if (!multiBytes.matches("[0-9]+([kmg]b)?")) {
            System.err.println(USAGE_MSG);
            System.exit(1);
        }

        int multi = 1;

        if (multiBytes.charAt(multiBytes.length() - 1) != 'b') return Integer.parseInt(multiBytes);

        switch (multiBytes.charAt(multiBytes.length() - 2)) {
          case 'g': multi *= 1024;
          case 'm': multi *= 1024;
          case 'k': multi *= 1024;
          default:
            if (multi > 1) {
              return multi * Integer.parseInt(multiBytes.substring(0, multiBytes.length() - 2));
            } else {
              System.err.println(USAGE_MSG);
              System.exit(1);
            }
        }

        return -1;
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 2) {
            System.err.println(USAGE_MSG);
            System.exit(1);
        }

        int fileSize = sizeInBytes(args[0]);
        int buffSize = sizeInBytes(args[1]);

        char[] buffer = new char[buffSize];
        Arrays.fill(buffer, (char) 1);

        BufferedWriter writer = new BufferedWriter(new FileWriter("dump"));

        int bytesWritten = 0;

        while (bytesWritten < fileSize) {
            int batchSize =
                    Math.min(fileSize - bytesWritten, buffSize);

            writer.write(buffer, 0, batchSize);
            bytesWritten += batchSize;
        }
    }
}
