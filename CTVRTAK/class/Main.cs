using System;

class Program
{
    static void Main()
    {

        Osoba osoba = new Osoba("Kuba", 19, "Teplice");

        Console.WriteLine("Jmeno: " + osoba.Jmeno());
        Console.WriteLine("Vek: " + osoba.Vek());
        Console.WriteLine("Mesto: " + osoba.Mesto());

        Console.WriteLine("Zadej počet osob: ");
        int pocet = int.Parse(Console.ReadLine());

        Osoba[] osobas = new Osoba[pocet];

        string jmeno;
        int vek;
        string mesto;

        for (int i = 0; i < pocet; i++)
        {
            Console.WriteLine("Zadej jmeno: ");
            jmeno = Console.ReadLine();

            Console.WriteLine("Zadej vek: ");
            vek = int.Parse(Console.ReadLine());

            Console.WriteLine("Zadej mesto: ");
            mesto = Console.ReadLine();

            osobas[i] = new Osoba(jmeno, vek, mesto);
        }

        Console.WriteLine("-----------------------------------");
        Console.WriteLine("             Vypis osob");
        Console.WriteLine("-----------------------------------");

        for (int i = 0; i < pocet; i++)
        {
            Console.WriteLine("Jmeno: " + osobas[i].Jmeno() + ", Vek: " + osobas[i].Vek() + ", Mesto: " + osobas[i].Mesto());
        }
        Console.ReadKey();
    }
}
//-------------------------------------------------------------

class Osoba
{
    private string jmeno;
    private int vek;
    private string mesto;

    public Osoba(){}

    public Osoba(string jmeno, int vek, string mesto)
    {
        this.jmeno = jmeno;
        this.vek = vek;
        this.mesto = mesto;
    }

    public string Jmeno() { return jmeno; }

    public int Vek(){ return vek; }

    public string Mesto() { return mesto; }

}