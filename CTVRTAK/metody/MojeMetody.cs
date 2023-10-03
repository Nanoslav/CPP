using System;

namespace metody
{

    class MojeMetody
    {
        public static int[] NaplnPole(int velikost)
        {
            int[] pole = new int[velikost];
            Random rnd = new Random();
            for (int i = 0; i < pole.Length; i++)
            {
                pole[i] = rnd.Next(1, 100);
            }
            return pole;
        }

        public static int[] VypisPole(int[] pole)
        {
            for (int i = 0; i < pole.Length; i++)
            {
                Console.WriteLine("pole[" + i + "] = " + pole[i]);
            }
            return pole;
        }

        //metoda ktera skonci program po kliknuti enteru
        public static void Konec()
        {
            Console.WriteLine("Stiskněte Enter pro ukončení programu.");

            while(Console.ReadKey().Key != ConsoleKey.Enter)
            {
                Console.Write("\b \b");
            }
        }

    }

    class Metody
    {
        public static void Radek()
        {
            Console.WriteLine();
        }

        public static void Radek(int pocet)
        {
            for (int i = 0; i < pocet; i++)
            {
                Console.WriteLine();
            }
        }

    }

    class ObsahyObvody
    {
        public static double ObsahCtverce(double strA)
        {
            return Math.Pow(strA, 2);
        }

        public static double ObvodKruhu(double polomer)
        {
            return Math.Round(2 * Math.PI * polomer, 2);
        }
    }

}
