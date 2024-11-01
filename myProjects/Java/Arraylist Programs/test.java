import java.util.ArrayList;

public class test {
    public static void main(String[] args) {
        ArrayList<String> possibleNames=new ArrayList<>();
        String firstName="abcdsadf";
        String lastName="b";

        for(int i=0; i< firstName.length(); i++){
            possibleNames.add(lastName+firstName.substring(0,i));
        }
        possibleNames.remove(0);
        System.out.println(possibleNames);
    }
}
