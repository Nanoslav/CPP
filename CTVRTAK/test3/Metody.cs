using System;

namespace Metody
{

    class Mistnost
    {
        private int sirka;
        private int delka;

        public Mistnost(int sirka, int delka)
        {
            this.sirka = sirka;
            this.delka = delka;
        }

        public int getSirka()
        {
            return sirka;
        }

        public int getDelka()
        {
            return delka;
        }

    }
    
    class Vlastnosti
    {

        public static Mistnost[] NaplnMistnosti()
        {
            Console.Write("Zadej pocet mistnosti: ");
            int pocet = int.Parse(Console.ReadLine());

            Mistnost[] mistnosti = new Mistnost[pocet];

            int sirka, delka;

            for(int i = 0; i < pocet; i++)
            {
                Console.Clear();
                Console.WriteLine(i + 1 + ". mistnost");
                Console.WriteLine("==================");
                Console.Write("Zadej sirku: ");
                sirka = int.Parse(Console.ReadLine());
                Console.Write("Zadej delku: ");
                delka = int.Parse(Console.ReadLine());
                mistnosti[i] = new Mistnost(sirka, delka);
            }

            return mistnosti;

        }

        public static int Plocha(Mistnost[] mistnosti)
        {

            Console.Clear();

            int plocha = 0;

            for (int i = 0; i < mistnosti.Length; i++)
            {
                plocha += (mistnosti[i].getSirka() * mistnosti[i].getDelka());
            }

            return plocha;
        }

    }

}
