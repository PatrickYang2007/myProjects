/*
 * Patrick Yang
 * March 19 2024(my bday 😁)
 * In a movie theater and it prompts the user if they want to buy a seat through pricing or through
 * seating or to quit. If they buy a seat then the seat is zeroed out and they are told how much they spent.
 * They then can not choose the same seat again, and they can buy as much as possible until they press the sentinel
 * value which is q in this case. 
 */
import java.util.Scanner;

public class main {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] seatingList = new int[][] {
                { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 },
                { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 },
                { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 },
                { 10, 10, 20, 20, 20, 20, 20, 20, 10, 10 },
                { 10, 10, 20, 20, 20, 20, 20, 20, 10, 10 },
                { 10, 10, 20, 20, 20, 20, 20, 20, 10, 10 },
                { 20, 20, 30, 30, 40, 40, 30, 30, 20, 20 },
                { 20, 30, 30, 40, 50, 50, 40, 30, 30, 20 },
                { 30, 40, 50, 50, 50, 50, 50, 50, 40, 30 },
        };
        while (true) {
            displaySeating(seatingList);
            while (true) {

                System.out.print(
                        "\n\nWould you like to select a specific seat, search for seats by price, or quit (s,p,q): ");
                String response = input.nextLine();
                if (response.equals("s")) {

                    int[] seatPosition = getSeatPosition();
                    int seatValue = seatingList[seatPosition[0]][seatPosition[1]];
                    
                    if (seatValue == 0) {
                        System.out
                                .print("\nThe seat in row " + (seatPosition[0] + 1) + " column " + (seatPosition[1] + 1)
                                        + " is not available to be purchased ");
                    } else {
                        System.out.print("\nYou purchased the seat in row " + (seatPosition[0] + 1) + " column "
                                + (seatPosition[1] + 1) + " for $" + seatValue);
                        seatingList[seatPosition[0]][seatPosition[1]] = 0;
                    }

                    break;
                }
                if (response.equals("p")) {

                    int priceOfSeat = getPrice();
                    int[] seatPosition = searchByPrice(seatingList, priceOfSeat);

                    if (seatPosition[0] == -1) {
                        System.out.print("\nThere are no seats available for $" + priceOfSeat);
                    } else {
                        System.out.print("\nYou have bought the seat in row " + (seatPosition[0] + 1) + " column "
                                + (seatPosition[1] + 1) + " for $" + priceOfSeat);
                        seatingList[seatPosition[0]][seatPosition[1]] = 0;
                    }
                    break;
                }

                if (response.equals("q")) {

                    System.out.print("Ending program...\n");
                    System.exit(0);
                }
                System.out.print("Invalid search type, please put in 's', 'p', or 'q'");
            }
            System.out.print("\n\n");
        }
    }

    static int[] getSeatPosition() {

        int seatRow = -1;
        while (true) {
            System.out.print("Put in the seat row (1 - 9 inclusive): ");
            String response = input.nextLine();
            try {
                seatRow = Integer.parseInt(response);

                if (seatRow >= 1 && seatRow <= 9) {
                    break;
                }

                System.out.println("Please put in a value between 1 - 9 inclusive\n");
            } catch (Exception e) {
                System.out.println("Please input a valid number\n");
            }
        }

        int seatCol = -1;
        while (true) {
            System.out.print("Put in the seat column (1 - 10 inclusive): ");
            String response = input.nextLine();
            try {
                seatCol = Integer.parseInt(response);

                if (seatCol >= 1 && seatCol <= 10) {
                    break;
                }

                System.out.println("Please put in a value between 1 - 10 inclusive\n");
            } catch (Exception e) {
                System.out.println("Please input a valid number\n");
            }
        }

        return new int[] { seatRow - 1, seatCol - 1 };
    }

    static int getPrice() {

        int priceOfSeat = 0;
        while (true) {
            System.out.print("Put in the seat price (10, 20, 30, 40, or 50): ");
            String response = input.nextLine();
            try {
                priceOfSeat = Integer.parseInt(response);

                if (priceOfSeat % 10 == 0 && priceOfSeat >= 10 && priceOfSeat <= 50) {
                    break;
                }
                System.out.println("Please put in a either 10, 20, 30, 40, or 50\n");
            } catch (Exception e) {
                System.out.println("Please input a valid number\n");
            }
        }
        return priceOfSeat;
    }
    
    static int[] searchByPrice(int[][] board, int price) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 10; col++) {
                if (board[row][col] == price) {
                    return new int[] { row, col };
                }
            }
        }
        //Returns -1 -1 if there is no match
        return new int[] { -1, -1 };
    }

    
    static void displaySeating(int[][] board) {
        
        
        System.out.printf("%35s\n%42s\n\n%29s\n%10s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n\n", "SEATING LAYOUT:",
                "------------------------------", "COL", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        
        for (int row = 0; row < 9; row++) {
    
            String rowLetter = "   ROW   ".substring(row, row + 1);
            System.out.printf("%s%3s  ", rowLetter, row + 1);

            for (int col = 0; col < 10; col++) {
                System.out.printf("%4s", board[row][col]);
            }
            System.out.println();
        }
    }
}