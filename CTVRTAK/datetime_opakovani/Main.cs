using System;
using System.IO;

class Program
{
    static void Main()
    {

        string soubor = "data.txt";

        Osoba[] osoby = new Osoba[Metody.GiveNumber(soubor)];

        using (StreamReader cteni = new StreamReader(soubor))
        {
            string radek;
            int index = 0;

            while ((radek = cteni.ReadLine()) != null)
            {
                string[] pole = radek.Split(';');
                osoby[index] = new Osoba(pole[0], pole[1], DateTime.Parse(pole[2]));
                index++;
            }
        }

        int vekMuzi = 0;
        int sumaMuzi = 0;
        int vekZeny = 0;
        int sumaZeny = 0;
        int sumaCelkem = Metody.GiveNumber(soubor);

        foreach (Osoba osoba in osoby)
        {
            //Console.WriteLine($"{osoba.Jmeno} {osoba.Pohlavi} {osoba.Vek}");
            if (osoba.Pohlavi == "žena")
            {
                sumaZeny++;
                vekZeny += osoba.Vek;
            }
            else
            {
                sumaMuzi++;
                vekMuzi += osoba.Vek;
            }
        }

        Console.WriteLine($"Průměrný věk žen: {vekZeny / sumaZeny} (Celkem žen: {sumaZeny})");
        Console.WriteLine($"Průměrný věk mužů: {vekMuzi / sumaMuzi} (Celkem mužů: {sumaMuzi})");
        Console.WriteLine($"Průměrný věk celkem: {(vekMuzi + vekZeny) / sumaCelkem} (Celkem osob: {sumaCelkem})");

        Console.ReadLine();
    }
}
//======================================================================
class Metody
{
    public static int GiveNumber(string soubor)
    {
        int velikost = 0;
        StreamReader cteni = new StreamReader(soubor);
        string radek;
        while ((radek = cteni.ReadLine()) != null)
        {
            velikost++;
        }
        cteni.Close();
        return velikost;
    }
}
class Osoba
{
    public string Jmeno { get; }
    public string Pohlavi { get; }
    public int Vek { get; }
    public DateTime DatumNarozeni { get; }

    //konstruktor
    public Osoba(string jmeno, string pohlavi, DateTime datumNarozeni)
    {
        Jmeno = jmeno;
        Pohlavi = pohlavi;
        DatumNarozeni = datumNarozeni;

        DateTime today = DateTime.Now;
        Vek = today.Year - datumNarozeni.Year;
        if (datumNarozeni > today.AddYears(-Vek)) Vek--;
    }

}