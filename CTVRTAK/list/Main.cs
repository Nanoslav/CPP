using System;
using System.Collections.Generic;
using System.IO;

class Program
{
    static void Main()
    {

        string soubor = "zakusky.txt";

        List<Zakusek> zakusky = new List<Zakusek>();
        if (!File.Exists(soubor))
        {
            Console.WriteLine($"Nepodařilo se otevřít soubor '{soubor}'...");
            Console.ReadKey();
            return;
        }

        using (StreamReader cteni = new StreamReader(soubor))
        {
            string radek;
            while ((radek = cteni.ReadLine()) != null)
            {
                string[] pole = radek.Split(';');
                DateTime expirace = DateTime.Parse(pole[0]);
                string nazev = pole[1];
                int kusy = int.Parse(pole[2]);
                int cena = int.Parse(pole[3]);

                zakusky.Add(new Zakusek(expirace, nazev, kusy, cena));
            }
        }

        int poradi = 1;
        foreach (Zakusek zakusek in zakusky)
        {
            Console.WriteLine($"{poradi++}. {zakusek.Expirace.ToShortDateString()} {zakusek.Nazev} {zakusek.Kusy}ks, {zakusek.Cena},-/ks - {zakusek.Kusy * zakusek.Cena},-Kč");
        }

        Console.WriteLine($"Kapacita: {zakusky.Capacity}");

        #region List
        //List<string> list = new List<string>();
        //Console.WriteLine($"Počet položek v listu: {list.Count}");
        //Console.WriteLine($"Kapacita položek: {list.Capacity}");
        //Console.WriteLine("====================================================");
        //list.Add("Ahoj");
        //Console.WriteLine($"Počet položek v listu: {list.Count}");
        //Console.WriteLine($"Kapacita položek: {list.Capacity}");
        //Console.WriteLine("====================================================");
        //list.Add("Čau");
        //list.Add("Nazdar");
        //list.Add("Hi");
        //list.Add("Hello");
        //Console.WriteLine($"Počet položek v listu: {list.Count}");
        //Console.WriteLine($"Kapacita položek: {list.Capacity}");
        //Console.WriteLine("====================================================");
        //list.Add("Jedna");
        //list.Add("Two");
        //list.Add("Drei");
        //list.Add("Quatro");
        //Console.WriteLine($"Počet položek v listu: {list.Count}");
        //Console.WriteLine($"Kapacita položek: {list.Capacity}");
        //Console.WriteLine("====================================================");

        ////list.Clear();
        //list.Remove("Ahoj");
        //list.RemoveAt(4);

        //Console.WriteLine($"Počet položek v listu: {list.Count}");
        //Console.WriteLine($"Kapacita položek: {list.Capacity}");
        //Console.WriteLine("====================================================");

        //for (int i = 0; i < list.Count; i++)
        //{
        //    Console.WriteLine(list[i]);
        //}

        //Console.WriteLine("====================================================");

        //foreach (string item in list)
        //{
        //    Console.WriteLine(item);
        //}
#endregion


        Console.ReadLine();
    }
}
//====================================================================================================
class Zakusek
{

    public DateTime Expirace { get; }
    public string Nazev { get; }
    public int Kusy { get; }
    public int Cena { get; }

    public Zakusek(DateTime expirace, string nazev, int kusy, int cena)
    {
        Expirace = expirace;
        Nazev = nazev;
        Kusy = kusy;
        Cena = cena;
    }

}