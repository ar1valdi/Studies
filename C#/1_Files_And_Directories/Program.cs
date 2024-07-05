using Extensions;
using Microsoft.VisualBasic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections.Generic;
using System.Runtime.Serialization;
using System.Collections;

[Serializable]
public class StringComparer : IComparer<string>
{
    public int Compare(string x, string y)
    {
        int lengthComparison = x.Length.CompareTo(y.Length);

        if (lengthComparison != 0)
        {
            return lengthComparison;
        }

        return string.Compare(x, y);
    }
}

class MainClass
{
    static string rootPath = "";

    private static void printDirRec(string path, string prefix, int maxDepth, int currDepth)
    {
        Console.Write(prefix + Path.GetFileName(path) + " ");
        FileInfo fileInfo = new FileInfo(path);

        if (!Directory.Exists(path))
        {
            long fileSize = fileInfo.Length;
            Console.Write(fileSize + " bytes ");
            Console.WriteLine(fileInfo.GetDOSAttributes());
            return;
        }

        string[] files = Directory.GetFileSystemEntries(path);
        Console.Write("(" + files.Length + ") ");
        Console.WriteLine(fileInfo.GetDOSAttributes());

        if (maxDepth <= currDepth)
        {
            return;
        }

        foreach (string file in files)
        {
            printDirRec(path + "/" + Path.GetFileName(file), prefix + "    ", maxDepth, currDepth + 1);
        }
    } 

    private static SortedDictionary<string, long> getDictionary(string path)
    {
        string[] files = Directory.GetFileSystemEntries(path);
        StringComparer comparer = new StringComparer();
        SortedDictionary<string, long> dict = new SortedDictionary<string, long>(comparer);

        foreach (string file in files)
        {
            if (Directory.Exists(file))
            {
                dict.Add(file, Directory.GetFileSystemEntries(file).Length);
            } 
            else
            {
                FileInfo fileInfo = new FileInfo(file);
                dict.Add(file, fileInfo.Length);
            }
        }
        return dict;
    }

    static void Main(string[] args)
    {
        AppContext.SetSwitch("System.Runtime.Serialization.EnableUnsafeBinaryFormatterSerialization", true);

        rootPath = args[0];
        printDirRec(rootPath, "", 10, 0);
        DirectoryInfo dir = new DirectoryInfo(rootPath);
        var oldestDatePair = dir.FindOldestDate();
        Console.WriteLine("\nNajstarsza plik: " + oldestDatePair.Key + " - " + oldestDatePair.Value + "\n"); ;

        SortedDictionary<string, long> dict = getDictionary(rootPath);

        Serialize(dict);
        SortedDictionary<string, long> deserializedDict = Deserialize();

        foreach (KeyValuePair<string, long> v in deserializedDict)
        {
            Console.WriteLine(v.Key + " -> " + v.Value);
        }
    }

    static void Serialize(SortedDictionary<string, long> dictionary)
    {
        BinaryFormatter formatter = new BinaryFormatter();
        using (FileStream stream = new FileStream("data.bin", FileMode.Create))
        { 
            formatter.Serialize(stream, dictionary);
        }
    }

    private static SortedDictionary<string, long> Deserialize()
    {
        BinaryFormatter formatter = new BinaryFormatter();
        using (FileStream stream = new FileStream("data.bin", FileMode.Open))
        {
            return (SortedDictionary<string, long>)formatter.Deserialize(stream);
        }
    }
}
