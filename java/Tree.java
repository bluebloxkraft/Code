import java.io.File;
import java.util.Arrays;

public class Tree {

   public static void main(String[] args){
      File dir = new File(".");
      
      if(args.length != 0)
         dir = new File(args[0]);
      
      if(!dir.isDirectory() || !dir.exists()){
         System.out.println("The provided path is not a directory or doesn't exist!");
         return;
      }
      
      tree(dir, "", "");
   }

   public static void tree(File dir, String hierPrefix, String dirPrefix){
      System.out.println(dirPrefix + dir.getName());
      File[] files = dir.listFiles();
      Arrays.sort(files, (f1, f2) -> f1.getName().compareTo(f2.getName()));
      for(int i = 0; i < files.length; i++){
         File f = files[i];
         if(i != files.length - 1){
            if(f.isDirectory()){
               tree(f, hierPrefix + "│    ", hierPrefix + "├── ");
            } else
               System.out.println(hierPrefix + "├── " + f.getName());
         } else {
            if(f.isDirectory()){
               tree(f, hierPrefix + "     ", hierPrefix + "└── ");
            } else
               System.out.println(hierPrefix + "└── " + f.getName());
         }
      }
   }
}
