using System;

class Program
{
    static void Main()
    {
        Osoba1 osoba1 = new Osoba1("Kuba", 19);
        Console.WriteLine(osoba1.Jmeno() + ", vek: " + osoba1.Vek());

        Osoba2 osoba2 = new Osoba2();
        osoba2.Jmeno = "Fanda";
        osoba2.Vek = 18;
        Console.WriteLine(osoba2.Jmeno + ", vek: " + osoba2.Vek);

        Osoba3 osoba3 = new Osoba3("Radek", 15);
        //osoba3.Jmeno = "Radek";
        //osoba3.Vek = 15;
        Console.WriteLine(osoba3.Jmeno + ", vek: " + osoba3.Vek);

        Console.ReadKey();
    }
}
//--------------------------------------------------------------------
class Osoba4
{
    public string Jmeno
    { get; set; }
    public int Vek
    { get; set; }

    public Osoba4(string jmeno, int vek)
    {
        Jmeno = jmeno;
        Vek = vek;
    }
}

class Osoba3
{
    private string jmeno;
    public string Jmeno
    {
        get { return jmeno; }
        private set { jmeno = value; }
    }
    private int vek;
    public int Vek
    {
        get { return vek; }
        private set { vek = value; }
    }

    public Osoba3(string jmeno, int vek)
    {
        Jmeno = jmeno;
        Vek = vek;
    }
}

class Osoba2
{
    private string jmeno;
    public string Jmeno
    {
        get { return jmeno; }
        set { jmeno = value; }
    }
    private int vek;
    public int Vek
    {
        get { return vek; }
        set { vek = value; }
    }

}

class Osoba1
{
    private string jmeno;
    private int vek;

    public Osoba1(){}

    public Osoba1(string jmeno, int vek)
    {
        this.jmeno = jmeno;
        this.vek = vek;
    }

    public string Jmeno() { return this.jmeno; }
    public int Vek() { return this.vek; }

}