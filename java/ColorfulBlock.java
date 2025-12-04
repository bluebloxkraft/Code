public class ColorfulBlock {
   public static void main(String[] args) throws InterruptedException
   {
      final int SIZE = 20;
      final int DELTA = 16;

      for(int r = 0; r < 0xFF; r += DELTA)
         for(int g = 0; g < 0xFF; g += DELTA)
            for(int b = 0; b < 0xFF; b += DELTA)
            {
               System.out.print(String.format("\033[H\033[48;2;%d;%d;%dm", r, g, b));
               for(int y = 0; y <  SIZE; y++)
               {
                  for(int x = 0; x < SIZE; x++)
                     System.out.print("  ");
                  System.out.print("\n");
               }

            }
   }
}
