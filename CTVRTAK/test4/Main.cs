using System;
using System.IO;

class Program
{
    static void Main()
    {
        string soubor = "zakusky.txt";
        Zakusek[] zakusky = new Zakusek[Metody.DejVelikost(soubor)];

        int index = 0;
        string radek;
        using (StreamReader cteni = new StreamReader(soubor))
        {
            while((radek = cteni.ReadLine()) != null)
            {
                string[] pole = radek.Split(';');
                zakusky[index] = new Zakusek(DateTime.Parse(pole[0]), pole[1], int.Parse(pole[2]), int.Parse(pole[3]));
                index++;
            }
        }

        int pocet = 0;
        int cena = 0;
        DateTime dnes = DateTime.Now;

        using (StreamWriter zapis = new StreamWriter("prosle.txt"))
        {
            foreach (Zakusek zakusek in zakusky)
            {
                if (zakusek.Expirace < dnes && !(zakusek.Expirace.Day == dnes.Day && zakusek.Expirace.Month == dnes.Month && zakusek.Expirace.Year == dnes.Year))
                {
                    Console.WriteLine($"{pocet + 1}. zakusek: {zakusek.Nazev}, {zakusek.Kusy}ks, {zakusek.Cena},-/ks, celkem na kusy: {zakusek.Kusy * zakusek.Cena},- datum spotřeby {zakusek.Expirace.ToShortDateString()}");
                    zapis.WriteLine($"{zakusek.Expirace.ToShortDateString()} {zakusek.Nazev} {zakusek.Kusy} {zakusek.Cena}");
                    cena += (zakusek.Kusy * zakusek.Cena);
                }
                pocet++;
            }
        }

        Console.WriteLine($"Cena za prošlé zákusky je: {cena},-");

        Console.ReadLine();
    }
}

class Metody
{
    public static int DejVelikost(string soubor)
    {
        int velikost = 0;
        using (StreamReader cteni = new StreamReader(soubor))
        {
            while(cteni.ReadLine() != null)
            {
                velikost++;
            }
        }
        return velikost;
    }
}

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