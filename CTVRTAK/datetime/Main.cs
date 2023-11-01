using System;
using System.IO;

class Program
{
    static void Main()
    {
        //DateTime dnes = DateTime.Now;
        //Console.WriteLine(dnes.ToLongDateString());
        //Console.WriteLine(dnes.ToLongTimeString());
        //Console.WriteLine(dnes.ToShortDateString());
        //Console.WriteLine(dnes.ToShortTimeString());
        //Console.WriteLine(dnes.ToString("dd.MM.yyyy - dddd"));

        //DateTime datum = new DateTime(2000, 11, 6);
        //Console.WriteLine(datum.ToString());

        //datum = datum.AddYears(1);

        //Console.WriteLine(datum.ToString());

        //datum = datum.AddYears(-1);

        //Console.WriteLine(datum.ToString());

        //Console.WriteLine($"Rozdíl dvou roků: {dnes.Year - datum.Year}");

        //TimeSpan rozsah = dnes - datum;
        //Console.WriteLine(rozsah.ToString());
        //Console.WriteLine(rozsah.Ticks);
        //Console.WriteLine(rozsah.Days);
        //Console.WriteLine(rozsah.TotalDays);
        //Console.WriteLine($"Počet let života: {rozsah.Days / 365}");

        Osoba[] osobas = new Osoba[Metody.GiveNumber("data.txt")];

        using (StreamReader cteni = new StreamReader("data.txt"))
        {
            string radek;
            int index = 0;

            while ((radek = cteni.ReadLine()) != null)
            {
                string[] pole = radek.Split(' ');
                osobas[index] = new Osoba(pole[0], DateTime.Parse(pole[1]));
                index++;
            }

        }

        foreach (Osoba osoba in osobas)
        {
            Console.WriteLine($"{osoba.Jmeno} - {osoba.DatumNarozeni.ToShortDateString()}, ve věku {osoba.Vek} let");
        }

        Console.ReadKey();
    }
}
//=========================================================================
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
    public int Vek { get; }
    public DateTime DatumNarozeni { get; }
    public Osoba(string jmeno, DateTime datumNarozeni)
    {
        Jmeno = jmeno;
        DatumNarozeni = datumNarozeni;

        DateTime dnes = DateTime.Now;
        Vek = dnes.Year - datumNarozeni.Year;
        if (datumNarozeni > dnes.AddYears(-Vek)) Vek--;
    }
}