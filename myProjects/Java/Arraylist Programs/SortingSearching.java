/*
 * Patrick Yang
 * Feb 25 2024
 * First program creates an array list of 35 ints from 1-25 and prints out the original array, an array with no duplicates and also an array with the numbers that were removed
 * 
 * Second program creates an array list of 35 ints from 1400-1500 and then sorts them in accending order and prints the original and the sorted one. It then takes the original 
 * array and finds the number that the user is looking for and returns the index that it is first found. The person can choose if they want to find a different number after. 
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;


public class SortingSearching {
    public static void main(String[] args) {
        ArrayList<Integer> removedIntegers=new ArrayList<>();
        ArrayList<Integer> arrayList= new ArrayList<>();
        for(int i=0; i<35; i++){
            arrayList.add((int)(Math.random()*25)+1);
        }

        ArrayList<Integer> newStuff=new ArrayList<>();
        for(int i: arrayList){
            newStuff.add(i);
        }

        for(int i=0; i<newStuff.size(); i++){
            for(int j=i+1; j<newStuff.size(); j++){
                if(newStuff.get(i)==newStuff.get(j)){
                    removedIntegers.add(newStuff.get(j));
                    newStuff.remove(j);
                    j--;
                }
            }
        }
        
        Collections.sort(newStuff);
        Collections.reverse(newStuff);

        System.out.println("Original array: " +arrayList);
        System.out.println("Array with no duplicates: "+newStuff);
        System.out.println("Removed integers: "+removedIntegers);


        Scanner scanner=new Scanner(System.in);
        Random random=new Random();
        int numLook=0; 
        String num="";
        ArrayList<Integer> hi= new ArrayList<>();
        for(int i=0; i< 35; i++){
            hi.add(random.nextInt(101)+1400);
        }
        System.out.println("Original:" +hi);
        ArrayList <Integer> hi1= new ArrayList<>();
        for(int i: hi){
            hi1.add(i);
        }
        Collections.sort(hi1);
        System.out.println("Accending Order: "+ hi1);

        System.out.println("What number are you looking for?: ");
        boolean innerLoop= true; 
        boolean wholeThing=true;
        int counter=0,index=0; 
        while (wholeThing) {
            while (innerLoop) {
                try {
                    num=scanner.nextLine();
                    numLook=Integer.parseInt(num);
                    if(numLook>=1400&&numLook<=1500){
                        innerLoop=false;
                    }else{
                        System.out.println("Error please enter an integer between 1400 and 1500: ");
                    }
                    
                } catch (Exception e) {
                    System.out.println("Error please enter an integer between 1400 and 1500: ");
                }
            }
            for(int i=0; i<hi.size(); i++){
                if(hi.get(i)==numLook){
                    index=i;
                    break;
                }
            }
            for(int i: hi){
                if(i==numLook){
                    counter++;
                }
            }
            if(counter==0){
                System.out.println("Your number was not found in this list");
            }else{
                System.out.println("The first index of your number was: "+ index+", and it showed up "+counter+" times");
            }

            System.out.println("Would you like to try again Y/N");
            String answer=scanner.nextLine();
            boolean miniThing=true;
            while (miniThing){
                if(answer.toLowerCase().equals("y")){
                    miniThing=false;
                    innerLoop=true;
                    System.out.println("Enter an integer from 1400 to 1500: ");
                }else if(answer.toLowerCase().equals("n")){
                    wholeThing=false;
                    System.out.println("Ok bye");
                    break;
                }else{
                    System.out.println("Please enter Y/N only and try again: ");
                    answer=scanner.nextLine();
                }
            }  
        }
        
        scanner.close();
    }
}
