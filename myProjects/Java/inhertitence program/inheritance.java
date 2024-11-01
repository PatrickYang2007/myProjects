/*
 * Patrick Yang
 * April 7th 2024
 * Prints out things about racing
 */
class racing{
    private String whereCompeted="world-wide";
    private String raceType="racing";
    public racing(){

    }
    public racing(String rt, String wC){
        raceType=rt;
        whereCompeted=wC;
    }
    public String returnAll(){
        return "I love " +raceType+ ", and I also love that it is competed "+ whereCompeted;
    }

}
class singleSeaterFormula extends racing{
    

    public singleSeaterFormula(String raceType, String wC){
        super(raceType,wC);
    }

    public String returnAll(){
        return super.returnAll();
    }
}
class formula1 extends singleSeaterFormula{
    String numOfCars="20 cars that compete";
    String level="highest level";
    public formula1(String raceType, String wC){
        super(raceType, wC);
    }
    public String returnAll(){
        return super.returnAll()+", and there are "+ numOfCars+". This is also the "+ level +" of racing in formula.";
    }
}
class formula2 extends singleSeaterFormula{
    String numOfCars="22 cars that compete";
    String level="second highest level";
    public formula2(String raceType,  String wC){
        super(raceType, wC);
    }
    public String returnAll(){
        return super.returnAll()+", and there are "+ numOfCars+". This is also the "+ level +" of racing in formula.";
    }
}
class formula3 extends singleSeaterFormula{
    String numOfCars="30 cars that compete";
    String level="third highest level";
    public formula3(String raceType, String wC){
        super(raceType,wC);
    }
    public String returnAll(){
        return super.returnAll()+", and there are "+ numOfCars+". This is also the "+ level +" of racing in formula.";
    }

}
class formula4 extends singleSeaterFormula{
    String numOfCars="an unknown number of cars that compete";
    String level="lowest level ";
    public formula4(String raceType, String wC){
        super(raceType,wC);
    }
    public String returnAll(){
        return super.returnAll()+", and there are "+ numOfCars+". This is also the "+ level +"of racing in formula.";
    }
}
class enduranceRacing extends racing{
    int length;
    public enduranceRacing(String raceType, String wC, int length){
        super(raceType, wC);
        this.length=length;
    }
    public String returnAll(){
        return super.returnAll()+". These races can also go on for "+length+" hours!";
    }
}
class nascar extends racing{
    public nascar(String raceType, String wC){
        super(raceType, wC);
    }
}
class karting extends racing{
    public karting(String raceType, String wC){
        super(raceType, wC);
    }
    public String returnAll(){
        return super.returnAll()+". Although quite fun, this is where professional drivers normally start out as kids!";
    }
}
public class inheritance {
    public static void main(String[] args) {
        racing num= new racing();
        singleSeaterFormula num1= new singleSeaterFormula("single-seater formula", "worldwide");
        formula1 num2= new formula1("Formula 1", "WorldWide");
        enduranceRacing num3= new enduranceRacing("endurance racing", "worldwide", 24);

        System.out.println(num.returnAll());
        System.out.println(num1.returnAll());
        System.out.println(num2.returnAll());
        System.out.println(num3.returnAll());

    }
}
