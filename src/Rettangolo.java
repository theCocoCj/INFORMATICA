public class Rettangolo {
    private float b;
    private float h;

    public Rettangolo(){
            this.b = 0;
            this.h = 0;
    }

    public Rettangolo(float b, float h){
        if(b >= 0 )
            this.b = b;
        if(h >= 0)
            this.h = h;
    }

    public float getArea(){
        return (b * h);
    }

    public float getPerimetro(){
        return ((b*2) + (h*2));
    }

    public boolean isSquare(){
        return (b==h);
    }

    public String toString() {
        return"[Area=" + getArea() + " Perimetro="  + getPerimetro() + ']';
    }
}
