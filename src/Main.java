public class Main {
    public static void main(String[] args){
        Rettangolo nRet;
        nRet = new Rettangolo(8,8);

        System.out.println(nRet.toString());
        System.out.println(nRet.getArea());
        System.out.println(nRet.getPerimetro());

        if(nRet.isSquare()){
            System.out.println("E' un quadrato");
        }else{
            System.out.println("Non e' un quadrato");
        }

        Rettangolo nRet2;
        nRet2 = new Rettangolo(4, 3);

        System.out.println(nRet2.toString());
        System.out.println(nRet2.getArea());
        System.out.println(nRet2.getPerimetro());

        if(nRet2.isSquare()){
            System.out.println("E' un quadrato");
        }else{
            System.out.println("Non e' un quadrato");
        }

    }
}
