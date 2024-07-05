using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Extensions
{
    public static class DirectoryInfoExtensions
    {
        public static KeyValuePair<string, DateTime> FindOldestDate(this DirectoryInfo directory)
        {
            DateTime oldestDate = DateTime.MaxValue;
            string oldestFile = "";

            foreach (var file in directory.GetFiles())
            {
                if (file.LastWriteTime < oldestDate)
                {
                    oldestDate = file.LastWriteTime;
                    oldestFile = file.Name;
                }
            }

            foreach (var subDir in directory.GetDirectories())
            {
                KeyValuePair<string, DateTime> recRes = FindOldestDate(subDir);
                DateTime subDirOldestDate = recRes.Value;
                if (subDirOldestDate < oldestDate)
                {
                    oldestDate = subDirOldestDate;
                    oldestFile = recRes.Key;
                }
            }

            return KeyValuePair.Create<string, DateTime>(oldestFile, oldestDate);
        }
    }
}
