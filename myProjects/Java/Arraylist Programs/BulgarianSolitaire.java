/*
 * Patrick Yang
 * Feb 25 2024
 * Creates a random number of piles consisting random numbers that add to 45 and then sorts them into the final destination of [1,2,3,4,5,6,7,8,9]
 */
import java.util.ArrayList;

public class BulgarianSolitaire {
    public static void main(String[] args) {
        int cardsLeft=45;
        int cardNum=0;
        int configurations=0;
        

        ArrayList<Integer> cardList=new ArrayList<>();
        ArrayList<Integer> Ans= new ArrayList<>();

        for(int i=1; i<10; i++){
            Ans.add(i);
        }

        while(cardsLeft!=0){
            cardNum=(int)(Math.random()*45+1);            
            cardNum=Math.min(cardNum, cardsLeft);
            
            cardList.add(cardNum);
            cardsLeft-=cardNum;
        }
        System.out.print("Original List [ ");
        for(int i:cardList){
            System.out.print(i+" ");
        }
        System.out.println("]");

       while (!cardList.equals(Ans)){
            int addition=0; 
            ArrayList<Integer> newList=new ArrayList<>();
            for(int i=0; i<cardList.size(); i++){
                cardList.set(i, cardList.get(i)-1);
                if(cardList.get(i)!=0){
                    newList.add(cardList.get(i));
                }
                addition++;

            }

            newList.add(addition);
            cardList=newList;
            configurations++;
            
        System.out.print("[ ");
        for(int i:cardList){
            System.out.print(i+" ");
        }
        System.out.println("]");

        }
       
        System.out.println("Total Number of Configurations: " +configurations);
       
    }
}