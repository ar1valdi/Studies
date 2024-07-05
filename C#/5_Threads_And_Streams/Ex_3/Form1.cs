using System.IO.Compression;
using System.Windows.Forms;

namespace Lab11_Forms_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // compress
        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult result = folderBrowserDialog1.ShowDialog();

            if (result == DialogResult.OK)
            {
                string selectedPath = folderBrowserDialog1.SelectedPath;
                string[] files = Directory.GetFiles(selectedPath);
                Parallel.ForEach(files, CompressFile);
                MessageBox.Show("Compression done");
            }
        }

        // decompress
        private void button2_Click(object sender, EventArgs e)
        {
            DialogResult result = folderBrowserDialog1.ShowDialog();

            if (result == DialogResult.OK)
            {
                string selectedPath = folderBrowserDialog1.SelectedPath;
                string[] files = Directory.GetFiles(selectedPath);
                Parallel.ForEach(files, DecompressFile);
                MessageBox.Show("Decompression done");
            }
        }
        static void CompressFile(string filePath)
        {
            if (Path.GetExtension(filePath) == ".gz") { return; }
            string compressedFilePath = filePath + ".gz";

            using (FileStream originalFileStream = File.OpenRead(filePath))
            {
                using (FileStream compressedFileStream = File.Create(compressedFilePath))
                {
                    using (GZipStream compressionStream = new GZipStream(compressedFileStream, CompressionMode.Compress))
                    {
                        originalFileStream.CopyTo(compressionStream);
                    }
                }
            }
        }
        static void DecompressFile(string filePath)
        {
            if (Path.GetExtension(filePath) != ".gz") { return; }

            string decompressedFilePath = filePath.Substring(0, filePath.Length - 3);

            using (FileStream compressedFileStream = File.OpenRead(filePath))
            {
                using (FileStream decompressedFileStream = File.Create(decompressedFilePath))
                {
                    using (GZipStream decompressionStream = new GZipStream(compressedFileStream, CompressionMode.Decompress))
                    {
                        decompressionStream.CopyTo(decompressedFileStream);
                    }
                }
            }

        }
    }
}