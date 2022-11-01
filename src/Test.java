public class Test {
    public static void main(String[] args) {

        Cerchio Ncerch;
        Ncerch = new Cerchio(4);
        //Ncerch.setR(4);

        System.out.println(Ncerch.toString());
        System.out.println(Ncerch.getRaggio());
        System.out.println(Ncerch.getArea());
        System.out.println(Ncerch.getCirconferenza());

        Cerchio Ncerch2;
        Ncerch2 = new Cerchio();
        Ncerch2.setR(4);

        System.out.println(Ncerch2.toString());
        System.out.println(Ncerch2.getRaggio());
        System.out.println(Ncerch2.getArea());
        System.out.println(Ncerch2.getCirconferenza());
    }
}
