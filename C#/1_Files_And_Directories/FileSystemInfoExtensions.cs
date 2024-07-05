using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Extensions
{
    public static class FileSystemInfoExtensions
    {
        public static string GetDOSAttributes(this FileSystemInfo fileInfo)
        {
            string attributes = "";
            attributes += (fileInfo.Attributes & FileAttributes.ReadOnly) == FileAttributes.ReadOnly ? 'r' : '-';
            attributes += (fileInfo.Attributes & FileAttributes.Archive) == FileAttributes.Archive ? 'a' : '-';
            attributes += (fileInfo.Attributes & FileAttributes.Hidden) == FileAttributes.Hidden ? 'h' : '-';
            attributes += (fileInfo.Attributes & FileAttributes.System) == FileAttributes.System ? 's' : '-';

            return attributes;
        }
    }
}
