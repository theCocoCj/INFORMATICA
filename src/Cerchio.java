public class Cerchio {
    private float raggio;

    private static final float piGreco = 3.1415926535f; //final perchè è una costante, static

public Cerchio(){
    this.raggio = 0;
}

public Cerchio(float raggio_dato){
    if(raggio_dato >= 0){
        this.raggio = raggio_dato;
    }else{
        this.raggio = 0;
    }
}
public float getRaggio(){
    return raggio;
}

public void setR(float r) {
    if (raggio >= 0) {
        this.raggio = r;
    }
}

public boolean isPerEqual(){

}

public float getArea(){
    return ((raggio*raggio)*piGreco);
}

public float getCirconferenza(){
    return ((2*raggio)*piGreco);

}
public String toString() {
    return "[raggio: " + raggio + "; Area: " + getArea() + " Circonferenza:" + getCirconferenza() + "]";
}
}

