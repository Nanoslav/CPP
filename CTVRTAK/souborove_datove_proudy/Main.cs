using System;
using System.Diagnostics.CodeAnalysis;
using System.IO;

class Program
{
    static void Main()
    {
        //======================================================================
        //                        Zapis do souboru
        //======================================================================
        StreamWriter zapis = new StreamWriter("soubor.txt");

        zapis.WriteLine("Ahoj svete!");
        zapis.WriteLine("Jak se mas?");
        zapis.WriteLine("Ja se mam dobre.");

        //zapis.Close(); // Uzavreni souboru - zapis do souboru je ukoncen
        //zapis.Flush(); // Vyprazdneni bufferu - mohu znovu zapisovat

        zapis.WriteLine("xxAhoj svete!");
        zapis.WriteLine("xxJak se mas?");
        zapis.WriteLine("xxJa se mam dobre.");

        zapis.Close();

        //======================================================================
        //                        Cteni ze souboru
        //======================================================================
        StreamReader cteni = new StreamReader("data.txt");
        //string text = cteni.ReadToEnd();

        Osoba[] osoby = new Osoba[100];

        string radek;
        int pocet = 0;
        while ((radek = cteni.ReadLine()) != null)
        {
            string[] pole = radek.Split(' ');
            Console.WriteLine(pole[0] + " " + pole[1]);
            osoby[pocet] = new Osoba(pole[0], int.Parse(pole[1]), pole[2]);

            pocet++;
        }

        cteni.Close();

        Console.WriteLine("======================================");
        Console.WriteLine("               Výpis                  ");
        Console.WriteLine("======================================");

        double suma = 0;
        for (int i = 0; i < pocet; i++)
        {
            Console.WriteLine($"{i + 1}. {osoby[i].Jmeno} {osoby[i].Vek} {osoby[i].Mesto}");
            suma += osoby[i].Vek;
        }

        Console.WriteLine("======================================");
        Console.WriteLine($"Prumerny vek: {suma / pocet}");

        Console.ReadKey();
    }
}
//======================================================================
class Osoba
{
    public string Jmeno { get; }
    public int Vek { get; }
    public string Mesto { get; }

    public Osoba(string jmeno, int vek, string mesto)
    {
        Jmeno = jmeno;
        Vek = vek;
        Mesto = mesto;
    }
}