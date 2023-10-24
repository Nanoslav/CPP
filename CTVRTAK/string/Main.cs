using System;
using System.Text;

class Program
{
    static void Main()
    {

        string text = "ahoj jak se vede";

        for (int i = 0; i < text.Length; i++)
        {
            if (text[i] == 'a')
            {
                //text[i] = 'b'; // nefunguje
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.Append(text);

        for (int i = 0; i < sb.Length; i++)
        {
            if (sb[i] == 'a')
            {
                sb[i] = 'b';
            }
        }

        Console.WriteLine(sb);
        //======================================================================
        string text2 = "ahoj";
        text2 += " cau" + " nazdar";

        Console.WriteLine(text2);

        Console.WriteLine(text2.Insert(5, "hi "));
        Console.WriteLine(text2);

        //======================================================================

        string veta = "ahoj jak se    vede;třído";
        //string[] pole = veta.Split(' ');
        char[] znaky = new char[] { ' ', ';', '#', '@' };
        string[] pole = veta.Split(znaky, StringSplitOptions.RemoveEmptyEntries);
        //string[] pole = veta.Split(new char[] {' ', ';', '#', '@'});

        for (int i = 0; i < pole.Length; i++)
        {
            Console.WriteLine(pole[i]);
        }

        //======================================================================

        string spojeni = string.Join(" ", pole);

        Console.WriteLine(spojeni);

        Console.ReadKey();
    }
}