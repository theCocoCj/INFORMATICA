public class Mostro {
    private String nome;
    private int vita;
    private int forza;
    private final int FORZA_MIN = 5;
    private final int FORZA_MAX = 10;
    private final int VITA_MIN = 0;
    private final int VITA_MAX = 100;


    public String getNome(){
        return nome;
    }

    public int getForza(){
        return forza;
    }

    public int getVita(){

        return vita;
    }

    public void setNome(String nome){

        this.nome = nome;
    }

    public  void setVita(int vita){
        if(vita >= VITA_MIN && vita <= VITA_MAX)
            this.vita = vita;
    }

    public void setForza(int forza){
        if(forza >= FORZA_MIN && forza <= FORZA_MAX)
            this.forza = forza;
    }

    public void incrementaVita(){
            setVita(vita + 1);
    }

    public void incrementaVita(int valore){
        setVita(vita + valore);
    }

    public  Mostro(String nome, int vita, int forza ) {
        this.nome = nome;
        if(forza >= FORZA_MIN && forza <= FORZA_MAX)
            this.forza = forza;
        else
            this.forza = FORZA_MIN;

        if(vita >= VITA_MIN && vita <= VITA_MAX)
            this.vita = vita;
        else
            this.vita =VITA_MAX / 2;

    }

    public Mostro(String nome){
        this.nome = nome;
        this.forza = FORZA_MIN;
        this.vita = (VITA_MAX - VITA_MIN)/2;
    }

    //overridding
    public String toString() { //stampa il nome la vita e la forza
        return nome + "[vita=" + vita +
                ", forza=" + forza +
                ']';
    }
}




