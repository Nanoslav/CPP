using System;

class Program
{
    static void Main()
    {
        Osoba1 osoba1 = new Osoba1("Pepa", 20);
        Student1 student1 = new Student1("Petr", 18, 4);

        Console.WriteLine($"Osoba: {osoba1.Jmeno} ve věku {osoba1.Vek}\n" +
                          $"Student: {student1.Jmeno} ve věku {student1.Vek}, ročník: {student1.Rocnik}");

        Console.ReadKey();
    }
}
//====================================================================================================
class Osoba1
{
    public string Jmeno { get; protected set; }
    public int Vek { get; protected set; }

    public Osoba1() { }

    public Osoba1(string jmeno, int vek)
    {
        Jmeno = jmeno;
        Vek = vek;
    }

}

class Student1 : Osoba1
{
    public int Rocnik { get; }

    public Student1() { }

    public Student1(string jmeno, int vek, int rocnik) //: base(jmeno, vek)
    {
        Vek = vek;
        Jmeno = jmeno;
        Rocnik = rocnik;
    }
}

class Osoba
{
    //private string jmeno;
    //private int vek;

    protected string jmeno;
    protected int vek;

    public Osoba(){}

    public Osoba(string jmeno, int vek)
    {
        this.jmeno = jmeno;
        this.vek = vek;
    }

    public string GetJmeno()
    {
        return jmeno;
    }

    public int GetVek()
    {
        return vek;
    }

}

class Student : Osoba
{
    private int rocnik;

    public Student(){}

    public Student(string jmeno, int vek, int rocnik) //: base(jmeno, vek)
    {
        this.jmeno = jmeno;
        this.vek = vek;
        this.rocnik = rocnik;
    }

    public int GetRocnik()
    {
        return rocnik;
    }

}