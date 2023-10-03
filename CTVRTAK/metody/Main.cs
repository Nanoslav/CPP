using System;
using metody;

class Program
{
    static void Main()
    {
        Console.WriteLine("===========================================");
        Metody.Radek();
        Console.WriteLine("===========================================");
        Metody.Radek(5);
        Console.WriteLine("===========================================");
        Console.WriteLine("Obsah čtverce o straně a=10 je: " + ObsahyObvody.ObsahCtverce(10));
        Console.WriteLine("===========================================");
        Console.WriteLine("Obvod kruhu o poloměru r=5 je: " + ObsahyObvody.ObvodKruhu(5));
        Console.WriteLine("===========================================");
        int velikostPole = 10;
        int[] ints = MojeMetody.NaplnPole(velikostPole);
        MojeMetody.VypisPole(ints);
        Console.WriteLine("===========================================");


        MojeMetody.Konec();

    }
}